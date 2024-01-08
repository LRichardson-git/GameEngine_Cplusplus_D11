#include "VertexBuffer.h"
#include "GraphicsEngine.h"
VertexBuffer::VertexBuffer():m_layout(0), m_buffer(0) //make sure do not contain garbage values
{
}

bool VertexBuffer::init()
{
	return false;
}

bool VertexBuffer::load(void * list_verticies, UINT size_vertex, UINT size_list, void*shader_byte_code, UINT size_byte_shader)
{
	//can be used to load different lists of verticies
	//release so can create new list of verticies
	if (m_buffer)m_buffer->Release();
	if (m_layout)m_layout->Release();


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


	//check get buffer
	if (FAILED(GraphicsEngine::get()->m_d3d_device->CreateBuffer(&buff_desc, &initData, &m_buffer)))
		return false;

	
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		//semnatic name - semantic index - format - input slot - aligned byte  offset - input slot class - instance data step rate
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0}
	};


	UINT size_layout = ARRAYSIZE(layout);

	GraphicsEngine::get()->m_d3d_device->CreateInputLayout(layout, size_layout, shader_byte_code, size_byte_shader, &m_layout);


	return true;
}

UINT VertexBuffer::getSizeVertexList()
{
	return this->m_size_list;
}

bool VertexBuffer::release()
{
	m_layout->Release();
	m_buffer->Release();
	delete this;
	return true;
}

VertexBuffer::~VertexBuffer()
{
}
