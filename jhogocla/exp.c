#include<stdio.h>

int main(){
    int j = 5;
    float h = 2.4;
    printf("%%d", j); // че за хуйню он мне выдает при  printf("%023f", h);
    //printf("%f%d", h, j); 2.4000005 вот этот вывод тоже надо прописать
    //printf("%%d", j); на это благо выдает ошибку
    j++;
    h++;
    return 0;
}