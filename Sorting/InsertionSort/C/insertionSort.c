#include <stdio.h>

void sort(int *toSort, int arraySize);

int main()
{
   int toSort[14] = {2, 12, 3, 9, 9, 0, 8, 4, 132, 23, 19999, 9, 9, 0};
   sort(toSort,14);
   int loop;
   for(loop = 0; loop < 14; loop++){
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
      while (i >= 0 && toSort[i] > key){
         toSort[i + 1] = toSort[i];
         i--;
      }
      toSort[i + 1] = key;
   }
}
