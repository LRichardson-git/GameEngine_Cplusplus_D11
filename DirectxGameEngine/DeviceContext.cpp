#include "DeviceContext.h"

DeviceContext::DeviceContext(ID3D11DeviceContext* device_context) : m_device_context(device_context)  //sets m_device context straight away
{


}

bool DeviceContext::clearRenderTargetColour(float r, float g, float b, float alpha)
{
	FLOAT clear_colour[] = { r,g,b,alpha };
	m_device_context->ClearRenderTargetView();

	return true;
}


bool DeviceContext::release() {
	m_device_context->Release();
	delete this;
	return true;
}
DeviceContext::~DeviceContext()
{
}
