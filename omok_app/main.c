#include <windows.h>
#include <stdio.h>

int main() {
    // 원하는 콘솔 창 크기 설정
    COORD newSize = { 100, 50 }; // 가로 100, 세로 50

    // 새로운 창 크기 설정
    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = newSize.X - 1;
    rect.Bottom = newSize.Y - 1;
    if (!SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect)) {
        printf("Failed to set console window size\n");
        return 1;
    }

    printf("Console size has been changed to %dx%d\n", newSize.X, newSize.Y);

    return 0;
}
