#include <stdio.h>
#include <stdlib.h>
#define NB_ASCII 128
#define SIZE 100
#define STATUS_OK -1
#define MEMORY_PB -1
#define DEBUG 777


typedef char* MESSAGE;
typedef char* CODE;
typedef struct character CHARACTER;
typedef CHARACTER* pCHARACTER;
typedef pCHARACTER* ppCHARACTER;
typedef struct treeNode TREENODE;
typedef TREENODE* pTREENODE;
typedef struct sortingTreeFifoElement SORTINGTREEFIFOELEMENT;
typedef SORTINGTREEFIFOELEMENT* pSORTINGTREEFIFOELEMENT;
typedef struct sortingTreeFifo SORTINGTREEFIFO;
typedef SORTINGTREEFIFO* pSORTINGTREEFIFO;
typedef struct huffmanTreeLinkedListElement HUFFMANTREELINKEDLISTELEMENT;
typedef HUFFMANTREELINKEDLISTELEMENT* pHUFFMANTREELINKEDLISTELEMENT;
typedef struct huffmanTreeLinkedList HUFFMANTREELINKEDLIST;
typedef HUFFMANTREELINKEDLIST* pHUFFMANTREELINKEDLIST;

/*Given for everyone*/
pCHARACTER createCharacter(char,int,int,char*);
int freeCharacter(pCHARACTER);
int displayCharacter(pCHARACTER);
int displayHeapArray (ppCHARACTER);
ppCHARACTER buildSampleCharacterHeapArray(void);
pTREENODE createTreeNode(pCHARACTER, pTREENODE, pTREENODE, pTREENODE, char, int);
int freeTreeNode(pTREENODE);
pHUFFMANTREELINKEDLISTELEMENT createHuffmanLinkedListElement(pTREENODE);
int freeHuffmanLinkedListElement(pHUFFMANTREELINKEDLISTELEMENT);
pTREENODE findTreeNode(pTREENODE,char);
void showBitsInCode(CODE,int);
/* *************************** */

struct character{
	char ascii;
	int occurrences;
	int codesize;
	char* code;
};

struct treeNode{
	struct character* pc;
	struct treeNode* father;
	struct treeNode* left;
	struct treeNode* right;
	char bit;
	int depth;
};

struct sortingTreeFifoElement{
	struct treeNode* node;
	struct sortingTreeFifoElement* next;
};

struct sortingTreeFifo{
	struct sortingTreeFifoElement* head;
	struct sortingTreeFifoElement* tail;
	int nbElements;
};

struct huffmanTreeLinkedListElement{
	struct treeNode* treenode;
	struct huffmanTreeLinkedListElement* next;
};

struct huffmanTreeLinkedList{
	struct huffmanTreeLinkedListElement* head;
	int nbElements;	
};


