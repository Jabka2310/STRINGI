#ifndef S21_SPRINTF
#define S21_SPRINTF

#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
typedef struct Specifiers{
    bool c;
    bool d;
    bool f;
    bool s;
    bool u;

} Spec;


void parse_spec(char *buffer, int lastInd, Specifiers *spec);
void work_with_str(char *str);
void s21_sprintf(char *buffer/*чтобы скопировать, нужен strncpy() из библиотеки s21_string.h*/, char *str_for_processing, ...);
char *my_strncpy(char *dest, const char *src, size_t n);

#endif 