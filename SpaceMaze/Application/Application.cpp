#include "Application.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Application Application::create(const GameConfiguration& config)
{
    Application app;

    auto hInstance = GetModuleHandle(NULL);
    app.window.lpfnWndProc = WindowProc;
    app.window.hInstance = hInstance;
    app.window.lpszClassName = L"Game";
    RegisterClass(&app.window);
    app.windowHandle = CreateWindowEx(
        0,
        L"Game",
        L"Level",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        config.windowWidth, config.windowHeight,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    return app;
}

int Application::start()
{
    ShowWindow(windowHandle, 0);

    while (true)
    {
        pump();
    }

    return close();
}

void Application::pump()
{
    return;
}

int Application::close()
{
    if (DestroyWindow(windowHandle))
    {
        return 0;
    }
    return 1;
}
