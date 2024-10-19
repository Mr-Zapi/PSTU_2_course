#include"stroka.h"

char* proverka(){
    char* file_in;
    while (1){
        printf("Введите имя файла: ");
        file_in = input();
        char* check = (char* )malloc(4 * sizeof(char));
        strncpy(check, &file_in[len(file_in) - 4], 4);
        if (strcmp(check, ".txt")){
            printf("Неверно указан формат входного файла...\n");
            free(file_in);
            continue;
        }
        free(check);
        break;
    }
    return file_in;
}

int main(){
    char* file_in = proverka();
    char* file_out = proverka();
    char ch;
    int size = 10;
    int index = 0;
    FILE* in = fopen(file_in, "r");
    FILE* out = fopen(file_out, "w");
    char* str = (char* )malloc(size * sizeof(char));
    if (!in || !out) {
        printf("Произошла ошибка при открытии файлов!\n");
        free(file_in);
        free(file_out);
        return 1;
    } else {
        int size = 10;
        int index = 0;
        while ((ch = fgetc(in)) != EOF) { 
            if (index + 1 >= size){
                size = size * 2;
                str = (char* )realloc(str, size);
            }
            str[index++] = ch;
        }
        printf("Считывание файла завершено...\n");
    }
    str = del(strip(str), ' ');// удаляем все ненужные пробелы в конце, начале и середине строки
    printf("Строка очищена от лишних пробелов\n");
    int length;
    char** mas = split(str, ' ', &length);
    int resoult = 0;
    for (int i = 0; i < length; i++){
        printf("Слово: %s  длина = %d\n", mas[i], len(mas[i]));
        if (mas[i][0] == mas[i][len(mas[i]) - 1]){
            resoult = 1;
            break;
        }
    }
    rewind(in);//перемещает указатель на начало входного файла
    if (resoult){
        fputc('!', out);
        while ((ch = fgetc(in)) != EOF) {
            fputc(ch, out); 
        }
        printf("Выходной файл заполнен! Со знаком восклицания в начале... \n");
    }
    else{
        while ((ch = fgetc(in)) != EOF) {
                    fputc(ch, out); 
                }
        printf("Выходной файл заполнен! Без знака восклицания в начале... \n");
        }
    for (int i = 0; i < length; i++){
        free(mas[i]);
    }
    free(mas);
    free(file_in);
    free(file_out);
    fclose(in);
    fclose(out);
    printf("Память очищена!\n");
    return 0;
}