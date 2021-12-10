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

void del()
{
	FILE* fp, * tmp;
	int i = 1;
	char id[MAX_NAME_INP];//20
	if ((tmp = fopen("temp.txt", "w")) == NULL)
	{
		printf("Error opening file!!");
		exit(0);
	}

	if ((fp = fopen("apt.txt", "r")) == NULL)
	{
		printf("Error opening file!!");
		exit(0);
	}

	system("cls");
	printf("Enter the Customer ID to remove it: \n");
	fflush(stdin);
	scanf("%s", id);
	while (fread(&det, sizeof(det), 1, fp) == 1)
	{
		if (strcmp(det.id, id) == 0)
		{
			i = 0;
			continue;
		}
		else
			fwrite(&det, sizeof(det), 1, tmp);
	}
	if (i == 1)
	{
		printf("\n\n Records of Customer with this ID is not found!!");

		_getch();
		fclose(fp);
		fclose(tmp);
		main();
	}
	fclose(fp);
	fclose(tmp);
	remove("apt.txt");
	rename("temp.txt", "apt.txt");
	printf("\n\nThe Customer is successfully removed....");
	fclose(fp);
	fclose(tmp);
	_getch();
}

void edit()
{
	FILE* fp;
	int flag = 1;
	char id[MAX_NAME_INP];//20
	long int size = sizeof(det);
	if ((fp = fopen("apt.txt", "r+")) == NULL)
		exit(0);
	system("cls");
	printf("Enter Customer ID to edit:\n\n");
	scanf("%s[^\n]", id);
	fflush(stdin);
	while (fread(&det, sizeof(det), 1, fp) == 1)
	{
		if (strcmp(det.id, id) == 0)
		{
			flag = 0;
			printf("\nEnter ID     :");
			scanf("%s", &det.id);
			printf("\nEnter first Name    :");
			fflush(stdin);
			scanf("%s", &det.name);
			printf("\nEnter last name        :");
			scanf("%s", &det.l_name);
			printf("\nEnter Date :");
			scanf("%s", &det.date);

			fseek(fp, size, SEEK_CUR);  //go to pointed position 
			fwrite(&det, sizeof(det), 1, fp);
			break;
		}
	}
	if (flag == 1) {
		printf("\n\nNO RECORD!!!!");
		fclose(fp);
		_getch();
	}
	else {
		fclose(fp);
		printf("\n\n\t\tRECORD IS SUCCESSFULLY EDITED!!!");
		_getch();
	}
}

void search()
{
	system("cls");
	FILE* fp;
	char id[MAX_NAME_INP];//20
	int flag = 1;
	fp = fopen("apt.txt", "r+");
	if (fp == 0)
	{
		printf("Error opening file!!");
		exit(0);
	}

	fflush(stdin);
	printf("Enter Customer ID to search its details: \n");
	scanf("%s", id);
	while (fread(&det, sizeof(det), 1, fp) == 1)
	{
		if (strcmp(det.id, id) == 0) {
			flag = 0;
			printf("\n\tRecord Found\n ");
			printf("\nID:\t%s", det.id);
			printf("\nFirst Name:\t%s", det.name);
			printf("\nLast Name:\t%s", det.l_name);
			printf("\nDate:\t%s", det.date);

			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		printf("\n\tRequested Customer could not be found!");
	}
	_getch();
	fclose(fp);
}
