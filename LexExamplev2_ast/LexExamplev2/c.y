
%{
#include <stdio.h>
#include "ast.h"

Node* astRoot = NULL;
int yyerror(char * s);
extern int yylex(void);

%}
%union{
	
	Node	*node;
	char* strings;
	int intVal;
}
%token INT
%token LONG
%token DOUBLE
%token SHORT
%token UNSIGNED
%token VOID
%token VOLATILE
%token WHILE
%token FLOAT
%token IF
%token ELSE
%token RETURN
%token <intVal> CONSTANT
%token STRING_LITERAL
%token ASSIGN
%token ADD
%token SUBSTRACT
%token <strings> IDENTIFIER
%token END_OF_INSTRUCTION
%token LPARAN
%token RPARAN

%type <node> program_unit
%type <node> declaration
%type <node> function_definition
%type <node> type_specifier
%type <node> params_list
%type <node> fun_param
%type <node> var_declaration
%type <node> compound_statement
%type <node> local_declaration_list
%type <node> instructions_list
%type <node> statement


%start program_unit
%%
program_unit
	: declaration	{ $$ = createProgramUnitNode($1); astRoot = $$;}
	| program_unit declaration	{							 
								  $$ = $1; 
								  addLinkToList($$, $2);
								}
	;

declaration
	:function_definition { $$ = createDeclarationNode($1);}
	| var_declaration {$$ = createDeclarationNode($1);}
	;

function_definition
	: type_specifier IDENTIFIER LPARAN params_list RPARAN compound_statement	{ $$ = createFunctionDeclarationNode($1, $2, $4, $6);  }
	;

type_specifier
	: INT																{	$$ = createTypeSpecifier("INT");	}
	| LONG																{$$ = createTypeSpecifier("LONG");}
	| DOUBLE															{$$ = createTypeSpecifier("DOUBLE");}
	| SHORT																{$$ = createTypeSpecifier("SHORT");}
	| UNSIGNED															{$$ = createTypeSpecifier("UNSIGNED");}
	| VOID																{$$ = createTypeSpecifier("VOID");}
	;
	
params_list
	: fun_param															{ $$ = createListNode("ParametersList", $1);}
	| params_list ',' fun_param											{ 
																	      $$ = $1;
																		  addLinkToList($$, $3);
																		}		
	;

fun_param
	: type_specifier IDENTIFIER											{ $$ = createVarDeclaration($1, $2, 0);}
	;

var_declaration
	:type_specifier IDENTIFIER END_OF_INSTRUCTION						{ $$ = createVarDeclaration($1, $2, 0);}
	| type_specifier IDENTIFIER ASSIGN CONSTANT END_OF_INSTRUCTION		{ $$ = createVarDeclaration($1, $2, $4);}
	;

compound_statement
	: '{' '}'															{$$ = createCompoundStatement(NULL, NULL);}
	| '{' local_declaration_list '}'									{$$ = createCompoundStatement($2, NULL);}
	| '{' local_declaration_list instructions_list '}'					{$$ = createCompoundStatement($2, $3);}
	;

local_declaration_list
	: var_declaration													{ $$ = createListNode("LocalDeclarations", $1); }
	| local_declaration_list var_declaration							{
																			$$ = $1;
																			addLinkToList($$, $2);
																		}
	;
instructions_list
	: statement															{ $$ = createListNode("InstructionsList", $1);}
	| instructions_list statement										{
																			$$ = $1;
																			addLinkToList($$, $2);
																		}	
	;

statement
	: IF LPARAN RPARAN compound_statement ELSE compound_statement		{ $$ = createIfStatement("", $4, $6);}
	| IF LPARAN IDENTIFIER RPARAN compound_statement					{ $$ = createIfStatement($3, $5, NULL);}
	
	;
	
%%

int yyerror(char * s) 
/* yacc error handler */
{    
	printf ( "%s\n", s); 
	return 0;
}  