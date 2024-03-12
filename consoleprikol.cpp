#include <iostream> 
#include <Windows.h> //не запустится тут, если не компилировать в Visual Studio
#include <conio.h>
#include <string>

using namespace std;

void gotoxy(short x, short y) {
    COORD p = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
int main() {
    char key;

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
    //std::cout << repeatedString << std::endl; // Выведет "XXXXX"
    std::string repeatedString(maxX+1, '/');
    
    for (int n = 0; n < maxY+1; n++) {
        if (n == 0 || n == maxY) {
            gotoxy(0, n);
            printf("%s\n", repeatedString.c_str());
        }
        else {
            gotoxy(0, n);
            printf("%c\n", '/');
            gotoxy(maxX, n);
            printf("%c\n", '/');
        }
    }
    gotoxy(1, 1);
    printf("columns: %d\n", maxX);
    gotoxy(1, 2);
    printf("rows: %d\n", maxY);
    while (true) {
        if (_kbhit()) {  // Проверка на наличие нажатия клавиши
            key = _getch();  // Получение кода нажатой клавиши
            gotoxy(1, 3);
            std::cout << "Pressed key: " << key << std::endl;

            


            if (key == 27) {  // Пример выхода из цикла по нажатию клавиши Esc (код 27)
                break;
            }
        }
    }

    return 0;
}
