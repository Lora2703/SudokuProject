#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sudoku.h"

extern int matr[][N],difficult;

void baseMatr(int matr[][N]) //shaping of the basic matrix
{
	int i,j,k=0,l,tmp1,tmp2,tmp3,n;	
	
	// matrix initialization
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matr[i][j]=j+1;			
		}
	}
	//shift elements of 2nd row by 3 to the left and of 3rd row by 6 to the left
	for(i=1;i<3;i++){
		tmp1=matr[i][0];
		tmp2=matr[i][1];
		tmp3=matr[i][2];
		for(j=0;j<6;j++){
			matr[i][j]=matr[i][j+3];
		}
		matr[i][j]=tmp1;
		matr[i][j+1]=tmp2;
		matr[i][j+2]=tmp3;
		k++;
		if(k==2){
			i--;
		}	
	}	
	copyArea(matr,0); // copying 1st area to 2nd area
	shiftRows(matr,3); // shifting all the row of the 2nd area by 1 to the left
	copyArea(matr,3); // copying 2nd area to 3rd area
	shiftRows(matr,6); // shifting all the row of the 3rd area by 1 to the left	
}

void copyArea(int matr[][N],int n)	//copying one area to another one
{	
	int i,j;
	for(i=n;i<n+3;i++){
		for(j=0;j<N;j++){
			matr[i+3][j]=matr[i][j];
		}
	}
}

void shiftRows(int matr[][N],int n)  //shifting all the row of one area by 1 to the left
{
	int i,j,tmp;
	for(i=n;i<n+3;i++){
		tmp=matr[i][0];
		for(j=0;j<N;j++){
			matr[i][j]=matr[i][j+1];
		}
		matr[i][N-1]=tmp;
	}
}

void shuffleMatr(int matr[][N]) //shuffle basic matrix in random order
{
	int i,n;		

	for(i=0;i<20;i++){
		n=rand()%5;			
		switch (n){
			case 0: transpMatr(matr); break; //transponsing of matrix
			case 1: swapRows(matr); break; //exchanging two rows in one area
			case 2: swapColumns(matr); break; // exchanging two columns in one area
			case 3: swapAreaRows(matr); break; //exchanging two areas horizontally
			case 4: swapAreaColumns(matr); break; //exchanging two areas vertically
		}		
	}	
}

void transpMatr(int matr[][N]) //transponsing of matrix
{
	int i,j,matrt[N][N];
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrt[j][i]=matr[i][j];		
		}	
	}
	copyMatr(matrt,matr);		
}

void choiceRowsOrColumns(int *rowOrColumn1,int *rowOrColumn2,int *area)
{	
	do{
	*rowOrColumn1=rand()%3;
	*rowOrColumn2=rand()%3;
	*area=rand()%3;	
	} while(*rowOrColumn1==*rowOrColumn2);	
}

void swapRows(int matr[][N]) //exchanging two rows in one area
{
	int j,row1,row2,area,tmp;
	
	choiceRowsOrColumns(&row1,&row2,&area);
		
	for(j=0;j<N;j++){
		tmp=matr[row1+3*area][j];
		matr[row1+3*area][j]=matr[row2+3*area][j];
		matr[row2+3*area][j]=tmp;
	}	
}

void swapColumns(int matr[][N]) // exchanging two columns in one area
{
	int i,column1,column2,area,tmp;	
	
	choiceRowsOrColumns(&column1,&column2,&area);

	for(i=0;i<N;i++){
		tmp=matr[i][column1+3*area];
		matr[i][column1+3*area]=matr[i][column2+3*area];
		matr[i][column2+3*area]=tmp;
	}
}

void choiceArea(int *area1,int *area2)
{	
	do{
	*area1=rand()%3;
	*area2=rand()%3;	
	} while(*area1==*area2);	
}

void swapAreaRows(int matr[][N]) //exchanging two areas horizontally
{
	int i,j,area1,area2,tmp;	
	
	choiceArea(&area1,&area2);
	
	for(i=0;i<N/3;i++){
		for(j=0;j<N;j++){
			tmp=matr[area1*3+i][j];
			matr[area1*3+i][j]=matr[area2*3+i][j];
			matr[area2*3+i][j]=tmp;
		}
	}
}

void swapAreaColumns(int matr[][N]) //exchanging two areas vertically
{
	int i,j,area1,area2,tmp;	
	
	choiceArea(&area1,&area2);
	
	for(j=0;j<N/3;j++){
		for(i=0;i<N;i++){
			tmp=matr[i][area1*3+j];
			matr[i][area1*3+j]=matr[i][area2*3+j];
			matr[i][area2*3+j]=tmp;
		}
	}	
}

void delNum(int matr[][N],int difficult) //deleting some numbers using the backtracking algorithm
{
	int i,j,diff=81,tmp,diffexp,solve,matrWiew[N][N]={0},matrSolve[N][N];
	
	switch(difficult){	
		case 1: diffexp=EASY; break;
		case 2: diffexp=MEDIUM; break;
		default: diffexp=COMPLEX; 
	}		
	while(diff>diffexp){				
		i=rand()%9;
		j=rand()%9;

		if(matrWiew[i][j]==0){ //"wiew" matrix. If we didn't look at this position - 0, else 1
			matrWiew[i][j]=1; //look at the position 
			tmp=matr[i][j]; //remember the number from matrix
			matr[i][j]=0; 
			diff--; //increse the difficulty		
			copyMatr(matr,matrSolve);
			solve=solveSudoku(matrSolve,i,j,tmp); //solving Sudoku
			if(solve==1){ //if solving is not the oly one			
				matr[i][j]=tmp;	//return the number to the position		
				diff++;	//decrease the difficulty							
			}			
		}	
	}
}
