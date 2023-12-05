#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine()
{
}

bool GraphicsEngine::init()
{
	//have to loop through driver types until succesful put best first (many differnet machines may use this)
	D3D_DRIVER_TYPE driver_types[] = {

		D3D_DRIVER_TYPE_HARDWARE, //GPU, fast
		D3D_DRIVER_TYPE_WARP, //CPU, middle
		D3D_DRIVER_TYPE_REFERENCE //slow

	};
	UINT num_driver_types = ARRAYSIZE(driver_types);

	//amount of features we can use
	D3D_FEATURE_LEVEL feature_levels[] = {

		D3D_FEATURE_LEVEL_11_0
	};
	UINT num_feature_levels = ARRAYSIZE(feature_levels);
	
	HRESULT res = 0;
	//create device to draw resources
	for (UINT driver_type_index = 0; driver_type_index < num_driver_types;) {
																																				  //outputs
		HRESULT res = D3D11CreateDevice(NULL, driver_types[driver_type_index], NULL, NULL, feature_levels, num_feature_levels, D3D11_SDK_VERSION, &m_d3d_device, &m_feature_level, &m_imm_context);

		if (SUCCEEDED(res)) //if create device break loop
			break;

		++driver_type_index;

	}

	if (FAILED(res))
		return false;

	&m_feature_level;

	m_d3d_device->QueryInterface(__uuidof(IDXGIDevice), (void**)(&m_dxgi_device)); //retrieving the IDXGIDevice interface from the Direct3D device object stored in m_d3d_device and storing it in m_dxgi_device
	m_dxgi_device->GetParent(__uuidof(IDXGIAdapter), (void**)&m_dxgi_adapter);
	m_dxgi_adapter->GetParent(__uuidof(IDXGIFactory), (void**)&m_dxgi_factory);

	return true;
}

bool GraphicsEngine::release()
{
	m_imm_context->Release();
	m_d3d_device->Release();
	return true;
}

GraphicsEngine* GraphicsEngine::get()
{
	static GraphicsEngine engine; //since it is static it is put on the stack and created only once, will always get the same address of same instance
	return &engine;
}

GraphicsEngine::~GraphicsEngine()
{
}