#include <Windows.h>
#include <iostream>
#include <string>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow) {
    std::wcout << L"Hello, Windows!" << std::endl;
    return 0;
}

int main() {
    return wWinMain(GetModuleHandle(nullptr), nullptr, GetCommandLineW(), SW_SHOWNORMAL);
}


