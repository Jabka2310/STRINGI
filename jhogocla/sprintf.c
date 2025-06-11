#include <sprintf.h> //потом из библиотеки sprint.h перетащить в s21_string.h и изменить здесь имя
//я уже шатал этот код



char /*  *? */s21_sprintf(char *buffer, char *str_for_processing, ...){

}

void 




int my_strncmp(
    const char *str1, const char *str2,
    size_t n) {  // Сравнивает две строки, возвращает 0 если они равны, 1 если
                 // первая больше, -1 если вторая больше
  int result = 0;
  size_t i = 0;

  while (i < n && str1[i] != '\0' && str2[i] != '\0' && result == 0) {
    result = (unsigned char)str1[i] - (unsigned char)str2[i];
    i++;
  }

  if (result == 0 && i < n) {
    result = (unsigned char)str1[i] - (unsigned char)str2[i];
  }

  return result;
}
