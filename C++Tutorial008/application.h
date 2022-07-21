//=============================================================================
//
// �A�v���P�[�V����
// Author : tanimoto kosuke
//
//=============================================================================
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "main.h"

//---------------------------
//�O���錾
//---------------------------
class CRenderer;
class CInput;
class CTexture;
class CMode;

//---------------------------
//�N���X�錾
//---------------------------
class CApplication
{
public:
	CApplication();
	~CApplication();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd, bool bWindow);
	void Uninit();
	void Update();
	void Draw();

	static CRenderer *GetRenderer();	//�����_���[�擾����
	static CInput *GetInput();			//���͎擾����
	static CTexture *GetTexture();		//�摜�擾����
	static CMode *GetMode();			//���[�h�擾����
private:
	static CRenderer *m_pRenderer;
	static CInput *m_pInput;
	static CTexture *m_pTexture;
	static CMode *m_pMode;
};

#endif // !_APPLICATION_H_
