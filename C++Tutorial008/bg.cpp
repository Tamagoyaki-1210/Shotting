//=============================================================================
//
// 背景
// Author : tanimoto kosuke
//
//=============================================================================
#include "bg.h"
#include "renderer.h"
#include "application.h"
#include "texture.h"

//=====================================
//デフォルトコンストラクタ
//=====================================
CBG::CBG()
{

}

//=====================================
//デストラクタ
//=====================================
CBG::~CBG()
{

}

//=====================================
//初期化処理
//=====================================
void CBG::Init()
{
	CObject2D::Init();

	//外部ファイルで変数に値を代入したい枠
	m_fWidth = BG_WIDTH;
	m_fHeight = BG_HEIGHT;

	//オブジェクト設定処理
	SetObject2D(CObject::OBJTYPE_BG, m_fWidth, m_fHeight);
}

//=====================================
//終了処理
//=====================================
void CBG::Uninit()
{
	CObject2D::Uninit();
}

//=====================================
//更新処理
//=====================================
void CBG::Update()
{
	CObject2D::Update();

	UpdateType();

	//UV設定処理
	CObject2D::SetUV();

	//位置取得
	D3DXVECTOR3 pos = CObject2D::GetPos();

	//角度取得処理
	D3DXVECTOR3 rot = CObject2D::GetRot();

	//減衰
	m_move = m_move - (m_move * 0.05f);

	//位置更新
	pos += m_move;

	//位置設定処理
	SetPos(pos);

	//角度取得処理
	CObject2D::SetRot(rot);
}

//=====================================
//描画処理
//=====================================
void CBG::Draw()
{
	switch (m_bgType)
	{
	case BGTYPE_NORMAL :
		CApplication::GetTexture()->TextureType(CTexture::TEXTYPE_BG);
		break;

	case BGTYPE_STAR1:
		CApplication::GetTexture()->TextureType(CTexture::TEXTYPE_BG_STAR1);
		break;
	}

	CObject2D::Draw();
}

//=====================================
//位置設定処理
//=====================================
void CBG::SetPos(D3DXVECTOR3 pos)
{
	CObject2D::SetPos(pos);
}

//=====================================
//種別更新処理
//=====================================
void CBG::UpdateType()
{
	switch (m_bgType)
	{
	case BGTYPE_NORMAL:
		//色設定処理
		CObject2D::SetColor(D3DXCOLOR(0.2f, 0.2f, 1.0f, 0.4f), D3DXCOLOR(0.2f, 0.2f, 1.0f, 0.4f), D3DXCOLOR(0.2f, 0.2f, 1.0f, 0.2f), D3DXCOLOR(0.2f, 0.2f, 1.0f, 0.2f));
		break;

	case BGTYPE_STAR1:
		CObject2D::SetTex(3000,1,1);
		CObject2D::SetColor(D3DXCOLOR(0.8f, 0.8f, 0.8f, 0.8f), D3DXCOLOR(0.8f, 0.8f, 0.8f, 0.8f), D3DXCOLOR(0.8f, 0.8f, 0.8f, 0.8f), D3DXCOLOR(0.8f, 0.8f, 0.8f, 0.8f));
		break;
	}
}

//=====================================
//プレイヤー生成処理
//=====================================
CBG *CBG::Create(D3DXVECTOR3 pos, BG_TYPE bgType)
{
	CBG* pBG = new CBG;		//プレイヤーポインタ

	if (pBG != nullptr)
	{
		pBG->Init();
		pBG->SetPos(pos);
		pBG->m_bgType = bgType;
	}

	return pBG;
}