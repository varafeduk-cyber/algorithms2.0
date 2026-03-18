
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>

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

    void shellsort(int arr[], int n){
    int gaps[20];
    int k = 0;
    for (int i = 0; ; i++) {
        int gap;
        if (i % 2 == 0) {
            gap = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
        } else {
            gap = 8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1;
        }
        if (gap >= n) break;
        gaps[k++] = gap;
    }
    for (int i = k - 1; i >= 0; i--) {
        int gap = gaps[i];
        for (int j = gap; j < n; j++) {
            int temp = arr[j];
            int l;
            for (l = j; l >= gap && arr[l - gap] > temp; l -= gap) {
                arr[l] = arr[l - gap];
            }
            arr[l] = temp;
        }
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
    int n, type, alg;
    printf("Podaj liczbe elementow n: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int *tab = (int*)malloc(n * sizeof(int));
    if (tab == NULL) return 1;

    printf("\nWybierz rodzaj danych:\n");
    printf("0 - Losowe\n1 - Rosnace\n2 - Malejace\n3 - Stale\n4 - A-ksztaltne\nWybor: ");
    scanf("%d", &type);
    generateData(tab, n, type);

    printf("\nWybierz algorytm:\n");
    printf("1 - Insertion Sort\n2 - Selection Sort\n3 - Shell Sort (Sedgewick)\n");
    printf("4 - Heap Sort\n5 - Quick Sort (Pivot: Random)\nWybor: ");
    scanf("%d", &alg);

    printf("\nPrzed sortowaniem:\n");
    for (int i = 0; i < n; i++) printf("%d ", tab[i]);
    printf("\n");

    clock_t start = clock();

    switch(alg) {
        case 1: insertionsort(tab, n); break;
        case 2: selectionsort(tab, n); break;
        case 3: shellsort(tab, n); break;
        case 4: heapsort(tab, n); break;
        case 5: quicksort(tab, 0, n - 1, 1); break;
        default: printf("Niepoprawny wybor.\n"); free(tab); return 1;
    }

    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    
    printf("Liczby po sortowaniu:\n");
    for(int i = 0; i < n; i++) printf("%d ", tab[i]);
    printf("Czas dzialania algorytmow dla n=%d : %f sekund\n",n,cpu_time_used);
    free(tab);
    return 0;
}
