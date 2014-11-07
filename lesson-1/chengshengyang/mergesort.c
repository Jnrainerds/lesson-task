//Mergesort.c
#include <stdio.h>
#include <stdlib.h>

void inputData(void);
void outputData(void);
void mergeSort(int left, int right);
void merge(int left, int right);

int size;
int * dataArray;

int main(void)
{
    int i;

    inputData();
    mergeSort(0, size - 1);
    outputData();

    free(dataArray);
    return 0;
}


void inputData(void)
{
    int i;

    printf("Enter how many numbers you want to sort:");
    scanf("%d", &size);
    dataArray = (int *)malloc(size * sizeof(int));

    printf("Enter the numbers:\n");
    for (i = 0; i < size; i++ )
        scanf("%d", &dataArray[i]);
    printf("\nBefore sorting\n");
    for (i = 0; i < size; i++)
        printf("%d ", dataArray[i]);
}

void outputData(void)
{
    int i;

    printf("\nAfter sorting\n");
    for (i = 0; i < size; i++)
        printf("%d ", dataArray[i]);
}

void mergeSort(int left, int right)
{
    int mid = (left + right) / 2;

    if (left < right)
    {
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, right);
    }
}


void merge(int left, int right)
{
    int i ,j, k;
    int mid = (left + right) / 2;
    int * tempArray;
    tempArray = (int *)malloc(size * sizeof(int));

    for (i = left; i <= mid; i++)
        tempArray[i] = dataArray[i];
    for (i = mid + 1, j = right; i <= right; i++, j--)
        tempArray[i] = dataArray[j];
    //copy data into "2" temp arrays
    //actually they are stored in only one array

    i = left;
    j = right;
    for (k = left; k <= right; k++)
        if (tempArray[i] <= tempArray[j])
            dataArray[k] = tempArray[i++];
        else
            dataArray[k] = tempArray[j--];
    //insert the temp arrays into data array

    free(tempArray);
}

