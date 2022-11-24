#include <stdio.h>
#include <stdlib.h>

void insertionSort(int a[], int last)
{
  for (int i=1; i<last; i++)
  {
    int ele = a[i];
    int j = i-1;
    while (j>=0 && a[j]>ele)
    {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = ele;
  }
}

int main(void){
  int size; 
  printf("Enter size of the array you want to input -> "); 
  scanf("%d", &size);
  
  int arr[size]; // creating an array of length 'size'
  
  for (int i = 0; i < size; i++) 
  {
    printf("\nEnter element %d: ", i+1);
    scanf("%d", &arr[i]);
  }

  //calling insertionSort function
  insertionSort(arr, size);

  //printing sorted array
  printf("\n____Sorted Array____\n");
  for (int i=0; i<size; i++)
  {
      printf("%d\n", arr[i]);
  }
}
