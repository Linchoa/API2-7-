#pragma once

#include "Enum.h"
#include "Define.h"
#include "Struct.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	void		Update_Rect(void);

public:
	virtual		void	Initialize(void) PURE;
	virtual		int		Update(void)	PURE;
	virtual		void	Late_Update(void) PURE;
	virtual		void	Render(HDC hDC) PURE;
	virtual		void	Release(void) PURE;

public:
	bool		Get_Dead(void) { return m_bDead; }

	const RECT&		Get_Rect(void) const { return m_tRect; }
	const INFO&		Get_Info(void) const { return m_tInfo; }

protected:
	INFO		m_tInfo;
	RECT		m_tRect;

	float		m_fSpeed;
	int			m_iLife;
	int			m_iScore;
	bool		m_bDead;

	CObj*		m_pTarget;
};

