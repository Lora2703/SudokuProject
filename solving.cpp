#include"sudoku.h"

extern int matr[][N],matrSolve[][N];

int checkMatr(int matr[][N],int row,int col,int num) //checking if the number present in the row, column or square 3x3
{
	int i,j,startRow,startCol;
	
	for (j=0;j<N;j++){	//checking in the row
		if(matr[row][j]==num)
		return 0;
	}	
	
	for(i=0;i<N;i++){	//checking in the column
		if(matr[i][col]==num)
		return 0;
	}	
	
	startRow=row-row%3; //checking in the square 3x3
	startCol=col-col%3;
	for(i=0;i<3;i++){	
		for(j=0;j<3;j++){		
			if(matr[i+startRow][j+startCol]==num)
			return 0;
		}
	}	
	return 1;
}

int solveSudoku(int matr[][N],int row,int col,int tmp) //solving Sudoku
{
	int num;
	if(row==N-1&&col==N) //checking the end of the matrix
		return 1;
	
	if(col==N){ //cheking the end of the row 
		row++;
		col=0;
	}
	if(matr[row][col]>0){ //if the current position contain a number>0 we go to the next column 
		return solveSudoku(matr,row,col+1,tmp);
	}
	for(num=1;num<=N;num++){ //choose the numbers from 1 to 9
		if(num==tmp) continue;
		else{				
			if(checkMatr(matr,row,col,num)==1){	//if the number don't present in the row, column and square	
				matr[row][col]=num;	//assigne the number to the position
				if(solveSudoku(matr,row,col+1,tmp)==1) //check the next column		
					return 1;
			}
		}
		matr[row][col]=0; //if the number was wrong we remove it and check the next number
	}
	return 0;
}

