#ifndef SPRINTF
#define SPRINTF

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


void parse_spec();
void work_with_str(char *str, );
void s21_sprintf(char *buffer/*чтобы скопировать, нужен strncpy() из библиотеки s21_string.h*/, char *str_for_processing, ...);
void int my_strncmp
#endif 