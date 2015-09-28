#include <stdio.h>

// shell sort
void shellsort(int v[], int n);

int main()
{
  int arr[] = {13,14,94,33,82,25,59,94,65,23,45,27,73,25,39,10};
  int len = 16;
  shellsort(arr, len);
  for(int i=0; i<len; i++)
    printf("%d, ", arr[i]);
  printf("\n");
}


void shellsort(int arr[], int len)
{
  int gap, i, j;
  int temp;
	for (gap = len >> 1; gap > 0; gap >>= 1)
		for (i = gap; i < len; i++) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
				arr[j + gap] = arr[j];
			arr[j + gap] = temp;
		}
}
