//=============================================================================
//
// 弾
// Author : tanimoto kosuke
//
//=============================================================================
#include "bullet.h"
#include "input.h"
#include "renderer.h"
#include "application.h"
#include "texture.h"
#include "explosion.h"
#include "enemy.h"

//=====================================
//デフォルトコンストラクタ
//=====================================
CBullet::CBullet() : m_nLife(0), m_fSpeed(0.0f)
{

}

//=====================================
//デストラクタ
//=====================================
CBullet::~CBullet()
{

}

//=====================================
//初期化処理
//=====================================
void CBullet::Init()
{
	CObject2D::Init();
	m_nLife = BULLET_LIFE;
	m_fSpeed = BULLET_FSPEED;
	m_fWidth = BULLET_WIDTH;
	m_fHeight = BULLET_HEIGHT;

	//オブジェクト設定処理
	SetObject2D(CObject::OBJTYPE_BULLET, m_fWidth, m_fHeight);
}

//=====================================
//終了処理
//=====================================
void CBullet::Uninit()
{
	CObject2D::Uninit();
}

//=====================================
//更新処理
//=====================================
void CBullet::Update()
{
	CObject2D::Update();

	//UV設定
	CObject2D::SetUV();

	//弾移動
	m_move.x = m_fSpeed;

	//減衰
	m_move = m_move - (m_move * 0.05f);

	//位置取得処理
	D3DXVECTOR3 pos = CObject2D::GetPos();
	
	//長さ取得処理
	float fLength = CObject2D::GetLength();

	//位置更新
	pos += m_move;

	//位置設定処理
	SetPos(pos);

	//位置設定処理
	SetLength(fLength);

	//当たり判定設定処理
	SetCollision(pos, fLength);

	//寿命計算
	if (m_nLife <= 0)
	{
		Destroy(pos);
	}
	else
	{//寿命を減らす
		m_nLife--;
	}
}

//=====================================
//描画処理
//=====================================
void CBullet::Draw()
{
	//画像取得処理
	CApplication::GetTexture()->TextureType(CTexture::TEXTYPE_BULLET);
	CObject2D::Draw();
}

//=====================================
//位置設定処理
//=====================================
void  CBullet::SetPos(D3DXVECTOR3 pos)
{
	CObject2D::SetPos(pos);
}

//=====================================
//消去処理
//=====================================
void CBullet::Destroy(D3DXVECTOR3 pos)
{
	//爆発生成処理
	CExplosion::Create(pos);

	Uninit();
}

//=====================================
//当たり判定設定処理
//=====================================
void CBullet::SetCollision(D3DXVECTOR3 pos, float fLength)
{
	//当たり判定
	for (int nInd = 0; nInd < MAX_OBJECT; nInd++)
	{
		CObject *pObject = Get(nInd);	//対象オブジェクトのポインタ

		if (pObject != nullptr)
		{
			CObject::Object_TYPE objtype = pObject->GetType();	//オブジェクトの種別

			if (objtype == CObject::OBJTYPE_ENEMY)
			{//敵キャラの場合
				if (CollisionCircle(pos, fLength, pObject->GetPos(), pObject->GetLength()))
				{//重なった場合
					Destroy(pos);

					//オブジェクト側の破棄
					pObject->Uninit();

					//被弾処理
					//pObject->Hit(10);
				}
			}
		}
	}
}

//=====================================
//円型当たり判定計算処理
//=====================================
bool CBullet::CollisionCircle(D3DXVECTOR3 pos, float fLength, D3DXVECTOR3 posSub, float fLengthSub)
{
	float fSumLengthRad = (fLength + fLengthSub) * 0.5f;				//円の半径同士の和

	float fDiffX = pos.x - posSub.x;									//X座標の差分
	float fDiffY = pos.y - posSub.y;									//Y座標の差分
	float fDiffLength = sqrtf((fDiffX * fDiffX) + (fDiffY * fDiffY));	//現在の2点の距離

	return fSumLengthRad >= fDiffLength;
}

//=====================================
//生成処理
//=====================================
CBullet *CBullet::Create(D3DXVECTOR3 pos)
{
	CBullet* pBullet = new CBullet;	//弾のポインタ

	if (pBullet != nullptr)
	{
		pBullet->Init();
		pBullet->SetPos(pos);
	}

	return pBullet;
}
