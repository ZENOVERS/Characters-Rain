#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#pragma  warning(disable:4996)

typedef struct Char
{
	BOOL RAND_X;
	char c;
	int x;
	int y;
} C;

void Setting()
{
	system("title Characters Rain");
	system("mode con cols=100 lines=30"); //�ܼ� ũ�� ����
	CONSOLE_CURSOR_INFO cursorinfo = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorinfo); //Ŀ�� �����
	srand(time(NULL));
}

void Goxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	Setting();

	C c[10000] = { 0, }; //�� 1���� �Է� ����
	int skip = 0; //�Էµ� �ܾ �ܼ� �ϴܿ� ���� �� C����ü c�迭�� ���� �迭���� �������� �Է� ���� ó��

	for (int i = 0; i < 10000; i++)
	{
		for (int j = skip; j < i + 1; j++)
		{
			if (c[j].RAND_X == !TRUE) //ó�� �� ���� x��ǥ ��, ���� ����
			{
				c[j].x = rand() % 100;
				c[j].c = getch();
				c[j].RAND_X = !FALSE;
			}

			c[j].y++;

			if (c[j].y > 28) //�Էµ� ���ڰ� �ϴܿ� ��� ���� ó��
				skip++; //j���� skip���� ������ skip���� �Էµ� ���鸸 ó��

			Goxy(c[j].x, c[j].y); //y��ǥ ���� �� �Էµ� ��ǥ �̵�
			printf("%c", c[j].c);
		}
		system("cls");
	}

	return 0;
}