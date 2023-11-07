#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/*string manipulation*/
int _putchar(char c);
int _strlen(const char *s);
void _puts(char *str);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
char* _strchr(const char* str, int character);

int lineop(ssize_t line, char *input);

ssize_t _getline(char **input, size_t *n, FILE *stream);
char* _getenv(const char* name, char** environ);

void _exits(const char *message);


void exec(char **argv, char **environ);

char *_strtok(char *str, const char *delim);

void _fork(char **argv, char **environ);

void _environ(char **env);

char **parse_input(char *input);

 char *search_in_path(const char *command, char **environ);
#endif
