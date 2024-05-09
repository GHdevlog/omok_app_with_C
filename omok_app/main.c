#include <windows.h>
#include <stdio.h>

int main() {
    // ���ϴ� �ܼ� â ũ�� ����
    COORD newSize = { 100, 50 }; // ���� 100, ���� 50

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

    return 0;
}
