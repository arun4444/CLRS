#include <stdio.h>
#include <limits.h>
#define ARRAY_SIZE 16

void printArray(int *array, int startIndex, int endIndex)
{
    int i = startIndex;
    printf("[ ");
    for (i = startIndex; i <= endIndex; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]\r\n");
}

//a is an array
//a[p...q] is a sorted sequence
//a[q+1...r] is a sorted sequence
//merge, merges a[p...q] and a[q+1...r] into a[p...r] in place while preserving sort
void merge(int *a, int p, int q, int r)
{
    int leftSize = q - p + 1;
    int rightSize = r - q;
    int left[leftSize + 1];
    int right[rightSize + 1];
    left[leftSize] = INT_MAX;
    right[rightSize] = INT_MAX;
    
    int i = p;
    int j = 0;
    for (i = p; i <= q; i++){
        left[j++] = a[i];
    }
    j = 0;
    for (i = q + 1; i <= r; i++){
        right[j++] = a[i];
    }

    int arIndex = p;
    int leftIndex = 0;
    int rightIndex = 0;
    for(arIndex = p; arIndex <= r; arIndex++){
        if(left[leftIndex] < right[rightIndex]){
            a[arIndex] = left[leftIndex++];
        } else {
            a[arIndex] = right[rightIndex++];
        }
    }
    //printArray(left, 0, leftSize );
    //printArray(right, 0, rightSize );
    //printArray(a, p, r);
}

void mergeSort(int *a, int startIndex, int stopIndex){
    if(startIndex < stopIndex){
        int midIndex = (startIndex + stopIndex) / 2;
        mergeSort(a, startIndex,  midIndex);
        mergeSort(a, midIndex+1, stopIndex);
        merge(a, startIndex, midIndex, stopIndex);
    }
}

int main()
{
    int toSort[ARRAY_SIZE] = { 2389,6490,1041,2522,5104,5876,3128,2125,4979,1415,7278,3545,8153,-1,10000,0 };
    mergeSort(toSort, 0, 15);
    printArray(toSort, 0, 15);
    return 0;
}
