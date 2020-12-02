#include "ast.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>
Node* createDefaultNode(const char* nodeName, unsigned int linksCount)
{
	Node* retNode = (Node*)malloc(sizeof(Node));
	if (retNode)
	{
		memset(retNode, 0, sizeof(Node));
		if (nodeName)
		{
			strcpy(retNode->type, nodeName);
		}
		retNode->numLinks = linksCount;
		if (linksCount > 0)
		{
			retNode->links = (Node**)malloc(linksCount * sizeof(Node*));
		}
	}
	return retNode;
}

Node* resizeNodeLinks(Node* nodeToResize, unsigned int newSize)
{
	if (nodeToResize->numLinks == 0)
	{
		nodeToResize->links = (Node**)malloc(newSize*sizeof(Node*));		
	}
	else
	{
		nodeToResize->links = (Node**)realloc(nodeToResize->links, newSize * sizeof(Node*));
	}
	nodeToResize->numLinks = newSize;
	return nodeToResize;
}

Node* createListNode(const char* listName, Node* firstLink)
{
	Node* retNode = createDefaultNode(listName, 1);
	retNode->links[0] = firstLink;
	return retNode;
}
void addLinkToList(Node* listNode, Node* linkToAdd)
{
	unsigned int numLinks = listNode->numLinks;	
	resizeNodeLinks(listNode, numLinks + 1);
	listNode->links[numLinks] = linkToAdd;
}

Node* createProgramNode(Node* body)
{
	Node* retNode = createDefaultNode("Program", 1);
	if (retNode)
	{
		retNode->links[0] = body;
	}

	return retNode;

}

Node* createBodyNode(Node* declarationList, Node* statementList)
{
	Node* retNode = createDefaultNode("Body", 2);
	if (retNode)
	{
		retNode->links[0] = declarationList;
		retNode->links[1] = statementList;
	}

	return retNode;

}


Node* createDeclarationNode(const char* identifier, Node* declaration)
{
	Node* retNode = createDefaultNode("Declaration", 1);
	
	if (retNode)
	{
		retNode->links[0] = declaration;
	}

	return retNode;
}

Node* createVarDeclaration(Node* varDecl, Node* simpleAssign)
{
	Node* retNode = createDefaultNode("VariableDeclaration", 2);

	if (retNode)
	{
		retNode->links[0] = varDecl;	
		retNode->links[1] = simpleAssign;
	}

	return retNode;

}

Node* createSimpleAssign(Node* idList, const char* assign, Node* expression)
{
	Node* retNode = createDefaultNode("SimpleAssign", 2);
	
	if (retNode)
	{
		retNode->links[0] = idList;
		retNode->links[1] = expression;
	}

	return retNode;

}

Node* createTypeDeclaration(Node* typeDecl, const char* token, Node* type)
{
	Node* retNode = createDefaultNode("TypeDeclaration", 2);

	if (retNode)
	{
		retNode->links[0] = typeDecl;
		retNode->links[1] = type;
	}

	return retNode;

}

Node* createProcedureDeclaration(Node* formalParams, Node* typename, Node* body)
{
	Node* retNode = createDefaultNode("ProcedureDeclaration", 3);

	if (retNode)
	{
		retNode->links[0] = formalParams;
		retNode->links[1] = typename;
		retNode->links[2] = body;
	}

	return retNode;

}

Node* createType(Node* component, Node* typename)
{
	Node* retNode = createDefaultNode("Type", 2);

	if (retNode)
	{
		retNode->links[0] = component;
		retNode->links[1] = typename;
	}

	return retNode;

}

Node* createTypename(const char* id)
{
	Node* retVal = createDefaultNode("TypeName", 0);
	
	if (id)
		sprintf(retVal->extraData, "%s", id);
	
	return retVal;
}

Node* createComponent(const char* id, Node* typename)
{
	Node* retNode = createDefaultNode("Component", 1);

	if (retNode)
	{
		retNode->links[0] = typename;
		if (id)
			sprintf(retNode->extraData, "%s", id);
	}

	return retNode;
}


Node* createFormalParameters(Node* fpSection, Node* fpSectionList)
{
	Node* retNode = createDefaultNode("FormalParameters", 2);

	if (retNode)
	{
		retNode->links[0] = fpSection;
		retNode->links[1] = fpSectionList;
	}

	return retNode;
}

Node* createFpSection(const char* id, Node* typename)
{
	Node* retNode = createDefaultNode("FpSection", 1);

	if (retNode)
	{
		retNode->links[0] = typename;
		if (id)
			sprintf(retNode->extraData, "%s", id);
	}

	return retNode;
}

Node* createStatementList(Node* emptyStatement)
{
	Node* retNode = createDefaultNode("EmptyStatement", 0);

	return retNode;
}

//Node* createIfStatement(const char* identifierName, Node* thenStatement, Node* elseStatement) 
//{
//
//	Node* retNode = createDefaultNode("IfStatement", 2);
//	retNode->links[0] = thenStatement;
//	retNode->links[1] = elseStatement;
//	if (identifierName)
//		sprintf(retNode->extraData, "%s", identifierName);
//	return retNode;
//}
//
//
//Node* createWriteStatement(const char* writeparameters)
//{
//
//	Node* retNode = createDefaultNode("WriteStatement", 1);
//	retNode->links[0] = writeparameters;
//
//	if (writeparameters)
//		sprintf(retNode->extraData, "%s", writeparameters);
//	return retNode;
//}
//
//Node* createNumber(const char* typeNumber)
//{
//	Node* retVal = createDefaultNode("Number", 0);
//	if (typeNumber)
//		sprintf(retVal->extraData, "%s", typeNumber);
//	return retVal;
//}
//
//Node* createUnaryOp(const char* typeUnaryOp)
//{
//	Node* retVal = createDefaultNode("UnaryOp", 0);
//	if (typeUnaryOp)
//		sprintf(retVal->extraData, "%s", typeUnaryOp);
//	return retVal;
//}
//
//Node* createBinaryOp(const char* typeBinaryOp)
//{
//	Node* retVal = createDefaultNode("BinaryOp", 0);
//	if (typeBinaryOp)
//	sprintf(retVal->extraData, "%s", typeBinaryOp);
//	return retVal;
//}

void printAst(Node* ast, int level)
{
	int idx = 0;
	if (ast)
	{
		for (idx = 0; idx < level; idx++)
		{
			printf(" ");
		}
		if (ast->type)
		{
			printf("%s ", ast->type);
		}
		if (ast->numLinks)
		{
			printf(" - %d - %s\n", ast->numLinks, ast->extraData);
		}
		else
		{
			printf(" - %s\n",  ast->extraData);
		}
		for (idx = 0; idx < ast->numLinks; idx++)
		{
			
			printAst(ast->links[idx], level + 1);			
		}
	}
}
