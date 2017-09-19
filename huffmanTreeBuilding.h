#include "huffmanProject.h"

pHUFFMANTREELINKEDLIST initHuffmanLinkedList(ppCHARACTER);
void insertElementHuffmanLinkedList(pHUFFMANTREELINKEDLIST,pHUFFMANTREELINKEDLISTELEMENT);
pTREENODE buildHuffmanTree(pHUFFMANTREELINKEDLIST);
void setBitAndDepthTreeNode(pTREENODE,char,int);
void createHuffmanCodes(pTREENODE);
