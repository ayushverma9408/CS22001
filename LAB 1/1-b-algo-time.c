#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
    int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int size[] = {10, 500, 1000, 10000, 50000, 75000, 100000};
    int i, j;

    printf("Input Size\tExecution Time (seconds)\n");

    for(i = 0; i < 7; i++)
    {
        int n = size[i];
        int arr[n];

        for(j = 0; j < n; j++)
            arr[j] = rand();

        clock_t start = clock();

        insertionSort(arr, n);

        clock_t end = clock();

        double time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t\t%lf\n", n, time);
    }

    return 0;
}