//=============================================================================
//
// �e
// Author : tanimoto kosuke
//
//=============================================================================
#ifndef _BULLET_H_
#define _BILLET_H_

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "object2D.h"

//---------------------------
//�}�N���֐�
//---------------------------
#define BULLET_WIDTH	(50)
#define BULLET_HEIGHT	(50)
#define BULLET_LIFE		(60)
#define BULLET_FSPEED	(8.0f)

//---------------------------
//�O���錾
//---------------------------
class CTexture;

//---------------------------
//�N���X
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

	void Destroy(D3DXVECTOR3 pos);																	//��������
	void SetCollision(D3DXVECTOR3 pos, float fLength);												//�����蔻��ݒ菈��
	bool CollisionCircle(D3DXVECTOR3 pos, float fLength, D3DXVECTOR3 posSub, float fLengthSub);		//�~�^�����蔻��v�Z����

	static CBullet *Create(D3DXVECTOR3 pos);
private:
	D3DXVECTOR3 m_move;		//�ړ���
	int m_nLife;			//�̗�
	float m_fSpeed;			//�ړ����x
	float m_fWidth;			//������
	float m_fHeight;		//�����c
};

#endif // !_BILLET_H_
