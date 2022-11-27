#include <stdio.h>
#include <color.h>
#include <interface.h>

#ifdef _WIN32
#include <windows.h>

void activateVirtualTerminal()
{       
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode( handleOut, &consoleMode);
    SetConsoleMode( handleOut, consoleMode );
}
#endif

int main() {
    #ifdef _WIN32
        activateVirtualTerminal();
    #endif

    browser_t browser = create_browser();
    tab_t* tab1 = create_tab();
    tab1->name = "New tab";
    insert_tab(&browser, tab1);
    interface_loop(&browser);
}