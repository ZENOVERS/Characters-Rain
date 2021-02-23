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
	system("mode con cols=100 lines=30"); //콘솔 크기 조정
	CONSOLE_CURSOR_INFO cursorinfo = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorinfo); //커서 숨기기
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

	C c[10000] = { 0, }; //총 1만자 입력 가능
	int skip = 0; //입력된 단어가 콘솔 하단에 닿을 시 C구조체 c배열의 낮은 배열부터 차례차례 입력 제한 처리

	for (int i = 0; i < 10000; i++)
	{
		for (int j = skip; j < i + 1; j++)
		{
			if (c[j].RAND_X == !TRUE) //처음 한 번만 x좌표 값, 문자 저장
			{
				c[j].x = rand() % 100;
				c[j].c = getch();
				c[j].RAND_X = !FALSE;
			}

			c[j].y++;

			if (c[j].y > 28) //입력된 문자가 하단에 닿기 직전 처리
				skip++; //j값이 skip부터 시작해 skip이후 입력될 값들만 처리

			Goxy(c[j].x, c[j].y); //y좌표 증가 후 입력될 좌표 이동
			printf("%c", c[j].c);
		}
		system("cls");
	}

	return 0;
}