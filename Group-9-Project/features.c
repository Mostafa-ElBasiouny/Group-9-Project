#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>

#include "Main.h"



void add()
{
	FILE* fp;
	char inp;
	fp = fopen("apt.txt", "a+");
	if (fp == 0)
	{
		fp = fopen("apt.txt", "w+");
		system("cls");
		printf("Error openning file!!");

		_getch();
	}
	while (1)
	{
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Customer ID #:\n");
		scanf("\n%s", det.id);
		fflush(stdin);
		printf("Enter First Name:\n");
		scanf("%s", det.name);
		printf("Enter Last NAME:\n");
		scanf("%s", det.l_name);
		printf("Enter Date:\n");
		scanf("%s", det.date);

		fwrite(&det, sizeof(det), 1, fp);
		fflush(stdin);
		printf("\n\n1 Appointment is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		inp = _getche();
		if (inp == 27)//ASCII of 'esc' button
			break;

	}
	fclose(fp);
}

void list()
{
	FILE* fp;
	int i;
	if ((fp = fopen("apt.txt", "r")) == NULL)
	{
		printf("Error opening file!!");
		exit(0);
	}

	system("cls");
	printf("ID    ");
	printf("FIRST NAME ");
	printf("\tLAST NAME ");
	printf("\tDATE\n");


	for (i = 0; i < 118; i++)
		printf("-");
	while (fread(&det, sizeof(det), 1, fp) == 1)
	{

		printf("\n%s \t%s \t\t%s \t\%s", det.id, det.name, det.l_name, det.date);
	}
	printf("\n");
	for (i = 0; i < 118; i++)
		printf("-");

	fclose(fp);
	_getch();
}
