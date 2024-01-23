#pragma once
#include "d3d11.h"

class SwapChain;
class VertexBuffer;

class DeviceContext
{
public:
	DeviceContext(ID3D11DeviceContext* device_context);
	void clearRenderTargetColour(SwapChain* swap_chain, float r, float g, float b, float alpha);
	void setVertexBuffer(VertexBuffer* vertex_buffer);
	void drawTraingleList(UINT vertex_count, UINT start_vertex_index);
	void drawTraingleStrip(UINT vertex_count, UINT start_vertex_index);
	void setViewportSize(UINT width, UINT height);

	bool release();
	~DeviceContext();

private:
	ID3D11DeviceContext * m_device_context;
};

