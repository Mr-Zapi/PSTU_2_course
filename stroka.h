//Юзаем библиотеки

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
//___________________



//Ввод динамической строкиint len(char* str){
char* input(){
    size_t size = 10;
    char* str = (char* )malloc(size * sizeof(char));
    if (str == NULL){
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    size_t length = 0;
    int ch; 
    ch = getchar();
    while (ch != '\n'){
        if (length + 1 >= size){
            size *= 2;
            str = (char* )realloc(str, size * sizeof(char));
            if (str == NULL) {
                printf("%s", "Ошибка перераспределения памяти\n");
                exit(1);
            }
        }
        str[length++] = (char)ch;
        ch = getchar();
    }
    str[length] = '\0';
    return str;
    
}
//___________________________________________________________________________________








//Разбиение строки по символу

char** split(char* str, char ch, int* count) {
    int size = strlen(str);
    int max_splits = size / 2 + 1;
    char** result = (char**)malloc(max_splits * sizeof(char*));
    if (result == NULL) {
        return NULL;
    }

    int start = 0;
    int index = 0;

    for (int i = 0; i <= size; i++) {
        if (str[i] == ch || str[i] == '\0') {
            int length = i - start;
            result[index] = (char*)malloc((length + 1) * sizeof(char));
            if (result[index] == NULL) {
                // Освобождаем ранее выделенную память в случае ошибки
                for (int j = 0; j < index; j++) {
                    free(result[j]);
                }
                free(result);
                return NULL;
            }
            strncpy(result[index], str + start, length);
            result[index][length] = '\0';
            index++;
            start = i + 1; // Переход к следующему началу подстроки
        }
    }
    *count = index;
    return result;
}

//________________________________________________________________________________








//Удаление символов из строки

char* del(char* str, char target){
    size_t len = strlen(str);
    char* new_str = (char* )malloc(len * sizeof(char));
    int index = 0;
    new_str[index] = str[index];
    for (int i = 0; i < len; i++){
        if (new_str[index] == target && str[i] == target){
            continue;
        }
        new_str[++index] = str[i];
    }
    index++;
    new_str[index] = '\0';
    new_str = (char* )realloc(new_str, index*sizeof(char));
    char* hop = (char* )malloc((index-1) * sizeof(char));
    for (int i = 1; i < index; i++){
        hop[i-1] = new_str[i];
    }
    if (new_str == NULL || hop == NULL){
        printf("%s", "Ошибка перераспределения памяти\n");
        exit(1);
    }
    return hop;
}
//___________________________________________________________







//Длина строки
int len(char* str){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++){
        count++;
    }
    return count;
}
//_________________________________________________________






//Количество символов в тексте
int count(char* str, char target){
    int kol = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == target){
            kol++;
        }
    }
    return kol;
}
//___________________________________________________





//Удаляем пробелы в начале и конце
char* strip(char* str){
    size_t lenght = len(str);
    char* s = (char* )malloc(lenght * sizeof(char));
    int left = 0, right = lenght;
    for (size_t i = 0; i < lenght; i++){
        if (str[left] == ' '){
            left++;
        }
        if (str[right] == ' '){
            right--;
        }
        if (left > right){
            printf("ОШибка очистки пробелов!");
            free(s);
            break;
        }
    }
    strncpy(s, str + left, right-left); 
    return s;
}