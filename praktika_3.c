#include"stroka.h"

int main(){
    setlocale(LC_ALL, "Russian");
    printf("Введите строку: ");
    char* s = input();
    printf("\n");
    printf("Длина строки до удаления лишних пробелов = %d\n\n", len(s));
    s = del(s, ' ');
    s = strip(s);
    printf("Длина строки после удаления лишних пробелов = %d\n\n", len(s));
    printf("Введённая строка - ");
    for (int i = 0; i < len(s); i++){
        printf("%c", s[i]);
    }
    printf("\n\n");
    printf("Слова, подходящие под условия: ");
    int len0 = 0;
    char** d = split(s, ' ', &len0);
    if (d != NULL){
        for (int i = 0; i < len0; i++){
            if (len(d[i]) % 2 != 0){
                char middle_char = d[i][len(d[i]) / 2]; 
                if (count(d[i], middle_char) == 2){
                    printf("%s, ", d[i]);
                }
            }
    }
    }
    printf("\n");
    for (int i = 0; i < len0; i++){
        free(d[i]);
    }
    free(d);
    free(s);
    return 0;
}