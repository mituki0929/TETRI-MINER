/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Common
//
// DATE 2018.06.13
// VER.0.0.5
//
// Author Harutaka-Tsujino
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TETLIS_DIRECTX_VER_0_0_1_H
#define TETLIS_DIRECTX_VER_0_0_1_H

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include <d3dx9.h>
#include <dinput.h>

#pragma comment(lib,"d3dx9d.lib")
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"winmm.lib")

#define DISPLAY_WIDTH 1280
#define DISPLAY_HEIGHT 720
#define TETLIS_WIDTH 12
#define TETLIS_HEIGHT 140
#define SHIFT_FRAME_COUNTER 6
#define DOWN_FRAME_COUNTER 2
#define FLAME_PER_DOWN 30
#define FLAME_PER_STOP 30
#define GAMEOVER ("GAME OVER")
#define GAMEOVER_COLOR (0xFF000000)
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define PI 3.141592

enum TEX
{
	g_teamLogoBgTex,
	g_teamLogoTex,
	g_titleBgTex,
	g_titleLogoTex,
	g_titleIconTex,
	g_backgroundTex,
	g_frameTex,
	g_tetminoITex,
	g_tetminoJTex,
	g_tetminoLTex,
	g_tetminoSTex,
	g_tetminoZTex,
	g_tetminoTTex,
	g_tetminoOTex,
	g_tetminoDirtTex,
	g_tetminoStoneTex,
	g_tetminoIronTex,
	g_tetminoTarTex,
	g_integratedBlockTex,
	g_reduceBlockDurTex,
	g_circuleEffectTex,
	g_treasureBoxTex,
	g_hardDropEffectTex,
	g_pauseTex,
	g_pauseIconTex,
	g_resultTex,
	g_resultIconTex,
	g_texMax
};

enum FONT
{
	g_titleFont,
	g_gameoverFont,
	g_scoreFont,
	g_undergroundFont,
	g_finalScoreFont,
	g_fontMax
};

enum SCENE
{
	g_titleScene,
	g_tutorialScene,
	g_gameScene,
	g_resultScene
};

typedef struct
{
	INT number;
	CHAR name;
	INT yx[4][2];
} Tetmino;

extern Tetmino g_tetmino[7];

typedef struct
{
	INT YX[4][2];
}MovMinoNumoOfArBuf;

extern MovMinoNumoOfArBuf g_movMinoNumOfArBuf;
extern MovMinoNumoOfArBuf g_targetMinoNumOfArBuf;

extern INT g_tetminoNum;
extern INT g_deletedLineCount;
extern INT g_hold, g_next, g_nextNext;
extern INT g_tetlisBoardSource[][TETLIS_WIDTH];
extern INT g_tetlisBoard[TETLIS_HEIGHT][TETLIS_WIDTH];
extern INT g_tetlisBoardBuf[TETLIS_HEIGHT][TETLIS_WIDTH];
extern INT g_holdBoard[4][4];
extern INT g_nextBoard[4][4];
extern INT g_nextNextBoard[4][4];

extern BOOL g_showGameoverStr;
extern BOOL g_hardDropedTetmino;

extern INT scene, teamLogo;

extern BOOL sceneChange, changeFont, deleteFont, arrowMoveUp, arrowMoveDown, arrowMoveRight, arrowMoveLeft, flashing, pause;

extern CHAR g_scoreArray[8];
extern CHAR g_undergroundArray[5];

#endif
