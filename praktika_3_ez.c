#include"stroka.h"

int main(){
    printf("Введите текст: ");
    char* str = input();
    str = strip(str);
    str[len(str)] = ' ';
    str[len(str) + 1] = '\0';
    int start = 0;
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ' '){
            for (int j = start; j < i; j++){
                if (str[j] == str[(i - start) / 2]){
                    printf("%d ", i);
                    count++;
                }
            }
            if (count == 2){
                char* s = (char* )malloc((i - start) * sizeof(char));
                strncpy(s, &str[start], i - start);
                printf("%s\n", s);
                free(s);
            }
            count = 0;
            start = i + 1;
        }
    }
    free(str);
}