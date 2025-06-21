# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -std=c11 
TEST_LIBS = -L. -l:s21_string.a -lcheck -lsubunit -pthread -lrt -lm -lgcov


TEST_DIR = ./test


# SRCS = $(wildcard $(SRC_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)

SRC_DIR = .
COVERAGE_INFO = coverage.info
REPORT_DIR = ./gcov_report

# OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

LIB_TARGET = s21_string.a
TEST_TARGET = $(TEST_DIR)/run_tests

# all: $(LIB_TARGET)

# $(LIB_TARGET): $(OBJS)
# 	ar rcs $@ $^

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

CC = gcc
CFLAGS = -Werror -Wall -Wextra -std=c11

all: s21_string.a

s21_string.a: mystring.o
	ar rcs s21_string.a mystring.o

# mystring.o: mystring.c mystring.h
# 	$(CC) $(CFLAGS) -c mystring.c -o mystring.o

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

test: s21_string.a ./test/run_tests.c
#	$(CC) $(CFLAGS) -o test/run_tests ./test/run_tests.c -L. -l:s21_string.a -lcheck -lsubunit -pthread -lrt -lm -lgcov
	$(CC) $(CFLAGS) -o test/run_tests ./test/run_tests.c -L. -l:s21_string.a -lcheck -lm -lsubunit
	./test/run_tests

gcov_report: CFLAGS += --coverage
gcov_report: clean test
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info '*/test/*' --output-file coverage.info
	genhtml coverage.info --output-directory ./gcov_report
	@echo "HTML report generated in ./gcov_report/index.html"

clean:
	rm -rf *.o *.a test/*.o test/*.a

rebuild: clean all