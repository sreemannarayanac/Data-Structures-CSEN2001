#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// binarySearch needs the array to be sorted. If array is not sorted binary search will give unintented result.

bool binarySearch(int array[], int target, int size){
  int begin = 0, end = size, mid;
  
  while (begin<=end)
  {
    mid = begin + (end - begin)/2;
    if (target>array[mid]) 
    {
      begin = mid+1;
    } 
    else if (target<array[mid]) 
    {
      end = mid-1;
    } 
    else 
    {
      begin = end + 1;
    }
  }
  
  if (array[mid]==target)
  {
    return true;
  } 
  else
  {
    return false;
  }
}

int main()
{
  int len;
  printf("Enter size of array: "); 
  scanf("%d", &len);
  
  int arr[len]; // creating an array of length 'len'
  
  for (int i = 0; i < len; i++) 
  {
    printf("\nEnter element %d: ", i+1);
    scanf("%d", &arr[i]);
  }
  
  int target; 
  printf("\nEnter target -> "); 
  scanf("%d", &target);
  
  if (binarySearch(arr, target, len-1))
  {
    printf("\nElement found.\n");
  } 
  else 
  {
    printf("\nElement not found.\n");
  }
}



