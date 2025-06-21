#include <check.h>
#include <string.h>

#include "../mystring.h"

START_TEST(test_s21_strlen_1) {
  const char str[10] = "abcdef";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_2) {
  const char str[10] = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_3) {
  const char str[40] = "abcdef\nasasd\nasdasdasd\nasdasd!";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_4) {
  char str[10000];
  memset(str, 'a', sizeof(str));
  str[sizeof(str) - 1] = '\0';
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_5) {
  const char str[1000] = "a";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_6) {
  const char str[] = "Hello\0World";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_7) {
  const char str[] = "Hello\t\n\r\f\v\a\\\"\'\?";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_8) {
  const char str[100] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_9) {
  const char str[] = {0};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_10) {
  const char str[] = "Hello\u00C5World";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

TCase *tcase_s21_strlen(void) {
  TCase *tcase = tcase_create("s21_strlen");
  tcase_add_test(tcase, test_s21_strlen_1);
  tcase_add_test(tcase, test_s21_strlen_2);
  tcase_add_test(tcase, test_s21_strlen_3);
  tcase_add_test(tcase, test_s21_strlen_4);
  tcase_add_test(tcase, test_s21_strlen_5);
  tcase_add_test(tcase, test_s21_strlen_6);
  tcase_add_test(tcase, test_s21_strlen_7);
  tcase_add_test(tcase, test_s21_strlen_8);
  tcase_add_test(tcase, test_s21_strlen_9);
  tcase_add_test(tcase, test_s21_strlen_10);

  return tcase;
}