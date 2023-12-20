#include "DeviceContext.h"
#include "SwapChain.h"

DeviceContext::DeviceContext(ID3D11DeviceContext* device_context) : m_device_context(device_context)  //sets m_device context straight away
{


}

bool DeviceContext::clearRenderTargetColour(SwapChain* swap_chain, float r, float g, float b, float alpha)
{
	FLOAT clear_colour[] = { r,g,b,alpha };
	m_device_context->ClearRenderTargetView(swap_chain->m_rtv,clear_colour);

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
