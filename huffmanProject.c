#include "huffmanProject.h"

/* Function createCharacter() : Allocate memory for a CHARACTER which fields are initialised to the input arguments.
 * Input arguments : initialisation arguments for the CHARACTER fields
 * Returns the pointer to the memory allocated CHARACTER.
 */
pCHARACTER createCharacter(char ascii, int occurrences, int codesize, char* code){
	pCHARACTER pc=(pCHARACTER)malloc(sizeof(CHARACTER));
	if(pc!=NULL){
		pc->ascii=ascii;
		pc->occurrences=occurrences;
		pc->codesize=codesize;
		pc->code=code;
		return pc;
	}
	else{
		if(DEBUG) printf("Erreur d'allocation dynamique dans la fonction createCharacter.\n");
		return NULL;
	}
}

/* Function freeCharacter() : free memory allocated for a CHARACTER
 * Input arguments : the pointer to the memory allocated CHARACTER.
 * Returns an error code
 */
int freeCharacter(pCHARACTER pc){
	int error = 0;
	if (pc!=NULL){
		if(pc->code!=NULL){
			free(pc->code);
			pc->code = NULL;
		}
		free(pc);
		return error;
	}else{
		return MEMORY_PB;
	}
}

/* Function displayCharacter() : Display the fields of a CHARACTER given in input argument.
 * Input arguments : CHARACTER to be displayed
 * Returns STATUS_OK if everything is fine, MEMORY_PB if not.
 */
int displayCharacter(pCHARACTER pc){
	int i;
	if(pc!=NULL){
		if(pc->ascii>32 && pc->ascii!=127) printf("ASCII:%c ", pc->ascii);
		else printf("ASCII:%d ", pc->ascii);
		printf("NB:%d ", pc->occurrences);
		printf("CODESIZE:%d ", pc->codesize);
		printf("CODE:");
		if(pc->code!=NULL) for(i=0;i<pc->codesize;i++) printf("%d", *((pc->code)+i));
		else printf("NULL");
		printf("\n");
		return STATUS_OK;
	}
	else{
		if(DEBUG) printf("Erreur de CHARACTER NULL dans la fonction displayCharacter\n.");
		return MEMORY_PB;
	}
}

/* Function displayHeapArray() : Displays a heap array of NB_ASCII pCHARACTER.
 * Input arguments : the array of heap addresses to be displayed
 * Returns void.
 */
int displayHeapArray(ppCHARACTER tas){
	int i,j;
	if(tas!=NULL){
		for(i=0;i<NB_ASCII;i++){
			if((*(tas+i))->ascii!=127 && (*(tas+i))->ascii>32)
				printf("%c %d ",(*(tas+i))->ascii,(*(tas+i))->occurrences);
			else
				printf("%d %d ",(*(tas+i))->ascii,(*(tas+i))->occurrences);
			if((*(tas+i))->codesize>0) {
				printf("%d ",(*(tas+i))->codesize);
				for(j=0;j<(*(tas+i))->codesize;j++) printf("%d",*(((*(tas+i))->code)+((*(tas+i))->codesize-1)-j));
			}
			printf("\n");
		}
		return STATUS_OK;
	}
	else{
		if(DEBUG) printf("Erreur de TAS NULL dans la fonction displayHeapArray.\n");
		return MEMORY_PB;
	}
}

/* Function buildSampleCharacterHeapArray() : Create and fill a heap array of NB_ASCII pCHARACTER. To be used by Part D.
 * Input arguments : void
 * Returns the heap array of addresses created and filled which also gives access to the CHARACTER data structures.
 */
ppCHARACTER buildSampleCharacterHeapArray(void){
	int i;
	pCHARACTER characterList,temp;
	ppCHARACTER heap;
	characterList=(pCHARACTER)malloc(NB_ASCII*sizeof(CHARACTER));
	heap=(ppCHARACTER)malloc(NB_ASCII*sizeof(pCHARACTER));
	for(i=0;i<NB_ASCII;i++){
		(characterList+i)->ascii=i;
		(characterList+i)->occurrences=0;
		(characterList+i)->codesize=0;
		(characterList+i)->code=NULL;
		switch(i){
			case 65 : (characterList+i)->occurrences=1;break; 
			case 66 : (characterList+i)->occurrences=1;break;
			case 67 : (characterList+i)->occurrences=2;break;
			case 68 : (characterList+i)->occurrences=2;break;
			case 69 : (characterList+i)->occurrences=3;break;
			default : (characterList+i)->occurrences=0;break;
		}
		*(heap+i)=characterList+i;
	}
	for(i=0;i<5;i++){
		temp=*(heap+NB_ASCII-5+i);
		*(heap+NB_ASCII-5+i)=*(heap+65+i);
		*(heap+65+i)=temp;
	}
	return heap;
}

/* Function createTreeNode() : Allocate memory for a TREENODE which fields are initialised to the input arguments.
 * Input arguments : initialisation arguments for the TREENODE fields
 * Returns the pointer to the memory allocated TREENODE.
 */
pTREENODE createTreeNode(pCHARACTER pc, pTREENODE f, pTREENODE l, pTREENODE r, char bit, int niveau){
	pTREENODE ptn;
	ptn=(pTREENODE)malloc(sizeof(TREENODE));
	if(ptn!=NULL){
		ptn->pc=pc;
		ptn->father=f;
		ptn->left=l;
		ptn->right=r;
		ptn->bit=bit;
		ptn->depth=niveau;
		return ptn;
	}
	else{
		if(DEBUG) printf("Erreur d'allocation dynamique dans la fonction createTreeNode.\n");
		return NULL;
	}
}
/* Function freeTreeNode() : free memory allocated for a TREENODE.
 * Input arguments : the pointer to the memory allocated TREENODE.
 * Returns an error code.
 */
int freeTreeNode(pTREENODE ptn){
	if(ptn!=NULL){
		ptn->father = NULL;
		ptn->left = NULL;
		ptn->right = NULL;
		if (ptn->pc!=NULL)
		{
		ptn->pc = NULL;
		}
		free(ptn);
		return 0;
	}
	else{
		return MEMORY_PB;
	}
}
/*error |= freeCharacter(ptn->pc); createTreeNode n'est pas createur du caractere donc ce n'est pas a freeTreeNode de l'effacer*/



/* Function createHuffmanLinkedListElement() : Allocate memory for a HUFFMANTREELINKEDLISTELEMENT which fields are initialised to the input arguments.
 * Input arguments : initialisation arguments for the HUFFMANTREELINKEDLISTELEMENT fields
 * Returns the pointer to the memory allocated HUFFMANTREELINKEDLISTELEMENT.
 */
pHUFFMANTREELINKEDLISTELEMENT createHuffmanLinkedListElement(pTREENODE ptn){
	pHUFFMANTREELINKEDLISTELEMENT element;
	element=(pHUFFMANTREELINKEDLISTELEMENT)malloc(sizeof(HUFFMANTREELINKEDLISTELEMENT));
	if(element!=NULL){
		element->treenode=ptn;
		element->next=NULL;
		return element;
	}
	else{
		if(DEBUG) printf("Erreur d'allocation dynamique dans la fonction createHuffmanLinkedListElement.\n");
		return NULL;
	}
}

/* Function freeHuffmanLinkedListElement() : free the memory allocated for a HUFFMANTREELINKEDLISTELEMENT
 * Input arguments : the pointer to the memory allocated HUFFMANTREELINKEDLISTELEMENT.
 * Returns an error code.
 */
int freeHuffmanLinkedListElement(pHUFFMANTREELINKEDLISTELEMENT phtlle){
	int error = 0;
	if(phtlle!=NULL){
		phtlle->next = NULL;
		if (phtlle->treenode!=NULL){
			error |= freeTreeNode(phtlle->treenode);
			phtlle->treenode = NULL;
		}
		free(phtlle);
		return error;
	}else{
		return MEMORY_PB;
	}
}

/* Function findTreeNode() : Search the TREENODE structure associated to the ASCII code given.
 * Input arguments : node from which the search is done and the ASCII code searched.
 * Returns the pointer to the searched TREENODE structure.
 */
pTREENODE findTreeNode(pTREENODE node, char ascii){	
	pTREENODE found=NULL;
	if(node!=NULL){
		if(node->pc!=NULL && node->pc->ascii==ascii) found=node;
		if(found==NULL) found=findTreeNode(node->left,ascii);
		if(found==NULL) found=findTreeNode(node->right,ascii);
	}
	return found;
}

/* Function showBitsInCode() : Shows the bits in a given code associated to a message.
 * Input arguments : the code and its length in bytes.
 * Returns none.
 */
void showBitsInCode(CODE messagecode, int nbbytes){
	int i,j;
	for(i=0;i<nbbytes;i++){
		for(j=7;j>=0;j--){
			printf("%d",(messagecode[i]&(1<<j))>>j);
		}
		printf(" ");
	}
	printf("\n");
	
}
