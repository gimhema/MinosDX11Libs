// Dx11Demo_04.cpp: ���� ���α׷��� �������� �����մϴ�.
//

#include "stdafx.h"
#include "SystemComponent.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	// System ��ü ����
	SystemClass* System = new SystemClass;
	if (!System)
	{
		return -1;
	}

	// System ��ü �ʱ�ȭ �� ����
	if (System->Initialize())
	{
		System->Run();
	}

	// System ��ü ���� �� �޸� ��ȯ
	System->Shutdown();
	delete System;
	System = nullptr;

	return 0;
}