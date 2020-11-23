D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "p.tab.h"

void count();
%}

%%
"/*"			{ comment(); }
"AND"			{ count(); return (AND_OP); }
"ARRAY"			{ count(); return(ARRAY); }
"BEGINTEST"			{ count(); return(BEGINTEST); }
"BY"			{ count(); return(BY); }
"DIV"			{ count(); return(DIV); }
"DO"			{ count(); return(DO); }
"ELSE"			{ count(); return(ELSE); }
"ELSIF"         { count(); return(ELSIF); }
"END"           { count(); return(END); }
"EXIT"          { count(); return(EXIT); }
"IS"            { count(); return(IS); }
"LOOP"          { count(); return(LOOP); }
"MOD"			{ count(); return(MOD); }
"NOT"           { count(); return(NOT); }
"OF"            { count(); return(OF); }
"OR"			{ count(); return(OR_OP); }
"PROCEDURE"     { count(); return(PROCEDURE); }
"PROGRAM"       { count(); return(PROGRAM); }
"READ"          { count(); return(READ); }
"THEN"          { count(); return(THEN); }
"TO"            { count(); return(TO); }
"TYPE"          { count(); return(TYPE); }
"VAR"           { count(); return(VAR); }
"WRITE"         { count(); return(WRITE); }
"FOR"			{ count(); return(FOR); }
"IF"			{ count(); return(IF); }
"RECORD"		{ count(); return(RECORD); }
"RETURN"		{ count(); return(RETURN); }
"WHILE"			{ count(); return(WHILE); }



{L}({L}|{D})*		{ count(); return(check_type()); }

0[xX]{H}+{IS}?		{ count(); return(CONSTANT); }
0{D}+{IS}?		{ count(); return(CONSTANT); }
{D}+{IS}?		{ count(); return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ count(); return(CONSTANT); }

{D}+{E}{FS}?		{ count(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ count(); return(STRING_LITERAL); }


"+"			{ count(); return(ADD); }
"-"			{ count(); return(SUB); }
"*"			{ count(); return(MUL); }  
"/"			{ count(); return(DIV); }
"<="			{ count(); return(LE_OP); }
">="			{ count(); return(GE_OP); }
"<"			    { count(); return(LT_OP); }
">"			    { count(); return(GT_OP); }
"="			    { count(); return(EQ_OP); }
"<>"			{ count(); return(NE_OP); }
";"			{ count(); return (END_OF_INSTRUCTION);}

"("			{ count(); return (OPEN_BR); }
")"			{ count(); return (CLOSE_BR); }
("{"|"<%")		{ count(); return(OPEN_CURLY); }
("}"|"%>")		{ count(); return(CLOSE_CURLY); }
("["|"<:")		{ count(); return(OPEN_SQUARE); }
("]"|":>")		{ count(); return(CLOSE_SQUARE); }
("[<"|"<:")		{ count(); return(OPEN_SQ_ANGL); }
(">]"|":>")		{ count(); return(CLOSE_SQ_ANGL); }

","			{ count(); return(COMMA); }
":"			{ count(); return(COLON); }
":="		{ count(); return(ASSIGN); }
"."			{ count(); return(DOT); }

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
	return(ID);
}