// /*Dejaun Wilmott, lab 7*/

#include <stdio.h>
#include <string.h>


#define ARRAY_SIZE 9




void swap(int *xp, int*yp) {
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}


void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for(i = 0; i < n-1; i++)
    {
        temp = 0;

        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

        if(!temp)
        {
            break;
        }
    }
}



void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;

    for(i = 0; i < n-1; i++)
    {
        min_idx = i;

        for(j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        if(min_idx != i)
        {
            swap(&arr[i], &arr[min_idx]);
        }
    }
}

void countSwaps(int arr[], int n, char* type)
{
    int swapCount = 0;

    int counts[ARRAY_SIZE] = {0};

    if(strcmp(type, "Bubble Sort") == 0)
    {
        bubbleSort(arr, n);
    }

    if(strcmp(type, "Selection Sort") == 0)
    {
        selectionSort(arr, n);
    }

    else
    {
        return;
    }

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if((type == "Bubble Sort" && arr[j] > arr[j+1]) || (type == "Selection Sort" && arr[j] > arr[j+1]))
            {
                swapCount++;
                counts[arr[j]]++;
            }
        }
    }

    printf("%s :\n", type);

    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        if (counts[i] > 0)
        {
            printf("%d: %d\n", i, counts[i]);
        }
    }

    printf("Total swaps: %d\n", swapCount);
}


int main() 
{
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    countSwaps(arr1, ARRAY_SIZE, "Bubble Sort");

    printf("\n");

    countSwaps(arr1, ARRAY_SIZE, "Selection Sort");

    countSwaps(arr2, ARRAY_SIZE, "Bubble Sort");

    printf("\n");

    countSwaps(arr2, ARRAY_SIZE, "Selection Sort");


    return 0;
}
