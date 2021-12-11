/*
*	GROUP 9 PROJECT - Appointment.h
*
*	DECEMBER - 2021
*
*	CONTRIBUTERS
*	- Aliouchi
*	- Mostafa-Elbasiouny
*	- Hunter-Oswald
*
*	HISTORY
*	- Added includes from appointment.c	and main.c		>>> Mostafa-Elbasiouny
*/

#pragma once

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#include "Utilities.h"

#define MAX_ID_INP 10			//10
#define MAX_NAME_INP 20			//20
#define MAX_DATE_INP 25			//25

struct info
{
	char id[MAX_ID_INP];		//10
	char name[MAX_NAME_INP];	//20
	char l_name[MAX_DATE_INP];	//25
	char date[MAX_DATE_INP];	//25

}det;

void add();
void list();
void del();
void edit();
void search();
void range();