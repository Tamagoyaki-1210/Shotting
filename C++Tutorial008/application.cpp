//=============================================================================
//
// �}�l�[�W���[
// Author : tanimoto kosuke
//
//=============================================================================
#include "application.h"
#include "object.h"
#include "renderer.h"
#include "input.h"
#include "texture.h"
#include "mode.h"

CRenderer *CApplication::m_pRenderer = nullptr;	//�����_���[�|�C���^
CInput *CApplication::m_pInput = nullptr;		//���̓|�C���^
CTexture *CApplication::m_pTexture = nullptr;	//�摜�|�C���^
CMode *CApplication::m_pMode = nullptr;			//���[�h�|�C���^
//=====================================
//�f�t�H���g�R���X�g���N�^
//=====================================
CApplication::CApplication()
{

}

//=====================================
//�f�X�g���N�^
//=====================================
CApplication::~CApplication()
{

}

//=====================================
//����������
//=====================================
HRESULT CApplication::Init(HINSTANCE hInstance, HWND hWnd, bool bWindow)
{
	m_pRenderer = new CRenderer;
	m_pInput = new CInput;
	m_pTexture = new CTexture;
	m_pMode = new CMode;

	//�L�[�{�[�h�̏���������
	if (FAILED(m_pInput->Init(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	//true : �E�B���h�E�T�C�Y, false : �S���
	if (FAILED(m_pRenderer->Init(hWnd, bWindow)))
	{
		return -1;
	}

	m_pTexture->Load();
	m_pMode->ChangeMode(CMode::MODE_GAME);

	return S_OK;
}

//=====================================
//�I������
//=====================================
void CApplication::Uninit()
{
	CObject::ReleaseAll();

	//�摜
	if (m_pTexture != nullptr)
	{
		m_pTexture->Uninit();
		delete m_pTexture;
		m_pTexture = nullptr;
	}

	//����
	if (m_pInput != nullptr)
	{
		m_pInput->Uninit();
		delete m_pInput;
		m_pInput = nullptr;
	}

	//�����_�����O
	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = nullptr;
	}

	//���[�h
	if (m_pMode != nullptr)
	{
		m_pMode->Uninit();
		delete m_pMode;
		m_pMode = nullptr;
	}
}

//=====================================
//�X�V����
//=====================================
void CApplication::Update()
{
	m_pInput->Update();
	m_pRenderer->Update();
	m_pMode->Update();
	m_pMode->SetMode();
}

//=====================================
//�`�揈��
//=====================================
void CApplication::Draw()
{
	m_pRenderer->Draw();
	m_pMode->Draw();
}

//=====================================
//���͎擾����
//=====================================
CInput *CApplication::GetInput(void)
{
	return m_pInput;
}

//=====================================
//�����_���[�擾����
//=====================================
CRenderer *CApplication::GetRenderer(void)
{
	return m_pRenderer;
}

//=====================================
//�摜�擾����
//=====================================
CTexture *CApplication::GetTexture(void)
{
	return m_pTexture;
}

//=====================================
//�擾����
//=====================================
CMode *CApplication::GetMode(void)
{
	return m_pMode;
}