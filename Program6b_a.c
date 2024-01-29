//Program6b = Write a program to search a data value using following technique: i) Linear Search
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int key,i;
	int array[10];
	int found=0;
	
	for(i=0;i<10;i++)
	{
		printf("\nEnter number : " ,i);
		scanf("%d", &array[i]);
	}
	printf("\nEnter the number you want to found = " ,key);
	scanf("%d", &key);
	
	for(i=0;i<10;i++)
	{
		if(array[i]==key)
		{
			found=1;
			break;
		}
	
	}
	
	if(found==1)
	{
		printf("\nKey Found..!!");
	}
	else
	{
		printf("\nKey dosen`t Found..!");
	}
	
	return 0;
}
