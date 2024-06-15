#include <core/error.h>
#include <ctype.h>
#include <module.h>
#include <stdio.h>
#include <stdlib.h>
#include <value.h>
#include <option.h>

Value is_alphabetic(size_t argc, Module *mod, Value *args) {
  ASSERT_FMT(argc == 1, "Expected 1 argument, but got %zu", argc);

  char *str = GET_STRING(args[0]);
  size_t l = strlen(str);
  ASSERT_FMT(l == 1, "Expected 1 character, but got %zu", l);

  char c = str[0];

  return MAKE_INTEGER(isalpha(c));
}

Value is_digit(size_t argc, Module *mod, Value *args) {
  ASSERT_FMT(argc == 1, "Expected 1 argument, but got %zu", argc);

  char *str = GET_STRING(args[0]);
  size_t l = strlen(str);
  ASSERT_FMT(l == 1, "Expected 1 character, but got %zu", l);

  char c = str[0];

  return MAKE_INTEGER(isdigit(c));
}

Value is_alphanumeric(size_t argc, Module *mod, Value *args) {
  ASSERT_FMT(argc == 1, "Expected 1 argument, but got %zu", argc);

  char *str = GET_STRING(args[0]);
  size_t l = strlen(str);
  ASSERT_FMT(l == 1, "Expected 1 character, but got %zu", l);

  char c = str[0];

  return MAKE_INTEGER(isalnum(c));
}

Value is_whitespace(size_t argc, Module *mod, Value *args) {
  ASSERT_FMT(argc == 1, "Expected 1 argument, but got %zu", argc);

  char *str = GET_STRING(args[0]);
  size_t l = strlen(str);
  ASSERT_FMT(l == 1, "Expected 1 character, but got %zu", l);

  char c = str[0];

  return MAKE_INTEGER(isspace(c));
}

Value str_split(size_t argc, Module *mod, Value *args) {
  ASSERT_FMT(argc == 2, "Expected 2 arguments, but got %zu", argc);

  char *str = GET_STRING(args[0]);
  char *delim = GET_STRING(args[1]);

  char *token = strtok(str, delim);
  Value *values = malloc(sizeof(Value) * 100);
  size_t i = 0;

  while (token != NULL) {
    printf("token: %s\n", token);
    values[i] = MAKE_STRING(mod->gc, token);
    token = strtok(NULL, delim);
    i++;
  }

  Value v = MAKE_LIST(mod->gc, values, i);

  return v;
}

Value ffi_to_int(size_t argc, Module *mod, Value *args) {
  ASSERT_FMT(argc == 1, "Expected 1 argument, but got %zu", argc);

  char *str = GET_STRING(args[0]);
  return MAKE_INTEGER(atoi(str));
}

Value str_index(size_t argc, Module *mod, Value *args) {
  ASSERT_FMT(argc == 2, "Expected 2 arguments, but got %zu", argc);

  char *str = GET_STRING(args[0]);
  int index = GET_INT(args[1]);

  if (index < 0 || index >= strlen(str)) {
    return MAKE_NONE(mod->gc);
  }

  return MAKE_SOME(mod->gc, MAKE_STRING(mod->gc, str + index));
}

Value explode(size_t argc, Module *mod, Value *args) {
  ASSERT_FMT(argc == 1, "Expected 1 argument, but got %zu", argc);

  char *str = GET_STRING(args[0]);
  size_t l = strlen(str);
  Value *values = gc_malloc(&mod->gc, sizeof(Value) * l);

  for (size_t i = 0; i < l; i++) {
    char* c = gc_malloc(&mod->gc, 2);
    c[0] = str[i];
    c[1] = '\0';
    values[i] = MAKE_STRING(mod->gc, c);
  }

  Value v = MAKE_LIST(mod->gc, values, l);

  return v;
}