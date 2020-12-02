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
Node* createDeclarationNode(const char* identifier, Node* declaration);
Node* createVarDeclaration(Node* varDecl, Node* simpleAssign);
Node* createSimpleAssign(Node* idList, const char* assign, Node* expression);
Node* createTypeDeclaration(Node* typeDecl, const char* token, Node* type);
Node* createProcedureDeclaration(Node* formalParams, Node* typename, Node* body);
Node* createType(Node* component, Node* typename);
Node* createTypename(const char* id);
Node* createComponent(const char* id, Node* typename);
Node* createFormalParameters(Node* fpSection, Node* fpSectionList);
Node* createFpSection(const char* id, Node* typename);
Node* createStatementList(Node* emptyStatement);

Node* createDefaultNode(const char* nodeName, unsigned int linksCount);
Node* resizeNodeLinks(Node* nodeToResize, unsigned int newSize);
Node* createListNode(const char* listName, Node* firstLink);
void addLinkToList(Node* listNode, Node* linkToAdd);
void printAst(Node* ast, int level);
#endif
