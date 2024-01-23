#include "AppWindow.h"
struct vec3 {

	float x, y, z;
};

struct vertex {

	vec3 position;

};


AppWindow::AppWindow()
{
}

AppWindow::~AppWindow()
{
}

void AppWindow::onCreate()
{
	Window::onCreate();
	GraphicsEngine::get()->init();
	m_swap_chain = GraphicsEngine::get()->createSwapChain();

	RECT rc = this->getClientWindowRect();
	m_swap_chain->init(this->m_hwnd,rc.right - rc.left, rc.bottom -rc.top);

	vertex list[] = {
		//X - Y - Z
		{-0.5f,-0.5f,0.0f}, //pos1
		{-0.5f,0.5f,0.0f}, //pos2
		{0.5f,-0.5f,0.0f}, //pos3

		{0.5f,0.5f,0.0f} //4  for strip mode
		//{0.5f,-0.5f,0.0f}, //pos2
		//{-0.5f,-0.5f,0.0f} //pos3
	};

	m_vb = GraphicsEngine::get()->createVertexBuffer();

	UINT size_list = ARRAYSIZE(list);

	GraphicsEngine::get()->createShaders();

	void* shader_byte_code = nullptr;
	UINT size_shader = 0;
	GraphicsEngine::get()->getShaderBufferAndSize(&shader_byte_code, &size_shader);
	m_vb->load(list,sizeof(vertex),size_list,shader_byte_code,size_shader);


}

void AppWindow::onUpdate()
{
	Window::onUpdate();
	GraphicsEngine::get()->getImmediateDeviceContext()->clearRenderTargetColour(this->m_swap_chain,1,0,0,1); //clear to choosen colour

	//SET VIEWPORT OF RENDER TARGET IN WHICH WE HAVE TO DRAW
	RECT rc = this->getClientWindowRect();
	GraphicsEngine::get()->getImmediateDeviceContext()->setViewportSize(rc.right - rc.left, rc.bottom - rc.top);
	//SET DEFAULT SHADER IN THE GRAPHICS PIPELINE TO BE ABLE TO DRAW
	GraphicsEngine::get()->setShaders();
	//SET THE VERTICES OF THE TRIANGLE TO DRAW
	GraphicsEngine::get()->getImmediateDeviceContext()->setVertexBuffer(m_vb);

	// FINALLY DRAW THE TRIANGLE
	GraphicsEngine::get()->getImmediateDeviceContext()->drawTraingleStrip(m_vb->getSizeVertexList(), 0);
	m_swap_chain->present(true);
}

void AppWindow::onDestroy()
{
	Window::onDestroy();
	m_vb->release();
	m_swap_chain->release();
	GraphicsEngine::get()->release();
}
