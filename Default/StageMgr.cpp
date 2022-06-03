#include "stdafx.h"
#include "StageMgr.h"

CStageMgr*		CStageMgr::m_pInstance = nullptr;

CStageMgr::CStageMgr()
{
	Release();
}


CStageMgr::~CStageMgr()
{
}

void CStageMgr::Initialize(void)
{
}

int CStageMgr::Update(void)
{
	return 0;
}

void CStageMgr::Late_Update(void)
{
}

void CStageMgr::Render(HDC hDC)
{
}

void CStageMgr::Release(void)
{
}
