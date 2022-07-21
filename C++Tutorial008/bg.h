//=============================================================================
//
// îwåi
// Author : tanimoto kosuke
//
//=============================================================================
#ifndef _BG_H_
#define _BG_H_

//*****************************************************************************
// ÉCÉìÉNÉãÅ[Éh
//*****************************************************************************
#include "object2D.h"

//---------------------------
//É}ÉNÉçä÷êî
//---------------------------
#define BG_WIDTH	(SCREEN_WIDTH)
#define BG_HEIGHT	(SCREEN_HEIGHT)

//---------------------------
//ÉNÉâÉX
//---------------------------
class CBG : public CObject2D
{
public:
	enum BG_TYPE
	{
		BGTYPE_NORMAL = 0,	//îwåi
		BGTYPE_STAR1,		//êØ1
		BGTYPE_MAX,			//ç≈ëÂíl
	};

	CBG();
	~CBG() override;

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	void SetPos(D3DXVECTOR3 pos) override;

	void UpdateType();
	static CBG *Create(D3DXVECTOR3 pos, BG_TYPE bgType);
private:
	D3DXVECTOR3 m_move;	//à⁄ìÆó 
	float m_fWidth;		//í∑Ç≥â°
	float m_fHeight;	//í∑Ç≥èc
	BG_TYPE m_bgType;	//îwåiéÌóﬁ
};

#endif // !_PLAYER_H_
