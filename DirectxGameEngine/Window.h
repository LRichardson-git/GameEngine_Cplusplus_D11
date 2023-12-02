#pragma once
#include <Windows.h>

class Window
{
public:
	Window();
	bool init();
	bool boradcast();

	bool release();
	bool isRun();

	//EVENT METHODS
	virtual void onCreate()=0;
	virtual void onUpdate()=0;
	virtual void onDestroy();
	~Window();

protected:
	HWND  m_hwnd;
	bool m_is_run;
};

