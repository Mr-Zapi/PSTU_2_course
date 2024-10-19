/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{ 
  srand(time(NULL));
  int i = rand() % 6 + 2;
  int j = i;
  int an;
  int numbers[i][j];
  printf("Выберите способ заполнения матрицы: 1 - Автоматический 0 - Ручной\n");
  scanf("%d", &an);
  if(an == 1){
    for(int k = 0; k < i; k++){
        for (int p = 0; p < j; p++){
        numbers[k][p] = rand();
    }
  }}
  else if(an == 0){
    for(int k = 0; k < i; k++){
        for (int p = 0; p < j; p++){
            printf("Введите элемент матрицы\n");
            scanf("%d", &numbers[k][p]);
  }}}
  
  for (int n = 0; n < i; n ++){
    for (int b = 0; b < j; b ++){
        printf(" %d", numbers[n][b]);
    }
    printf("\n");
  }
}