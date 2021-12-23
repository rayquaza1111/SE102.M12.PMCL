#include "Camera.h"
#include "Mario.h"
#include "Map.h"
#include "PlayScene.h"
#include "hud.h"
CCamera* CCamera::__instance = NULL;

CCamera* CCamera::GetInstance()
{
	if (__instance == NULL)
		__instance = new CCamera();
	return __instance;
}

CCamera::CCamera()
{
	cam_x = 0;
	cam_y = 0;
	this->width = SCREEN_WIDTH;
	this->height = SCREEN_HEIGHT;
}

void CCamera::Update()
{
	CMario* player = ((CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer());
	float cx, cy;
	player->GetPosition(cx, cy);
	CGame *game = CGame::GetInstance();
	cx -= game->GetBackBufferWidth() / 2;
	cy -= game->GetBackBufferHeight() / 2;
	if (cx < 0) cx = 0;
	if (cy < 0) cy = 0;
	float mapEnd = CMaps::GetInstance()->GetWidthMap();
	if (cx + game->GetBackBufferWidth() >= mapEnd) 
		cx = mapEnd - game->GetBackBufferWidth();
	float mapEndY = CMaps::GetInstance()->GetHeightMap();
	if (cy + game->GetBackBufferWidth() >= mapEndY)
		cy = mapEndY - game->GetBackBufferWidth();
	SetCamPos(cx, cy);
}


CCamera::~CCamera()
{
}