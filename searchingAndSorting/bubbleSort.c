#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int a[], int len){
  int sorted;
  for (int i=0; i<len; i++)
  {
    sorted = 1;
    for (int j=0; j<len-i; j++)
    {
      if (a[j+1] < a[j])
      {
        // swap the element at index j with element at index j+1
        int temp = a[j+1];
        a[j+1] = a[j];
        a[j] = temp;
        sorted = 0;
      }
    }
    
    if (sorted==1)
    {
      // elements are already sorted
      break;
    }
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

  //calling bubbleSort function
  bubbleSort(arr, size);
  
  //printing the sorted array
  printf("\n____Sorted Array____\n");
  for (int i=0; i<size; i++)
  {
      printf("%d\n", arr[i]);
  }
}

