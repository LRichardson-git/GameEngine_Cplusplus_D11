#include "DeviceContext.h"
#include "SwapChain.h"
#include "VertexBuffer.h"

DeviceContext::DeviceContext(ID3D11DeviceContext* device_context) : m_device_context(device_context)  //sets m_device context straight away
{


}

void DeviceContext::clearRenderTargetColour(SwapChain* swap_chain, float r, float g, float b, float alpha)
{
	FLOAT clear_colour[] = { r,g,b,alpha };
	m_device_context->ClearRenderTargetView(swap_chain->m_rtv,clear_colour);
	m_device_context->OMSetRenderTargets(1, &swap_chain->m_rtv, NULL); //set render target, use back buffer of swapchain


}

void DeviceContext::setVertexBuffer(VertexBuffer* vertex_buffer)
{
	UINT stride = vertex_buffer->m_size_vertex ;
	UINT offset = 0;

	//pass one buffer
	m_device_context->IASetVertexBuffers(0, 1, &vertex_buffer->m_buffer, &stride, &offset);

	m_device_context->IASetInputLayout(vertex_buffer->m_layout);

}

void DeviceContext::drawTraingleList(UINT vertex_count, UINT start_vertex_index)
{
	m_device_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	m_device_context->Draw(vertex_count, start_vertex_index);



}

void DeviceContext::drawTraingleStrip(UINT vertex_count, UINT start_vertex_index)
{
	//set to strip instead of list
	m_device_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	m_device_context->Draw(vertex_count, start_vertex_index);
}

void DeviceContext::setViewportSize(UINT width, UINT height)
{
	D3D11_VIEWPORT vp = {};
	vp.Width = width;
	vp.Height = height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	m_device_context->RSSetViewports(1, &vp);

}


bool DeviceContext::release() {
	m_device_context->Release();
	delete this;
	return true;
}
DeviceContext::~DeviceContext()
{
}
