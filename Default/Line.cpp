#include "stdafx.h"
#include "Line.h"
#include "ScrollMgr.h"

CLine::CLine()
{
}

CLine::CLine(const LINE& tInfo)
	: m_tInfo(tInfo)
{

}

CLine::CLine(LINEPOINT & tLeft, LINEPOINT & tRight) : m_tInfo(tLeft, tRight)
{
}


CLine::~CLine()
{
	Release();
}

void CLine::Render(HDC hDC)
{
	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();

	MoveToEx(hDC, (int)m_tInfo.tLPoint.fX + iScrollX, (int)m_tInfo.tLPoint.fY, nullptr);
	LineTo(hDC, (int)m_tInfo.tRPoint.fX + iScrollX, (int)m_tInfo.tRPoint.fY);
}

void CLine::Release(void)
{
}
