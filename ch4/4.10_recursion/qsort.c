#include <stdio.h>

void qsort(int v[], int left, int right);

int main()
{
  int a[] = {22,32,18,98,10,7,92,67,8,33,4,90};
  int len = sizeof(a) / sizeof(a[0]);
  qsort(a, 0, len);
  for (int i = 0; i < len; ++i)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}

void qsort(int v[], int left, int right)
{
  int i, last;
  void swap(int v[], int i, int j);
  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; ++i)
    if (v[i] < v[left])
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);

}

void swap(int v[], int i, int j)
{
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
