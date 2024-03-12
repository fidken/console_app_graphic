#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void gotoxy(short x, short y) {
    COORD p = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
int main() {
    char key;

    while (true) {
        if (_kbhit()) {  // Проверка на наличие нажатия клавиши
            key = _getch();  // Получение кода нажатой клавиши
            gotoxy(0, 0);
            std::cout << "Pressed key: " << key << std::endl;

            int maxX, maxY;

            HANDLE hStdout;
            CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
            SMALL_RECT srctWindow;

            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

            if (!GetConsoleScreenBufferInfo(hStdout, &csbiInfo)) {
                printf("GetConsoleScreenBufferInfo (%d)\n", GetLastError());
                return FALSE;
            }
            srctWindow = csbiInfo.srWindow;

            maxX = srctWindow.Right - 1;
            maxY = srctWindow.Bottom - 1;
            printf("columns: %d\n", maxX);
            printf("rows: %d\n", maxY);
           
            
            if (key == 27) {  // Пример выхода из цикла по нажатию клавиши Esc (код 27)
                break;
            }
        }
    }

    return 0;
}
