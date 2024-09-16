#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "CollisionMgr.h"
#include "LineMgr.h"
#include "StageMgr.h"

CMainGame::CMainGame() : m_eStage(STAGE_START)
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_hDC = GetDC(g_hWnd);

	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());

	CLineMgr::Get_Instance()->Initialize();
	CStageMgr::Get_Instance()->Initialize();
}

void CMainGame::Update(void)
{
	CObjMgr::Get_Instance()->Update();
	CStageMgr::Get_Instance()->Update();

	CLineMgr::Get_Instance()->Update();
}

void CMainGame::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
	CStageMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render(void)
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	CObjMgr::Get_Instance()->Render(m_hDC);
	CLineMgr::Get_Instance()->Render(m_hDC);
	CStageMgr::Get_Instance()->Render(m_hDC);
}

void CMainGame::Release(void)
{
	CKeyMgr::Get_Instance()->Destroy_Instance();
	CLineMgr::Get_Instance()->Destroy_Instance();
	CObjMgr::Get_Instance()->Destroy_Instance();
	CStageMgr::Get_Instance()->Destroy_Instance();

	ReleaseDC(g_hWnd, m_hDC);
}
