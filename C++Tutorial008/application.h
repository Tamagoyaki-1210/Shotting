//=============================================================================
//
// アプリケーション
// Author : tanimoto kosuke
//
//=============================================================================
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "main.h"

//---------------------------
//前方宣言
//---------------------------
class CRenderer;
class CInput;
class CTexture;
class CMode;

//---------------------------
//クラス宣言
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

	static CRenderer *GetRenderer();	//レンダラー取得処理
	static CInput *GetInput();			//入力取得処理
	static CTexture *GetTexture();		//画像取得処理
	static CMode *GetMode();			//モード取得処理
private:
	static CRenderer *m_pRenderer;
	static CInput *m_pInput;
	static CTexture *m_pTexture;
	static CMode *m_pMode;
};

#endif // !_APPLICATION_H_
