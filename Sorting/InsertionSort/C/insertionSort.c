#include <stdio.h>
#define ARRAY_SIZE 14

void sort(int *toSort, int arraySize);

int main()
{
   int toSort[ARRAY_SIZE] = {2, 12, 3, 9, 9, 0, 8, 4, 132, 23, 19999, 9, 9, 0};
   sort(toSort, ARRAY_SIZE);
   int loop;
   for (loop = 0; loop < ARRAY_SIZE; loop++)
   {
      printf("%d ", toSort[loop]);
   }
   return 0;
}

void sort(int *toSort, int arraySize)
{
   int j;
   for (j = 1; j < arraySize; j++)
   {
      int key = toSort[j];
      int i = j - 1;
      while (i >= 0 && toSort[i] > key)
      {
         toSort[i + 1] = toSort[i];
         i--;
      }
      toSort[i + 1] = key;
   }
}
