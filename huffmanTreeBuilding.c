#include "huffmanTreeBuilding.h"


pHUFFMANTREELINKEDLIST initHuffmanLinkedList(ppCHARACTER heap)
{
	pHUFFMANTREELINKEDLIST phll = (pHUFFMANTREELINKEDLIST)malloc(sizeof(HUFFMANTREELINKEDLIST));
			
			int i,k;
			int a=0;
			int nbElements=0;
			for(i=0;i<NB_ASCII;i++)
			{
					if(heap[i]->occurrences!=0)
					{
							nbElements++;
					}
			}
			
			phll->nbElements = nbElements;
			
	pHUFFMANTREELINKEDLISTELEMENT phlle = (pHUFFMANTREELINKEDLISTELEMENT)malloc(nbElements*sizeof(HUFFMANTREELINKEDLISTELEMENT));
			
			for(k=0;k<NB_ASCII;k++)
			{		
					if( ((heap[k]->occurrences) != 0) && (a==0) )
					{
						phll->head = phlle;	
						phlle[0].treenode = createTreeNode(heap[k],NULL,NULL,NULL,0,0);
						phlle[0].next=(phlle+1);
						a++;
					}
					else if((heap[k]->occurrences != 0) && (a < (nbElements-1)) )
					{
						
						phlle[a].treenode = createTreeNode(heap[k],NULL,NULL,NULL,0,0);
						phlle[a].next = (phlle+a+1);
						a++;
						
					}
					else
					{
						phlle[a].treenode = createTreeNode(heap[k],NULL,NULL,NULL,0,0);
						phlle[a].next = NULL;
					}
					
			}
return phll;
}


void insertElementHuffmanLinkedList(pHUFFMANTREELINKEDLIST phll, pHUFFMANTREELINKEDLISTELEMENT phlle)
{
		phll->nbElements++;
		int valocc = (phlle->treenode->pc->occurrences);
		pHUFFMANTREELINKEDLISTELEMENT pElement = phll->head;
		pHUFFMANTREELINKEDLISTELEMENT pElementprecedent;
			while(1==1)
			{
				if((pElement->treenode->pc->occurrences) > valocc )
				{
					phlle->next=pElement;
					
					if(pElement == (phll->head))
					{
						(phll->head) = phlle;
						break;
					}
					else
					{
						pElementprecedent = phlle;
						break;
					}
					
					
					
				}
				else if(pElement->next == NULL)
				{
					pElement->next = phlle->next;
					phlle->next = NULL;
					break;
				}
				else
				{	
					pElementprecedent = pElement;
					pElement = (pElement->next);
					break;
				}
			}
}
 
/*
pTREENODE buildHuffmanTree(pHUFFMANTREELINKEDLIST phll)
{
		int nbElements = phll->nbElements;
		pCHARACTER pc1 = createCharacter(0,0,0,NULL);
		pTREENODE ptn = NULL;
		
		pHUFFMANTREELINKEDLISTELEMENT phlle1 = NULL;
		pHUFFMANTREELINKEDLISTELEMENT phlle2 = NULL;
		
		int i;
			while(nbElements > 1)
			{
				pc1->occurrences = ((phll->head->treenode->pc->occurrences) + (phll->head->next->treenode->pc->occurrences));
				ptn = createTreeNode(pc1,NULL,phll->head->treenode,phll->head->next->treenode,0,0);
				phlle1 = phll->head;
				phlle2 = phll->head->next;
				phll->head = (phll->head->next->next);
				free(phlle1);
				free(phlle2);
				pHUFFMANTREELINKEDLISTELEMENT phlle = (pHUFFMANTREELINKEDLISTELEMENT)malloc(sizeof(HUFFMANTREELINKEDLISTELEMENT));
				phlle->treenode = ptn;
				insertElementHuffmanLinkedList(phll,phlle);
				phll->nbElements--;
				
			}
return ptn;
}*/

void setBitAndDepthTreeNode(pTREENODE ptn,char bit,int depth) /*Les arguments 2 et 3 de la fonction sont inutiles.*/
{	
	pTREENODE ptn1 = ptn;
	int a=0;
	while((ptn1->father) != NULL)
	{
		ptn1 = ptn1->father;
		a++;
	}
	ptn->depth=a;
	if((ptn->father) == NULL)
	{
		ptn->bit=-1;
		ptn->depth=0;
	}
	
	else
	{
		if(ptn->father->left == ptn)
		{
			ptn->bit=0;
		}
		else
		{
			ptn->bit=1;
		}
	}
}
/*
void createHuffmanCodes(pTREENODE ptn)
{
	
}
*/










