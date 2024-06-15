#ifndef OPTION_H
#define OPTION_H

#include <value.h>
#include <stdlib.h>

static inline Value MAKE_NONE(GarbageCollector gc) {
  Value *ls = (Value*) gc_malloc(&gc, sizeof(Value) * 3);
  ls[0] = MAKE_SPECIAL();
  ls[1] = MAKE_STRING(gc, "Option");
  ls[2] = MAKE_STRING(gc, "None");

  return MAKE_LIST(gc, ls, 3);
}

static inline Value MAKE_SOME(GarbageCollector gc, Value value) {
  Value *ls = (Value*) gc_malloc(&gc, sizeof(Value) * 4);
  ls[0] = MAKE_SPECIAL();
  ls[1] = MAKE_STRING(gc, "Option");
  ls[2] = MAKE_STRING(gc, "Some");
  ls[3] = value;
  return MAKE_LIST(gc, ls, 4);
}
#endif // OPTION_H