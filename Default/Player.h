#pragma once
#include "Obj.h"
#include "LineMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"

class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void	Late_Update(void);
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	void		Key_Input(void);
	void		Jumping(void);
	void		Offset(void);

private:
	bool				m_bJump;
	float				m_fJumpPower;
	float				m_fTime;
};

