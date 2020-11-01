%{
 /* C declarations used in actions */
%} 

%token PROGRAM PROCEDURE IS OF BEGIN END EXIT 
%token IF THEN ELSIF ELSE WHILE DO LOOP FOR TO BY 
%token RETURN RECORD TYPE ID READ WRITE
%token STRING INTEGER REAL NOT VAR ARRAY
%token MOD OR AND ASSIGN OPEN_SQ_ANGL CLOSE_SQ_ANGL OPEN_BR CLOSE_BR OPEN_SQUARE CLOSE_SQUARE OPEN_CURLY CLOSE_CURLY
%token NE_OP GE_OP LE_OP GT_OP LT_OP EQ_OP
%token ADD SUB MUL DIV

%start program

%%
program: PROGRAM IS body ';'
	
body:  declaration  BEGIN  statement END

declaration:  VAR  var-decl 
	| TYPE  type-decl 
	| PROCEDURE  procedure-decl 
	
var-decl: ID ASSIGN expression ';' 
	
type-decl: typename IS type ';'
	
procedure-decl: ID OPEN_BR formal-params CLOSE_BR IS body ';'

type: ARRAY OF typename
	| RECORD component  component  END

typename: ID

component: ID ':' typename ';'

formal-params: OPEN_BR fp-section CLOSE_BR
	| OPEN_BR CLOSE_BR

fp-section: ID ':' typename

statement: lvalue ASSIGN expression ';'
	| ID actual-params
	| READ OPEN_BR lvalue CLOSE_BR ';'
	| WRITE write-params ';'
	| IF expression THEN  statement 
	| ELSIF expression THEN  statement  
	| ELSE  statement  END ';'
	| WHILE expression DO  statement  END ';'
	| LOOP  statement  END ';'
	| FOR ID ASSIGN expression TO expression DO statement END ';'
	| EXIT ';'
	| RETURN expression ';'

write-params: OPEN_BR write-expr ',' write-expr CLOSE_BR
	| OPEN_BR CLOSE_BR

write-expr: STRING
	| expression

expression: number
	| lvalue
	| OPEN_BR expression CLOSE_BR
	| unary-op expression
	| binary-op expression
	| typename actual-params
	| typename record-inits
	| typename array-inits

lvalue: ID
	| lvalue OPEN_SQUARE expression CLOSE_SQUARE
	| lvalue '.' ID

actual-params: OPEN_BR expression CLOSE_BR ',' expression CLOSE_BR
	| OPEN_BR CLOSE_BR
	
	
record-inits: OPEN_CURLY ID ASSIGN expression ';' ID ASSIGN expression  CLOSE_CURLY


array-inits: OPEN_SQ_ANGL array-init ',' array-init   CLOSE_SQ_ANGL

array-init: expression OF expression

number: INTEGER 
	| REAL
	
unary-op: '+' 
	| '-' 
	| NOT

binary-op: ADD 
	| SUB 
	| MUL 
	| DIV 
	| MOD 
	| OR 
	| AND
	| GT_OP 
	| LT_OP
	| EQ_OP 
	| GE_OP 
	| LE_OP 
	| NE_OP
%%

#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
 
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
 