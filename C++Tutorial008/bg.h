//=============================================================================
//
// �w�i
// Author : tanimoto kosuke
//
//=============================================================================
#ifndef _BG_H_
#define _BG_H_

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "object2D.h"

//---------------------------
//�}�N���֐�
//---------------------------
#define BG_WIDTH	(SCREEN_WIDTH)
#define BG_HEIGHT	(SCREEN_HEIGHT)

//---------------------------
//�N���X
//---------------------------
class CBG : public CObject2D
{
public:
	enum BG_TYPE
	{
		BGTYPE_NORMAL = 0,	//�w�i
		BGTYPE_STAR1,		//��1
		BGTYPE_MAX,			//�ő�l
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
	D3DXVECTOR3 m_move;	//�ړ���
	float m_fWidth;		//������
	float m_fHeight;	//�����c
	BG_TYPE m_bgType;	//�w�i���
};

#endif // !_PLAYER_H_
