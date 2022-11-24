#include <stdio.h>
#include <stdlib.h>

void selectionSort(int a[], int last)
{
  for (int i=0; i<last; i++)
  {
    int minimum = i;  // setting index of first element of unsorted array as minimum
    
    for (int j=i+1; j<last; j++)
    {
      if (a[j] < a[minimum]) // comparing if the element is less than minimum
      {
        minimum = j; // as the element is less than minimum, changing the value of minimum
      }
    }

    //swapping the first element of unsorted array with the element having minimum value of the unsorted array.
    int temp = a[minimum];
    a[minimum] = a[i];
    a[i] = temp;
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

  //calling selectionSort function
  selectionSort(arr, size);

  //printing the sorted array
  printf("\n____Sorted Array____\n");
  for (int k=0; k<size; k++)
  {
    printf("%d\n", arr[k]);
  }
}
