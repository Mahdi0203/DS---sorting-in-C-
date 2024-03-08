#include <stdio.h>

int Partition(int arr[],int low,int high){
    //choose the pivot
    int pivot=arr[high];
                                  //Index of smaller element and Indicate the right position of pivot found so far
    int i = low - 1;
    for(int j=low; j<=high; j++){
        if(arr[j] < pivot){            //If current element is smaller than the pivot
            i++;                       //Increment index of smaller element
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    
    int temp = arr[high];
    arr[high] = arr[i+1];
    arr[i+1] = temp;
    
    return (i+1);
}

// The Quicksort function Implement
void quickSort(int arr[],int low,int high){
    if(low < high){                           // when low is less than high
        int pi = Partition(arr,low,high);     // pi is the Partition return index of pivot
        quickSort(arr,low,pi-1);              // Recursion Call
        quickSort(arr,pi+1,high);             // smaller element than pivot goes left and higher element goes right
    }
}

int main(){
  int n;
  scanf("%d", &n);

	int arr[n];
	for(int i = 0; i < n; i++){
      scanf("%d", &arr[i]);
	}    
	
	quickSort(arr,0,n-1);
	
  printf("Sorted Array\n");
  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
    
    return 0;
}
