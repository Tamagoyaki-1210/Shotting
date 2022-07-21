//=============================================================================
//
// 弾
// Author : tanimoto kosuke
//
//=============================================================================
#ifndef _BULLET_H_
#define _BILLET_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "object2D.h"

//---------------------------
//マクロ関数
//---------------------------
#define BULLET_WIDTH	(50)
#define BULLET_HEIGHT	(50)
#define BULLET_LIFE		(60)
#define BULLET_FSPEED	(8.0f)

//---------------------------
//前方宣言
//---------------------------
class CTexture;

//---------------------------
//クラス
//---------------------------
class CBullet: public CObject2D
{
public:
	CBullet();
	~CBullet() override;

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	void SetPos(D3DXVECTOR3 pos) override;

	void Destroy(D3DXVECTOR3 pos);																	//消去処理
	void SetCollision(D3DXVECTOR3 pos, float fLength);												//当たり判定設定処理
	bool CollisionCircle(D3DXVECTOR3 pos, float fLength, D3DXVECTOR3 posSub, float fLengthSub);		//円型当たり判定計算処理

	static CBullet *Create(D3DXVECTOR3 pos);
private:
	D3DXVECTOR3 m_move;		//移動量
	int m_nLife;			//体力
	float m_fSpeed;			//移動速度
	float m_fWidth;			//長さ横
	float m_fHeight;		//長さ縦
};

#endif // !_BILLET_H_
