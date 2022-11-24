#include <stdbool.h>  // for using boolean true and false
#include <stdio.h>

bool linearSearch(int array[], int size, int target) 
{
  for (int i = 0; i < size; i++) 
  {
    if (array[i] == target) 
    {
      return true;
    }
  }
  return false;
}


int main() {
  int size; 
  printf("Enter size of array you want to input -> "); 
  scanf("%d", &size);
  
  int arr[size]; // creating an array of length 'size'
  
  for (int i = 0; i < size; i++) 
  {
    printf("\nEnter element %d: ", i+1);
    scanf("%d", &arr[i]);
  }
  
  int target; 
  printf("\nEnter target -> "); 
  scanf("%d", &target);
  
  if (linearSearch(arr, size, target)) 
  {
    printf("\nTarget is present in given array\n");
  } 
  else 
  {
    printf("\nTarget not present in given array\n");
  }
}