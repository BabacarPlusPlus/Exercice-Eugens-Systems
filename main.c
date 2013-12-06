/*********************************************************************************
1) Ecrire une recherche linéaire dans un tableau d'entiers.
int* LinearSearch(int* values, size_t count, int itemToFind); 

2) Ecrire une recherche linéaire à l'envers dans un tableau d'entiers.
int* ReverseLinearSearch(int* values, size_t count, int itemToFind); 

3) Ecrire une recherche dichotomique dans un tableau d'entiers.
Quelle est la précondition sur les données pour pouvoir appeler cette fonction?
int* BinarySearch(int* values, size_t count, int itemToFind);

***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>


int* LinearSearch( int* values, size_t count, int itemToFind)
{
	int i;
	for(i=0;i<count;i++)
	{
		if(values[i]==itemToFind)
			return &values[i];
	}
	return NULL;
}

int* ReverseLinearSearch( int* values, size_t count, int itemToFind)
{
	int i;
	for(i=count-1;i>=0;i--)
	{
		if(values[i]==itemToFind)
			return &values[i];
	}
	return NULL;
}


int* BinarySearch( int* values, size_t count, int itemToFind)
{
	int begin=0,mid,find=0,end=count;
	
	do{
		mid=abs((begin+end)/2);

		if(values[mid]==itemToFind)
		{
			find=1;
		}
		else {

			if(values[mid]>itemToFind) 
			{
				end=mid-1;				
			}
			else{
				begin=mid+1;
			} 
		}
	}while((!find)&&(begin<=end));
	
	if(find)
		return &values[mid];
	else return NULL;
}


int main(int argc, char *argv[])
{

    int array[10]={2,8,7,12,5,6,9,12,8,5};

	printf("\nLinearSearch pour l'entier 5, adresse :%p\n",LinearSearch( array,10,5));
	printf("ReverseLinearSearch pour l'entier 5, adresse :%p\n\n",ReverseLinearSearch( array, 10,5));

	printf("LinearSearch pour l'entier 8, adresse :%p\n",LinearSearch( array,10,8));
	printf("ReverseLinearSearch pour l'entier 8, adresse :%p\n\n",ReverseLinearSearch( array, 10,8));

	printf("LinearSearch pour l'entier 10, adresse :%p\n",LinearSearch( array,10,10));
	printf("ReverseLinearSearch pour l'entier 10, adresse :%p\n\n",ReverseLinearSearch( array, 10,10));

	printf("LinearSearch pour l'entier 6, adresse :%p\n",LinearSearch( array,10,6));
	printf("ReverseLinearSearch pour l'entier 6, adresse :%p\n\n",ReverseLinearSearch( array, 10,6));

	printf("\nSi les adresses sont différentes c'est qu'il y à plusieurs occurences\n");
	/*
		Quelle est la précondition sur les données pour pouvoir appeler cette fonction?

		Pour appliquer un algorithme qui procède avec une approche dichotomique il faut que la structure de donnée
		sur laquelle on travail sois triée (croissante ou décroissante).
	*/
	int arraySorted[14]={2,4,6,8,9,10,11,12,15,32,58,98,112,113};
	printf("\n BinarySearch pour l'entier 2, adresse :  %p\n",BinarySearch( arraySorted, 14,2));    
	printf("BinarySearch pour l'entier 12, adresse :  %p\n",BinarySearch( arraySorted, 14,12));  
	printf("BinarySearch pour l'entier 16, adresse :  %p\n",BinarySearch( arraySorted, 14,16));  
	printf("BinarySearch pour l'entier 112, adresse :  %p\n",BinarySearch( arraySorted, 14,112));  

    return 0;
}

