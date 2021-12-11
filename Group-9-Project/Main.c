/*
*	GROUP 9 PROJECT - Main.c
*
*	DECEMBER - 2021
*
*	CONTRIBUTERS
*	- Aliouchi
*	- Mostafa-Elbasiouny
*	- Hunter-Oswald
*
*	HISTORY
*	- Added initial menu.	>>> Ali-Noureddine
*	- Cleaned up main.c and added range search to the menu.		>>> Mostafa-Elbasiouny
*/

#include "Appointment.h"

int main(void)
{
	int i = 0;
	char customername;
	char input;

	while (1)
	{
		clear_screen();

		printf("%s", BLUE);
		for (int i = 0; i < 16; i++) printf("=-=");
		printf("%s", RESET);
		
		printf("\n\t\tEnter your choice\n");
		printf("\t\t%s_________________%s\n", BLUE, RESET);
		printf("\n%s[1]%s Book an appointment", CYAN, RESET);
		printf("\n%s[2]%s Delete an appointment", CYAN, RESET);
		printf("\n%s[3]%s Update an appointment", CYAN, RESET);
		printf("\n%s[4]%s Display a single appointment", CYAN, RESET);
		printf("\n%s[5]%s Display a range of appointments", CYAN, RESET);
		printf("\n%s[6]%s Display all appointments", CYAN, RESET);
		printf("\n%s[7]%s Exit%s\n", CYAN, RED, RESET);

		printf("%s", BLUE);
		for (int i = 0; i < 16; i++) printf("=-=");
		printf("%s", RESET);

		printf("\n\n%sChoice%s ~> ", CYAN, RESET);

		input = _getche();
		input = toupper(input);
		switch (input)
		{
		case '1':
			add(); break;
		case '2':
			del(); break;
		case '3':
			edit(); break;
		case '4':
			search(); break;
		case '5':
			range(); break;
		case '6':
			list(); break;
		case '7':
			clear_screen();
			printf("%sExiting...%s\n", RED, RESET);
			exit(0);
			break;
		default:
			clear_screen();
			printf("%sIncorrect Input!%s", RED, RESET);
			printf("\nPress any key to go back to menu.");
			_getch();
		}
	}
}