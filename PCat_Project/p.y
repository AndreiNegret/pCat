
%{
    #include <stdio.h>
	#include "ast.h"

Node* astRoot = NULL;
int yyerror(char * s);
extern int yylex(void);

%}

%union{
	
	Node* node;
	char* strings;
	int intVal;
}

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
%token <strings> ID 
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
%token <intVal> CONSTANT
%token <strings> STRING_LITERAL

%type <node> program
%type <node> body
%type <node> declaration_list
%type <node> declaration
%type <node> ID_list
%type <node> var-decl
%type <node> simple_assign
%type <node> type-decl
%type <node> procedure-decl
%type <node> type
%type <node> typename
%type <node> component
%type <node> fp-section_list
%type <node> formal-params
%type <node> fp-section
%type <node> statement_list
%type <node> statement
%type <node> write-expr_list
%type <node> write-params
%type <node> write-expr 
%type <node> expression
%type <node> lvalue_list
%type <node> lvalue
%type <node> expression_list
%type <node> actual-params
%type <node> ID-expression_list
%type <node> record-inits
%type <node> array-init_list
%type <node> array-inits
%type <node> array-init
%type <node> number
%type <node> unary-op
%type <node> binary-op



%start program

%%

program: PROGRAM IS body END_OF_INSTRUCTION				{ $$ = createProgramNode($3); astRoot = $$; }
		 ;
	
body:  declaration_list  BEGINTEST  statement_list END    { $$ = createBodyNode($1, $3); } 					
		;

declaration_list: declaration							{ $$ = createListNode("Declaration", $1); }
				| declaration_list declaration          { $$ = $1; addLinkToList($$, $2);}
				|										{ $$ = createDeclarationNode(NULL); }
				;

declaration:  
	| VAR  var-decl										{ $$ = createDeclarationNode($2);}			
	| TYPE  type-decl									{ $$ = createDeclarationNode($2);}
	| PROCEDURE  procedure-decl							{ $$ = createDeclarationNode($2);}
	;
	
ID_list: ID                                             { $$ = createIdList($1); }
	     | ID_list COMMA ID								{ $$ = $1; addIdToList($1, $3);}
	     ;

var-decl: simple_assign                                 { $$ = createVarDeclarationList($1); }         
		 | var-decl simple_assign                       { $$ = $1; addLinkToList($1, $2); }     
		;

simple_assign: ID_list ASSIGN expression END_OF_INSTRUCTION       { $$ = createSimpleAssign($1, $3); }
				;
	
type-decl: typename IS type END_OF_INSTRUCTION                    { $$ = createTypeDeclaration($1, $3);}
		;
	
procedure-decl: ID OPEN_BR formal-params CLOSE_BR COLON typename IS body END_OF_INSTRUCTION         { $$ = createProcedureDeclaration($3, $6, $8);}
		;

type: ARRAY OF typename                                 { $$ = createType(NULL, $3, "ARRAY OF");}                 
	| RECORD component  component  END                  { $$ = createType($2, $3, "RECORD");}          	


typename: ID                                            { $$ = createTypename($1);} 
		  ;

component: ID COLON typename END_OF_INSTRUCTION        { $$ = createComponent($3); } 
		   ;

fp-section_list: fp-section                                        { $$ = createListNode("FormalParameter", $1); }
				| fp-section_list fp-section					   { $$ = $1; addLinkToList($$, $2); }
					;

formal-params: OPEN_BR fp-section fp-section_list CLOSE_BR          { $$ = createFormalParameters($2, $3); }  
	| OPEN_BR CLOSE_BR                                              { $$ = createFormalParameters(NULL, NULL); }  
	;

fp-section: ID COLON typename                                       { $$ = createFpSection($3);}  
			;

statement_list: statement                                          { $$ = createListNode("Statement", $1); }
				| statement_list statement						   { $$ = $1; addLinkToList($$, $2);}
				|                                                  { $$ = NULL;}                 
				;

statement: lvalue ASSIGN expression END_OF_INSTRUCTION									{ $$ = createLvalueStatement($1, $3);}           
	| ID actual-params                                                                  { $$ = createIDStatement($1, $2);}                   
	| READ OPEN_BR lvalue lvalue_list CLOSE_BR END_OF_INSTRUCTION                		{ $$ = createReadStatement($3, $4);}
	| WRITE write-params END_OF_INSTRUCTION												{ $$ = createWriteStatement($2);}
	| IF expression THEN  statement_list												{ $$ = createIfStatement($2, $4);}
	| ELSIF expression THEN  statement_list												{ $$ = createElsIfStatement($2, $4);}
	| ELSE  statement_list  END END_OF_INSTRUCTION                                      { $$ = createElseStatement($2);}
	| WHILE expression DO  statement_list  END END_OF_INSTRUCTION                       { $$ = createWhileStatement($2, $4);}
	| LOOP  statement_list  END END_OF_INSTRUCTION                                      { $$ = createLoopStatement($2);}
	| FOR ID ASSIGN expression TO expression DO statement_list END END_OF_INSTRUCTION           { $$ = createForStatement($4, $6, $8);}
	| EXIT END_OF_INSTRUCTION                                                           { $$ = NULL;}
	| RETURN expression END_OF_INSTRUCTION												{ $$ = createReturnStatement($2);}
	;

write-expr_list: write-expr                                       { $$ = createListNode("WriteExpressions", $1); } 
				 | write-expr_list COMMA write-expr               { $$ = $1; addLinkToList($$, $3);} 
				 ;

write-params: OPEN_BR write-expr_list CLOSE_BR                    { $$ = createWriteParameters($2);}  
	| OPEN_BR CLOSE_BR											  { $$ =  NULL;}  
	| OPEN_BR STRING_LITERAL CLOSE_BR                             { $$ = createStringLiteral($2);}        
	;

write-expr: STRING_LITERAL                                        { $$ = NULL;}        
	| expression												  { $$ = createWriteExpressions($1);}  
	;

expression: number                                                { $$ = createNumberExpression($1);}  
	| lvalue													  { $$ = createLvalueExpression($1);}  
	| OPEN_BR expression CLOSE_BR                                 { $$ = createExpression($2);}  
	| unary-op expression										  { $$ = createUnaryExpression($1, $2);} 
	| expression binary-op expression							  { $$ = createBinaryExpression($1, $2, $3);}  
	| typename actual-params									  { $$ = createActualParametersExpression($1, $2);}  
	| typename record-inits                                       { $$ = createRecordInitsExpression($1, $2);}        
	| typename array-inits                                        { $$ = createArrayInitsExpression($1, $2);}        
	;

lvalue_list: lvalue                                               { $$ = createListNode("Lvalues", $1); }  
			| lvalue_list lvalue                                  { $$ = $1; addLinkToList($$, $2);}
			;

lvalue: ID                                                        { $$ = createLvalue($1, NULL, NULL);} 
	| lvalue OPEN_SQUARE expression CLOSE_SQUARE				  { $$ = createLvalue(NULL, $1, $3);} 
	| lvalue DOT ID												  { $$ = createLvalue($3, $1, NULL);}      
	;

expression_list: expression										  { $$ = createListNode("Expressions", $1); }
					| expression_list expression                  { $$ = $1; addLinkToList($$, $2);}
					;

actual-params: OPEN_BR expression expression_list CLOSE_BR        { $$ = createActualParameters($2, $3);} 
			  | OPEN_BR CLOSE_BR								  { $$ = NULL;} 
			  ;

ID-expression_list: ID ASSIGN expression                          { $$ = createListNode("IdentifierExpressions", $3); }
					| ID-expression_list ID ASSIGN expression     { $$ = $1; addLinkToList($$, $4);}
					;
	
record-inits: OPEN_CURLY ID ASSIGN expression ID-expression_list CLOSE_CURLY         { $$ = createRecordInits($2, $4, $5);}   
			  ;

array-init_list: array-init                                       { $$ = createListNode("ArrayInit", $1); }   
				 | array-init_list COMMA array-init               { $$ = $1; addLinkToList($$, $3);}
				 ;												 
																 
array-inits: OPEN_SQ_ANGL array-init_list CLOSE_SQ_ANGL           { $$ = createArrayInits($2);} 
			 ;													 
																 
array-init: expression                                            { $$ = createArrayInit($1, NULL);} 
			| array-init OF expression							  { $$ = createArrayInit($1, $3);} 
			;													 
														 
number: CONSTANT                                             	  { $$ = createNumber($1);}                          
		;												 
														
														 
unary-op: '+'                                                	  {$$ = createUnaryOp("+");}              
	| '-'                                                    	  {$$ = createUnaryOp("-");}            
	| NOT                                                    	  {$$ = createUnaryOp("NOT");}
	;													 
														 
binary-op: ADD                                               	  {$$ = createBinaryOp("ADD");}
	| SUB														  {$$ = createBinaryOp("SUB");}
	| MUL                                                         {$$ = createBinaryOp("MUL");}
	| DIV                                                         {$$ = createBinaryOp("DIV");}
	| MOD                                                         {$$ = createBinaryOp("MOD");}
	| OR_OP                                                       {$$ = createBinaryOp("OR_OP");}
	| AND_OP                                                      {$$ = createBinaryOp("AND_OP");}
	| GT_OP                                                       {$$ = createBinaryOp("GT_OP");}
	| LT_OP                                                       {$$ = createBinaryOp("LT_OP");}
	| EQ_OP                                                       {$$ = createBinaryOp("EQ_OP");}
 	| GE_OP                                                       {$$ = createBinaryOp("GE_OP");} 
	| LE_OP                                                       {$$ = createBinaryOp("LE_OP");}
	| NE_OP                                                       {$$ = createBinaryOp("NE_OP");}
	;
%%

int yyerror(char * s) 
/* yacc error handler */
{    
	printf ( "%s\n", s); 
	return 0;
}  
