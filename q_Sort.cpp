#include<iostream>
#include<vector>
using namespace std;

void q_sort(vector<int> mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];

    do {
        //Делим массив
        while(mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            j--;
        }
        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
         } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        q_sort(mas, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        q_sort(&mas[i], size - i);
    }
}
int* vector_to_array(vector<int> mas){
    int* arr = new int[mas.size()];
    for(int i = 0; i < mas.size(); i++){
        arr[i] = mas[i];
        cout<<mas[i]<<' ';
    }
    cout<<endl;
    return arr;
}

int main(){
    vector<int> arr = {4,3,1,5,10,22};
    int* a = vector_to_array(arr);
    q_sort(a, 6);
    for (int* ptr = a; ptr < a + arr.size(); ptr++){
        cout<<*ptr<<' ';
    }
    delete[] a;
    return 0;
}