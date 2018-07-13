/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Initialize
//
// DATE 2018.06.13
// VER.0.0.5
//
// Author Harutaka-Tsujino
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "tetlisDirectxVer.0.0.1Common.h"
#include "tetlisDirectxVer.0.0.1Initialize.h"

LPDIRECT3D9 g_pDirect3D;
LPDIRECT3DDEVICE9 g_pD3dDevice;
LPDIRECTINPUT8 g_pDinput = NULL;
LPDIRECT3DTEXTURE9 g_pTexture[g_texMax];
LPDIRECTINPUTDEVICE8 g_pDKeyDevice = NULL;
LPD3DXFONT g_pFont[g_fontMax];
D3DPRESENT_PARAMETERS g_D3dPresentParameters;

//////////////////////////////////
//�_�C���N�g3D�̏������Ɋւ���֐�
HRESULT InitDirect3D(HWND hWnd)
{
	//�_�C���N�g3D�̍쐬
	if (NULL == (g_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, "Direct3D�̍쐬�Ɏ��s���܂���", "", MB_OK);
		return E_FAIL;
	}

	//g_D3dPresentParameters�̒��g�̏���
	ZeroMemory(&g_D3dPresentParameters, sizeof(g_D3dPresentParameters));

	//////////////////////////////////////
	//�o�b�t�@�[�`���A�����A�؂�ւ��̐ݒ�
	SetBuckBufferOverall();

	//�E�B���h�E���[�h�œ����Ă��邱�Ƃ̒�
	g_D3dPresentParameters.Windowed = TRUE;

	//�_�C���N�g3D�f�o�C�X�̍쐬
	if (FAILED(g_pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&g_D3dPresentParameters, &g_pD3dDevice)))
	{
		//�`�惂�[�h�̐ݒ�
		MessageBox(0, "HAL���[�h��DIRECT3D�f�o�C�X���쐬�ł��܂���\nREF���[�h�ōĎ��s���܂�", NULL, MB_OK);
		if (FAILED(g_pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd,
			D3DCREATE_MIXED_VERTEXPROCESSING,
			&g_D3dPresentParameters, &g_pD3dDevice)))
		{
			MessageBox(0, "DIRECT3D�f�o�C�X�̍쐬�Ɏ��s���܂���", NULL, MB_OK);
			return E_FAIL;
		}
	}

	////////////////
	//�`��̏ڍאݒ�
	SetRenderStateOverall();

	//////////////////////////
	//�e�N�X�`���K�w�̏ڍאݒ�
	SetTextureStageStateOverall();

	//���_���̓o�^
	g_pD3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	//////////////////
	//�e�N�X�`���̐���
	CreateTextureFromFile();
	
	return S_OK;
}

VOID SetBuckBufferOverall(VOID)
{
	//�o�b�t�@�[�̌`���ݒ�
	g_D3dPresentParameters.BackBufferFormat = D3DFMT_UNKNOWN;
	//�o�b�t�@�[�̖����ݒ�
	g_D3dPresentParameters.BackBufferCount = 1;
	//�o�b�t�@�[�̐؂�ւ����@�̐ݒ�
	g_D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;

	return;
}

VOID SetRenderStateOverall(VOID)
{
	g_pD3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	return;
}

VOID SetTextureStageStateOverall(VOID)
{
	g_pD3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	g_pD3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	return;
}

VOID CreateTextureFromFile(VOID)
{
	//�`�[�����S�̃e�N�X�`���̐���
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"teamLogo.png",
		&g_pTexture[g_teamLogoTex]);

	//�`�[�����S�̔w�i�̃e�N�X�`���̐���
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"teamLogoBg.png",
		&g_pTexture[g_teamLogoBgTex]);

	//�^�C�g�����S�̃e�N�X�`������
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"titleLogo.png",
		&g_pTexture[g_titleLogoTex]);

	//�^�C�g���w�i�̃e�N�X�`������
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"titleSample.png",
		&g_pTexture[g_titleBgTex]);

	//���A�C�R���̃e�N�X�`������
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"arrow.png",
		&g_pTexture[g_titleIconTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"background.png",
		&g_pTexture[g_backgroundTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"frame.png",
		&g_pTexture[g_frameTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"fallBlock/redBlock.png",
		&g_pTexture[g_tetminoITex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"fallBlock/orangeBlock.png",
		&g_pTexture[g_tetminoJTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"fallBlock/yellowBlock.png",
		&g_pTexture[g_tetminoLTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"fallBlock/greenBlock.png",
		&g_pTexture[g_tetminoSTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"fallBlock/waterBlueBlock.png",
		&g_pTexture[g_tetminoZTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"fallBlock/BlueBlock.png",
		&g_pTexture[g_tetminoTTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"fallBlock/violetBlock.png",
		&g_pTexture[g_tetminoOTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"blockTarget.png",
		&g_pTexture[g_tetminoTarTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"block_integrated_illust_HT.png",
		&g_pTexture[g_integratedBlockTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"deletedLine.png",
		&g_pTexture[g_reduceBlockDurTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"circuleEffect.png",
		&g_pTexture[g_circuleEffectTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"treasureBox.png",
		&g_pTexture[g_treasureBoxTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"hardDropEffect.png",
		&g_pTexture[g_hardDropEffectTex]);
	
	//�|�[�Y��ʂ̃e�N�X�`��
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"pauseMenu.png",
		&g_pTexture[g_pauseTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"arrow.png",
		&g_pTexture[g_pauseIconTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"resultMenu.png",
		&g_pTexture[g_resultTex]);

	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"arrow.png",
		&g_pTexture[g_resultIconTex]);

	return;
}

//////////////////////////////////////////
//�_�C���N�g�C���v�b�g�̏������Ɋւ���֐�
HRESULT InitDinput(HWND hWnd)
{
	HRESULT hr;

	//�_�C���N�g�C���v�b�g�̐���
	if (FAILED(hr = DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&g_pDinput, NULL)))
	{
		return hr;
	}

	//�_�C���N�g�C���v�b�g�f�o�C�X�̐���
	if (FAILED(hr = g_pDinput->CreateDevice(GUID_SysKeyboard,
		&g_pDKeyDevice, NULL)))
	{
		return hr;
	}

	//���͌`�����L�[�{�[�h�ɐݒ�
	if (FAILED(hr = g_pDKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return hr;
	}

	//�_�C���N�g�C���v�b�g�f�o�C�X�̌����擾�̗D��x�ݒ�
	if (FAILED(hr = g_pDKeyDevice->SetCooperativeLevel(
		hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return hr;
	}

	return S_OK;
}

HRESULT InitDfont(HWND hWnd)
{
	////////////////
	//�t�H���g�̐���
	CreateFont();

	return S_OK;
}

VOID CreateFont(VOID)
{
	//�^�C�g���t�H���g�̃I�u�W�F�N�g�̐���
	D3DXCreateFont(
		g_pD3dDevice,
		50,
		0,
		FW_NORMAL,
		1,
		FALSE,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,
		"Comic Sans MS Bold",
		&g_pFont[g_titleFont]);

	D3DXCreateFont(
		g_pD3dDevice,
		80,
		0,
		FW_NORMAL,
		1,
		FALSE,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,
		"Comic Sans MS Bold",
		&g_pFont[g_finalScoreFont]);

	D3DXCreateFont(g_pD3dDevice, 120, 60, 0, 0, 0, 0, 0, 0, 0, "Comic Sans MS Bold", &g_pFont[g_gameoverFont]);
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Comic Sans MS Bold", &g_pFont[g_scoreFont]);
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Comic Sans MS Bold", &g_pFont[g_undergroundFont]);

	return;
}