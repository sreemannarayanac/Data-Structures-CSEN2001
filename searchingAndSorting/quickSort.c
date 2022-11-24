#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int low, int high)
{
  int pivot = a[high];
  
  int i = low - 1, temp;
  
  for (int j=low; j<high; j++)
  {
    if (a[j] <= pivot)
    {
      i++;
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
  
  temp = a[i+1];
  a[i+1] = a[high];
  a[high] = temp;
  
  return i+1;
}

int quickSort(int a[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(a, low, high);
    
    quickSort(a, low, pi-1);
    quickSort(a, pi+1, high);
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

  //calling quickSort function
  quickSort(arr, 0, size-1);

  //printing the sorted array
  printf("\n____Sorted Array____\n");
  for (int i=0; i<size; i++)
  {
      printf("%d\n", arr[i]);
  }
}