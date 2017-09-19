#include "sourceDataManaging.h"



/**************************************FONCTION createCharacterList()**************************************/
pCHARACTER createCharacterList()
{
pCHARACTER pc = (pCHARACTER)malloc(NB_ASCII*sizeof(CHARACTER));
	if(pc != NULL)
	{
	int i;
		for(i=0;i<(NB_ASCII);i++)
			{
			(pc+i)->ascii=i; /*Cf "buildSampleCharacterHeapArray()"*/
			(pc+i)->occurrences=0;
			(pc+i)->codesize=0;
			(pc+i)->code=NULL;
			}
		return pc;
	}
	else
	{
		if(DEBUG) printf("Erreur d'allocation dynamique dans la fonction createCharacterList.\n");
		return NULL;
	}

}
/**********************************************************************************************************/


/**************************************FONCTION countOccurrences*******************************************/

void countOccurrences(pCHARACTER pc,MESSAGE mes)
{
	int i,a;
	int b=strlen(mes);

	for(a=0;a<b;a++)
	{
		for(i=33;i<127;i++)
		{
			if((*(mes+a))==((pc+i)->ascii))
			{
			(pc+i)->occurrences++;
			}
		}
	}
} 
/**********************************************************************************************************/

/************************************** Fonction swapHeapArray ********************************************/

void swapHeapArray (ppCHARACTER array,int first,int second)
{
    pCHARACTER swap;
    swap=array[second];
    array[second]=array[first];
    array[first]=swap;
}

/**********************************************************************************************************/



/************************************** Fonction buildHeapArray *******************************************/

ppCHARACTER buildHeapArray (pCHARACTER list)
{
    ppCHARACTER array = (ppCHARACTER)malloc(NB_ASCII*sizeof(pCHARACTER));
    int i,y;
    for (i=0;i<NB_ASCII;i++)
    {	
	y=i;
        (*(array+i))=(list+i); /*insertion dans un tableau*/
	
		while(y>1 && ((array[y])->occurrences > (array[y-2])->occurrences) )
		{
		swapHeapArray(array,y,y-2);
		y=y-2;
			if(y==1 && ((*(array+1))->occurrences > (*(array))->occurrences) )
			{
			swapHeapArray(array,1,0);
			break;
			}
		}
	
    }
    return array;
}

/**********************************************************************************************************/

/************************************** Fonction sortHeapArray ********************************************/
/*
void sortHeapArray (ppCHARACTER)
{

}
*/



/**********************************************************************************************************/



