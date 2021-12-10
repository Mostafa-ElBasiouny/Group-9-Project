#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>

#include "Main.h"


int main(void)
{
	int i = 0;


	char customername;
	char input;

	system("cls");


	system("cls");
	while (1)
	{
		system("cls");

		for (i = 0; i < 80; i++)
			printf("-");
		printf("\n");



		printf("\n");
		printf("\t\t *ENTER YOUR CHOICE*:");
		printf("\n\n");
		printf(" \n Enter 1 -> Book an Appointment");
		printf("\n---------------------------------");
		printf(" \n Enter 2 -> View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Delete Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 -> Search Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 -> Edit Record");
		printf("\n-----------------------");
		printf(" \n Enter 6 -> Exit");
		printf("\n-----------------");
		printf("\n");

		for (i = 0; i < 80; i++)
			printf("-");

		printf("\n\n-->");

		input = _getche();
		input = toupper(input);
		switch (input)
		{
		case '1':

			add(); break;
		case '2':
			list(); break;
		case '3':
			del(); break;
		case '4':
			search(); break;
		case '5':
			edit(); break;
		case '6':
			system("cls");
			printf("\n\n\t GOOD BYE!");


			exit(0);
			break;
		default:
			system("cls");
			printf("Incorrect Input");
			printf("\n Press any key to continue");
			_getch();
		}
	}
}