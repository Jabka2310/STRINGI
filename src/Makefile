# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -std=c11 
# TEST_LIBS = -L. -l:s21_string.a -lcheck -lsubunit -pthread -lrt -lm -lgcov

# SRC_DIR = .
# TEST_DIR = ./tests
# REPORT_DIR = ./gcov_report

# SRCS = $(wildcard $(SRC_DIR)/*.c)
# TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
# COVERAGE_INFO = coverage.info

# OBJS = $(SRCS:.c=.o)
# TEST_OBJS = $(TEST_SRCS:.c=.o)

# LIB_TARGET = s21_string.a
# TEST_TARGET = $(TEST_DIR)/run_tests

# all: $(LIB_TARGET)

# $(LIB_TARGET): $(OBJS)
# 	ar rcs $@ $^

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

CC = gcc
CFLAGS = -Werror -Wall -Wextra -std=c11

all: s21_string.a

s21_string.a: s21_string.o
	ar rcs s21_string.a s21_string.o

s21_string.o: s21_strlen.c s21_string.h
	$(CC) $(CFLAGS) -c s21_strlen.c -o s21_string.o

# test: $(LIB_TARGET) $(TEST_OBJS)
# 	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJS) $(TEST_LIBS)
# 	$(TEST_TARGET)

clean:
	rm -rf *.o *.a 

rebuild: clean all