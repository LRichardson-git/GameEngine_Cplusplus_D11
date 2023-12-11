#pragma once
#pragma comment(lib,"d3d11.lib") 
#include <Windows.h>


class Window
{
public:
	Window();
	bool init();
	bool boradcast();

	bool release();
	bool isRun();

	RECT getClientWindowRect();
	void setHWND(HWND hwnd);

	//EVENT METHODS
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();
	~Window();

protected:
	HWND  m_hwnd;
	bool m_is_run;
};

