// LexExamplev2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "ast.h"
//#include "symbols.h"
//extern int yylex(void);
extern int yyparse(void);
extern FILE* yyin;
extern int yydebug;
extern Node* astRoot;

//char* symbols[] = {
//	"END",
//							"INT",
//							"LONG",
//							"DOUBLE",
//							"SHORT",
//							"UNSIGNED",
//							"VOID",
//							"VOLATILE",
//							"WHILE",
//							"FLOAT",
//							"IF",
//							"ELSE",
//							"RETURN",
//							"CONSTANT",
//							"STRING_LITERAL",
//							"ASSIGN",
//							"ADD",
//							"SUBSTRACT",
//							"IDENTIFIER",
//							"END_OF_INSTRUCTION"
//
//};
int main()
{
	
	//yydebug = 1;
	yyin = fopen("input.csrc","rt");
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
		fclose(yyin);
	}
	else
	{
		printf("Fisier inexistent");
	}

}
