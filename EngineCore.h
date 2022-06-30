#pragma once

class GameInputComponent;
class GameGraphicsComponent;

class EngineCore
{
public:
	EngineCore();
	EngineCore(const EngineCore&);
	~EngineCore();

	bool ProgramInitialize();
	void ProgramShutdown();
	void Run();

	LRESULT CALLBACK WindowMessageHandler(HWND, UINT, WPARAM, LPARAM);
private:
	bool WindowFrame();
	void WindowInitialize(int&, int&);
	void WindowShutdown();

private:
	LPCWSTR ApplicationName;
	HINSTANCE InstanceHandler;
	HWND WindowHandler;

	GameInputComponent* InputComponent = nullptr;
	GameGraphicsComponent* GraphicsComponent = nullptr;
};


static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static EngineCore* EngineApplicationHandle = 0;