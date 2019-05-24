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
 
void Digit(int j)
{

	switch (j)
	{
	case 1:printf("One ");
		break;
	case 2:printf("Two ");
		break;
	case 3:printf("Three ");
		break;
	case 4:printf("Four ");
		break;
	case 5:printf("Five ");
		break;
	case 6:printf("Six ");
		break;
	case 7:printf("Seven ");
		break;
	case 8:printf("Eight ");
		break;
	case 9:printf("Nine ");
		break;
	}

}

void Complicate(int j)
{
	switch (j)
	{
	case 1:printf("Ten ");
		break;
	case 2:printf("Eleven ");
		break;
	case 3:printf("Twelve ");
		break;
	case 4:printf("Thirteen ");
		break;
	case 5:printf("Fourteen ");
		break;
	case 6:printf("Fifteen ");
		break;
	case 7:printf("Sixteen ");
		break;
	case 8:printf("Seventeen ");
		break;
	case 9:printf("Eighteen ");
		break;
	case 10:printf("Ninteen ");
		break;

	}
}
void MultiDigit(int j)
{
	switch (j)
	{
	case 1:printf("Hundred ");
		break;
	case 2:printf("Thousand ");
		break;
	case 3:printf("Lac ");
		break;
	case 4:printf("Crore ");
		break;
	}
}


void TwoDigit(int j)
{
	switch (j)
	{
	case 2:printf("Twenty ");
		break;
	case 3:printf("Thirty ");
		break;
	case 4:printf("Forty ");
		break;
	case 5:printf("Fifty ");
		break;
	case 6:printf("Sixty ");
		break;
	case 7:printf("Seventy ");
		break;
	case 8:printf("Eighty ");
		break;
	case 9:printf("ninety ");
		break;
	}
}
void Tens(int *arr, int cnt)
{

	if (arr[cnt - 1] != 1)
	{
		TwoDigit(arr[cnt - 1]);
		cnt--;
		Digit(arr[cnt - 1]);
		//arr[cnt - 1] = 0;
	}
	else
		Complicate(arr[cnt - 1] + arr[cnt - 2]);

}
void Hundred(int *arr, int cnt)
{

	Digit(arr[cnt - 1]);
	//arr[cnt - 1] = 0;
	
	if (arr[cnt-1] > 0)
	MultiDigit(1);
	cnt--;
	if (arr[cnt - 1] != 1)
	{
		TwoDigit(arr[cnt - 1]);
		cnt--;
		Digit(arr[cnt - 1]);
		//arr[cnt - 1] = 0;
	}
	else
		Complicate(arr[cnt - 1] + arr[cnt - 2]);
}
void Thousand(int *arr, int cnt)
{
	if (cnt == 5)
	{
		if (arr[cnt - 1] != 1)
		{
			TwoDigit(arr[cnt - 1]);
			cnt--;
		
		}
		else
		{
			Complicate(arr[cnt - 1] + arr[cnt - 2]);
			cnt--;
			MultiDigit(2);
			cnt--;
			goto l1;
		}

	}
	

	
	
		Digit(arr[cnt - 1]);
		if (arr[cnt - 1] > 0)
			MultiDigit(2);
		cnt--;
	l1:Hundred(arr, cnt);
		/*l1:Digit(arr[cnt - 1]);
		//arr[cnt - 1] = 0;

		if (arr[cnt - 1] > 0)
			MultiDigit(1);
		cnt--;
		if (arr[cnt - 1] != 1)
		{
			TwoDigit(arr[cnt - 1]);
			cnt--;
			Digit(arr[cnt - 1]);
			//arr[cnt - 1] = 0;
		}
		else
			Complicate(arr[cnt - 1] + arr[cnt - 2]);
	*/
}
void Lac(int *arr, int cnt)
{
	if (cnt == 7)
	{
		if (arr[cnt - 1] != 1)
		{
			TwoDigit(arr[cnt - 1]);
			cnt--;
		}
		else
		{
			Complicate(arr[cnt - 1] + arr[cnt - 2]);
			cnt--;
			MultiDigit(3);
			cnt--;
			goto l2;
		}

	}
	Digit(arr[cnt - 1]);
	if (arr[cnt - 1] > 0)
		MultiDigit(3);
	cnt--;
	l2:Thousand(arr, cnt);
}
void Crore(int *arr, int cnt)
{
	if (cnt == 9)
	{
		if (arr[cnt - 1] != 1)
		{
			TwoDigit(arr[cnt - 1]);
			cnt--;
		}
		else
		{
			Complicate(arr[cnt - 1] + arr[cnt - 2]);
			cnt--;
			MultiDigit(4);
			cnt--;
			goto l3;
		}

	}
	Digit(arr[cnt - 1]);
	MultiDigit(4);
	cnt--;
	l3:Lac(arr, cnt);
}
