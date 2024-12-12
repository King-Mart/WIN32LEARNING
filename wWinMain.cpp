#include <Windows.h>
#include <iostream>
#include <string>

/**
 * Entry point for a Windows application.
 *
 * @param hInstance Handle to the current instance of the application.
 * @param hPrevInstance Handle to the previous instance of the application. This parameter is always NULL since it is not used on modern windows applications.
 * @param lpCmdLine Command line arguments for the application, excluding the program name.
 * @param nCmdShow Controls how the window is to be shown (minimized, maximized, etc).
 * @return The function returns the exit value contained in that application's message loop. If the return value is zero, the application terminated successfully. If the return value is nonzero, the application terminated with an error.
 */
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow) {
    std::wcout << L"Hello, Windows!" << std::endl;
    return 0;
}

/**
 * Entry point for the program. This function is defined as the entry point when
 * compiling as a console application. It calls the real entry point, wWinMain,
 * with the appropriate parameters.
 *
 * @return The exit value returned by wWinMain.
 */
int main() {
    return wWinMain(GetModuleHandle(nullptr), nullptr, GetCommandLineW(), SW_SHOWNORMAL);
}


