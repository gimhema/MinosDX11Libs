#include "stdafx.h"
#include "D3DComponent.h"
#include "CameraComponent.h"
#include "ModelComponent.h"
#include "ColorShaderComponent.h"
#include "GraphicsComponent.h"


GraphicsClass::GraphicsClass()
{
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	
	m_Direct3D = new D3DClass;
	if (!m_Direct3D)
	{
		return false;
	}

	
	if (!m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR))
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	
	m_Camera = new CameraClass;
	if (!m_Camera)
	{
		return false;
	}

	
	m_Camera->SetPosition(0.0f, 0.0f, -5.0f);

	
	m_Model = new ModelClass;
	if (!m_Model)
	{
		return false;
	}

	
	if (!m_Model->Initialize(m_Direct3D->GetDevice()))
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	
	m_ColorShader = new ColorShaderClass;
	if (!m_ColorShader)
	{
		return false;
	}

	
	if (!m_ColorShader->Initialize(m_Direct3D->GetDevice(), hwnd))
	{
		MessageBox(hwnd, L"Could not initialize the color shader object.", L"Error", MB_OK);
		return false;
	}

	return true;
}


void GraphicsClass::Shutdown()
{
	
	if (m_ColorShader)
	{
		m_ColorShader->Shutdown();
		delete m_ColorShader;
		m_ColorShader = 0;
	}

	
	if (m_Model)
	{
		m_Model->Shutdown();
		delete m_Model;
		m_Model = 0;
	}

	
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}
}


bool GraphicsClass::Frame()
{
	
	return Render();
}


bool GraphicsClass::Render()
{
	
	m_Direct3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	
	m_Camera->Render();

	
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
	m_Direct3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	m_Direct3D->GetProjectionMatrix(projectionMatrix);

	
	m_Model->Render(m_Direct3D->GetDeviceContext());

	
	if (!m_ColorShader->Render(m_Direct3D->GetDeviceContext(), m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix))
	{
		return false;
	}

	
	m_Direct3D->EndScene();

	return true;
}