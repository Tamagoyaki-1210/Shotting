//=============================================================================
//
// �e
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
//�f�t�H���g�R���X�g���N�^
//=====================================
CBullet::CBullet() : m_nLife(0), m_fSpeed(0.0f)
{

}

//=====================================
//�f�X�g���N�^
//=====================================
CBullet::~CBullet()
{

}

//=====================================
//����������
//=====================================
void CBullet::Init()
{
	CObject2D::Init();
	m_nLife = BULLET_LIFE;
	m_fSpeed = BULLET_FSPEED;
	m_fWidth = BULLET_WIDTH;
	m_fHeight = BULLET_HEIGHT;

	//�I�u�W�F�N�g�ݒ菈��
	SetObject2D(CObject::OBJTYPE_BULLET, m_fWidth, m_fHeight);
}

//=====================================
//�I������
//=====================================
void CBullet::Uninit()
{
	CObject2D::Uninit();
}

//=====================================
//�X�V����
//=====================================
void CBullet::Update()
{
	CObject2D::Update();

	//UV�ݒ�
	CObject2D::SetUV();

	//�e�ړ�
	m_move.x = m_fSpeed;

	//����
	m_move = m_move - (m_move * 0.05f);

	//�ʒu�擾����
	D3DXVECTOR3 pos = CObject2D::GetPos();
	
	//�����擾����
	float fLength = CObject2D::GetLength();

	//�ʒu�X�V
	pos += m_move;

	//�ʒu�ݒ菈��
	SetPos(pos);

	//�ʒu�ݒ菈��
	SetLength(fLength);

	//�����蔻��ݒ菈��
	SetCollision(pos, fLength);

	//�����v�Z
	if (m_nLife <= 0)
	{
		Destroy(pos);
	}
	else
	{//���������炷
		m_nLife--;
	}
}

//=====================================
//�`�揈��
//=====================================
void CBullet::Draw()
{
	//�摜�擾����
	CApplication::GetTexture()->TextureType(CTexture::TEXTYPE_BULLET);
	CObject2D::Draw();
}

//=====================================
//�ʒu�ݒ菈��
//=====================================
void  CBullet::SetPos(D3DXVECTOR3 pos)
{
	CObject2D::SetPos(pos);
}

//=====================================
//��������
//=====================================
void CBullet::Destroy(D3DXVECTOR3 pos)
{
	//������������
	CExplosion::Create(pos);

	Uninit();
}

//=====================================
//�����蔻��ݒ菈��
//=====================================
void CBullet::SetCollision(D3DXVECTOR3 pos, float fLength)
{
	//�����蔻��
	for (int nInd = 0; nInd < MAX_OBJECT; nInd++)
	{
		CObject *pObject = Get(nInd);	//�ΏۃI�u�W�F�N�g�̃|�C���^

		if (pObject != nullptr)
		{
			CObject::Object_TYPE objtype = pObject->GetType();	//�I�u�W�F�N�g�̎��

			if (objtype == CObject::OBJTYPE_ENEMY)
			{//�G�L�����̏ꍇ
				if (CollisionCircle(pos, fLength, pObject->GetPos(), pObject->GetLength()))
				{//�d�Ȃ����ꍇ
					Destroy(pos);

					//�I�u�W�F�N�g���̔j��
					pObject->Uninit();

					//��e����
					//pObject->Hit(10);
				}
			}
		}
	}
}

//=====================================
//�~�^�����蔻��v�Z����
//=====================================
bool CBullet::CollisionCircle(D3DXVECTOR3 pos, float fLength, D3DXVECTOR3 posSub, float fLengthSub)
{
	float fSumLengthRad = (fLength + fLengthSub) * 0.5f;				//�~�̔��a���m�̘a

	float fDiffX = pos.x - posSub.x;									//X���W�̍���
	float fDiffY = pos.y - posSub.y;									//Y���W�̍���
	float fDiffLength = sqrtf((fDiffX * fDiffX) + (fDiffY * fDiffY));	//���݂�2�_�̋���

	return fSumLengthRad >= fDiffLength;
}

//=====================================
//��������
//=====================================
CBullet *CBullet::Create(D3DXVECTOR3 pos)
{
	CBullet* pBullet = new CBullet;	//�e�̃|�C���^

	if (pBullet != nullptr)
	{
		pBullet->Init();
		pBullet->SetPos(pos);
	}

	return pBullet;
}
