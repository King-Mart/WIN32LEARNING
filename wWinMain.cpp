// #include <Windows.h>
// #include <iostream>
// #include <string>

// /**
//  * Entry point for a Windows application.
//  *
//  * @param hInstance Handle to the current instance of the application.
//  * @param hPrevInstance Handle to the previous instance of the application. This parameter is always NULL since it is not used on modern windows applications.
//  * @param lpCmdLine Command line arguments for the application, excluding the program name.
//  * @param nCmdShow Controls how the window is to be shown (minimized, maximized, etc).
//  * @return The function returns the exit value contained in that application's message loop. If the return value is zero, the application terminated successfully. If the return value is nonzero, the application terminated with an error.
//  */
// int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow) {
//     std::wcout << L"Hello, Windows!" << std::endl;
//     return 0;
// }

// /**
//  * Entry point for the program. This function is defined as the entry point when
//  * compiling as a console application. It calls the real entry point, wWinMain,
//  * with the appropriate parameters.
//  *
//  * @return The exit value returned by wWinMain.
//  */

#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM
lParam);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR
pCmdLine, int nCmdShow)
{
// Register the window class.
const wchar_t CLASS_NAME[] = L"Sample Window Class";
WNDCLASS wc = { };
wc.lpfnWndProc = WindowProc;
wc.hInstance = hInstance;
wc.lpszClassName = CLASS_NAME;
RegisterClass(&wc);
// Create the window.
HWND hwnd = CreateWindowEx(
0, // Optional window styles.
CLASS_NAME, // Window class
L"Learn to Program Windows", // Window text
WS_OVERLAPPEDWINDOW, // Window style
// Size and position
CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
NULL, // Parent window
NULL, // Menu
hInstance, // Instance handle
NULL // Additional application data
);
if (hwnd == NULL)
{
return 0;
}
ShowWindow(hwnd, nCmdShow);
// Run the message loop.
MSG msg = { };
while (GetMessage(&msg, NULL, 0, 0) > 0)
{
TranslateMessage(&msg);
DispatchMessage(&msg);
}
return 0;
}
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM
lParam)
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
// All painting occurs here, between BeginPaint and EndPaint.
FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
EndPaint(hwnd, &ps);
}
return 0;
}
return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main() {
    return wWinMain(GetModuleHandle(nullptr), nullptr, GetCommandLineW(), SW_SHOWNORMAL);
}

