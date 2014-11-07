#include <stdio.h>
#include <stdlib.h>

int * temp;

void MergeSort(int data[ ], int left, int right);

int main(void)
{
    int i, size;
    int * data;

    printf("Enter how many numbers you want to sort:");
    scanf("%d", &size);
    temp=(int *)malloc(size * sizeof(int));
    data = (int *)malloc(size * sizeof(int));

    printf("Enter the numbers:\n");
    for (i = 0; i < size; i++ )
        scanf("%d", &data[i]);
    printf("\nBefore sorting\n");
    for (i = 0; i < size; i++)
        printf("%d ", data[i]);

    MergeSort(data, 0, size - 1);

    printf("\nAfter sorting\n");
    for (i = 0; i < size; i++)
        printf("%d ", data[i]);

    free(temp);
    free(data);

    return 0;
}

void MergeSort(int data[ ], int left, int right)
{
    int mid, i, j, k;

    if (left >= right)              
        return;

    mid = (left + right) / 2;
    MergeSort(data, left, mid);
    MergeSort(data, mid + 1, right);

    for (i = left; i <= mid; i++)
        temp[i] = data[i];

    for (i = mid + 1, j = right; i <= right; i++, j--)
        temp[i] = data[j];

    i = left;
    j = right;

    for (k = left; k <= right; k++)
        if (temp[i] <= temp[j])
            data[k] = temp[i++];
        else
            data[k] = temp[j--];
}