
%{
    #include <stdio.h>

	int yyerror(char * s);
	extern int yylex( );
%}

%token PROGRAM 
%token PROCEDURE 
%token IS 
%token OF 
%token BEGINTEST
%token END 
%token EXIT 
%token IF 
%token THEN 
%token ELSIF 
%token ELSE 
%token WHILE 
%token DO 
%token LOOP 
%token FOR 
%token TO 
%token BY 
%token RETURN 
%token RECORD 
%token TYPE 
%token ID 
%token READ 
%token WRITE
%token STRING 
%token INTEGER 
%token REAL 
%token NOT 
%token VAR 
%token ARRAY
%token MOD 
%token OR_OP 
%token ASSIGN 
%token OPEN_SQ_ANGL 
%token CLOSE_SQ_ANGL 
%token OPEN_BR 
%token CLOSE_BR 
%token OPEN_SQUARE 
%token CLOSE_SQUARE  
%token OPEN_CURLY 
%token CLOSE_CURLY
%token NE_OP 
%token GE_OP 
%token LE_OP 
%token GT_OP 
%token LT_OP 
%token EQ_OP
%token ADD 
%token SUB 
%token MUL 
%token DIV
%token END_OF_INSTRUCTION 
%token COLON 
%token COMMA 
%token DOT
%token AND_OP
%token CONSTANT
%token STRING_LITERAL



%start program

%%

program: PROGRAM IS body END_OF_INSTRUCTION
		 ;
	
body:  declaration_list  BEGINTEST  statement_list END
		;

declaration_list: declaration
				| declaration_list declaration
				;

declaration:  
	| VAR  var-decl 
	| TYPE  type-decl 
	| PROCEDURE  procedure-decl
	;
	
ID_list: ID
	     | ID_list COMMA ID
	     ;

var-decl: simple_assign | var-decl simple_assign
		;

simple_assign: ID_list ASSIGN expression END_OF_INSTRUCTION
				;
	
type-decl: typename IS type END_OF_INSTRUCTION
		;
	
procedure-decl: ID OPEN_BR formal-params CLOSE_BR COLON typename IS body END_OF_INSTRUCTION
		;

type: ARRAY OF typename
	| RECORD component  component  END
	;


typename: ID
		  ;

component: ID COLON typename END_OF_INSTRUCTION
		   ;

fp-section_list: fp-section
					| fp-section_list fp-section
					;

formal-params: OPEN_BR fp-section fp-section_list CLOSE_BR
	| OPEN_BR CLOSE_BR
	;

fp-section: ID COLON typename
			;

statement_list: statement
				| statement_list statement
				| 
				;

statement: lvalue ASSIGN expression END_OF_INSTRUCTION
	| ID actual-params
	| READ OPEN_BR lvalue lvalue_list CLOSE_BR END_OF_INSTRUCTION
	| WRITE write-params END_OF_INSTRUCTION
	| IF expression THEN  statement_list 
	| ELSIF expression THEN  statement_list  
	| ELSE  statement_list  END END_OF_INSTRUCTION
	| WHILE expression DO  statement_list  END END_OF_INSTRUCTION
	| LOOP  statement_list  END END_OF_INSTRUCTION
	| FOR ID ASSIGN expression TO expression DO statement_list END END_OF_INSTRUCTION
	| EXIT END_OF_INSTRUCTION
	| RETURN expression END_OF_INSTRUCTION
	;

write-expr_list: write-expr
				 | write-expr_list COMMA write-expr
				 ;

write-params: OPEN_BR write-expr_list CLOSE_BR
	| OPEN_BR CLOSE_BR
	| OPEN_BR STRING_LITERAL CLOSE_BR
	;

write-expr: STRING_LITERAL
	| expression
	;

expression: number
	| lvalue
	| OPEN_BR expression CLOSE_BR
	| unary-op expression
	| expression binary-op expression
	| typename actual-params
	| typename record-inits
	| typename array-inits
	;

lvalue_list: lvalue
			| lvalue_list lvalue 
			;

lvalue: ID
	| lvalue OPEN_SQUARE expression CLOSE_SQUARE
	| lvalue DOT ID
	;

expression_list: expression
					| expression_list expression
					;

actual-params: OPEN_BR expression expression_list CLOSE_BR
			  | OPEN_BR CLOSE_BR
			  ;

ID-expression_list: ID ASSIGN expression
					| ID-expression_list ID ASSIGN expression
					;
	
record-inits: OPEN_CURLY ID ASSIGN expression ID-expression_list CLOSE_CURLY
			  ;

array-init_list: array-init
				 | array-init_list COMMA array-init
				 ;

array-inits: OPEN_SQ_ANGL array-init_list CLOSE_SQ_ANGL
			 ;

array-init: expression 
			| array-init OF expression
			;

number: CONSTANT
		;
	
	
unary-op: '+' 
	| '-' 
	| NOT
	;

binary-op: ADD 
	| SUB 
	| MUL 
	| DIV 
	| MOD 
	| OR_OP 
	| AND_OP
	| GT_OP 
	| LT_OP
	| EQ_OP 
	| GE_OP 
	| LE_OP 
	| NE_OP
	;
%%

int yyerror(char * s) 
/* yacc error handler */
{    
	printf ( "%s\n", s); 
	return 0;
}  
