#include "main.h"

char* _getenv(const char* name, char** environ) {
    size_t name_len;
    char** env;

    if (name == NULL || environ == NULL) {
        return NULL;
    }

    name_len = _strlen(name);
    env = environ;

    while (*env != NULL) {
        if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=') {
            return &(*env)[name_len + 1]; /* Return the value after the '=' character */
        }
        ++env;
    }

    return NULL; /* Environment variable not found */
}
