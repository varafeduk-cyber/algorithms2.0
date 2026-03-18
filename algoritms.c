#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

    void insertionsort(int arr[], int n ){
        for(int i = 1; i < n; i++ ){
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key ){
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        

        }
    }

    void selectionsort(int arr[],int n){
        for(int i = 0; i < n - 1; i++){
            int min_z = i;
            for(int j = i + 1; j < n; j++){
                if(arr[j] < arr[min_z]){
                    min_z = j;
                }
            }
            
            int temp = arr[i];
            arr[i] = arr[min_z];
            arr[min_z] = temp;

        }

    }

 void heap(int arr[], int n,int i){
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && arr[l] > arr[large]) large = l;
    if(r < n && arr[r] > arr[large]) large = r;
    if(large != i){
        int t = arr[i];
        arr[i] = arr[large];
        arr[large] = t;
        heap(arr, n, large);
    }
 }
void heapsort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--) heap(arr,n,i);
    for(int i = n - 1; i > 0; i--){
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heap(arr,i,0);
    }
}
 int part(int arr[], int low, int h, int pivot){
    if(pivot == 1){
        int random = low + rand() % (h - low);
        int t = arr[random];
        arr[random] = arr[low];
        arr[low] = t;
    }
    int pivoT = arr[low];
    int i = low + 1;
    int j = h;
    while(i <= j){
        while(i <= h && arr[i] <= pivoT) i++;
        while(j >= low + 1 && arr[j] > pivoT) j--;
        if(i < j){
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[low];
    arr[low] = arr[j];
    arr[j] = t;
    return j;
 } 
 void quicksort(int arr[], int low, int h, int pivot){
    if(low < h){
        int p = part(arr, low,h,pivot);
        quicksort(arr,low,p - 1, pivot);
        quicksort(arr, p + 1, h, pivot);
    }
 }

 void generateData(int arr[], int n, int type){
    switch(type){
        case 0: 
            for(int i = 0; i < n; i++) arr[i] = rand()% 1000;
            break;
        case 1:
            for(int i = 0; i < n; i++) arr[i] = i;
            break;
        case 2:
            for(int i = 0; i < n; i++) arr[i] =  n -i;
            break;
        case 3:
            for(int i = 0; i < n; i++) arr[i] = 7;
            break;
        case 4:
            for(int i = 0; i < n; i++) arr[i] = i * 2;
            for(int i = n / 2 + 1; i< n; i++) arr[i] = arr[n - i - 1];
            break;
    }
 }



    



int main(){
    srand(time(NULL));
    int n = 20;
    int tab[n];
    clock_t start,end;
    double cpu_time_used;
    start = clock();


    generateData(tab,n,0);

    printf("Liczby przed sortowaniem:\n");
    for(int i = 0; i < n; i++) printf("%d ", tab[i]);
    quicksort(tab,0,n - 1,1);
    selectionsort(tab,n);

    end = clock();
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("Liczby po sortowaniu:\n");
    for(int i = 0; i < n; i++) printf("%d ", tab[i]);
    printf("Czas dzialania algorytmow dla n=%d : %f sekund\n",n,cpu_time_used);
    return 0;
 }