//Program6b = Write a program to search a data value using following technique: ii)Binary search
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,key;
	int array[11];
	int low,high,mid;
	
	for(i=0;i<11;i++)
	{
		printf("\nEnter number : " ,i);
		scanf("%d" ,&array[i]);
	}
	
	printf("\nEnter number you want to search = ");
	scanf("%d",&key);
	{
		low=0;
		high=11;
		
		while(low<=high)
		{
			mid=(low+high)/2;
			if(array[mid]==key)
			{
				printf("\nKey Found...-");
				exit(0);
			}
			else if(array[mid]<key)
			{
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
		printf("\nKey not Found..!");
	}
	return 0;
}
