#include "VertexBuffer.h"
#include "GraphicsEngine.h"
VertexBuffer::VertexBuffer()
{
}

bool VertexBuffer::init()
{
	return false;
}

bool VertexBuffer::load(void * list_verticies, UINT size_vertex, UINT size_list, void*shader_byte_code, UINT size_nyte_shader)
{
	//buffer data
	D3D11_BUFFER_DESC buff_desc = {};
	buff_desc.Usage = D3D11_USAGE_DEFAULT;
	buff_desc.ByteWidth = size_vertex * size_list;
	buff_desc.BindFlags = D3D11_BIND_VERTEX_BUFFER; //bind as vertex buffer
	buff_desc.CPUAccessFlags = 0;
	buff_desc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = list_verticies;

	m_size_vertex = size_vertex;
	m_size_list = size_list;


	if (FAILED(GraphicsEngine::get()->m_d3d_device->CreateBuffer(&buff_desc, &initData, &m_buffer)))
		return false;




	return true;
}

bool VertexBuffer::release()
{
	return true;
}

VertexBuffer::~VertexBuffer()
{
}
