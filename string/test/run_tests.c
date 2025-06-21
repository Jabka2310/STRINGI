#include "run_tests.h"

#include <check.h>
#include <stdlib.h>

TCase *tcase_s21_strlen(void);
TCase *tcase_s21_strncpy(void);
TCase *tcase_s21_strncmp(void);
TCase *tcase_s21_memchr(void);
TCase *tcase_s21_memcmp(void);
TCase *tcase_s21_memcpy(void);
TCase *tcase_s21_memset(void);
TCase *tcase_s21_strncat(void);
TCase *tcase_s21_strchr(void);
TCase *tcase_s21_strcspn(void);


START_TEST(test_s21_strlen_1) {
  char *str = "Hello, world";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST
START_TEST(test_s21_strlen_2) {
  char *str = "Привет, мир";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST
START_TEST(test_s21_strlen_3) {
  char *str = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST
START_TEST(test_s21_strlen_4) {
  char *str = "q";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST
START_TEST(test_s21_strlen_5) {
  char *str = "Hello\0world";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST
START_TEST(test_s21_strlen_6) {
  char *str = {"   "};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST
START_TEST(test_s21_strlen_7) {
  char *str = "Hello\nmy\ndear\nworld";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST
START_TEST(test_s21_strlen_8) {
  char str[1000];
  for (int i = 0; i < 999; i++) {
    str[i] = 'a';
  }
  str[999] = '\0';
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST
START_TEST(test_s21_strlen_9) {
  char *str = "Hello\\\"\'\n\t\?";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST
// -----------------------------------------------------


START_TEST(test_s21_strncpy_1) {
  char *src = "Hello, world!";
  char dest[20];
  int count = 0;
  ck_assert_ptr_eq(s21_strncpy(dest, src, count), strncpy(dest, src, count));
}
END_TEST
START_TEST(test_s21_strncpy_2) {
  char *src = "Hello, world!";
  char dest[20];
  int count = 13;
  ck_assert_ptr_eq(s21_strncpy(dest, src, count), strncpy(dest, src, count));
}
END_TEST
START_TEST(test_s21_strncpy_3) {
  char *src = "Hello, world!";
  char dest[20];
  int count = 15;
  ck_assert_ptr_eq(s21_strncpy(dest, src, count), strncpy(dest, src, count));
}
END_TEST
START_TEST(test_s21_strncpy_4) {
  char dest[20];
  char *src = "";
  int count = 5;
    ck_assert_ptr_eq(s21_strncpy(dest, src, count), strncpy(dest, src, count));
}
END_TEST
START_TEST(test_s21_strncpy_5) {
  char src[] = "Hello\0world";
  char dest[20];
  int count = 5;
  ck_assert_ptr_eq(s21_strncpy(dest, src, count), strncpy(dest, src, count));
}
END_TEST
START_TEST(test_s21_strncpy_6) {
  char src[] = "\\\"\'\n\t\?";
  char dest[20];
  int count = 5;
  ck_assert_ptr_eq(s21_strncpy(dest, src, count), strncpy(dest, src, count));
}
END_TEST
START_TEST(test_s21_strncpy_7) {
  char src[] = "Hello";
  char dest[20] = "World";
  int count = 5;
  ck_assert_ptr_eq(s21_strncpy(dest, src, count), strncpy(dest, src, count));
}
END_TEST
// -----------------------------------------------------

START_TEST(test_s21_strncmp_1) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  int count = 13;
  ck_assert_int_eq(s21_strncmp(str1, str2, count), strncmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_strncmp_2) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  int count = 10;
  ck_assert_int_eq(s21_strncmp(str1, str2, count), strncmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_strncmp_3) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  int count = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, count), strncmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_strncmp_4) {
  char str1[] = "Hello, world!";
  char str2[] = "hello, world!";
  int count = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, count), strncmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_strncmp_5) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello world!";
  int count = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, count), strncmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_strncmp_6) {
  char str1[] = "";
  char str2[] = "";
  int count = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, count), strncmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_strncmp_7) {
  char str1[] = "Hello";
  char str2[] = "Hello, world!";
  int count = 6;
  ck_assert_int_eq(s21_strncmp(str1, str2, count), strncmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_strncmp_8) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello";
  int count = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, count), strncmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_strncmp_9) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello,\0 world!";
  int count = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, count), strncmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_strncmp_10) {
  char str1[1000];
  char str2[1000];
  for (int i = 0; i < 999; i++) {
    str1[i] = 'H';
  }
  for (int i = 0; i < 999; i++) {
    str2[i] = 'w';
  }
  int count = 1000;
  ck_assert_int_eq(s21_strncmp(str1, str2, count), strncmp(str1, str2, count));
}
END_TEST
// -----------------------------------------------------

START_TEST(test_s21_memchr_1) {
  char *str = "Hello, world!";
  ck_assert_ptr_eq(s21_memchr(str, 'o', 13), memchr(str, 'o', 13));
}
END_TEST

START_TEST(test_s21_memchr_2) {
  char *str = "Hello, world!";
  ck_assert_ptr_eq(s21_memchr(str, 'o', 3), memchr(str, 'o', 3));
}
END_TEST

START_TEST(test_s21_memchr_3) {
  char *str = "Hello, world!";
  ck_assert_ptr_eq(s21_memchr(str, 'q', 13), memchr(str, 'q', 13));
}
END_TEST

START_TEST(test_s21_memchr_4) {
  char str[15] = "";
  ck_assert_ptr_eq(s21_memchr(str, 'o', 0), memchr(str, 'o', 0));
}
END_TEST

START_TEST(test_s21_memchr_5) {
  char *str = "Hello, world!";
  ck_assert_ptr_eq(s21_memchr(str, 'q', 0), memchr(str, 'q', 0));
}
END_TEST

START_TEST(test_s21_memchr_6) {
  char *str = "Hello, world!";
  ck_assert_ptr_eq(s21_memchr(str, 'H', 13), memchr(str, 'H', 13));
}
END_TEST

START_TEST(test_s21_memchr_7) {
  char *str = "Hello, world!";
  ck_assert_ptr_eq(s21_memchr(str, '!', 13), memchr(str, '!', 13));
}
END_TEST

START_TEST(test_s21_memchr_8) {
  char *str = "1234567890\0";
  ck_assert_ptr_eq(s21_memchr(str, '\0', 11), memchr(str, '\0', 11));
}
END_TEST


START_TEST(test_s21_memchr_9) {
  char *str = "AbCdEfGhIjKlMnOpQrStUvWxYz";
  ck_assert_ptr_eq(s21_memchr(str, 'A', 26), memchr(str, 'A', 26));
}
END_TEST

START_TEST(test_s21_memchr_10) {
  char *str = "abCdEfGhIjKlMnAOpQrStUvWxYz";
  ck_assert_ptr_eq(s21_memchr(str, 'A', 10), memchr(str, 'A', 10));
}
END_TEST

START_TEST(test_s21_memchr_11) {
  char *str = "abCdEfGhIjKlMnAOpQrStUvWxYz";
  ck_assert_ptr_eq(s21_memchr(str, 'A', 26), memchr(str, 'A', 26));
}
END_TEST

START_TEST(test_s21_memchr_12) {
  char *str = "\\\"\'\n\t\?";
  ck_assert_ptr_eq(s21_memchr(str, '\t', 6), memchr(str, '\t', 6));
}
END_TEST

START_TEST(test_s21_memchr_13) {
  char *str = "\\\"\'\n\t\?";
  ck_assert_ptr_eq(s21_memchr(str, '\t', 3), memchr(str, '\t', 3));
}
END_TEST
// -----------------------------------------------------

START_TEST(test_s21_memcmp_1) {
  char *str1 = "Hello";
  char *str2 = "Hello";
  int count = 5;
  ck_assert_int_eq(s21_memcmp(str1, str2, count), memcmp(str1, str2, count));
}
END_TEST

// START_TEST(test_s21_memcmp_2) {
//   char *str1 = "Hello";
//   char *str2 = "Hellu";
//   int count = 5;
//   ck_assert_int_eq(s21_memcmp(str1, str2, count), memcmp(str1, str2, count));
// }
// END_TEST

START_TEST(test_s21_memcmp_3) {
  char *str1 = "Hello";
  char *str2 = "Hello, world!";
  int count = 5;
  ck_assert_int_eq(s21_memcmp(str1, str2, count), memcmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_memcmp_4) {
  char *str1 = "Hello";
  char *str2 = "Hello, world!";
  int count = 5;
  ck_assert_int_eq(s21_memcmp(str1, str2, count), memcmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_memcmp_5) {
  char *str1 = "Hello, world";
  char *str2 = "Hello, friend!";
  int count = 5;
  ck_assert_int_eq(s21_memcmp(str1, str2, count), memcmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_memcmp_6) {
  char *str1 = "Hello";
  char *str2 = "Hello";
  int count = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, count), memcmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_memcmp_7) {
  char *str1 = "";
  char *str2 = "";
  int count = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, count), memcmp(str1, str2, count));
}
END_TEST

START_TEST(test_s21_memcmp_8) {
  char str1[1000];
  char str2[1000];
  for (int i = 0; i < 999; i++) {
    str1[i] = 'H';
  }
  for (int i = 0; i < 999; i++) {
    str2[i] = 'w';
  }
  int count = 1000;
  ck_assert_int_eq(s21_memcmp(str1, str2, count), memcmp(str1, str2, count));
}
END_TEST
// -----------------------------------------------------

START_TEST(test_s21_memcpy_1) {
  char *src = "Hello, world!";
  char my_result[5] = {0};
  char func_result[5] = {0};
  int count = 5;
  s21_memcpy(my_result, src, count);
  memcpy(func_result, src, count);
  ck_assert_mem_eq(my_result, func_result, 5);
}
END_TEST

START_TEST(test_s21_memcpy_2) {
  char *src = "Hello";
  char my_result[5] = {0};
  char func_result[5] = {0};
  int count = 0;
  s21_memcpy(my_result, src, count);
  memcpy(func_result, src, count);
  ck_assert_mem_eq(my_result, func_result, 5);
}
END_TEST


START_TEST(test_s21_memcpy_3) {
  char *src = "Hello";
  char my_result[10] = {0};
  char func_result[10] = {0};
  int count = 5;
  s21_memcpy(my_result, src, count);
  memcpy(func_result, src, count);
  ck_assert_mem_eq(my_result, func_result, 5);
}
END_TEST

START_TEST(test_s21_memcpy_4) {
  char *src = "Hello";
  char my_result[3] = {0};
  char func_result[3] = {0};
  int count = 3;
  s21_memcpy(my_result, src, count);
  memcpy(func_result, src, count);
  ck_assert_mem_eq(my_result, func_result, 3);
}
END_TEST

START_TEST(test_s21_memcpy_5) {
  char src[10] = "Hello";
  char my_result[10] = "Hello";
  char func_result[10] = "Hello";
  int count = 0;
  s21_memcpy(my_result + 2, src, count);
  memcpy(func_result + 2, src, count);
  ck_assert_mem_eq(my_result, func_result, 10);
}
END_TEST

START_TEST(test_s21_memcpy_6) {
  char src[10] = "Hello";
  char my_result[10] = "Hello";
  char func_result[10] = "Hello";
  int count = 3;
  s21_memcpy(my_result + 2, src, count);
  memcpy(func_result + 2, src, count);
  ck_assert_mem_eq(my_result, func_result, 10);
}
END_TEST

START_TEST(test_s21_memcpy_7) {
  char src[10] = "Hello";
  char my_result[10] = "Hello";
  char func_result[10] = "Hello";
  int count = 5;
  s21_memcpy(my_result + 5, src, count);
  memcpy(func_result + 5, src, count);
  ck_assert_mem_eq(my_result, func_result, 10);
}
END_TEST
// -----------------------------------------------------

START_TEST(test_s21_memset_1) {
  char my_result[10] = {0};
  char func_result[10] = {0};
  int count = 1;
  s21_memset(my_result, 'H', count);
  memset(func_result, 'H', count);
  ck_assert_mem_eq(my_result, func_result, 10);
}
END_TEST

START_TEST(test_s21_memset_2) {
  char my_result[10] = {0};
  char func_result[10] = {0};
  int count = 5;
  s21_memset(my_result, 'H', count);
  memset(func_result, 'H', count);
  ck_assert_mem_eq(my_result, func_result, 10);
}
END_TEST

START_TEST(test_s21_memset_3) {
  char my_result[10] = {0};
  char func_result[10] = {0};
  int count = 10;
  s21_memset(my_result, 'w', count);
  memset(func_result, 'w', count);
  ck_assert_mem_eq(my_result, func_result, 10);
}
END_TEST

START_TEST(test_s21_memset_4) {
  char my_result[20] = "Hello, world!";
  char func_result[20] = "Hello, world!";
  int count = 10;
  s21_memset(my_result, 'o', count);
  memset(func_result, 'o', count);
  ck_assert_mem_eq(my_result, func_result, 20);
}
END_TEST

START_TEST(test_s21_memset_5) {
  char my_result[20] = "Hello, world!";
  char func_result[20] = "Hello, world!";
  int count = 5;
  s21_memset(my_result, '\0', count);
  memset(func_result, '\0', count);
  ck_assert_mem_eq(my_result, func_result, 20);
}
END_TEST

START_TEST(test_s21_memset_6) {
  char my_result[20] = "Hello, world!";
  char func_result[20] = "Hello, world!";
  int count = 5;
  s21_memset(my_result, '\n', count);
  memset(func_result, '\n', count);
  ck_assert_mem_eq(my_result, func_result, 20);
}
END_TEST

START_TEST(test_s21_memset_7) {
  char my_result[20] = "Hello,\0 world!";
  char func_result[20] = "Hello,\0 world!";
  int count = 5;
  s21_memset(my_result, '\t', count);
  memset(func_result, '\t', count);
  ck_assert_mem_eq(my_result, func_result, 20);
}
END_TEST

START_TEST(test_s21_memset_8) {
  char my_result[20] = "He\0llo,\0 world!";
  char func_result[20] = "He\0llo,\0 world!";
  int count = 10;
  s21_memset(my_result, '\n', count);
  memset(func_result, '\n', count);
  ck_assert_mem_eq(my_result, func_result, 20);
}
END_TEST

START_TEST(test_s21_memset_9) {
  char my_result[1] = "";
  char func_result[1] = "";
  int count = 0;
  s21_memset(my_result, 'H', count);
  memset(func_result, 'H', count);
  ck_assert_mem_eq(my_result, func_result, 1);
}
END_TEST

START_TEST(test_s21_memset_10) {
  char my_result[20] = "Hello, world!";
  char func_result[20] = "Hello, world!";
  int count = 1;
  s21_memset(&my_result[2], 'A', count);
  memset(&func_result[2], 'A', count);
  ck_assert_mem_eq(my_result, func_result, 20);
}
END_TEST

START_TEST(test_s21_memset_11) {
  char my_result[1000] = {0};
  char func_result[1000] = {0};
  int count = 1000;
  s21_memset(my_result, 'H', count);
  memset(func_result, 'H', count);
  ck_assert_mem_eq(my_result, func_result, 1000);
}
END_TEST

START_TEST(test_s21_memset_12) {
  char my_result[10] = "Hello\0";
  char func_result[10] = "Hello\0";
  int count = 1;
  s21_memset(&my_result[5], '\0', count);
  memset(&func_result[5], '\0', count);
  ck_assert_mem_eq(my_result, func_result, 10);
}
END_TEST

START_TEST(test_s21_memset_13) {
  char my_result[20] = "Hello, world!";
  char func_result[20] = "Hello, world!";
  int count = 12;
  s21_memset(my_result, 'w', count);
  memset(func_result, 'w', count);
  ck_assert_mem_eq(my_result, func_result, 20);
}
END_TEST
// -----------------------------------------------------

START_TEST(test_s21_strncat_1) {
  char *src = "world!";
  char my_result[20] = "Hello, ";
  char func_result[20] = "Hello, ";
  int count = 6;
  s21_strncat(my_result, src, count);
  strncat(func_result, src, count);
  ck_assert_mem_eq(my_result, func_result, 20);
}
END_TEST

START_TEST(test_s21_strncat_2) {
  char *src = "world!";
  char my_result[20] = "Hello, ";
  char func_result[20] = "Hello, ";
  int count = 4;
  s21_strncat(my_result, src, count);
  strncat(func_result, src, count);
  ck_assert_mem_eq(my_result, func_result, 20);
}
END_TEST

START_TEST(test_s21_strncat_3) {
  char *src = "world!";
  char my_result[20] = "Hello, ";
  char func_result[20] = "Hello, ";
  int count = 0;
  s21_strncat(my_result, src, count);
  strncat(func_result, src, count);
  ck_assert_mem_eq(my_result, func_result, 20);
}
END_TEST

START_TEST(test_s21_strncat_4) {
  char *src = "";
  char my_result[20] = "Hello, ";
  char func_result[20] = "Hello, ";
  int count = 6;
  s21_strncat(my_result, src, count);
  strncat(func_result, src, count);
  ck_assert_str_eq(my_result, func_result);
}
END_TEST

START_TEST(test_s21_strncat_5) {
  char *src = "";
  char my_result[20] = "Hello, ";
  char func_result[20] = "Hello, ";
  int count = 0;
  s21_strncat(my_result, src, count);
  strncat(func_result, src, count);

  ck_assert_str_eq(my_result, func_result);
}
END_TEST

START_TEST(test_s21_strncat_6) {
  char *src = "Hello";
  char my_result[20] = "";
  char func_result[20] = "";
  int count = 5;
  s21_strncat(my_result, src, count);
  strncat(func_result, src, count);
  ck_assert_str_eq(my_result, func_result);
}
END_TEST

START_TEST(test_s21_strncat_7) {
  char *src = "Hello, world!";
  char my_result[20] = "Hello, world!";
  char func_result[20] = "Hello, world!";
  int count = 6;
  s21_strncat(my_result, src, count);
  strncat(func_result, src, count);
  ck_assert_str_eq(my_result, func_result);
}
END_TEST

START_TEST(test_s21_strncat_8) {
  char *src = "\\\"\'\n\t\?";
  char my_result[20] = "Hello, ";
  char func_result[20] = "Hello, ";
  int count = 6;
  s21_strncat(my_result, src, count);
  strncat(func_result, src, count);
  ck_assert_str_eq(my_result, func_result);
}
END_TEST

START_TEST(test_s21_strncat_9) {
  char *src = "\0";
  char my_result[20] = "Hello, ";
  char func_result[20] = "Hello, ";
  int count = 1;
  s21_strncat(my_result, src, count);
  strncat(func_result, src, count);
  ck_assert_str_eq(my_result, func_result);
}
END_TEST
// -----------------------------------------------------

START_TEST(test_s21_strchr_1) {
  char *str = "Hello, world!";
  int c = 'H';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_2) {
  char *str = "Hello, world!";
  int c = 'w';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_3) {
  char *str = "Hello, world!";
  int c = '!';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST


START_TEST(test_s21_strchr_4) {
  char *str = "Hello, world!";
  int c = 'q';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_5) {
  char *str = "";
  int c = 'w';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_6) {
  char *str = "Hello, world!";
  int c = '\0';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_7) {
  char *str = "Hello, world!";
  int c = '1';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_8) {
  char *str = "";
  int c = '1';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_9) {
  char *str = "Hello1, world!";
  int c = 1;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_10) {
  char *str = "\0Hello, world!";
  int c = '\0';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_11) {
  char *str = "Hello\n, \tworld!";
  int c = '\t';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST
// -----------------------------------------------------

START_TEST(test_s21_strcspn_1) {
  char *str1 = "Hello, world!";
  char *str2 = "world";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  char *str1 = "Hello, world!";
  char *str2 = "Hello, world!";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  char *str1 = "Hello, world!";
  char *str2 = "qaz";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_4) {
  char *str1 = "Hello, world!";
  char *str2 = "o";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_5) {
  char *str1 = "";
  char *str2 = "word";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_6) {
  char *str1 = "Hello, world!";
  char *str2 = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_7) {
  char *str1 = "\\\"\'\?\n\t";
  char *str2 = "Hello, world!";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_8) {
  char *str1 = "Hello, world!";
  char *str2 = "\\\"\'\?\n\t";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_9) {
  char *str1 = "Hello,\0 world!";
  char *str2 = "world";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_10) {
  char *str1 = "\0";
  char *str2 = "Hello, world!";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_11) {
  char *str1 = "Hello, world!";
  char *str2 = "\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST
// -----------------------------------------------------


int main(void) {
  int failed_count = 0;
  Suite *suite = s21_suite();
  SRunner *suite_runner = srunner_create(suite);
  
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  
  if (failed_count != 0) {
      return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

Suite *s21_suite(void) {
  Suite *suite = suite_create("s21_str");
  
  suite_add_tcase(suite, tcase_s21_strlen());
  suite_add_tcase(suite, tcase_s21_strncpy());
  suite_add_tcase(suite, tcase_s21_strncmp());
  suite_add_tcase(suite, tcase_s21_memchr());
  suite_add_tcase(suite, tcase_s21_memcmp());
  suite_add_tcase(suite, tcase_s21_memset());
  suite_add_tcase(suite, tcase_s21_memcpy());
  suite_add_tcase(suite, tcase_s21_strncat());
  suite_add_tcase(suite, tcase_s21_strchr());
  suite_add_tcase(suite, tcase_s21_strcspn());

  return suite;
}


TCase *tcase_s21_strlen(){
  TCase *tcase_core = tcase_create("test_s21_strlen");
  tcase_add_test(tcase_core, test_s21_strlen_1);
  tcase_add_test(tcase_core, test_s21_strlen_2);
  tcase_add_test(tcase_core, test_s21_strlen_3);
  tcase_add_test(tcase_core, test_s21_strlen_4);
  tcase_add_test(tcase_core, test_s21_strlen_5);
  tcase_add_test(tcase_core, test_s21_strlen_6);
  tcase_add_test(tcase_core, test_s21_strlen_7);
  tcase_add_test(tcase_core, test_s21_strlen_8);
  tcase_add_test(tcase_core, test_s21_strlen_9);
  return tcase_core;
}

TCase *tcase_s21_strncpy(){
  TCase *tcase_core = tcase_create("test_s21_strncpy");
  tcase_add_test(tcase_core, test_s21_strncpy_1);
  tcase_add_test(tcase_core, test_s21_strncpy_2);
  tcase_add_test(tcase_core, test_s21_strncpy_3);
  tcase_add_test(tcase_core, test_s21_strncpy_4);
  tcase_add_test(tcase_core, test_s21_strncpy_5);
  tcase_add_test(tcase_core, test_s21_strncpy_6);
  tcase_add_test(tcase_core, test_s21_strncpy_7);
  return tcase_core;
}

TCase *tcase_s21_strncmp(){
  TCase *tcase_core = tcase_create("test_ss21_strncmp");
  tcase_add_test(tcase_core, test_s21_strncmp_1);
  tcase_add_test(tcase_core, test_s21_strncmp_2);
  tcase_add_test(tcase_core, test_s21_strncmp_3);
  tcase_add_test(tcase_core, test_s21_strncmp_4);
  tcase_add_test(tcase_core, test_s21_strncmp_5);
  tcase_add_test(tcase_core, test_s21_strncmp_6);
  tcase_add_test(tcase_core, test_s21_strncmp_7);
  tcase_add_test(tcase_core, test_s21_strncmp_8);
  tcase_add_test(tcase_core, test_s21_strncmp_9);
  tcase_add_test(tcase_core, test_s21_strncmp_10);
  return tcase_core;
}

TCase *tcase_s21_memchr(void) {
  TCase *tcase_core = tcase_create("s21_memchr");
  tcase_add_test(tcase_core, test_s21_memchr_1);
  tcase_add_test(tcase_core, test_s21_memchr_2);
  tcase_add_test(tcase_core, test_s21_memchr_3);
  tcase_add_test(tcase_core, test_s21_memchr_4);
  tcase_add_test(tcase_core, test_s21_memchr_5);
  tcase_add_test(tcase_core, test_s21_memchr_6);
  tcase_add_test(tcase_core, test_s21_memchr_7);
  tcase_add_test(tcase_core, test_s21_memchr_8);
  tcase_add_test(tcase_core, test_s21_memchr_9);
  tcase_add_test(tcase_core, test_s21_memchr_10);
  tcase_add_test(tcase_core, test_s21_memchr_11);
  tcase_add_test(tcase_core, test_s21_memchr_12);
  tcase_add_test(tcase_core, test_s21_memchr_13);
  return tcase_core;
}

TCase *tcase_s21_memcmp(void) {
  TCase *tcase_core = tcase_create("s21_memcmp");
  tcase_add_test(tcase_core, test_s21_memcmp_1);
  // tcase_add_test(tcase_core, test_s21_memcmp_2);
  tcase_add_test(tcase_core, test_s21_memcmp_3);
  tcase_add_test(tcase_core, test_s21_memcmp_4);
  tcase_add_test(tcase_core, test_s21_memcmp_5);
  tcase_add_test(tcase_core, test_s21_memcmp_6);
  tcase_add_test(tcase_core, test_s21_memcmp_7);
  tcase_add_test(tcase_core, test_s21_memcmp_8);
  return tcase_core;
}

TCase *tcase_s21_memcpy(void) {
  TCase *tcase_core = tcase_create("s21_memcpy");
  tcase_add_test(tcase_core, test_s21_memcpy_1);
  tcase_add_test(tcase_core, test_s21_memcpy_2);
  tcase_add_test(tcase_core, test_s21_memcpy_3);
  tcase_add_test(tcase_core, test_s21_memcpy_4);
  tcase_add_test(tcase_core, test_s21_memcpy_5);
  tcase_add_test(tcase_core, test_s21_memcpy_6);
  tcase_add_test(tcase_core, test_s21_memcpy_7);
  return tcase_core;
}

TCase *tcase_s21_memset(void) {
  TCase *tcase_core = tcase_create("s21_memset");
  tcase_add_test(tcase_core, test_s21_memset_1);
  tcase_add_test(tcase_core, test_s21_memset_2);
  tcase_add_test(tcase_core, test_s21_memset_3);
  tcase_add_test(tcase_core, test_s21_memset_4);
  tcase_add_test(tcase_core, test_s21_memset_5);
  tcase_add_test(tcase_core, test_s21_memset_6);
  tcase_add_test(tcase_core, test_s21_memset_7);
  tcase_add_test(tcase_core, test_s21_memset_8);
  tcase_add_test(tcase_core, test_s21_memset_9);
  tcase_add_test(tcase_core, test_s21_memset_10);
  tcase_add_test(tcase_core, test_s21_memset_11);
  tcase_add_test(tcase_core, test_s21_memset_12);
  tcase_add_test(tcase_core, test_s21_memset_13);
  return tcase_core;
}

TCase *tcase_s21_strncat(void) {
  TCase *tcase_core = tcase_create("s21_strncat");
  tcase_add_test(tcase_core, test_s21_strncat_1);
  tcase_add_test(tcase_core, test_s21_strncat_2);
  tcase_add_test(tcase_core, test_s21_strncat_3);
  tcase_add_test(tcase_core, test_s21_strncat_4);
  tcase_add_test(tcase_core, test_s21_strncat_5);
  tcase_add_test(tcase_core, test_s21_strncat_6);
  tcase_add_test(tcase_core, test_s21_strncat_7);
  tcase_add_test(tcase_core, test_s21_strncat_8);
  tcase_add_test(tcase_core, test_s21_strncat_9);
  return tcase_core;
}

TCase *tcase_s21_strchr(void) {
  TCase *tcase_core = tcase_create("test_s21_strchr");
  tcase_add_test(tcase_core, test_s21_strchr_1);
  tcase_add_test(tcase_core, test_s21_strchr_2);
  tcase_add_test(tcase_core, test_s21_strchr_3);
  tcase_add_test(tcase_core, test_s21_strchr_4);
  tcase_add_test(tcase_core, test_s21_strchr_5);
  tcase_add_test(tcase_core, test_s21_strchr_6);
  tcase_add_test(tcase_core, test_s21_strchr_7);
  tcase_add_test(tcase_core, test_s21_strchr_8);
  tcase_add_test(tcase_core, test_s21_strchr_9);
  tcase_add_test(tcase_core, test_s21_strchr_10);
  tcase_add_test(tcase_core, test_s21_strchr_11);

  return tcase_core;
}

TCase *tcase_s21_strcspn(void) {
  TCase *tcase = tcase_create("test_s21_strcspn");
  tcase_add_test(tcase, test_s21_strcspn_1);
  tcase_add_test(tcase, test_s21_strcspn_2);
  tcase_add_test(tcase, test_s21_strcspn_3);
  tcase_add_test(tcase, test_s21_strcspn_4);
  tcase_add_test(tcase, test_s21_strcspn_5);
  tcase_add_test(tcase, test_s21_strcspn_6);
  tcase_add_test(tcase, test_s21_strcspn_7);
  tcase_add_test(tcase, test_s21_strcspn_8);
  tcase_add_test(tcase, test_s21_strcspn_9);
  tcase_add_test(tcase, test_s21_strcspn_10);
  tcase_add_test(tcase, test_s21_strcspn_11);

  return tcase;
}