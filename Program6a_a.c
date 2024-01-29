//write a c program to sort a data value using following technique: i)Selection sort
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

void selectionSort(int arr[], int n)
{
    int i, j, min_index;
    for (i=0; i<n-1; i++)
    {
        min_index = i;
        for (j=i+1; j<n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

int main()
{
    int n;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter the elements of the array: ");
    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);
    printf("\nSorted array using Selection Sort: ");
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}