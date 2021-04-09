#include<stdio.h>
#include"sudoku.h"

extern int matr[][N],matrBase[][N],matrSolve[][N],matrt[][N];

void rulesSudoku()
{
	printf("\nRULES OF SOLVING SUDOKU\n\n");		
	printf("1. Only use the numbers from 1 to 9.\n");
	printf("2. Only use each number once in each row, column and nonet (square 3x3).\n");
	printf("3. Avoid trying to guess the solution to the puzzle.\n");
	printf("4. Use the process of elimination as a tactic.\n");
}

void copyMatr(int matr[][N],int matrBase[][N]) 
{
	int i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrBase[i][j]=matr[i][j];
		}
	}	
}

void printMatr(int matr[][N]) //printing of matrix
{
	int i,j,k=0,l=0;
	
	for(i=0;i<(N+4);i++){
		if(i%4==0){
			printf("=============================\n");
			l++;
		}
		else{		
			for(j=0;j<(N+4);j++){
				if(j%4==0){			
					printf(" ! ");
				k++;
				}
				else
					printf("%i ",matr[i-l][j-k]);		
				}
			k=0;
			printf("\n");
		}
	}
}	
