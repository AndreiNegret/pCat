#pragma once

#include "ast.h"

#ifndef MAX_SYMBOL_NAME
#define MAX_SYMBOL_NAME 255
#endif // !MAX_SYMBOL_NAME

#ifndef MAX_DATATYPE_NAME
#define MAX_DATATYPE_NAME 127
#endif // !MAX_DATATYPE_NAME

#define MAX_NODE_TYPE 50
#define MAX_EXTRA_DATA 50

/* If variable is local or global */
enum IdentifierScope {
	LOCAL = 0,
	GLOBAL
};

typedef struct symTableEntry {

	char symbolName[MAX_SYMBOL_NAME];
	char dataType[MAX_DATATYPE_NAME];
	int symbolType;
	enum IdentifierScope symbolScope;
	char contextName[MAX_SYMBOL_NAME];
	int numLinks;

}SymTableEntry;

SymTableEntry* symTableEntryList;
unsigned int lengthList;
