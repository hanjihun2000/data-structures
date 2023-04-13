#ifndef SYMTAB_H_INCLUDED
#define SYMTAB_H_INCLUDED
#include <stdbool.h>

typedef struct symtabCDT* symtabADT;
// Define funtion pointer type.
typedef void (*symtabFnT)(char*, void*);

symtabADT getEmptySymtab(void);
void enter(symtabADT table, char* key, void* value);
void* lookup(symtabADT table, char* key);
bool isSymtabEmpty(symtabADT table);
void forEachEntryDo(symtabFnT f, symtabADT table);

#endif // SYMTAB_H_INCLUDED
