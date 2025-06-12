#include <sprintf.h> //потом из библиотеки sprint.h перетащить в s21_string.h и изменить здесь имя
//я уже шатал этот код



char /*  *? */s21_sprintf(char *buffer, char *str_for_processing, ...){
    work_with_str(str_for_processing);
}

void work_with_str(char *str){
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] == '%' && str[i+1] == 'c' && c == true){
            //нужно понять как считывать спецификатор после %, и то дополнительные условия между %...f, это ... надо в отдельный буфер закидывать и разбирать
        }
    }
}




char *my_strncpy(char *dest, const char *src,
                 size_t n) {  // Копирует строку src в dest, возвращает dest
  char *result = dest;
  size_t i = 0;

  while (i < n && *src != '\0') {
    *dest = *src;
    dest++;
    src++;
    i++;
  }

  while (i < n) {
    *dest = '\0';
    dest++;
    i++;
  }

  return result;
}

