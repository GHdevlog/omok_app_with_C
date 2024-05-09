#include <windows.h>
#include <stdio.h>

int main() {
    // ���ϴ� �ܼ� â ũ�� ����
    COORD newSize = { 120, 50 }; // ���� 120����, ���� 9001����

    // ���ο� â ũ�� ����
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

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

    GetConsoleScreenBufferInfo(hConsole, &bufferInfo);

    printf("Console buffer size: %dx%d\n", bufferInfo.dwSize.X, bufferInfo.dwSize.Y);

    return 0;
}
