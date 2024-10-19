#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int min(int* arr, int size){
    int m = 100000;
    printf("Min: ");
    for(int i = 0; i < size; i++){
        if (m > arr[i]){
            printf("%d ", arr[i]);
            m = arr[i];
        }
    }
    printf("\n_____\n");
    return m;
    }
int max(int* arr, int size){
    int m = 0;
    printf("Max: ");
    for(int i = 0; i < size; i++){
        if (m < arr[i]){
            printf("%d ", arr[i]);
            m = arr[i];
        }
    }
    printf("\n_____\n");
    return m;
    }
float sr(int* arr, int size){
    int sum = 0;
    int ma = max(arr, size);
    int mi = min(arr, size);
    printf("Max = %d Min = %d", ma, mi);
    printf("\n");
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    printf("Сумма = %d\n",sum);
    sum = sum - mi - ma;
    return (float)sum / size;
}
int main(){
    int vibor = 0;
    printf("Ручной ввод или автоматический (1, 0): ");
    scanf("%d", &vibor);
    printf("\n");
    int arr[17];
    int size = sizeof(arr) / sizeof(arr[0]);
    if (vibor == 0){
        srand(time(NULL));
        for(int i = 0; i < size; i++){
            arr[i] = rand() % 100;
        }
        for (int i = 0; i < size; i++){
            printf("%d ", arr[i]);
        }
    }
    else{
        printf("Вводи числа: ");
        for(int i = 0; i < size; i++){
            scanf("%d ", &arr[i]);
        }
    }
    
    printf("\n");
    printf("Среднее = %f", sr(arr, size));
    return 0;
}