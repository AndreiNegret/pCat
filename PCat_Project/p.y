
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
%token STRING_LITERAL

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
				;

declaration:  
	| VAR  var-decl										{ $$ = createDeclarationNode("VAR", $2);}			
	| TYPE  type-decl									{ $$ = createDeclarationNode("TYPE", $2);}
	| PROCEDURE  procedure-decl							{ $$ = createDeclarationNode("PROCEDURE", $2);}
	;
	
ID_list: ID                                             { $$ = createListNode("Identifier", $1); }
	     | ID_list COMMA ID								{ $$ = $1; addLinkToList($$, $3);}
	     ;

var-decl: simple_assign                                 { $$ = createVarDeclaration($1, NULL); }         
		 | var-decl simple_assign                       { $$ = createVarDeclaration($1, $2); }     
		;

simple_assign: ID_list ASSIGN expression END_OF_INSTRUCTION       { $$ = createSimpleAssign($1, "ASSIGN", $3); }
				;
	
type-decl: typename IS type END_OF_INSTRUCTION                    { $$ = createTypeDeclaration($1, "IS", $3);}
		;
	
procedure-decl: ID OPEN_BR formal-params CLOSE_BR COLON typename IS body END_OF_INSTRUCTION         { $$ = createProcedureDeclaration($3, $6, $8);}
		;

type: ARRAY OF typename                                 { $$ = createType(NULL, $3);}                 
	| RECORD component  component  END                  { $$ = createType($2, $3);}          	


typename: ID                                            { $$ = createTypename("ID");} 
		  ;

component: ID COLON typename END_OF_INSTRUCTION        { $$ = createComponent("ID", $3); } 
		   ;

fp-section_list: fp-section                                        { $$ = createListNode("FormalParameter", $1); }
				| fp-section_list fp-section					   { $$ = $1; addLinkToList($$, $2); }
					;

formal-params: OPEN_BR fp-section fp-section_list CLOSE_BR          { $$ = createFormalParameters($2, $3); }  
	| OPEN_BR CLOSE_BR                                              { $$ = createFormalParameters(NULL, NULL); }  
	;

fp-section: ID COLON typename                                       { $$ = createFpSection("ID", $3);}  
			;

statement_list: statement                                          { $$ = createListNode("Statement", $1); }
				| statement_list statement						   { $$ = $1; addLinkToList($$, $2);}
				|                                                  { $$ = createStatementList(NULL);}                 
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
