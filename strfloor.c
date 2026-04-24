#include <stdlib.h>
#include <string.h>
#include "strfloor.h"

string str(const char *cstr) {
    const size_t length = strlen(cstr);
    const size_t capacity = length;
    char *buf = malloc(capacity + 1);
    if (!buf) return (string){0};

    memcpy(buf, cstr, length + 1);
    return (string){
        .cstr = buf,
        .length = length,
        .capacity = capacity,
    };
}

const char *str_cstr(const string str) {
    return str.cstr;
}

size_t str_length(const string str) {
    return str.length;
}

int str_insert(string *str, const string b, const size_t i) {
    if (str->capacity == 0) str->capacity = 1;
    if (str->length + b.length > str->capacity) {
        while (str->length + b.length > str->capacity) str->capacity *= 2;
        char *tmp = realloc(str->cstr, str->capacity + 1);
        if (!tmp) return 1;
        str->cstr = tmp;
    }

    if (i > str->length) return 1;
    for (size_t j = str->length; j > i; j--) str->cstr[j + b.length - 1] = str->cstr[j - 1];
    for (size_t j = 0; j < b.length; j++) str->cstr[i + j] = b.cstr[j];
    str->length += b.length;
    str->cstr[str->length] = '\0';
    return 0;
}

void str_append(string *str, const string b) {
    str_insert(str, b, str_length(*str));
}

void str_prepend(string *str, const string b) {
    str_insert(str, b, 0);
}

int str_equals(const string a, const string b) {
    return strcmp(str_cstr(a), str_cstr(b)) == 0;
}

void str_free(string *str) {
    free(str->cstr);
    str->cstr = NULL;
    str->length = 0;
    str->capacity = 0;
}
