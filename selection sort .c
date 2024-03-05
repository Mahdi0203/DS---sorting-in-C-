#include <stdio.h>

/* void swap(int *xp, int *yp) {   you can use this function
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
} */
void selectionSort(int arr[], int n){
	int i, j, min_idx;
	for (i = 0; i < n-1; i++) {         // One by one move boundary of unsorted subarray
		min_idx = i;                    // Find the minimum element in unsorted array
		for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
		}
		// Swap the found minimum element with the first element
		if(min_idx != i){
            /* swap(&arr[min_idx], &arr[i]); */     /// you can use this function.
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
		}
	}
}

int main(){

    int n;
    scanf("%d", &n);

	int arr[n];
	for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
	}

	selectionSort(arr, n);

	printf("Sorted array: \n");
	for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
