#include "list.h"
#include "alghorims.h"
#include<time.h>

int main() {
    size_t size;
    printf("Введите размерность матрицы: ");
    scanf("%lu", &size);
    if (size > 10){
        printf("Превышена допустимая размерность!");
        exit(1);
    }
    printf("\n");

    int **mas = (int **)malloc(size * sizeof(int *));
    for (size_t i = 0; i < size; i++) {
        mas[i] = (int *)malloc(size * sizeof(int));
    }

    printf("Выберите способ заполнения матрицы: ручной, автоматический (0, 1) = ");
    int varik;
    scanf("%d", &varik);
    if (varik != 0 && varik != 1) varik = 1;

    if (varik == 0) {
        printf("Заполните матрицу...\n");
        for (size_t i = 0; i < size; i++) {
            printf("Ввод %lu строки: ", i);
            for (size_t j = 0; j < size; j++) {
                scanf("%d", &mas[i][j]);
            }
            printf("\n");
        }
    } else {
        srand(time(NULL));
        printf("Матрица заполняется...\n");
        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size; j++) {
                mas[i][j] = rand() % 100;
            }
        }
        printf("Матрица заполнилась!\n");
    }
    printf("\n\n");
    out_matrix(mas, size); // Вывод матрицы

    int *for_sort = (int *)malloc((size * 3 - 2) * sizeof(int));
    int index = 0;

    // Заполнение for_sort
    for (int i = size - 1; i >= 0; i--) {
        for_sort[index++] = mas[i][0];
    }
    for (int i = 1; i < size - 1; i++) {
        for_sort[index++] = mas[0][i];
    }
    for (int i = 0; i < size; i++) {
        for_sort[index++] = mas[i][size - 1];
    }

    qSort(for_sort, index);

    index = 0;//перезаполняем старый массив
    for (int i = size - 1; i >= 0; i--) {
        mas[i][0] = for_sort[index++];
    }
    for (int i = 1; i < size - 1; i++) {
        mas[0][i] = for_sort[index++];
    }
    for (int i = 0; i < size; i++) {
        mas[i][size - 1] = for_sort[index++];
    }

    printf("\n\n");
    out_matrix(mas, size);
    printf("\n");
    int mi = min_mod(mas, size);//немножко изменённые функции, чтобы удовлетворить условиям задачи, находятся в list.h
    int ma = max_mod(mas, size);
    printf("Минимальное значение = %d, Максимальное значение = %d\n", mi, ma);
    if (search(mas, mi, size)){
        printf("Минимальный элемент находится на главной диагонали!\n");
    }
    if (search(mas, ma, size)){
        printf("Максимальный элемент находится на главной диагонали!\n");
    }
    // Освобождение памяти
    for (size_t i = 0; i < size; i++) {
        free(mas[i]);
    }
    free(mas);
    free(for_sort);

    return 0;
}
