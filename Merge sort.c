#include <stdio.h>

const int N = 1e6 + 7;
int n, arr[N];

void Marge(int l, int mid, int r){
    // M[n1]={arr[l,,,mid]}
    // N[n2]={arr[mid+1,,,r]}

    int n1 = mid - l + 1;
    int n2 = r - mid;
    int M[n1];
    int N[n2];

    for (int i = 0; i < n1; i++){
        M[i] = arr[l+i];
    }

    for (int i = 0; i <n2; i++){
        N[i] = arr[mid+1+i];
    }

    int i = 0, j = 0;
    int k = l;
    while (i < n1 && j < n2){
        if (M[i] < N[j]){
            arr[k] = M[i];
            i++;
        }
        else{
            arr[k] = N[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = M[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = N[j];
        j++;
        k++;
    }
}

void Marge_sort(int l, int r){
    int mid = (l + r) / 2;

    if(l==r)  {
        Marge(l, mid, r);
    }
    else if (l < r){

        Marge_sort(l, mid);
        Marge_sort(mid + 1, r);

        Marge(l, mid, r);
    }
}

int main(){

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    Marge_sort(0,n-1);

    printf("Sorted array \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}
