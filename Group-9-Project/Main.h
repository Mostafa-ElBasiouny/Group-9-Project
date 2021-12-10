#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>


#define MAX_ID_INP 10//10
#define MAX_NAME_INP 20//20
#define MAX_DATE_INP 25//25

struct info
{
	char id[MAX_ID_INP];//10
	char name[MAX_NAME_INP];//20
	char l_name[MAX_DATE_INP];//25
	char date[MAX_DATE_INP];//25

}det;

void add();
void list();