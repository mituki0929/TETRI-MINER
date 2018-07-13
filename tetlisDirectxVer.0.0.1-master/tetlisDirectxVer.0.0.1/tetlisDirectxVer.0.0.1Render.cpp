/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Render
//
// DATE 2018.06.13
// VER.0.0.5
//
// Author Harutaka-Tsujino
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "tetlisDirectxVer.0.0.1Common.h"
#include "tetlisDirectxVer.0.0.1Initialize.h"
#include "tetlisDirectxVer.0.0.1Render.h"
#include "tetlisDirectxVer.0.0.1Control.h"
#include <d3dx9.h>

ICON arrowIconState = { 530.f, 425.f, 20.f };

ICON pauseIconState = { 510.f, 305.f, 20.f };

ICON resultIconState = {300.f, 560.f, 20.f};

BOOL flashing = true;

DWORD logoAlpha = 0x00FFFFFF;

ImageState g_tetminoState = { 0.f, 0.f, 30.f / 2, 30.f / 2 };
ImageState g_deletedLineEffectState = { 545.f,0.f,150.f,15.f };
ImageState g_gameoverStrState = { 1060,590,800.f, 450.f };
ImageState g_scoreStrState = { 800.f,790.f,400.f, 225.f };
ImageState g_undergroundStrState = { 800.f,500.f,400.f, 225.f };

//�^�C�g���`�揈���֐�
void titleRender()
{
	static DWORD titleAlpha = 0xFF;

	CustomVertex titleLogo[4]
	{
		{  30.f,  50.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{1230.f,  50.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{1230.f, 370.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{  30.f, 370.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�w�i�̒��_���
	CustomVertex titleBackGround[4]
	{
		{	 0.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{	 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	CustomVertex logoBackGround[4]
	{
		{	 0.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{	 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	CustomVertex teamLogoStr[4]
	{
		{  107.5,  38.5, 1.f, 1.f, logoAlpha, 0.f, 0.f },
		{ 1172.5,  38.5, 1.f, 1.f, logoAlpha, 1.f, 0.f },
		{ 1172.5, 681.5, 1.f, 1.f, logoAlpha, 1.f, 1.f },
		{  107.5, 681.5, 1.f, 1.f, logoAlpha, 0.f, 1.f }
	};

	//���̒��_���
	CustomVertex arrow[4]
	{
		{ arrowIconState.x - arrowIconState.scale, arrowIconState.y - arrowIconState.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ arrowIconState.x + arrowIconState.scale, arrowIconState.y - arrowIconState.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ arrowIconState.x + arrowIconState.scale, arrowIconState.y + arrowIconState.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ arrowIconState.x - arrowIconState.scale, arrowIconState.y + arrowIconState.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	RECT PressAnyEnterState, playState, exitState;

	//Press Any Button�̕\�����W�̐ݒ�
	PressAnyEnterState.left = 465;		//�����x���W
	PressAnyEnterState.top = 450;		//�����y���W
	PressAnyEnterState.right = 0;		//�E���x���W
	PressAnyEnterState.bottom = 0;		//�E���y���W

	//playState�̕\�����W�̐ݒ�	
	playState.left = 580;
	playState.top = 400;
	playState.right = 0;
	playState.bottom = 0;

	//exitState�̕\�����W
	exitState.left = 580;
	exitState.top = 500;
	exitState.right = 0;
	exitState.bottom = 0;

	//��ʂ̏���
	g_pD3dDevice->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0, 0);

	//�`��̊J�n
	g_pD3dDevice->BeginScene();

	if (teamLogo <= 200)
	{
		/*if (teamLogo >= 0xFF)
		{
			teamLogo = 0xFF;
		}*/
		if (teamLogo >= 10 && teamLogo < 50)
		{
			logoAlpha += 0x04000000;
		}
		else if (teamLogo >= 50 && teamLogo < 60)
		{
			logoAlpha += 0x05000000;
		}

		if (teamLogo == 60)
		{
			logoAlpha = 0xFFFFFFFF;
		}

		/*if (teamLogo >= 0x00)
		{
			logoAlpha = 0x00;
		}*/
		if (teamLogo >= 120 && teamLogo < 170)
		{
			logoAlpha -= 0x04000000;
		}
		else if (teamLogo >= 170 && teamLogo < 180)
		{
			logoAlpha -= 0x05000000;
		}

		if (teamLogo == 180)
		{
			logoAlpha = 0x00FFFFFF;
		}
		
		g_pD3dDevice->SetTexture(0, g_pTexture[g_teamLogoBgTex]);
		g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, logoBackGround, sizeof(CustomVertex));
		g_pD3dDevice->SetTexture(0, g_pTexture[g_teamLogoTex]);
		g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, teamLogoStr, sizeof(CustomVertex));
	}
	else if(teamLogo >= 200)
	{
		//�w�i�e�N�X�`���̕`��
		g_pD3dDevice->SetTexture(0, g_pTexture[g_titleBgTex]);
		g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, titleBackGround, sizeof(CustomVertex));
		g_pD3dDevice->SetTexture(0, g_pTexture[g_titleLogoTex]);
		g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, titleLogo, sizeof(CustomVertex));

		//�t���O�`�F�b�N
		if (!deleteFont)
		{
			if (flashing)
			{
				titleAlpha -= 0x03;
			}
			else if (!flashing)
			{
				titleAlpha += 0x03;
			}

			if (titleAlpha == 0x00)
			{
				flashing = false;
			}
			else if (titleAlpha == 0xFF)
			{
				flashing = true;
			}

			//�t�H���g�̕`��
			g_pFont[g_titleFont]->DrawText(NULL,
				"PRESS ANY ENTER",
				-1,
				&PressAnyEnterState,
				DT_LEFT | DT_NOCLIP,
				D3DCOLOR_ARGB(titleAlpha, 0xFF, 0xFF, 0x5F)
			);
		}

		//�t���O�`�F�b�N
		if (changeFont)
		{
			//���e�N�X�`���̕`��
			g_pD3dDevice->SetTexture(0, g_pTexture[g_titleIconTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, arrow, sizeof(CustomVertex));

			//���̑��t�H���g�̕`��
			g_pFont[g_titleFont]->DrawText(NULL,
				"PLAY",
				-1,
				&playState,
				DT_LEFT | DT_NOCLIP,
				D3DCOLOR_ARGB(0xFF, 0xFF, 0xFF, 0x5F)
			);

			//���̑��t�H���g�̕`��
			g_pFont[g_titleFont]->DrawText(NULL,
				"EXIT",
				-1,
				&exitState,
				DT_LEFT | DT_NOCLIP,
				D3DCOLOR_ARGB(0xFF, 0xFF, 0xFF, 0x5F)
			);
		}
	}

	//�`��̏I��
	g_pD3dDevice->EndScene();

	//�\��
	g_pD3dDevice->Present(NULL, NULL, NULL, NULL);
}

VOID Render(VOID)//////////////////////////////////////////////////////////////////////////////////
{
	static INT toDeleteTargetBlockCount = 0, prevDeletedLineState;

	//////////////////////////////////////////////
	//���_�ʒu�̐ݒ�A�Ō�ɐ�΍��W�ւ̕ϊ����s��
	SetViewPointOverall();

	////////////////////////////////////////////
	//����p�̐ݒ�A�Ō�ɐ�΍��W�ւ̕ϊ����s��
	SetFocusOfViewOverall();

	//��ʂ̏���
	g_pD3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);

	//�`��J�n
	g_pD3dDevice->BeginScene();


	RenderBackground();

	/////////////////////////////////////////////////////////////////
	//�e�g���X�u���b�N�̂S���_��tetlisBoard�̔z��ԍ���p���Đݒ肷��
	SetBlockVerticesAndRender();

	if (!prevDeletedLineState)
	{
		if (g_deletedLine)
		{
			toDeleteTargetBlockCount = 0;
		}
	}

	if (!g_deletedLine && !(0 < toDeleteTargetBlockCount&&toDeleteTargetBlockCount < 30))
	{
		//////////////////////////////////////////
		//�e�g���~�m�^�[�Q�b�g�̂S���_��ݒ�A�`��
		SetTetliminoTargetTextureAndRender();
	}

	else
	{
		toDeleteTargetBlockCount++;
		if (toDeleteTargetBlockCount == 45)
		{
			toDeleteTargetBlockCount = 0;
		}
	}

	//////////////////////////////////////////
	//�n�[�h�h���b�v�̃G�t�F�N�g��`�悷��֐�
	SetHardDropEffectTextureAndRender();

	//////////////////////////////////////////////
	//���C���������ꂽ���̃G�t�F�N�g��`�悷��֐�
	SetDeletedLineEffectTextureAndRender();

	////////////
	//�z���̕`��
	RnderFrame();

	////////////////////
	//�X�R�A������̕`��
	RenderScoreStr();

	//////////////////////////////////////
	//�ǂ̂��炢�@��i�񂾂��̕�����̕`��
	RenderUndergroundStr();

	/////////////////////////////////////////////////////////
	//�z�[���h�A�l�N�X�g�A�l�N�X�g�l�N�X�g��4���_��ݒ�A�`��
	SetHoldNextNextNextVerticesAndRender();

	////////////////////////////////
	//�Q�[���I�[�o�[���̕�����̕`��
	RenderGameoverStr();
	
	if (pause)
	{
		//�|�[�Y��ʂ̕`��
		pauseRender();
	}

	//�`��̏I��
	g_pD3dDevice->EndScene();

	//��ʕ\�����s��ꂽ���Ƃ��o�b�N�o�b�t�@�[�ɓ`����
	g_pD3dDevice->Present(NULL, NULL, NULL, NULL);

	prevDeletedLineState = g_deletedLine;
	
	return;
}

VOID SetViewPointOverall(VOID)
{
	D3DXVECTOR3 vecEyePt(0.0f, 1.0f, -3.0f);
	D3DXVECTOR3 vecLookatPt(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vecUpVec(0.0f, 1.0f, 100.0f);
	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &vecEyePt, &vecLookatPt, &vecUpVec);
	g_pD3dDevice->SetTransform(D3DTS_VIEW, &matView);

	return;
}

VOID SetFocusOfViewOverall(VOID)
{
	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	g_pD3dDevice->SetTransform(D3DTS_VIEW, &matProj);

	return;
}

VOID RenderBackground(VOID)
{
	CustomVertex cusV4Background[4] =
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3dDevice->SetTexture(0, g_pTexture[g_backgroundTex]);
	g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Background, sizeof(CustomVertex));

	return;
}

VOID SetHardDropEffectTextureAndRender(VOID)
{
	static INT hardDropEffectCount = 0;
	static MovMinoNumoOfArBuf hardDropNumofArBuf;
	static INT InitDeflecton = false;
	static BOOL installatedBlock[4] = { 0,0,0,0 };

	typedef struct
	{
		INT deflectionalPosX;
		INT deflectionalInitialVelocityY;
		INT deflectionalInitialVelocityX;
	}ParticleDeflection;

	static ParticleDeflection particleDeflection[12 * 4];

	if (g_hardDropedTetmino)
	{
		InitDeflecton = true;
	}

	if (InitDeflecton&&hardDropEffectCount == 0)
	{
		memcpy(&hardDropNumofArBuf, &g_movMinoNumOfArBuf, sizeof(MovMinoNumoOfArBuf));

		for (INT effect = 0; effect < 12 * 4; effect++)
		{
			(particleDeflection + effect)->deflectionalPosX = rand() % 30;
			(particleDeflection + effect)->deflectionalInitialVelocityY = rand() % 15+1;
			(particleDeflection + effect)->deflectionalInitialVelocityX = rand() % 15 - 7;
		}

		if (g_tetlisBoardBuf[hardDropNumofArBuf.YX[0][0] + 1][hardDropNumofArBuf.YX[0][1]] != -1)
		{
			installatedBlock[0] = true;
		}

		if (g_tetlisBoardBuf[hardDropNumofArBuf.YX[1][0] + 1][hardDropNumofArBuf.YX[1][1]] != -1)
		{
			installatedBlock[1] = true;
		}

		if (g_tetlisBoardBuf[hardDropNumofArBuf.YX[2][0] + 1][hardDropNumofArBuf.YX[2][1]] != -1)
		{
			installatedBlock[2] = true;
		}

		if (g_tetlisBoardBuf[hardDropNumofArBuf.YX[3][0] + 1][hardDropNumofArBuf.YX[3][1]] != -1)
		{
			installatedBlock[3] = true;
		}

		hardDropEffectCount++;
	}

	if (hardDropEffectCount)
	{
		CustomVertex CusV3HardDropParticleEffect[3] =
		{
			{ 0.f,0.f,1.f,1.f,0xFFFFFFFF,0.5f,0.f },
			{ 0.f,0.f,1.f,1.f,0xFFFFFFFF,1.f,1.f },
			{ 0.f,0.f,1.f,1.f,0xFFFFFFFF,0.f,1.f }
		};

		static FLOAT accelY = 0;

		InitDeflecton = false;

		for (INT effect = 0; effect < 12; effect++)
		{
			if (installatedBlock[0] == 1)
			{
				(CusV3HardDropParticleEffect)->x = 395.f + hardDropNumofArBuf.YX[0][1] * (g_tetminoState.xScale * 2) + particleDeflection[effect].deflectionalPosX + 4 + (particleDeflection[effect].deflectionalInitialVelocityX*(hardDropEffectCount - 1));
				(CusV3HardDropParticleEffect)->y = -35.f + (hardDropNumofArBuf.YX[0][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) + ((-particleDeflection[effect].deflectionalInitialVelocityY + accelY)*(hardDropEffectCount - 1));

				(CusV3HardDropParticleEffect + 1)->x = 395.f + hardDropNumofArBuf.YX[0][1] * (g_tetminoState.xScale * 2) + particleDeflection[effect].deflectionalPosX + 8 + (particleDeflection[effect].deflectionalInitialVelocityX*(hardDropEffectCount - 1));
				(CusV3HardDropParticleEffect + 1)->y = -35.f + (hardDropNumofArBuf.YX[0][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) + 7 + ((-particleDeflection[effect].deflectionalInitialVelocityY + accelY)*(hardDropEffectCount - 1));

				(CusV3HardDropParticleEffect + 2)->x = 395.f + hardDropNumofArBuf.YX[0][1] * (g_tetminoState.xScale * 2) + particleDeflection[effect].deflectionalPosX + 0 + (particleDeflection[effect].deflectionalInitialVelocityX*(hardDropEffectCount - 1));
				(CusV3HardDropParticleEffect + 2)->y = -35.f + (hardDropNumofArBuf.YX[0][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) + 7 + ((-particleDeflection[effect].deflectionalInitialVelocityY + accelY)*(hardDropEffectCount - 1));


				DWORD randomColor = (0xFF000000) + ((rand() % 256) * 0x10000) + ((rand() % 256) * 0x100) + (rand() % 256);

				CusV3HardDropParticleEffect->color = randomColor;
				(CusV3HardDropParticleEffect + 1)->color = randomColor;
				(CusV3HardDropParticleEffect + 2)->color = randomColor;

				g_pD3dDevice->SetTexture(0, g_pTexture[g_hardDropEffectTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 1, CusV3HardDropParticleEffect, sizeof(CustomVertex));
			}
		}

		for (INT effect = 12; effect < 24; effect++)
		{
			if (installatedBlock[1] == 1)
			{
				(CusV3HardDropParticleEffect)->x = 380.f + hardDropNumofArBuf.YX[1][1] * (g_tetminoState.xScale * 2) + particleDeflection[effect].deflectionalPosX + 4 + (particleDeflection[effect].deflectionalInitialVelocityX*(hardDropEffectCount - 1));
				(CusV3HardDropParticleEffect)->y = -35.f + (hardDropNumofArBuf.YX[1][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) + ((-particleDeflection[effect].deflectionalInitialVelocityY + accelY)*(hardDropEffectCount - 1));

				(CusV3HardDropParticleEffect + 1)->x = 380.f + hardDropNumofArBuf.YX[1][1] * (g_tetminoState.xScale * 2) + particleDeflection[effect].deflectionalPosX + 8 + (particleDeflection[effect].deflectionalInitialVelocityX*(hardDropEffectCount - 1));
				(CusV3HardDropParticleEffect + 1)->y = -35.f + (hardDropNumofArBuf.YX[1][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) + 7 + ((-particleDeflection[effect].deflectionalInitialVelocityY + accelY)*(hardDropEffectCount - 1));

				(CusV3HardDropParticleEffect + 2)->x = 380.f + hardDropNumofArBuf.YX[1][1] * (g_tetminoState.xScale * 2) + particleDeflection[effect].deflectionalPosX + (particleDeflection[effect].deflectionalInitialVelocityX*(hardDropEffectCount - 1));
				(CusV3HardDropParticleEffect + 2)->y = -35.f + (hardDropNumofArBuf.YX[1][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) + 7 + ((-particleDeflection[effect].deflectionalInitialVelocityY + accelY)*(hardDropEffectCount - 1));

				DWORD randomColor = (0xFF000000) + ((rand() % 256) * 0x10000) + ((rand() % 256) * 0x100) + (rand() % 256);

				CusV3HardDropParticleEffect->color = randomColor;
				(CusV3HardDropParticleEffect + 1)->color = randomColor;
				(CusV3HardDropParticleEffect + 2)->color = randomColor;

				g_pD3dDevice->SetTexture(0, g_pTexture[g_hardDropEffectTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 1, CusV3HardDropParticleEffect, sizeof(CustomVertex));
			}
		}

		for (INT effect = 24; effect < 36; effect++)
		{
			if (installatedBlock[2] == 1)
			{
				(CusV3HardDropParticleEffect)->x = 380.f + hardDropNumofArBuf.YX[2][1] * (g_tetminoState.xScale * 2) + particleDeflection[effect].deflectionalPosX + 4 + (particleDeflection[effect].deflectionalInitialVelocityX*(hardDropEffectCount - 1));
				(CusV3HardDropParticleEffect)->y = -35.f + (hardDropNumofArBuf.YX[2][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) + ((-particleDeflection[effect].deflectionalInitialVelocityY + accelY)*(hardDropEffectCount - 1));

				(CusV3HardDropParticleEffect + 1)->x = 380.f + hardDropNumofArBuf.YX[2][1] * (g_tetminoState.xScale * 2) + particleDeflection[effect].deflectionalPosX + 8 + (particleDeflection[effect].deflectionalInitialVelocityX*(hardDropEffectCount - 1));
				(CusV3HardDropParticleEffect + 1)->y = -35.f + (hardDropNumofArBuf.YX[2][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) + 7 + ((-particleDeflection[effect].deflectionalInitialVelocityY + accelY)*(hardDropEffectCount - 1));

				(CusV3HardDropParticleEffect + 2)->x = 380.f + hardDropNumofArBuf.YX[2][1] * (g_tetminoState.xScale * 2) + particleDeflection[effect].deflectionalPosX + (particleDeflection[effect].deflectionalInitialVelocityX*(hardDropEffectCount - 1));
				(CusV3HardDropParticleEffect + 2)->y = -35.f + (hardDropNumofArBuf.YX[2][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) + 7 + ((-particleDeflection[effect].deflectionalInitialVelocityY + accelY)*(hardDropEffectCount - 1));

				DWORD randomColor = (0xFF000000) + ((rand() % 256) * 0x10000) + ((rand() % 256) * 0x100) + (rand() % 256);

				CusV3HardDropParticleEffect->color = randomColor;
				(CusV3HardDropParticleEffect + 1)->color = randomColor;
				(CusV3HardDropParticleEffect + 2)->color = randomColor;

				g_pD3dDevice->SetTexture(0, g_pTexture[g_hardDropEffectTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 1, CusV3HardDropParticleEffect, sizeof(CustomVertex));
			}
		}

		for (INT effect = 36; effect < 48; effect++)
		{
			if (installatedBlock[3] == 1)
			{
				(CusV3HardDropParticleEffect)->x = 380.f + hardDropNumofArBuf.YX[3][1] * (g_tetminoState.xScale * 2) + particleDeflection[effect].deflectionalPosX + 4 + (particleDeflection[effect].deflectionalInitialVelocityX*(hardDropEffectCount - 1));
				(CusV3HardDropParticleEffect)->y = -35.f + (hardDropNumofArBuf.YX[3][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) + ((-particleDeflection[effect].deflectionalInitialVelocityY + accelY)*(hardDropEffectCount - 1));

				(CusV3HardDropParticleEffect + 1)->x = 380.f + hardDropNumofArBuf.YX[3][1] * (g_tetminoState.xScale * 2) + particleDeflection[effect].deflectionalPosX + 8 + (particleDeflection[effect].deflectionalInitialVelocityX*(hardDropEffectCount - 1));
				(CusV3HardDropParticleEffect + 1)->y = -35.f + (hardDropNumofArBuf.YX[3][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) +7 + ((-particleDeflection[effect].deflectionalInitialVelocityY + accelY)*(hardDropEffectCount - 1));

				(CusV3HardDropParticleEffect + 2)->x = 380.f + hardDropNumofArBuf.YX[3][1] * (g_tetminoState.xScale * 2) + particleDeflection[effect].deflectionalPosX + (particleDeflection[effect].deflectionalInitialVelocityX*(hardDropEffectCount - 1));
				(CusV3HardDropParticleEffect + 2)->y = -35.f + (hardDropNumofArBuf.YX[3][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) + 7 + ((-particleDeflection[effect].deflectionalInitialVelocityY + accelY)*(hardDropEffectCount - 1));

				DWORD randomColor = (0xFF000000) + ((rand() % 256) * 0x10000) + ((rand() % 256) * 0x100) + (rand() % 256);

				CusV3HardDropParticleEffect->color = randomColor;
				(CusV3HardDropParticleEffect + 1)->color = randomColor;
				(CusV3HardDropParticleEffect + 2)->color = randomColor;

				g_pD3dDevice->SetTexture(0, g_pTexture[g_hardDropEffectTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 1, CusV3HardDropParticleEffect, sizeof(CustomVertex));
			}
		}

		g_hardDropedTetmino = false;
		hardDropEffectCount++;
		accelY += 0.7f;

		if (hardDropEffectCount > 25)
		{
			hardDropEffectCount = 0;
			accelY = 0;
			installatedBlock[0] = false;
			installatedBlock[1] = false;
			installatedBlock[2] = false;
			installatedBlock[3] = false;
		}
	}

	return;
}

VOID SetBlockVerticesAndRender(VOID)
{
	static INT swellingUp = 0;
	static INT swellingUpCount = 0;
	static INT prevDeletedLineCount = 0;
	static INT differenceDeletedLineCount = 0;

	INT deletedLineCount = 0;

	for (INT column = 19; column < TETLIS_HEIGHT - 2; column++)
	{
		INT numOfDirt = 0;
		for (INT row = 1; row < TETLIS_WIDTH - 2; row++)
		{
			if (g_tetlisBoardBuf[column][row] % 100 == 10)
			{
				numOfDirt++;
			}
		}

		if (numOfDirt < 4)
		{
			deletedLineCount++;
		}
	}

	if (!(g_deletedLine))
	{
		prevDeletedLineCount = deletedLineCount;
	}
	
	if (g_deletedLine && (swellingUpCount == 0))
	{
		differenceDeletedLineCount = deletedLineCount - prevDeletedLineCount;
	}

	if (g_deletedLine)
	{
		swellingUpCount++;
		if ((swellingUpCount > 30) && (swellingUp < differenceDeletedLineCount * 30))
		{
			swellingUp += 15;
		}

		if (swellingUpCount == 60)
		{
			swellingUp = 0;
		}
	}

	else
	{
		swellingUpCount = 0;
	}

	for (int column = 4; column < TETLIS_HEIGHT; column++)
	{
		for (int row = 0; row < TETLIS_WIDTH; row++)
		{
			CustomVertex cusV4Tetmino[4] =
			{
				{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
				{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
				{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
				{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
			};

			if ((g_tetlisBoard[column][row] != -1) && (g_tetlisBoard[column][row] != 9))
			{
				cusV4Tetmino[0].x = 395.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				cusV4Tetmino[0].y = -35.f-swellingUp + (column - g_deletedLineCount) * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				cusV4Tetmino[1].x = 395.f + row * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				cusV4Tetmino[1].y = -35.f- swellingUp + (column - g_deletedLineCount) * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				cusV4Tetmino[2].x = 395.f + row * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				cusV4Tetmino[2].y = -35.f- swellingUp + (column - g_deletedLineCount) * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				cusV4Tetmino[3].x = 395.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				cusV4Tetmino[3].y = -35.f- swellingUp + (column - g_deletedLineCount) * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
			
				g_pD3dDevice->SetTexture(0, g_pTexture[g_integratedBlockTex]);
				
				switch (g_tetlisBoard[column][row] % 100)
				{
				case 0:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoITex]);
					break;
				case 1:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoJTex]);
					break;
				case 2:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoLTex]);
					break;
				case 3:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoSTex]);
					break;
				case 4:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoZTex]);
					break;
				case 5:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoTTex]);
					break;
				case 6:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoOTex]);
					break;
				case 10:
					cusV4Tetmino[0].tu = 101.f / 512;
					cusV4Tetmino[0].tv = 51.f / 256;
					cusV4Tetmino[1].tu = 150.f / 512;
					cusV4Tetmino[1].tv = 51.f / 256;
					cusV4Tetmino[2].tu = 150.f / 512;
					cusV4Tetmino[2].tv = 97.f / 256;
					cusV4Tetmino[3].tu = 101.f / 512;
					cusV4Tetmino[3].tv = 97.f / 256;
					break;
				case 21:
					cusV4Tetmino[0].tu = 51.f / 512;
					cusV4Tetmino[0].tv = 51.f / 256;
					cusV4Tetmino[1].tu = 100.f / 512;
					cusV4Tetmino[1].tv = 51.f / 256;
					cusV4Tetmino[2].tu = 100.f / 512;
					cusV4Tetmino[2].tv = 97.f / 256;
					cusV4Tetmino[3].tu = 51.f / 512;
					cusV4Tetmino[3].tv = 97.f / 256;
					break;
				case 20:
					cusV4Tetmino[0].tu = 51.f / 512;
					cusV4Tetmino[0].tv = 51.f / 256;
					cusV4Tetmino[1].tu = 100.f / 512;
					cusV4Tetmino[1].tv = 51.f / 256;
					cusV4Tetmino[2].tu = 100.f / 512;
					cusV4Tetmino[2].tv = 97.f / 256;
					cusV4Tetmino[3].tu = 51.f / 512;
					cusV4Tetmino[3].tv = 97.f / 256;
					break;
				case 32:
					cusV4Tetmino[0].tu = 0.f;
					cusV4Tetmino[0].tv = 51.f / 256;
					cusV4Tetmino[1].tu = 50.f / 512;
					cusV4Tetmino[1].tv = 51.f / 256;
					cusV4Tetmino[2].tu = 50.f / 512;
					cusV4Tetmino[2].tv = 97.f / 256;
					cusV4Tetmino[3].tu = 0.f;
					cusV4Tetmino[3].tv = 97.f / 256;
					break;
				case 31:
					cusV4Tetmino[0].tu = 0.f;
					cusV4Tetmino[0].tv = 51.f / 256;
					cusV4Tetmino[1].tu = 50.f / 512;
					cusV4Tetmino[1].tv = 51.f / 256;
					cusV4Tetmino[2].tu = 50.f / 512;
					cusV4Tetmino[2].tv = 97.f / 256;
					cusV4Tetmino[3].tu = 0.f;
					cusV4Tetmino[3].tv = 97.f / 256;
					break;
				case 30:
					cusV4Tetmino[0].tu = 0.f;
					cusV4Tetmino[0].tv = 51.f / 256;
					cusV4Tetmino[1].tu = 50.f / 512;
					cusV4Tetmino[1].tv = 51.f / 256;
					cusV4Tetmino[2].tu = 50.f / 512;
					cusV4Tetmino[2].tv = 97.f / 256;
					cusV4Tetmino[3].tu = 0.f;
					cusV4Tetmino[3].tv = 97.f / 256;
					break;
				}

				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
			}
		}
	}

	return;
}

VOID SetTetliminoTargetTextureAndRender(VOID)
{
	CustomVertex cusV4Tetmino[4] =
	{
		{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 2/512.f, 152/256.f },
		{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 50/512.f, 152/256.f },
		{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 50/512.f, 199/256.f },
		{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 2/512.f, 199/256.f }
	};

	////////////////////////////////////////////////////
	//flameCount�ƃ}�X�N��p���A���t�@�l�����������Ă���
	UnderGoChangeTarAlpha(cusV4Tetmino);

	for (INT block = 0; block < 4; block++)
	{
		cusV4Tetmino[0].x =2+ 395.f + g_targetMinoNumOfArBuf.YX[block][1] * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
		cusV4Tetmino[0].y =2+ -35.f + (g_targetMinoNumOfArBuf.YX[block][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
		cusV4Tetmino[1].x =-2+ 395.f + g_targetMinoNumOfArBuf.YX[block][1] * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
		cusV4Tetmino[1].y =2+ -35.f + (g_targetMinoNumOfArBuf.YX[block][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
		cusV4Tetmino[2].x =-2+ 395.f + g_targetMinoNumOfArBuf.YX[block][1] * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
		cusV4Tetmino[2].y =-2+ -35.f + (g_targetMinoNumOfArBuf.YX[block][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
		cusV4Tetmino[3].x =2+ 395.f + g_targetMinoNumOfArBuf.YX[block][1] * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
		cusV4Tetmino[3].y =-2+ -35.f + (g_targetMinoNumOfArBuf.YX[block][0] - g_deletedLineCount) * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;

		g_pD3dDevice->SetTexture(0, g_pTexture[g_integratedBlockTex]);
		g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
	}
	
	return;
}

VOID UnderGoChangeTarAlpha(CustomVertex *cusV4Tetmino)
{
	static INT frameCount = 0;

	if (frameCount < 64)
	{
		for (INT coordinate = 0; coordinate < 4; coordinate++)
		{	
			DWORD titleAlpha = 255 - 4 * frameCount;

			(cusV4Tetmino + coordinate)->color &= 0x00ffffff;
			(cusV4Tetmino + coordinate)->color += titleAlpha * 0x1000000;
		}
	}

	else
	{
		for (INT coordinate = 0; coordinate < 4; coordinate++)
		{
			DWORD titleAlpha = 4 * frameCount;
			
			(cusV4Tetmino + coordinate)->color &= 0x00ffffff;
			(cusV4Tetmino + coordinate)->color += titleAlpha * 0x1000000;
		}

		if (frameCount == 127)
		{
			frameCount = 0;
		}
	}

	frameCount++;

	return;
}

VOID SetDeletedLineEffectTextureAndRender(VOID)
{
	static INT renderEffectCount = 0;

	if (g_deletedLine && (renderEffectCount < 30))
	{
		INT additionalDeletedEffectScale = 0;
		static INT deletedLineEffectCount = 0;

		CustomVertex cusV4DeletedLineEffect[4] =
		{

			{ g_deletedLineEffectState.x - g_deletedLineEffectState.xScale, g_deletedLineEffectState.y - g_deletedLineEffectState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
			{ g_deletedLineEffectState.x + g_deletedLineEffectState.xScale, g_deletedLineEffectState.y - g_deletedLineEffectState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ g_deletedLineEffectState.x + g_deletedLineEffectState.xScale, g_deletedLineEffectState.y + g_deletedLineEffectState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
			{ g_deletedLineEffectState.x - g_deletedLineEffectState.xScale, g_deletedLineEffectState.y + g_deletedLineEffectState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
		};

		///////////////////////////////////////////////////
		//�J�E���g��p���A�j���[�V�������s�����߂̐ݒ���s��
		CountToAnimation(&additionalDeletedEffectScale, &deletedLineEffectCount, cusV4DeletedLineEffect);

		for (INT column = 0; column < TETLIS_HEIGHT; column++)
		{
			if (g_reduceBlockDurPosition[column][1] ||
				g_reduceBlockDurPosition[column][2] ||
				g_reduceBlockDurPosition[column][3] ||
				g_reduceBlockDurPosition[column][4] ||
				g_reduceBlockDurPosition[column][5] ||
				g_reduceBlockDurPosition[column][6] ||
				g_reduceBlockDurPosition[column][7] ||
				g_reduceBlockDurPosition[column][8] ||
				g_reduceBlockDurPosition[column][9] ||
				g_reduceBlockDurPosition[column][10])
			{
				g_deletedLineEffectState.xScale = 15.f + additionalDeletedEffectScale;

				cusV4DeletedLineEffect[0].x = 560.f - g_deletedLineEffectState.xScale;
				cusV4DeletedLineEffect[0].y = -35.f + (column - g_deletedLineCount) * (g_deletedLineEffectState.yScale * 2) - g_deletedLineEffectState.yScale;
				cusV4DeletedLineEffect[1].x = 560.f + g_deletedLineEffectState.xScale;
				cusV4DeletedLineEffect[1].y = -35.f + (column - g_deletedLineCount) * (g_deletedLineEffectState.yScale * 2) - g_deletedLineEffectState.yScale;
				cusV4DeletedLineEffect[2].x = 560.f + g_deletedLineEffectState.xScale;
				cusV4DeletedLineEffect[2].y = -35.f + (column - g_deletedLineCount) * (g_deletedLineEffectState.yScale * 2) + g_deletedLineEffectState.yScale;
				cusV4DeletedLineEffect[3].x = 560.f - g_deletedLineEffectState.xScale;
				cusV4DeletedLineEffect[3].y = -35.f + (column - g_deletedLineCount) * (g_deletedLineEffectState.yScale * 2) + g_deletedLineEffectState.yScale;

				g_pD3dDevice->SetTexture(0, g_pTexture[g_reduceBlockDurTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4DeletedLineEffect, sizeof(CustomVertex));
			}
		}

		CustomVertex cusV4DeletedCirculeEffect[4] =
		{
			{ g_deletedLineEffectState.x - g_deletedLineEffectState.xScale, g_deletedLineEffectState.y - g_deletedLineEffectState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
			{ g_deletedLineEffectState.x + g_deletedLineEffectState.xScale, g_deletedLineEffectState.y - g_deletedLineEffectState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ g_deletedLineEffectState.x + g_deletedLineEffectState.xScale, g_deletedLineEffectState.y + g_deletedLineEffectState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
			{ g_deletedLineEffectState.x - g_deletedLineEffectState.xScale, g_deletedLineEffectState.y + g_deletedLineEffectState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
		};

		typedef struct
		{
			INT effectDeflectionalScale[16];
			INT effectDeflectionalPosX[16];
			INT effectDeflectionalPosY[16];
			INT effectDeflectionalDegree[16];
			INT effectDeflectionalAppearanceTime[16];
		}EffectDeflection;

		static EffectDeflection effectDeflection[11];

		static INT isFirstFrame, circuleEffectCount = 0;

		if (!circuleEffectCount)
		{
			isFirstFrame = true;
		}

		else
		{
			isFirstFrame = false;
		}

		if (isFirstFrame)
		{
			for (INT line = 0; line < 11; line++)
			{
				for (INT effect = 0; effect < 16; effect++)
				{
					(effectDeflection + line)->effectDeflectionalScale[effect] = rand() % 7 + 10;
					(effectDeflection + line)->effectDeflectionalPosX[effect] = rand() % 290;
					(effectDeflection + line)->effectDeflectionalPosY[effect] = rand() % 20;
					(effectDeflection + line)->effectDeflectionalDegree[effect] = rand() % 180;
					(effectDeflection + line)->effectDeflectionalAppearanceTime[effect] = rand() % 12;
				}
			}

			isFirstFrame = false;
		}

		INT line = 0;

		for (INT column = 0; column < TETLIS_HEIGHT; column++)
		{
			if (g_reduceBlockDurPosition[column][1] ||
				g_reduceBlockDurPosition[column][2] ||
				g_reduceBlockDurPosition[column][3] ||
				g_reduceBlockDurPosition[column][4] ||
				g_reduceBlockDurPosition[column][5] ||
				g_reduceBlockDurPosition[column][6] ||
				g_reduceBlockDurPosition[column][7] ||
				g_reduceBlockDurPosition[column][8] ||
				g_reduceBlockDurPosition[column][9] ||
				g_reduceBlockDurPosition[column][10])
			{
				for (INT effect = 0; effect < 16; effect++)
				{
					cusV4DeletedCirculeEffect->x = 410 + 5.f + (effectDeflection + line)->effectDeflectionalPosX[effect] + (-(effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)cos((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180) - (-(effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)sin((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180);
					cusV4DeletedCirculeEffect->y = -50 + 5.f + (column - g_deletedLineCount) * (g_deletedLineEffectState.yScale * 2) + (effectDeflection + line)->effectDeflectionalPosY[effect] + (-(effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)sin((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180) + (-(effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)cos((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180);
					(cusV4DeletedCirculeEffect + 1)->x = 410 + 5.f + (effectDeflection + line)->effectDeflectionalPosX[effect] + ((effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)cos((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180) - (-(effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)sin((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180);
					(cusV4DeletedCirculeEffect + 1)->y = -50 + 5.f + (column - g_deletedLineCount) * (g_deletedLineEffectState.yScale * 2) + (effectDeflection + line)->effectDeflectionalPosY[effect] + ((effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)sin((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180) + (-(effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)cos((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180);
					(cusV4DeletedCirculeEffect + 2)->x = 410 + 5.f + (effectDeflection + line)->effectDeflectionalPosX[effect] + ((effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)cos((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180) - ((effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)sin((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180);
					(cusV4DeletedCirculeEffect + 2)->y = -50 + 5.f + (column - g_deletedLineCount) * (g_deletedLineEffectState.yScale * 2) + (effectDeflection + line)->effectDeflectionalPosY[effect] + ((effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)sin((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180) + ((effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)cos((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180);
					(cusV4DeletedCirculeEffect + 3)->x = 410 + 5.f + (effectDeflection + line)->effectDeflectionalPosX[effect] + (-(effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)cos((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180) - ((effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)sin((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180);
					(cusV4DeletedCirculeEffect + 3)->y = -50 + 5.f + (column - g_deletedLineCount) * (g_deletedLineEffectState.yScale * 2) + (effectDeflection + line)->effectDeflectionalPosY[effect] + (-(effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)sin((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180) + ((effectDeflection + line)->effectDeflectionalScale[effect])*(FLOAT)cos((effectDeflection + line)->effectDeflectionalDegree[effect] *PI / 180);

					DWORD randomColor = (0xFF000000) + ((rand() % 256) * 0x10000) + ((rand() % 256) * 0x100) + (rand() % 256);

					cusV4DeletedCirculeEffect->color = randomColor;
					(cusV4DeletedCirculeEffect + 1)->color = randomColor;
					(cusV4DeletedCirculeEffect + 2)->color = randomColor;
					(cusV4DeletedCirculeEffect + 3)->color = randomColor;

					INT timeFromAppearance = (circuleEffectCount - (effectDeflection + line)->effectDeflectionalAppearanceTime[effect]);

					if ((0 <= timeFromAppearance) && (timeFromAppearance <= 17))
					{
						cusV4DeletedCirculeEffect->tu = ((timeFromAppearance / 3) * 64) / 512.f;
						(cusV4DeletedCirculeEffect + 1)->tu = (((timeFromAppearance / 3 + 1) * 64) - 1) / 512.f;
						(cusV4DeletedCirculeEffect + 2)->tu = (((timeFromAppearance / 3 + 1) * 64) - 1) / 512.f;
						(cusV4DeletedCirculeEffect + 3)->tu = ((timeFromAppearance / 3) * 64) / 512.f;
						g_pD3dDevice->SetTexture(0, g_pTexture[g_circuleEffectTex]);
						g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4DeletedCirculeEffect, sizeof(CustomVertex));
					}
				}
				line++;
			}
		}

		circuleEffectCount++;
		if (circuleEffectCount == 30)
		{
			circuleEffectCount = 0;
			isFirstFrame = true;
		}
	}

	if (g_deletedLine)
	{
		renderEffectCount++;
	}

	else
	{
		renderEffectCount = 0;
	}

	return;
}

VOID CountToAnimation(INT *additionalDeletedEffectScale, INT *deletedLineEffectCount, CustomVertex *cusV4DeletedLineEffect)
{
	if (g_deletedLine)
	{
		*additionalDeletedEffectScale = 10 * (*deletedLineEffectCount);

		if ((*additionalDeletedEffectScale) > 150)
		{
			*additionalDeletedEffectScale = 150;
		}

		for (INT coordinate = 0; coordinate < 4; coordinate++)
		{
			(cusV4DeletedLineEffect + coordinate)->color &= 0x00FFFFFF;
			(cusV4DeletedLineEffect + coordinate)->color += (0xFF - 8 * (*deletedLineEffectCount)) << 24;
		}

		*deletedLineEffectCount += 1;
		if (*deletedLineEffectCount == 30)
		{
			*additionalDeletedEffectScale = 0;
			*deletedLineEffectCount = 0;
		}
	}

	return;
}

VOID RnderFrame(VOID)
{
	CustomVertex cusV4Frame[4] =
	{
		{	 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{	 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3dDevice->SetTexture(0, g_pTexture[g_frameTex]);
	g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Frame, sizeof(CustomVertex));

	return;
}

VOID RenderGameoverStr(VOID)
{
	CustomVertex resultState[4]
	{
		{    0.f,    0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f,    0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f,  720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{    0.f,  720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	CustomVertex resultIcon[4]
	{
		{ resultIconState.x - resultIconState.scale, resultIconState.y - resultIconState.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ resultIconState.x + resultIconState.scale, resultIconState.y - resultIconState.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ resultIconState.x + resultIconState.scale, resultIconState.y + resultIconState.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ resultIconState.x - resultIconState.scale, resultIconState.y + resultIconState.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	RECT finalScoreStr;

	finalScoreStr.left = 320.f;
	finalScoreStr.top = 450.f;
	finalScoreStr.right = 960.f;
	finalScoreStr.bottom = 530.f;


	RECT rectGameoverStr
	{
		(LONG)(g_gameoverStrState.x - g_gameoverStrState.xScale), (LONG)(g_gameoverStrState.y - g_gameoverStrState.yScale), (LONG)(g_gameoverStrState.x + g_gameoverStrState.xScale), (LONG)(g_gameoverStrState.y + g_gameoverStrState.yScale)
	};

	if (g_showGameoverStr)
	{
		g_pD3dDevice->SetTexture(0, g_pTexture[g_resultTex]);
		g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, resultState, sizeof(CustomVertex));
		g_pD3dDevice->SetTexture(0, g_pTexture[g_pauseIconTex]);
		g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, resultIcon, sizeof(CustomVertex));

		g_pFont[g_gameoverFont]->DrawText(NULL, GAMEOVER, -1, &rectGameoverStr, NULL, 0xFFFFFF5F);
		g_pFont[g_finalScoreFont]->DrawText(NULL, g_scoreArray, -1, &finalScoreStr, DT_CENTER, 0xFFFFFF5F);
	}

	return;
}

VOID RenderScoreStr(VOID)
{
	RECT rectScoreStr
	{
		(LONG)(g_scoreStrState.x - g_scoreStrState.xScale + 700), (LONG)(g_scoreStrState.y - g_scoreStrState.yScale), (LONG)(g_scoreStrState.x + g_scoreStrState.xScale), (LONG)(g_scoreStrState.y + g_scoreStrState.yScale)
	};

	g_pFont[g_scoreFont]->DrawText(NULL, g_scoreArray, -1, &rectScoreStr, DT_RIGHT, GAMEOVER_COLOR);

	return;
}

VOID RenderUndergroundStr(VOID)
{
	RECT rectUndergroundStr
	{
		(LONG)(g_undergroundStrState.x - g_undergroundStrState.xScale), (LONG)(g_undergroundStrState.y - g_undergroundStrState.yScale), (LONG)(g_undergroundStrState.x + g_undergroundStrState.xScale), (LONG)(g_undergroundStrState.y + g_undergroundStrState.yScale)
	};

	sprintf(g_undergroundArray, "%d", g_deletedLineCount);
		g_pFont[g_undergroundFont]->DrawText(NULL, g_undergroundArray, -1, &rectUndergroundStr, DT_RIGHT, GAMEOVER_COLOR);

	return;
}

VOID SetHoldNextNextNextVerticesAndRender(VOID)
{
	CustomVertex cusV4Tetmino[4] =
	{
		{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	for (int coordinateY = 0; coordinateY < 4; coordinateY++)
	{
		for (int coordinateX = 0; coordinateX < 4; coordinateX++)
		{
			if (g_holdBoard[coordinateY][coordinateX] != -1)
			{
				cusV4Tetmino[0].x = 235.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				cusV4Tetmino[0].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				cusV4Tetmino[1].x = 235.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				cusV4Tetmino[1].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				cusV4Tetmino[2].x = 235.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				cusV4Tetmino[2].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				cusV4Tetmino[3].x = 235.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				cusV4Tetmino[3].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				
				switch (g_holdBoard[coordinateY][coordinateX] % 100)
				{
				case 0:
					cusV4Tetmino[0].x = 250.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
					cusV4Tetmino[0].y = 85.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
					cusV4Tetmino[1].x = 250.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
					cusV4Tetmino[1].y = 85.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
					cusV4Tetmino[2].x = 250.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
					cusV4Tetmino[2].y = 85.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
					cusV4Tetmino[3].x = 250.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
					cusV4Tetmino[3].y = 85.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;

					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoITex]);
					break;
				case 1:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoJTex]);
					break;
				case 2:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoLTex]);
					break;
				case 3:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoSTex]);
					break;
				case 4:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoZTex]);
					break;
				case 5:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoTTex]);
					break;
				case 6:
					cusV4Tetmino[0].x = 250.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
					cusV4Tetmino[0].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
					cusV4Tetmino[1].x = 250.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
					cusV4Tetmino[1].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
					cusV4Tetmino[2].x = 250.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
					cusV4Tetmino[2].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
					cusV4Tetmino[3].x = 250.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
					cusV4Tetmino[3].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;

					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoOTex]);
					break;
				}

				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
			}

			if (g_nextBoard[coordinateY][coordinateX] != -1)
			{
				cusV4Tetmino[0].x = 790.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				cusV4Tetmino[0].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				cusV4Tetmino[1].x = 790.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				cusV4Tetmino[1].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				cusV4Tetmino[2].x = 790.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				cusV4Tetmino[2].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				cusV4Tetmino[3].x = 790.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				cusV4Tetmino[3].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				
				switch (g_nextBoard[coordinateY][coordinateX] % 100)
				{
				case 0:
					cusV4Tetmino[0].x = 805.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
					cusV4Tetmino[0].y = 85.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
					cusV4Tetmino[1].x = 805.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
					cusV4Tetmino[1].y = 85.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
					cusV4Tetmino[2].x = 805.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
					cusV4Tetmino[2].y = 85.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
					cusV4Tetmino[3].x = 805.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
					cusV4Tetmino[3].y = 85.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;

					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoITex]);
					break;
				case 1:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoJTex]);
					break;
				case 2:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoLTex]);
					break;
				case 3:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoSTex]);
					break;
				case 4:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoZTex]);
					break;
				case 5:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoTTex]);
					break;
				case 6:
					cusV4Tetmino[0].x = 805.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
					cusV4Tetmino[0].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
					cusV4Tetmino[1].x = 805.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
					cusV4Tetmino[1].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
					cusV4Tetmino[2].x = 805.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
					cusV4Tetmino[2].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
					cusV4Tetmino[3].x = 805.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
					cusV4Tetmino[3].y = 70.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;

					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoOTex]);
					break;
				}

				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
			}

			ImageState tetminoNextNextState = { 0.f, 0.f, 26.f / 2, 26.f / 2 };

			CustomVertex cusV4TetminoNextNext[4]
			{
				{ tetminoNextNextState.x - tetminoNextNextState.xScale, tetminoNextNextState.y - tetminoNextNextState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
				{ tetminoNextNextState.x + tetminoNextNextState.xScale, tetminoNextNextState.y - tetminoNextNextState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
				{ tetminoNextNextState.x + tetminoNextNextState.xScale, tetminoNextNextState.y + tetminoNextNextState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
				{ tetminoNextNextState.x - tetminoNextNextState.xScale, tetminoNextNextState.y + tetminoNextNextState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
			};

			if (g_nextNextBoard[coordinateY][coordinateX] != -1)
			{
				cusV4TetminoNextNext[0].x = 800.f + coordinateX * (tetminoNextNextState.xScale * 2) - tetminoNextNextState.xScale;
				cusV4TetminoNextNext[0].y = 285.f + coordinateY * (tetminoNextNextState.yScale * 2) - tetminoNextNextState.yScale;
				cusV4TetminoNextNext[1].x = 800.f + coordinateX * (tetminoNextNextState.xScale * 2) + tetminoNextNextState.xScale;
				cusV4TetminoNextNext[1].y = 285.f + coordinateY * (tetminoNextNextState.yScale * 2) - tetminoNextNextState.yScale;
				cusV4TetminoNextNext[2].x = 800.f + coordinateX * (tetminoNextNextState.xScale * 2) + tetminoNextNextState.xScale;
				cusV4TetminoNextNext[2].y = 285.f + coordinateY * (tetminoNextNextState.yScale * 2) + tetminoNextNextState.yScale;
				cusV4TetminoNextNext[3].x = 800.f + coordinateX * (tetminoNextNextState.xScale * 2) - tetminoNextNextState.xScale;
				cusV4TetminoNextNext[3].y = 285.f + coordinateY * (tetminoNextNextState.yScale * 2) + tetminoNextNextState.yScale;
				
				switch (g_nextNextBoard[coordinateY][coordinateX] % 10)
				{
				case 0:
					cusV4TetminoNextNext[0].x = 810.f + coordinateX * (tetminoNextNextState.xScale * 2) - tetminoNextNextState.xScale;
					cusV4TetminoNextNext[0].y = 302.f + coordinateY * (tetminoNextNextState.yScale * 2) - tetminoNextNextState.yScale;
					cusV4TetminoNextNext[1].x = 810.f + coordinateX * (tetminoNextNextState.xScale * 2) + tetminoNextNextState.xScale;
					cusV4TetminoNextNext[1].y = 302.f + coordinateY * (tetminoNextNextState.yScale * 2) - tetminoNextNextState.yScale;
					cusV4TetminoNextNext[2].x = 810.f + coordinateX * (tetminoNextNextState.xScale * 2) + tetminoNextNextState.xScale;
					cusV4TetminoNextNext[2].y = 302.f + coordinateY * (tetminoNextNextState.yScale * 2) + tetminoNextNextState.yScale;
					cusV4TetminoNextNext[3].x = 810.f + coordinateX * (tetminoNextNextState.xScale * 2) - tetminoNextNextState.xScale;
					cusV4TetminoNextNext[3].y = 302.f + coordinateY * (tetminoNextNextState.yScale * 2) + tetminoNextNextState.yScale;

					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoITex]);
					break;
				case 1:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoJTex]);
					break;
				case 2:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoLTex]);
					break;
				case 3:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoSTex]);
					break;
				case 4:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoZTex]);
					break;
				case 5:
					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoTTex]);
					break;
				case 6:
					cusV4TetminoNextNext[0].x = 813.f + coordinateX * (tetminoNextNextState.xScale * 2) - tetminoNextNextState.xScale;
					cusV4TetminoNextNext[0].y = 285.f + coordinateY * (tetminoNextNextState.yScale * 2) - tetminoNextNextState.yScale;
					cusV4TetminoNextNext[1].x = 813.f + coordinateX * (tetminoNextNextState.xScale * 2) + tetminoNextNextState.xScale;
					cusV4TetminoNextNext[1].y = 285.f + coordinateY * (tetminoNextNextState.yScale * 2) - tetminoNextNextState.yScale;
					cusV4TetminoNextNext[2].x = 813.f + coordinateX * (tetminoNextNextState.xScale * 2) + tetminoNextNextState.xScale;
					cusV4TetminoNextNext[2].y = 285.f + coordinateY * (tetminoNextNextState.yScale * 2) + tetminoNextNextState.yScale;
					cusV4TetminoNextNext[3].x = 813.f + coordinateX * (tetminoNextNextState.xScale * 2) - tetminoNextNextState.xScale;
					cusV4TetminoNextNext[3].y = 285.f + coordinateY * (tetminoNextNextState.yScale * 2) + tetminoNextNextState.yScale;

					g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoOTex]);
					break;
				}

				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4TetminoNextNext, sizeof(CustomVertex));
			}
		}
	}

	return;
}

VOID pauseRender()
{
	//�|�[�Y��ʂ̒��_���
	CustomVertex pause[4]
	{
		{	 0.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{	 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	
	CustomVertex pauseIcon[4]
	{
		{ pauseIconState.x - pauseIconState.scale, pauseIconState.y - pauseIconState.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ pauseIconState.x + pauseIconState.scale, pauseIconState.y - pauseIconState.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ pauseIconState.x + pauseIconState.scale, pauseIconState.y + pauseIconState.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ pauseIconState.x - pauseIconState.scale, pauseIconState.y + pauseIconState.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3dDevice->SetTexture(0, g_pTexture[g_pauseTex]);
	g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, pause, sizeof(CustomVertex));
	g_pD3dDevice->SetTexture(0, g_pTexture[g_pauseIconTex]);
	g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, pauseIcon, sizeof(CustomVertex));
}