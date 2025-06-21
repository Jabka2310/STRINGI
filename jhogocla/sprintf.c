#include "s21_sprintf.h" //потом из библиотеки sprint.h перетащить в s21_string.h и изменить здесь имя
//я уже шатал этот код



char /*  *? */s21_sprintf(char *buffer, char *str_for_processing, ...){
    work_with_str(str_for_processing);
}

void work_with_str(char *str, char *add_buffer){
    int i = 0;
    int j = 0;
    int lastInd = 0;
    bool repeat = false; //нужен для того, чтобы в доп буффер закинуть модификаторы(для их обработки) спецификатора
    while (str[i] != '\0'){
        if (str[i] == '%' || repeat == true){
            //нужно понять как считывать спецификатор после %, и то дополнительные условия между %...f, это ... надо в отдельный буфер закидывать и разбирать
            if (str[i] != 'c' && str[i] != 'd' && str[i] != 'f' && str[i] != 's' && str[i] != 'u'){
              add_buffer[j] = str[i];
              j++;
            }
            else{
              add_buffer[j] = str[i];
              lastInd = j;
              j = 0;
            }
          repeat = true;
          i++;
          continue;
        }
        repeat = false;
    }
    if (add_buffer != NULL){
      void parse_spec(char *add_buffer, int lastInd);
    }
}


void parse_spec(char *add_buffer, int lastInd, Specifiers *spec){
  spec->c = spec->d = spec->f = spec->s = spec->u = false;
  //это можно просто отдельно сделать. здесб не нужен булл
  switch(add_buffer[lastInd]){
    case 'c': 
      spec->c = true;
      break;
    case 'd': 
      spec->d = true;
      break;
    case 'f': 
      spec->f = true;
      break;
    case 's': 
      spec->s = true;
      break;
    case 'u': 
      spec->u = true;
      break;
    case '%':
      //здесь надо вывести этот %, типо printf("%%"), выводится один знак "%"
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

