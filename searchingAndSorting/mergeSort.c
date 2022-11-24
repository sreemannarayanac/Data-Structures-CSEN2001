#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int beg, int mid, int end)
{
  int i, j, k=beg;
  int n1 = mid - beg + 1;
  int n2 = end - mid;
  
  int L[n1], R[n2];
  
  for (i = 0; i<n1; i++)
  {
    L[i] = a[beg+i];
  }
  for (j = 0; j<n2; j++)
  {
    R[j] = a[mid+j+1];
  }
  
  i = 0; j = 0;
  while (i<n1 && j<n2)
  {
    if (L[i] < R[j])
    {
      a[k] = L[i];
      i++;
    }
    else
    {
      a[k] = R[j];
      j++;
    }
    k++;
  }
  
  while (i<n1)
  {
    a[k] = L[i];
    i++; k++;
  }
  
  while (j<n2)
  {
    a[k] = R[j];
    j++; k++;
  }
}

void mergeSort(int a[], int beg, int end)
{
  if (beg<end)
  {
    int mid = beg + (end-beg)/2;
    
    mergeSort(a, beg, mid);
    mergeSort(a, mid+1, end);
    
    merge(a, beg, mid, end);
  }
}

int main(void)
{
  int size; 
  printf("Enter size of the array you want to input -> "); 
  scanf("%d", &size);
  
  int arr[size]; // creating an array of length 'size'
  
  for (int i = 0; i < size; i++) 
  {
    printf("\nEnter element %d: ", i+1);
    scanf("%d", &arr[i]);
  }

  //calling mergeSort function
  mergeSort(arr, 0, size-1);

  //diplaying the sorted array
  printf("\n____Sorted Array____\n");
  for (int i=0; i<size; i++)
  {
      printf("%d\n", arr[i]);
  }
}
