#pragma once
#include<d3d11.h>

class DeviceContext;

class VertexBuffer
{

public:
	VertexBuffer();


	bool init();

	bool load(void* list_verticies, UINT size_vertex, UINT size_list, void* shader_byte_code, UINT size_nyte_shader);
	UINT getSizeVertexList();
	//release resources
	bool release();
	~VertexBuffer();

private:
	UINT m_size_vertex;
	UINT m_size_list;
private:
	ID3D11Buffer* m_buffer;
	ID3D11InputLayout* m_layout;
private:
	friend class DeviceContext;


};

