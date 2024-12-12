#include <Windows.h>
#include <iostream>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow) {
    std::wcout << L"Hello, Windows!" << std::endl;
    return 0;
}
