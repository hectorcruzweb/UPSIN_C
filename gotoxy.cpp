#include<stdio.h>
#include<windows.h>
void gotoxy(int X, int Y){
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=X;
	dwPos.Y=Y;
	SetConsoleCursorPosition(hcon,dwPos);
}

main(){
	gotoxy(50,10);
	printf("hola");
}
