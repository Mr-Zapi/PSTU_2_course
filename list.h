//Юзаем библиотеки

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
//___________________


typedef struct {
    int* data;
    int size;
} array;





//Количество символов в списке
int count(array mas, char target){
    int kol = 0;
    for (int i = 0; i < mas.size; i++){
        if (mas.data[i] == target){
            kol++;
        }
    }
    return kol;
}
//___________________________________________________








//Добавление нового элемента
void append(array* mas, int number) {
    int size = mas->size;
    mas->data = (int*)realloc(mas->data, (size + 1) * sizeof(int));
    if (mas->data != NULL) {
        mas->data[size] = number;
        mas->size = size + 1; 
    }
}
//________________________________________________________






//Вывод матрицы
void out_matrix(int** mas, size_t size){
    for (size_t i = 0; i < size; i++){
        printf("|");
        for (size_t j = 0; j < size; j++){
            printf("%d ", mas[i][j]);
        }
        printf("|\n");
    }
}




int min_mod(int** mas, int size){
    int m = 1000000;
    for (int i = 1; i < size; i++){
        for (int j = 1; j < size - 1; j++){
            if (m > mas[i][j]){
                m = mas[i][j];
            }
        }
    }
    return m;
}





int max_mod(int** mas, int size){
    int m = -1;
    for (int i = 1; i < size; i++){
        for (int j = 1; j < size - 1; j++){
            if (m < mas[i][j]){
                m = mas[i][j];
            }
        }
    }
    return m;
}





int search(int** mas, int target, int size){
    for (int i = 0; i < size - 1; i++){
        if (mas[i][i] == target){
            return 1;
        }
    }
    return 0;
}