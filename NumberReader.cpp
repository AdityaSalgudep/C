// NumberReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
void MultiDigit(int);
void TwoDigit(int);
void Digit(int);
void Tens(int*, int);
void Hundred(int *, int);
void Thousand(int *, int);
void Lac(int *, int);           
void Crore(int *, int);
void Complicate(int);
int main()
{
	int no, i = 0, j, m = 0;
	int digit, cnt = 0, arr[100];
	printf("Enter Number:");
	scanf_s("%d", &no);
	if (no == 0)
		printf("Zero ");
	while (no > 0)
	{
		digit = no % 10;
		arr[m] = digit;
		no = no / 10;
		cnt++;
		m++;
	}
	
	if (cnt == 1)
	{
		
		Digit(arr[cnt - 1]);
	}
	if (cnt == 2)
	{	
		Tens(arr, cnt);
	}
	if (cnt == 3)
	{
		Hundred(arr, cnt);
	}
	if (cnt == 4 || cnt==5)
	{
		Thousand(arr, cnt);
		
	}
	if (cnt == 6 || cnt == 7)
		Lac(arr, cnt);

	if (cnt == 8 || cnt == 9)
		Crore(arr, cnt);
		
}


