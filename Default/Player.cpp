#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer() :m_bJump(false), m_fTime(0.f), m_fJumpPower(0.f)
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo = { 100.f, 300.f, 60.f, 60.f };

	m_fSpeed = 10.f;
	m_fJumpPower = 15.f;
}

int CPlayer::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Jumping();
	Key_Input();
	Offset();

	Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update(void)
{
}

void CPlayer::Render(HDC hDC)
{
	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();

	Rectangle(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top,
		m_tRect.right + iScrollX,
		m_tRect.bottom);
}

void CPlayer::Release(void)
{
}

void CPlayer::Key_Input(void)
{
	if (GetAsyncKeyState(VK_LEFT))
		m_tInfo.fX -= m_fSpeed;

	if (GetAsyncKeyState(VK_RIGHT))
		m_tInfo.fX += m_fSpeed;

	if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
	{
		m_bJump = true;
	}
}

void CPlayer::Jumping(void)
{
	float	fY = 0.f;

	bool bLineCol = CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, &fY);

	if (m_bJump)
	{
		m_tInfo.fY -= m_fJumpPower * m_fTime - (9.8f * m_fTime * m_fTime * 0.5f);
		m_fTime += 0.15f;

		if (bLineCol && fY < m_tInfo.fY)
		{
			m_bJump = false;
			m_fTime = 0.f;
			m_tInfo.fY = fY;
		}
	}
	else if (bLineCol)
	{
		m_tInfo.fY = fY;
	}
	else if (!bLineCol)
	{
		m_tInfo.fY += m_fSpeed;
	}
}

void CPlayer::Offset(void)
{
	int iOffsetMinX = 100.f;
	int iOffsetMaxX = 400.f;

	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();

	if (iOffsetMinX > m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(m_fSpeed);

	if (iOffsetMaxX < m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);

}
