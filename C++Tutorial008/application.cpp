//=============================================================================
//
// マネージャー
// Author : tanimoto kosuke
//
//=============================================================================
#include "application.h"
#include "object.h"
#include "renderer.h"
#include "input.h"
#include "texture.h"
#include "mode.h"

CRenderer *CApplication::m_pRenderer = nullptr;	//レンダラーポインタ
CInput *CApplication::m_pInput = nullptr;		//入力ポインタ
CTexture *CApplication::m_pTexture = nullptr;	//画像ポインタ
CMode *CApplication::m_pMode = nullptr;			//モードポインタ
//=====================================
//デフォルトコンストラクタ
//=====================================
CApplication::CApplication()
{

}

//=====================================
//デストラクタ
//=====================================
CApplication::~CApplication()
{

}

//=====================================
//初期化処理
//=====================================
HRESULT CApplication::Init(HINSTANCE hInstance, HWND hWnd, bool bWindow)
{
	m_pRenderer = new CRenderer;
	m_pInput = new CInput;
	m_pTexture = new CTexture;
	m_pMode = new CMode;

	//キーボードの初期化処理
	if (FAILED(m_pInput->Init(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	//true : ウィンドウサイズ, false : 全画面
	if (FAILED(m_pRenderer->Init(hWnd, bWindow)))
	{
		return -1;
	}

	m_pTexture->Load();
	m_pMode->ChangeMode(CMode::MODE_GAME);

	return S_OK;
}

//=====================================
//終了処理
//=====================================
void CApplication::Uninit()
{
	CObject::ReleaseAll();

	//画像
	if (m_pTexture != nullptr)
	{
		m_pTexture->Uninit();
		delete m_pTexture;
		m_pTexture = nullptr;
	}

	//入力
	if (m_pInput != nullptr)
	{
		m_pInput->Uninit();
		delete m_pInput;
		m_pInput = nullptr;
	}

	//レンダリング
	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = nullptr;
	}

	//モード
	if (m_pMode != nullptr)
	{
		m_pMode->Uninit();
		delete m_pMode;
		m_pMode = nullptr;
	}
}

//=====================================
//更新処理
//=====================================
void CApplication::Update()
{
	m_pInput->Update();
	m_pRenderer->Update();
	m_pMode->Update();
	m_pMode->SetMode();
}

//=====================================
//描画処理
//=====================================
void CApplication::Draw()
{
	m_pRenderer->Draw();
	m_pMode->Draw();
}

//=====================================
//入力取得処理
//=====================================
CInput *CApplication::GetInput(void)
{
	return m_pInput;
}

//=====================================
//レンダラー取得処理
//=====================================
CRenderer *CApplication::GetRenderer(void)
{
	return m_pRenderer;
}

//=====================================
//画像取得処理
//=====================================
CTexture *CApplication::GetTexture(void)
{
	return m_pTexture;
}

//=====================================
//取得処理
//=====================================
CMode *CApplication::GetMode(void)
{
	return m_pMode;
}