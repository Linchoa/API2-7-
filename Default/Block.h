#pragma once
#include "Struct.h"

class CBlock
{
private:
	CBlock();
	~CBlock();

public:
	void		Initialize(void);
	void		Update();
	void		Render(HDC hDC);
	void		Release(void);

public:
	static		CBlock*		Get_Instance(void)
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CBlock;

		return m_pInstance;
	}

	static		void			Destroy_Instance(void)
	{
		if (nullptr != m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static		CBlock*		m_pInstance;
};

