#include "moApplication.h"
#include "moSceneManager.h"
#include "moTime.h"
#include "moInput.h"

namespace mo {
	Application::Application()
		: mHdc(NULL)
		, mHwnd(NULL)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);

		mWidth = 1080;
		mHeight = 600;

		// ���ϴ�ũ��� RECT����� rect ������ ����â�� ũ�⸦ ������?
		RECT rect = { 0, 0, mWidth, mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		// ������ ũ�� ����� ��¼���
		SetWindowPos(mHwnd
			, nullptr, 100, 50
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(mHwnd, true);


		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP defaultBitmap
			= (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(defaultBitmap);


		Input::Initialize();
		Time::Initizlize();
		SceneManager::Initialize();
	}
	void Application::Run()
	{
		Update();
		Render();
	}
	void Application::Update()
	{

		Input::Update();
		Time::Update();
		SceneManager::Update();
		
		// ����ۿ� �ִ� �׸��� �������ۿ� �׷�����Ѵ�.
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
	void Application::Render()
	{
		clear();

		Input::Render(mHdc);
		Time::Render(mHdc);
		SceneManager::Render(mHdc);
	}

	void Application::clear()
	{
		HBRUSH grayBrush = CreateSolidBrush(RGB(121, 121, 121));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, grayBrush);
		Rectangle(mBackHdc, -1, -1, 1082, 602);
		SelectObject(mBackHdc, oldBrush);
		DeleteObject(grayBrush);
	}
	
}