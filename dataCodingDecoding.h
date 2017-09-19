#include "huffmanProject.h"
#include <string.h>
#include <math.h>

pTREENODE buildSampleHuffmanTree(void);
int findCodeRawSizeInBytesSendingMessage(pTREENODE,MESSAGE);
int partieEntiere(float);
int findCodeSizeInBytesSendingMessage(pTREENODE, MESSAGE);
int computeParityBit(char);
CODE messageCoding(pTREENODE,MESSAGE);
