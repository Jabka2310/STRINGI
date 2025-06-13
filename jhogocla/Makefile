CC = gcc
CFLAGS = -Werror -Wall -Wextra -std=c11

SPRINTF = sprintf

all: $(SPRINTF)

$(SPRINTF): sprintf.c s21_sprintf.h
		$(CC) $(CFLAGS) $< -o $@

clean: rm -f $(SPRINTF)