// SimpleCLexer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
//#include "symbols.h"
#include <errno.h>
#include "ast.h"
#include "SymbolTable.h"
extern int yyparse(void);
extern FILE* yyin;
extern int yydebug;
extern Node* astRoot;
extern SymTableEntry* symTableEntryList;


int main()
{
	yydebug = 1;
	yyin = fopen("input.csrc", "rt");
	if (yyin != NULL)
	{
		int result = yyparse();
		switch (result)
		{
		case 0:
			printf("Parse successfull.\n");
			break;

		case 1:
			printf("Invalid input encountered\n");
			break;

		case 2:
			printf("Out of memory\n");
			break;

		default:
			break;
		}
		printAst(astRoot, 0);
		symTableEntryList = malloc(sizeof(SymTableEntry) * 1000);
		createSymListFromTree(astRoot, 0);
		printSymNodeList();
		fclose(yyin);
	}
	else
	{
		printf("Fisier inexistent");
	}


}

