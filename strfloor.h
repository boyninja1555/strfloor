#ifndef STRFLOOR_H
#define STRFLOOR_H

typedef struct {
    char *cstr;
    size_t length;
    size_t capacity;
} string;

string str(const char *cstr);

const char *str_cstr(string str);

size_t str_length(string str);

int str_insert(string *str, string b, size_t i);

void str_append(string *str, string b);

void str_prepend(string *str, string b);

int str_equals(string a, string b);

void str_free(string *str);

#endif // STRFLOOR_H
