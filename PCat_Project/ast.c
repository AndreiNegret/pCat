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


Node* createDeclarationNode(Node* declaration)
{
	Node* retNode = createDefaultNode("Declaration", 1);
	
	if (retNode)
	{
		retNode->links[0] = declaration;
	}

	return retNode;
}

Node* createVarDeclarationList(Node* varDecl)
{
	Node* retNode = createDefaultNode("VariableDeclarationList", 1);

	if (retNode)
	{
		retNode->links[0] = varDecl;	
	}

	return retNode;

}


Node* createIdList(const char* id)
{
	Node* retNode = createDefaultNode("IdList", 1);

	if (retNode)
	{
		if (id)
		{
			retNode->links[0] = createDefaultNode("Identifier", 0);
			sprintf(retNode->links[0]->extraData, "%s", id);
		}
	}

	return retNode;

}

void addIdToList(Node* IdList, const char* Id)
{
	Node* newNode = createDefaultNode("Identifier", 0);

	if (newNode)
	{
		sprintf(newNode->extraData, "%s", Id);
	}

	addLinkToList(IdList, newNode);
}


Node* createSimpleAssign(Node* idList, Node* expression)
{
	Node* retNode = createDefaultNode("SimpleAssign", 2);
	
	if (retNode)
	{
		retNode->links[0] = idList;
		retNode->links[1] = expression;
	}

	return retNode;

}

Node* createTypeDeclaration(Node* typename, Node* type)
{
	Node* retNode = createDefaultNode("TypeDeclaration", 2);

	if (retNode)
	{
		retNode->links[0] = typename;
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

Node* createType(Node* component, Node* typename, const char* type)
{
	Node* retNode = createDefaultNode("Type", 2);

	if (retNode)
	{
		retNode->links[0] = component;
		retNode->links[1] = typename;
		sprintf(retNode->extraData, "%s", type);
	}

	return retNode;

}

Node* createTypename(const char* id)
{
	Node* retVal = createDefaultNode("TypeName", 0);
	
	if (id)
	{
		sprintf(retVal->extraData, "%s", id);
	}
	
	return retVal;
}

Node* createComponent(Node* typename)
{
	Node* retNode = createDefaultNode("Component", 1);

	if (retNode)
	{
		retNode->links[0] = typename;
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

Node* createFpSection(Node* typename)
{
	Node* retNode = createDefaultNode("FpSection", 1);

	if (retNode)
	{
		retNode->links[0] = typename;
	}

	return retNode;
}


Node* createLvalueStatement(Node* lvalue, Node* expression) 
{
	Node* retNode = createDefaultNode("LvalueStatement", 2);

	if (retNode)
	{
		retNode->links[0] = lvalue;
		retNode->links[1] = expression;
	}

	return retNode;
}

Node* createIDStatement(const char* id, Node* actualparams)
{
	Node* retNode = createDefaultNode("IDStatement", 1);

	if (retNode)
	{
		retNode->links[0] = actualparams;
		if (id)
			sprintf(retNode->extraData, "%s", id);
	}
	return retNode;
}

Node* createReadStatement(Node* lvalue, Node* lvaluelist)
{
	Node* retNode = createDefaultNode("ReadStatement", 2);

	if (retNode)
	{
		retNode->links[0] = lvalue;
		retNode->links[1] = lvaluelist;
	}

	return retNode;
}

Node* createWriteStatement(Node* writeparams)
{

	Node* retNode = createDefaultNode("WriteStatement", 1);

	if (retNode)
	{
		retNode->links[0] = writeparams;
	}
	return retNode;
}

Node* createIfStatement(Node* expression, Node* statementlist)
{
	Node* retNode = createDefaultNode("IfStatement", 2);

	if (retNode)
	{
		retNode->links[0] = expression;
		retNode->links[1] = statementlist;
	}

	return retNode;
}

Node* createElsIfStatement(Node* expression, Node* statementlist)
{
	Node* retNode = createDefaultNode("ElsIfStatement", 2);

	if (retNode)
	{
		retNode->links[0] = expression;
		retNode->links[1] = statementlist;
	}

	return retNode;
}

Node* createElseStatement(Node* statementlist )
{
	Node* retNode = createDefaultNode("ElseStatement", 1);

	if (retNode)
	{
		retNode->links[0] = statementlist;
	}

	return retNode;
}

Node* createWhileStatement(Node* expression, Node* statementlist)
{
	Node* retNode = createDefaultNode("WhileStatement", 2);

	if (retNode)
	{
		retNode->links[0] = expression;
		retNode->links[1] = statementlist;
	}

	return retNode;
}

Node* createLoopStatement(Node* statementlist)
{
	Node* retNode = createDefaultNode("LoopStatement", 1);

	if (retNode)
	{
		retNode->links[0] = statementlist;
	}

	return retNode;
}

Node* createForStatement(Node* initExpression, Node* condExpression, Node* statementlist)
{
	Node* retNode = createDefaultNode("ForStatement", 3);

	if (retNode)
	{
		retNode->links[0] = initExpression;
		retNode->links[1] = condExpression;
		retNode->links[2] = statementlist;
	}

	return retNode;
}


Node* createReturnStatement(Node* expression)
{
	Node* retNode = createDefaultNode("ReturnStatement", 1);

	if (retNode)
	{
		retNode->links[0] = expression;
	}

	return retNode;
}

Node* createWriteParameters(Node* writeexprlist)  
{
	Node* retNode = createDefaultNode("WriteParameters", 1);

	if (retNode)
	{
		retNode->links[0] = writeexprlist;
	}

	return retNode;
}

Node* createStringLiteral(const char* StringLiteral)
{
	Node* retVal = createDefaultNode("StringLiteral", 0);

	if (retVal)
	{
		sprintf(retVal->extraData, "%s", StringLiteral);
	}

	return retVal;
}


Node* createWriteExpressions(Node* expression)
{
	Node* retNode = createDefaultNode("WriteExpressions", 1);

	if (retNode)
	{
		retNode->links[0] = expression;
	}

	return retNode;
}


Node* createNumberExpression(Node* number)
{
	Node* retNode = createDefaultNode("NumberExpression", 1);

	if (retNode)
	{
		retNode->links[0] = number;
	}

	return retNode;
	
}

Node* createLvalueExpression(Node* lvalue)
{
	Node* retNode = createDefaultNode("LvalueExpression", 1);  

	if (retNode)
	{
		retNode->links[0] = lvalue;
	}

	return retNode;

}

Node* createExpression(Node* expression)      
{
	Node* retNode = createDefaultNode("Expression", 1);

	if (retNode)
	{
		retNode->links[0] = expression;
	}

	return retNode;

}

Node* createUnaryExpression(Node* unaryop, Node* expression)
{
	Node* retNode = createDefaultNode("UnaryExpression", 2);

	if (retNode)
	{
		retNode->links[0] = unaryop;
		retNode->links[1] = expression;
	}

	return retNode;

}

Node* createBinaryExpression(Node* expression1, Node* binaryop, Node* expression2)  
{
	Node* retNode = createDefaultNode("BinaryExpression", 3);

	if (retNode)
	{
		retNode->links[0] = expression1;
		retNode->links[1] = binaryop;
		retNode->links[2] = expression2;
	}

	return retNode;

}

Node* createActualParametersExpression(Node* typename, Node* actualparams)
{
	Node* retNode = createDefaultNode("ActualParameters", 2);

	if (retNode)
	{
		retNode->links[0] = typename;
		retNode->links[1] = actualparams;
	}

	return retNode;

}

Node* createRecordInitsExpression(Node* typename, Node* recordinits)
{
	Node* retNode = createDefaultNode("RecordInits", 2);

	if (retNode)
	{
		retNode->links[0] = typename;
		retNode->links[1] = recordinits;
	}

	return retNode;

}

Node* createArrayInitsExpression(Node* typename, Node* arrayinits)
{
	Node* retNode = createDefaultNode("ArrayInits", 2);

	if (retNode)
	{
		retNode->links[0] = typename;
		retNode->links[1] = arrayinits;
	}

	return retNode;

}

Node* createLvalue(const char* id, Node* lvalue, Node* expression)
{
	Node* retNode = createDefaultNode("Lvalue", 2);

	if (retNode)
	{
		retNode->links[0] = lvalue;
		retNode->links[1] = expression;
		if (id)
			sprintf(retNode->extraData, "%s", id);
	}

	return retNode;

}

Node* createActualParameters(Node* expression, Node* expressionlist)    
{
	Node* retNode = createDefaultNode("ActualParameters", 2);

	if (retNode)
	{
		retNode->links[0] = expression;
		retNode->links[1] = expressionlist;
	}

	return retNode;

}

Node* createRecordInits(const char* id, Node* expression, Node* IdExpressionList)
{
	Node* retNode = createDefaultNode("RecordInits", 2);

	if (retNode)
	{
		retNode->links[0] = expression;
		retNode->links[1] = IdExpressionList;
		if (id)
			sprintf(retNode->extraData, "%s", id);
	}

	return retNode;

}

Node* createArrayInits(Node* arrayinitlist)     
{
	Node* retNode = createDefaultNode("ArrayInits", 1);

	if (retNode)
	{
		retNode->links[0] = arrayinitlist;
	}

	return retNode;

}

Node* createArrayInit(Node* expression, Node* arrayinit) 
{
	Node* retNode = createDefaultNode("ArrayInit", 2);

	if (retNode)
	{
		retNode->links[0] = expression;
		retNode->links[1] = arrayinit;
	}

	return retNode;

}

Node* createNumber(int constant) 
{
	Node* retVal = createDefaultNode("Number", 0);

	if (retVal)
	{
		sprintf(retVal->extraData, "%d", constant);
	}

	return retVal;

}



Node* createUnaryOp(const char* typeUnaryOp)
{
	Node* retNode = createDefaultNode("UnaryOp", 0);
	if (typeUnaryOp)
		sprintf(retNode->extraData, "%s", typeUnaryOp);
	return retNode;
}

Node* createBinaryOp(const char* typeBinaryOp)
{
	Node* retNode = createDefaultNode("BinaryOp", 0);
	if (typeBinaryOp)
	sprintf(retNode->extraData, "%s", typeBinaryOp);
	return retNode;
}

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
