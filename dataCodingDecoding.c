#include "dataCodingDecoding.h"

pTREENODE buildSampleHuffmanTree(void)
{
	CODE cf1 = (CODE)malloc(3*sizeof(char));
	cf1[0]=0;
	cf1[1]=0;
	cf1[2]=0;

	CODE cf2 = (CODE)malloc(3*sizeof(char));
	cf2[0]=0;
	cf2[1]=0;
	cf2[2]=1;

	CODE cf3 = (CODE)malloc(2*sizeof(char));
	cf3[0]=0;
	cf3[1]=1;

	CODE cf4 = (CODE)malloc(2*sizeof(char));
	cf4[0]=1;
	cf4[1]=0;

	CODE cf5 = (CODE)malloc(2*sizeof(char));
	cf5[0]=1;
	cf5[1]=1;

	pCHARACTER pc1 = createCharacter('A',1,3,cf1);
	pCHARACTER pc2 = createCharacter('B',1,3,cf2);
	pCHARACTER pc3 = createCharacter('C',2,2,cf3);
	pCHARACTER pc4 = createCharacter('D',2,2,cf4);
	pCHARACTER pc5 = createCharacter('E',3,2,cf5);
	pCHARACTER pc6 = createCharacter(-1,2,0,NULL);
	pCHARACTER pc7 = createCharacter(-1,4,0,NULL);
	pCHARACTER pc8 = createCharacter(-1,5,0,NULL);
	pCHARACTER pc9 = createCharacter(-1,9,0,NULL);

	pTREENODE ptn1 = createTreeNode(pc1,NULL,NULL,NULL,0,3);
	pTREENODE ptn2 = createTreeNode(pc2,NULL,NULL,NULL,1,3);
	pTREENODE ptn3 = createTreeNode(pc3,NULL,NULL,NULL,1,1);
	pTREENODE ptn4 = createTreeNode(pc4,NULL,NULL,NULL,0,2);
	pTREENODE ptn5 = createTreeNode(pc5,NULL,NULL,NULL,1,2);
	pTREENODE ptn6 = createTreeNode(pc6,NULL,NULL,NULL,0,2);
	pTREENODE ptn7 = createTreeNode(pc7,NULL,NULL,NULL,0,1);
	pTREENODE ptn8 = createTreeNode(pc8,NULL,NULL,NULL,1,1);
	pTREENODE ptn9 = createTreeNode(pc9,NULL,NULL,NULL,-1,0);
	
	ptn9->left=ptn7;
	ptn9->right=ptn8;
	ptn7->father=ptn9;
	ptn7->left=ptn6;
	ptn7->right=ptn3;
	ptn8->father=ptn9;
	ptn8->left=ptn4;
	ptn8->right=ptn5;
	ptn6->father=ptn7;
	ptn6->left=ptn1;
	ptn6->right=ptn2;
	ptn1->father=ptn6;
	ptn2->father=ptn6;
	ptn3->father=ptn7;
	ptn4->father=ptn8;
	ptn5->father=ptn8;
	
	return ptn9;
}

int findCodeRawSizeInBytesSendingMessage(pTREENODE ptn, MESSAGE mes)
{	
	int i;
	int rawsize = 0;
	for(i=0;i<strlen(mes);i++)
	{
			ptn = findTreeNode(ptn , mes[i]);
			rawsize = rawsize + ptn->pc->codesize;
	}
	return rawsize;
}

int partieEntiere(float nb)
{
	int a;
	a = nb;
	return a;
}


int findCodeSizeInBytesSendingMessage(pTREENODE ptn, MESSAGE mes)
{		
		int nbbytes,a;
		int rawsize = findCodeRawSizeInBytesSendingMessage(ptn,mes);
		
		if(rawsize%7 == 0)
		{
			a = rawsize + rawsize/7;
		}
		else
		{
			a = rawsize + partieEntiere(rawsize/7) + 1;
		}
		if(a%8==0)
		{
			nbbytes = a/8;
		}
		else
		{
			nbbytes = partieEntiere(a/8) + 1;
		}
		
return nbbytes;
}

int computeParityBit(char sevenbit)
{
	int i,paritybit;
	int bit = 0;	
	
	for(i=0;i<7;i++)
	{
			if( (sevenbit&(1<<i)) != 0)
			{
				bit = bit+1;
			}
			
	}
	
	if(bit%2 == 0)
	{
		paritybit = 0;
	}
	else
	{
		paritybit = 1;		
	}

return paritybit;
}

CODE messageCoding(pTREENODE ptn,MESSAGE mes)
{

	nbbytes = findCodeSizeInBytesSendingMessage(ptn,mes);
	pTREENODE ptn1;
	int actualcodesize = 0;
	int i,a,b;
	CODE mescode = (CODE)malloc(8*nbbytes*sizeof(char));
	
	for(i=0;i<strlen(mes);i++)
	{
		ptn1 = findTreeNode(ptn,mes[i]);
						/*Cela suppose évidemment de ne pas avoir des codes de plus de 7 bits!*/
		
			for(a=actualcodesize; b<(actualcodesize + (ptn1->pc->codesize));a++)
			{
				mescode[a] = ((*(ptn1->pc->code))+b);
				
					if( (actualcodesize%7 ==0) && (actualcodesize)!=0 )
					{
						mescode[actualcodesize] = computeParityBit();
					}
				b++;
			}
		
			
			
		actualcodesize = actualcodesize + (ptn1->pc->codesize);
		b = 0;
	}


return mescode;
}




















