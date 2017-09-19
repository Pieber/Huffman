#include "sourceDataManaging.h"



int main(void)
{
	CODE cf1=(CODE)malloc(2*sizeof(char));
	cf1[0]=0;
	cf1[1]=0;

	CODE cf2=(CODE)malloc(2*sizeof(char));
	cf2[0]=0;
	cf2[1]=1;

	CODE cf3=(CODE)malloc(sizeof(char));
	cf3[0]=0;

	pCHARACTER pc1 = createCharacter('A',1,2,cf1);
	pCHARACTER pc2 = createCharacter('B',1,2,cf2);
	pCHARACTER pc3 = createCharacter('C',2,1,cf3);
	pCHARACTER pc4 = createCharacter(-1,2,0,NULL);
	pCHARACTER pc5 = createCharacter(-1,4,0,NULL);

	pTREENODE ptn1 = createTreeNode(pc1,NULL,NULL,NULL,0,2);
	pTREENODE ptn2 = createTreeNode(pc2,NULL,NULL,NULL,1,2);
	pTREENODE ptn3 = createTreeNode(pc3,NULL,NULL,NULL,1,1);
	pTREENODE ptn4 = createTreeNode(pc4,NULL,NULL,NULL,0,1);
	pTREENODE ptn5 = createTreeNode(pc5,NULL,NULL,NULL,-1,0);

	ptn5->left=ptn4;
	ptn5->right=ptn3;
	ptn4->father=ptn5;
	ptn4->left=ptn1;
	ptn4->right=ptn2;
	ptn1->father=ptn4;
	ptn2->father=ptn4;
	ptn3->father=ptn5;

	
	createCharacterList();
	pCHARACTER list = createCharacterList();

	/*Vérification avec la fonction displayCharacter*/

	/*
	int i;
	for(i=0;i<NB_ASCII;i++){displayCharacter(list+i);}*/

	countOccurrences(list,"C'est quand même mieux quand ca marche!");
	/*
	int i;
	for(i=0;i<NB_ASCII;i++){displayCharacter(list+i);}

	*/
	ppCHARACTER tas = buildHeapArray(list);
	
	displayHeapArray(tas);
	


	return 0;
}
