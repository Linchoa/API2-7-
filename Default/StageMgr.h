#pragma once
class CStageMgr
{
public:
	CStageMgr();
	~CStageMgr();

public:
	void		Initialize(void);
	int			Update(void);
	void		Late_Update(void);
	void		Render(HDC hDC);
	void		Release(void);

public:
	static		CStageMgr*		Get_Instance(void)
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CStageMgr;

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
	static		CStageMgr*		m_pInstance;
};

