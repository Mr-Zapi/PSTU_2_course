#include<stdio.h>

void qSort(int* mas, int size){
    int i = 0;
    int j = size - 1;

    int mid = mas[size / 2];

    do {
        while(mas[i] < mid) {
            i++;
        }
        while(mas[j] > mid) {
            j--;
        }
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
         } while (i <= j);


    if(j > 0) {
        //"Левый кусок"
        qSort(mas, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        qSort(&mas[i], size - i);
    }
}