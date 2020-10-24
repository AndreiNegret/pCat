// SimpleCLexer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "symbols.h"
#include <errno.h>

extern FILE* yyin;
extern int yylex(void);
const char* lexUnits[] = {  
							"END",
							"ARRAY",
							"BEGIN",
							"BY",
							"DO",
							"ELSE",
							"ELSIF",
							"EXIT",
							"WHILE",
							"IS",
							"IF",
							"LOOP",
							"RETURN",
							"NOT",
							"OF",
							"PROCEDURE",
							"PROGRAM",
							"READ",
							"THEN",
							"FOR",
							"TO",
							"TYPE",
							"VAR",
							"WRITE",
							"RECORD",
							"CONSTANT",
							"STRING_LITERAL",
							"ADD",
							"SUB",
							"MUL",
							"DIV",
							"MOD",
							"OR_OP",
							"LE_OP",
							"GE_OP",
							"LT_OP",
							"GT_OP",
							"EQ_OP",
							"NE_OP",
							"AND_OP",
							"OPEN_BR",
							"CLOSE_BR",
							"OPEN_CURLY",
							"CLOSE_CURLY",
							"OPEN_SQUARE",
							"CLOSE_SQUARE",
							"OPEN_SQ_ANGL",
							"CLOSE_SQ_ANGL",
							"COMMA",
							"COLON",
							"ASSIGN",
							"DOT",
							"IDENTIFIER",
							"END_OF_INSTRUCTION"};

int main()
{
	int tokenValue = 0;
	yyin = fopen("input.csrc", "rt");
	if (yyin != NULL)
	{
		while ((tokenValue = yylex()) != END)
		{
			printf(" -> TOKEN ID: %d; Token Value: %s \n", tokenValue, lexUnits[tokenValue]);
		}
	}
	else
	{
		printf("Fisierul de intrare nu poate fi deschis. Erorare: %d", errno);
	}


}

