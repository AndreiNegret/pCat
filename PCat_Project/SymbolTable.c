#include "SymbolTable.h"


SymTableEntry createDefaultSymTableListNode(char* symbolName,
	char* dataType,
	int symbolType,
	enum IdentifierScope symbolScope,
	char* contextName,
	unsigned int linksCount)
{
	SymTableEntry retSymListNode;

	if (symbolName)
	{
		strcpy(retSymListNode.symbolName, symbolName);
	}
	if (dataType)
	{
		strcpy(retSymListNode.dataType, dataType);
	}
	if (symbolType)
	{
		strcpy(retSymListNode.symbolType, symbolType);
	}
	if (symbolScope)
	{
		strcpy(retSymListNode.symbolScope, symbolScope);
	}
	if (contextName)
	{
		strcpy(retSymListNode.contextName, contextName);
	}

	retSymListNode.numLinks = linksCount;


	return retSymListNode;
}


void insertSymNodeInList(SymTableEntry symNode)
{
	//symTableEntryList = realloc(++lengthList, lengthList * sizeof(SymTableEntry));
	symTableEntryList[lengthList++] = symNode;
}

void createSymListFromTree(Node* ast, int level)
{
	int flagInsert = 0;

	SymTableEntry retSymListNode;
	retSymListNode.symbolType = -1;

	int idx = 0;
	if (ast)
	{
		if (ast->type)
		{
			//strcpy(retSymListNode.symbolName, ast->type);
			if (!strcmp(ast->type, "Identifier")) {
				/* is a VAR */
				strcpy(retSymListNode.symbolName, ast->extraData);
				retSymListNode.symbolType = 0;
				flagInsert = 1;
			}
			if (!strcmp(ast->type, "Type")) {
				/* is a TYPE */
				strcpy(retSymListNode.symbolName, ast->extraData);
				retSymListNode.symbolType = 1;
				flagInsert = 1;
			}
			if (!strcmp(ast->type, "ProcedureDeclaration")) {
				/* is a PROCEDURE */
				strcpy(retSymListNode.symbolName, ast->extraData);
				retSymListNode.symbolType = 2;
				flagInsert = 1;
			}
		}
		if (ast->extraData)
		{
			switch (retSymListNode.symbolType)
			{
			case 0:
				strcpy(retSymListNode.dataType, "VAR");
				break;
			case 1:
				strcpy(retSymListNode.dataType, "TYPE");
				break;
			case 2:
				strcpy(retSymListNode.dataType, "PROCEDURE");
				break;
			default:
				break;
			}
		}

		if (!retSymListNode.symbolType)
		{
			retSymListNode.symbolScope = LOCAL;
		}
		else
		{
			retSymListNode.symbolScope = GLOBAL;
		}
		if (retSymListNode.symbolScope == LOCAL)
		{
			strcpy(retSymListNode.contextName, "Local level");
		}
		else
		{
			strcpy(retSymListNode.contextName, "Global level");
		}


		if (ast->numLinks)
		{
			retSymListNode.numLinks = ast->numLinks;
		}

		if (flagInsert)
		{
			insertSymNodeInList(retSymListNode);
		}
		for (idx = 0; idx < retSymListNode.numLinks; idx++)
		{
			createSymListFromTree(ast->links[idx], level + 1);
		}

	}
}

void printSymNodeList()
{
	int it;
	printf("\n");
	/* Header */

	printf("%-20s %-20s %-15s %-15s %-25s\n",
		"Symbol Name",
		"Data Type",
		"Symbol Type",
		"Symbol Scope",
		"Context Name"
	);

	printf("\n");
	for (it = 0; it < lengthList; it++)
	{
		printf("%-20s %-20s %-15d %-15d %-25s\n",
			symTableEntryList[it].symbolName,
			symTableEntryList[it].dataType,
			symTableEntryList[it].symbolType,
			symTableEntryList[it].symbolScope,
			symTableEntryList[it].contextName
		);
	}
}
