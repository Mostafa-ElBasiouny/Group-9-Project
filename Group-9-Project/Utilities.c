/*
*	GROUP 9 PROJECT - Utilities.c
*
*	DECEMBER - 2021
*
*	CONTRIBUTERS
*	- Aliouchi
*	- Mostafa-Elbasiouny
*	- Hunter-Oswald
*
*	HISTORY
*	- Added platform agnostic clear_screen()		>>> Mostafa-Elbasiouny
*/

#include "Utilities.h"

void clear_screen()
{
#if defined(_WIN32) || defined(_WIN64)
	system("cls");		// Windows specific command.
#else
	system("clear");	// Unix specific command.
#endif
}