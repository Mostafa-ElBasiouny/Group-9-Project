/*
*	GROUP 9 PROJECT - Appointment.c
* 
*	DECEMBER - 2021
*	
*	CONTRIBUTERS
*	- Aliouchi
*	- Mostafa-Elbasiouny
*	- Hunter-Oswald
* 
*	HISTORY
*	- Added add() function		>>> Ali-Noureddine
*	- Added list() function		>>> Ali-Noureddine
*	- Added del() function		>>> Ali-Noureddine
*	- Added edit() function		>>> Ali-Noureddine
*	- Added search() function	>>> Ali-Noureddine
* 
*	- Added range() function					>>> Mostafa-Elbasiouny
*	- Fixed add() to reject non-numeric id's	>>> Mostafa-Elbasiouny
*	- Fixed duplicate id's check in add()		>>> Mostafa-Elbasiouny
*	- Cleaned up appointment ADT in
*	  appointment.c and appointment.h			>>> Mostafa-Elbasiouny
*/

#include "Appointment.h"

void add()
{
	FILE* fp1;
	FILE* fp;
	char inp;
	fp = fopen("apt.txt", "a+");
	if (fp == 0)
	{
		fp = fopen("apt.txt", "w+");
		clear_screen();
		printf("%sError openning file!%s\n", RED, RESET);

		_getch();
	}
	while (1)
	{
		for (int i = 0; i < MAX_ID_INP; i++)
		{
			det.id[i] = '\0';
		}
		clear_screen();
		printf("Enter appointment details");
		printf("\n%s______________________%s\n", BLUE, RESET);
		printf("\n%sEnter ID #: %s", CYAN, RESET);
		scanf("%s", det.id);

		fflush(stdin);
		printf("%sEnter first name: %s", CYAN, RESET);
		scanf("%s", det.name);
		printf("%sEnter last name:%s ", CYAN, RESET);
		scanf("%s", det.l_name);
		printf("%sEnter Date: %s", CYAN, RESET);
		scanf("%s", det.date);

		for (int i = 0; i < strlen(det.id); i++)
		{
				if (!isdigit(det.id[i]))
				{
					printf("\n%sInvalid appointment ID!%s\n", RED, RESET);
					printf("\nPress any key to book another appointment or %sESC%s to go back to menu.", YELLOW, RESET);
					inp = _getche();
					if (inp == 27)//ASCII of 'esc' button
						main();
					else
						add();
				}
			}

		struct info tmp;

		if ((fp1 = fopen("apt.txt", "r")) == NULL)
		{
			printf("%sError openning file!%s\n", RED, RESET);
			exit(0);
		}

		while (fread(&tmp, sizeof(tmp), 1, fp1) == 1)
		{
			if (strcmp(tmp.id, det.id) == 0)
			{
				printf("\n%sAppointment already exists!%s\n", RED, RESET);
				printf("\nPress any key to book another appointment or %sESC%s to go back to menu.", YELLOW, RESET);
				inp = _getche();
				fclose(fp1);
				if (inp == 27)//ASCII of 'esc' button
					main();
				else
					add();
			}
		}

		fwrite(&det, sizeof(det), 1, fp);
		fflush(stdin);

		fclose(fp);

		printf("\n%sAppointment successfully booked!%s", GREEN, RESET);
		printf("\n\nPress any key to book another appointment or %sESC%s to go back to menu.", YELLOW, RESET);
		inp = _getche();
		if (inp == 27)//ASCII of 'esc' button
			main();
		else
			add();
	}
	fclose(fp);
	fclose(fp1);
}

void list()
{
	FILE* fp;
	int i;
	if ((fp = fopen("apt.txt", "r")) == NULL)
	{
		printf("%sError openning file!%s\n", RED, RESET);
		exit(0);
	}

	clear_screen();

	printf("ID #\t\tFirst name\tLast name\tDate\n");

	printf("%s", BLUE);
	for (int i = 0; i < 18; i++) printf("=-=");
	printf("%s", RESET);

	while (fread(&det, sizeof(det), 1, fp) == 1)
	{
		if (isdigit(det.id[0]))
			printf("\n%s\t\t%s\t\t%s\t\t%s", det.id, det.name, det.l_name, det.date);
	}
	printf("\n");

	printf("%s", BLUE);
	for (int i = 0; i < 18; i++) printf("=-=");
	printf("%s", RESET);

	printf("\n\nPress any key to go back to menu.");

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
		printf("%sError opening file!%s\n", RED, RESET);
		exit(0);
	}

	if ((fp = fopen("apt.txt", "r")) == NULL)
	{
		printf("%sError opening file!%s\n", RED, RESET);
		exit(0);
	}

	clear_screen();
	printf("Enter appointment ID to %sdelete%s it", RED, RESET);
	printf("\n%s______________________%s\n\n", BLUE, RESET);
	printf("%sAppointment ID #:%s ", CYAN, RESET);
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
		printf("\n%sAppointment ID %s does not exist!%s\n", RED, id, RESET);

		_getch();
		fclose(fp);
		fclose(tmp);
		main();
	}
	fclose(fp);
	fclose(tmp);
	remove("apt.txt");
	rename("temp.txt", "apt.txt");
	printf("\n%sAppointment successfully removed!%s\n", GREEN, RESET);
	printf("\nPress any key to go back to menu.");
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
	clear_screen();
	printf("Enter appointment ID to %supdate%s it", YELLOW, RESET);
	printf("\n%s______________________%s\n\n", BLUE, RESET);
	printf("%sAppointment ID #:%s ", CYAN, RESET);
	scanf("%s[^\n]", id);
	fflush(stdin);
	while (fread(&det, sizeof(det), 1, fp) == 1)
	{
		if (strcmp(det.id, id) == 0)
		{
			flag = 0;
			printf("%sEnter ID #: %s", CYAN, RESET);
			scanf("%s", &det.id);
			printf("%sEnter first name: %s", CYAN, RESET);
			fflush(stdin);
			scanf("%s", &det.name);
			printf("%sEnter last name: %s", CYAN, RESET);
			scanf("%s", &det.l_name);
			printf("%sEnter date: %s", CYAN, RESET);
			scanf("%s", &det.date);

			fseek(fp, size, SEEK_CUR);  //go to pointed position 
			fwrite(&det, sizeof(det), 1, fp);
			break;
		}
	}
	if (flag == 1) {
		printf("%s\nAppointment does not exist!%s\n", RED, RESET);
		printf("\nPress any key to go back to menu.");
		fclose(fp);
		_getch();
	}
	else {
		fclose(fp);
		printf("\n%sAppointment successfully updated!\n%s", GREEN, RESET);
		printf("\nPress any key to go back to menu.");
		_getch();
	}
}

void search()
{
	clear_screen();
	FILE* fp;
	char id[MAX_NAME_INP];//20
	int flag = 1;
	fp = fopen("apt.txt", "r+");
	if (fp == 0)
	{
		printf("%sError opening file!%s\n", RED, RESET);
		exit(0);
	}

	fflush(stdin);
	printf("Enter the appointment ID to be searched");
	printf("\n%s______________________%s\n\n", BLUE, RESET);
	printf("%sAppointment ID #:%s ", CYAN, RESET);
	scanf("%s", id);
	while (fread(&det, sizeof(det), 1, fp) == 1)
	{
		if (strcmp(det.id, id) == 0) {
			flag = 0;
			printf("\n%sAppointment found!%s\n", GREEN, RESET);
			printf("%s\nID:         %s%s",CYAN, RESET, det.id);
			printf("%s\nFirst Name: %s%s",CYAN, RESET, det.name);
			printf("%s\nLast Name:  %s%s",CYAN, RESET, det.l_name);
			printf("%s\nDate:       %s%s\n",CYAN, RESET, det.date);
			printf("\nPress any key to go back to menu.");
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		printf("%s\nAppointment does not exist!%s\n", RED, RESET);
		printf("\nPress any key to go back to menu.");
	}
	_getch();
	fclose(fp);
}

void range()
{
	FILE* fp;
	int i;
	if ((fp = fopen("apt.txt", "r")) == NULL)
	{
		printf("%sError openning file!%s\n", RED, RESET);
		exit(0);
	}

	clear_screen();

	printf("Enter the appointment ID range to be searched");
	printf("\n%s______________________%s\n\n", BLUE, RESET);
	printf("%sAppointment ID # (Lower) inclusive:%s ", CYAN, RESET);
	char upper[MAX_ID_INP];
	char lower[MAX_ID_INP];
	scanf("%s", lower);
	printf("%sAppointment ID # (Upper) inclusive:%s ", CYAN, RESET);
	scanf("%s", upper);

	printf("\nID #\t\tFirst name\tLast name\tDate\n");

	printf("%s", BLUE);
	for (int i = 0; i < 18; i++) printf("=-=");
	printf("%s", RESET);

	while (fread(&det, sizeof(det), 1, fp) == 1)
	{
		if ((strcmp(lower, det.id) < 0 && strcmp(upper, det.id) > 0) || strcmp(lower, det.id) == 0 || strcmp(upper, det.id) == 0)
		{
			printf("\n%s\t\t%s\t\t%s\t\t%s", det.id, det.name, det.l_name, det.date);
		}
	}
	printf("\n");

	printf("%s", BLUE);
	for (int i = 0; i < 18; i++) printf("=-=");
	printf("%s", RESET);

	printf("\n\nPress any key to go back to menu.");

	_getch();
	fclose(fp);
}