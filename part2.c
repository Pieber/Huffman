#include "huffmanTreeBuilding.h"
int main(void)
{	
	pCHARACTER pc1 = createCharacter('A',2,0,NULL);
	pCHARACTER pc2 = createCharacter('B',1,0,NULL);

	pTREENODE ptna = createTreeNode(pc1,NULL,NULL,NULL,-1,0);
	pTREENODE ptnb = createTreeNode(pc2,NULL,NULL,NULL,-1,0);

	pHUFFMANTREELINKEDLISTELEMENT phtlla = createHuffmanLinkedListElement(ptna);
	pHUFFMANTREELINKEDLISTELEMENT phtllb = createHuffmanLinkedListElement(ptnb);

	phtlla->next = phtllb;
	
	(phtlla->treenode)->left = (phtllb->treenode);
	(phtllb->treenode)->father = phtlla->treenode;

	ppCHARACTER heap = buildSampleCharacterHeapArray();
	printf("%p",heap);
	displayHeapArray(heap);

	pHUFFMANTREELINKEDLIST phll = initHuffmanLinkedList(heap);
	printf("%p\n",phll);
	
	pHUFFMANTREELINKEDLISTELEMENT phlle3 = NULL;
	pCHARACTER pc3 = createCharacter('i',2,0,NULL);
	HUFFMANTREELINKEDLISTELEMENT hlle3;
	hlle3.treenode = createTreeNode(pc3,NULL,NULL,NULL,-1,0);
	hlle3.next = NULL;
	phlle3 = &hlle3;
	insertElementHuffmanLinkedList(phll,phlle3);

	

return 0;
}
