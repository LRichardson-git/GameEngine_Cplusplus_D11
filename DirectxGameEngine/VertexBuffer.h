#pragma once
#include<d3d11.h>
class VertexBuffer
{

public:
	VertexBuffer();


	bool init();

	bool load(void* list_verticies, UINT size_vertex, UINT size_list);
	//release resources
	bool release();
	~VertexBuffer();

private:
	UINT m_size_vertex;
	UINT m_size_list;

private:
	ID3D11Buffer* m_buffer;
};

