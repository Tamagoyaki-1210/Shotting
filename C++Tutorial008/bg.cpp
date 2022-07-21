//=============================================================================
//
// �w�i
// Author : tanimoto kosuke
//
//=============================================================================
#include "bg.h"
#include "renderer.h"
#include "application.h"
#include "texture.h"

//=====================================
//�f�t�H���g�R���X�g���N�^
//=====================================
CBG::CBG()
{

}

//=====================================
//�f�X�g���N�^
//=====================================
CBG::~CBG()
{

}

//=====================================
//����������
//=====================================
void CBG::Init()
{
	CObject2D::Init();

	//�O���t�@�C���ŕϐ��ɒl�����������g
	m_fWidth = BG_WIDTH;
	m_fHeight = BG_HEIGHT;

	//�I�u�W�F�N�g�ݒ菈��
	SetObject2D(CObject::OBJTYPE_BG, m_fWidth, m_fHeight);
}

//=====================================
//�I������
//=====================================
void CBG::Uninit()
{
	CObject2D::Uninit();
}

//=====================================
//�X�V����
//=====================================
void CBG::Update()
{
	CObject2D::Update();

	UpdateType();

	//UV�ݒ菈��
	CObject2D::SetUV();

	//�ʒu�擾
	D3DXVECTOR3 pos = CObject2D::GetPos();

	//�p�x�擾����
	D3DXVECTOR3 rot = CObject2D::GetRot();

	//����
	m_move = m_move - (m_move * 0.05f);

	//�ʒu�X�V
	pos += m_move;

	//�ʒu�ݒ菈��
	SetPos(pos);

	//�p�x�擾����
	CObject2D::SetRot(rot);
}

//=====================================
//�`�揈��
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
//�ʒu�ݒ菈��
//=====================================
void CBG::SetPos(D3DXVECTOR3 pos)
{
	CObject2D::SetPos(pos);
}

//=====================================
//��ʍX�V����
//=====================================
void CBG::UpdateType()
{
	switch (m_bgType)
	{
	case BGTYPE_NORMAL:
		//�F�ݒ菈��
		CObject2D::SetColor(D3DXCOLOR(0.2f, 0.2f, 1.0f, 0.4f), D3DXCOLOR(0.2f, 0.2f, 1.0f, 0.4f), D3DXCOLOR(0.2f, 0.2f, 1.0f, 0.2f), D3DXCOLOR(0.2f, 0.2f, 1.0f, 0.2f));
		break;

	case BGTYPE_STAR1:
		CObject2D::SetTex(3000,1,1);
		CObject2D::SetColor(D3DXCOLOR(0.8f, 0.8f, 0.8f, 0.8f), D3DXCOLOR(0.8f, 0.8f, 0.8f, 0.8f), D3DXCOLOR(0.8f, 0.8f, 0.8f, 0.8f), D3DXCOLOR(0.8f, 0.8f, 0.8f, 0.8f));
		break;
	}
}

//=====================================
//�v���C���[��������
//=====================================
CBG *CBG::Create(D3DXVECTOR3 pos, BG_TYPE bgType)
{
	CBG* pBG = new CBG;		//�v���C���[�|�C���^

	if (pBG != nullptr)
	{
		pBG->Init();
		pBG->SetPos(pos);
		pBG->m_bgType = bgType;
	}

	return pBG;
}