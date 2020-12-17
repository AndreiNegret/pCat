#pragma once
#ifndef __AST_H
#define __AST_H

#define MAX_NODE_TYPE 50
#define MAX_EXTRA_DATA 50

typedef struct node {
	char type[MAX_NODE_TYPE];
	int numLinks;
	char extraData[MAX_EXTRA_DATA];
	struct node** links;
}Node;

Node* createProgramNode(Node* body);
Node* createBodyNode(Node* declarationList, Node* statementList);
Node* createDeclarationNode(Node* declaration);
Node* createVarDeclarationList(Node* varDecl);
Node* createSimpleAssign(Node* idList, Node* expression);
Node* createTypeDeclaration(Node* typename, Node* type);
Node* createProcedureDeclaration(Node* formalParams, Node* typename, Node* body);
Node* createType(Node* component, Node* typename, const char* type);
Node* createTypename(const char* id);
Node* createComponent(Node* typename);
Node* createFormalParameters(Node* fpSection, Node* fpSectionList);
Node* createFpSection(Node* typename);
Node* createLvalueStatement(Node* lvalue, Node* expression);
Node* createIDStatement(const char* id, Node* actualparams);
Node* createIdList(const char* id);
Node* createReadStatement(Node* lvalue, Node* lvaluelist);
Node* createWriteStatement(Node* writeparams);
Node* createIfStatement(Node* expression, Node* statementlist);
Node* createElsIfStatement(Node* expression, Node* statementlist);
Node* createElseStatement(Node* statementlist);
Node* createWhileStatement(Node* expression, Node* statementlist);
Node* createLoopStatement(Node* statementlist);
Node* createForStatement(Node* initExpression, Node* condExpression, Node* statementlist);
Node* createReturnStatement(Node* expression);
Node* createWriteParameters(Node* writeexprlist);
Node* createStringLiteral(const char* StringLiteral);
Node* createWriteExpressions(Node* expression);
Node* createNumberExpression(Node* number);
Node* createLvalueExpression(Node* lvalue);
Node* createExpression(Node* expression);
Node* createUnaryExpression(Node* unaryop, Node* expression);
Node* createBinaryExpression(Node* expression1, Node* binaryop, Node* expression2);
Node* createActualParametersExpression(Node* typename, Node* actualparams);
Node* createRecordInitsExpression(Node* typename, Node* recordinits);
Node* createArrayInitsExpression(Node* typename, Node* arrayinits);
Node* createLvalue(const char* id, Node* lvalue, Node* expression);
Node* createActualParameters(Node* expression, Node* expressionlist);
Node* createRecordInits(const char* id, Node* expression, Node* IdExpressionList);
Node* createArrayInits(Node* arrayinitlist);
Node* createArrayInit(Node* expression, Node* arrayinit);
Node* createNumber(int constant);
Node* createUnaryOp(const char* typeUnaryOp);
Node* createBinaryOp(const char* typeBinaryOp);


Node* createDefaultNode(const char* nodeName, unsigned int linksCount);
Node* resizeNodeLinks(Node* nodeToResize, unsigned int newSize);
Node* createListNode(const char* listName, Node* firstLink);
void addLinkToList(Node* listNode, Node* linkToAdd);
void printAst(Node* ast, int level);
#endif
