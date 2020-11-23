D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "ast.h"
#include "c.tab.h"

void count();
%}

%%
"/*"			{ comment(); }

"double"		{ count(); return(DOUBLE); }
"else"			{ count(); return(ELSE); }
"float"			{ count(); return(FLOAT); }
"if"			{ count(); return(IF); }
"int"			{ count(); return(INT); }
"long"			{ count(); return(LONG); }
"return"		{ count(); return(RETURN); }
"short"			{ count(); return(SHORT); }
"unsigned"		{ count(); return(UNSIGNED); }
"void"			{ count(); return(VOID); }
"volatile"		{ count(); return(VOLATILE); }
"while"			{ count(); return(WHILE); }

{L}({L}|{D})*		{ count(); yylval.strings = strdup(yytext); return(check_type()); }
0{D}+{IS}?		{ count(); yylval.intVal = atoi(yytext); return(CONSTANT); }
{D}+{IS}?		{ count(); yylval.intVal = atoi(yytext); return(CONSTANT); }
{D}+{E}{FS}?		{ count(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); return(CONSTANT); }

{L}?\"(\\.|[^\\"])*\"	{ count(); return(STRING_LITERAL); }


"="			{ count(); return(ASSIGN); }
"+"			{ count(); return(ADD); }
"-"			{ count(); return(SUBSTRACT); }
";"			{ count(); return (END_OF_INSTRUCTION);}
"("			{count(); return LPARAN;}
")"			{count(); return RPARAN;}
"{"			{count(); return '{';}
"}"			{count(); return '}';}


[ \t\v\n\f]		{ count(); }
.			{ /* ignore bad characters */ }

%%

yywrap()
{
	return(1);
}


comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);
}


int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}


int check_type()
{

	return(IDENTIFIER);
}