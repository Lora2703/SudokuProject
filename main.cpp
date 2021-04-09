#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include"sudoku.h"

int main()
{	
	int matr[N][N],matrBase[N][N],difficult,i,j,n;
	char key;
	
	srand(time(0));	
	
	printf("     xxxx      xx     xx   xxxxxx        xxxxx     xx     xx   xx     xx\n");
	printf("   xxx   xxx   xx     xx   xx   xx      xx   xx    xx    xx    xx     xx\n");
	printf("  xxx          xx     xx   xx    xx    xx     xx   xx   xx     xx     xx\n");
	printf("    xxxx       xx     xx   xx     xx   xx     xx   xxxxxx      xx     xx\n");
	printf("        xxx    xx     xx   xx     xx   xx     xx   xxxxxx      xx     xx\n");
	printf("          xxx  xx     xx   xx    xx    xx     xx   xx   xx     xx     xx\n");
	printf("   xxx   xxx    xxx xxx    xx   xx      xx   xx    xx    xx     xxx xxx\n");
	printf("     xxxx        xxxxx     xxxxxx        xxxxx     xx     xx     xxxxx\n");
	
	do{			
		printf("\n\nIf you want to generate Sudoku - press G,\nto solve Sudoku - press S,\nto read rules - press R: ");	
		key=getch();
		printf("%c\n",key);		
		if(key=='G'||key=='g'){	//generation Sudoku	
			baseMatr(matr); //shaping of the basic matrix			
			shuffleMatr(matr); //shuffle basic matrix in random order
			copyMatr(matr,matrBase); //coping basic matrix for printing after deleting numbers
			do{			
				printf("\n\nInput expected difficulty (easy - 1, medium - 2, complex - 3): ");
				key=getch();
				printf("%c\n",key);			
				if(key=='1'||key=='2'||key=='3'){
					difficult=key-'0';					
					break;
				}	
				else{				
					printf("\nEntered symbol is wrong\n");
				}		
			}while(key!='1'&&key!='2'&&key!='3');			
			delNum(matr,difficult); //deleting some numbers from matrix
			printf("Generated Sudoku\n");
			printMatr(matr);
			printf("For printing original matrix input Y, for exit - input any key: ");
			key=getch();
			printf("%c\n",key);
			if(key=='Y'||key=='y'){
				printf("Original matrix\n");
				printMatr(matrBase);
			}
		}
		else{		
			if(key=='S'||key=='s'){ //solving given Sudoku
				for(i=0;i<N;i++){
					printf("\nInput %i row: ",i+1);	
					for(j=0;j<N;j++){
						do{
							key=getch();
						}while(key<'0'||key>'9');
						printf("%c ",key);
						matr[i][j]=key-'0';
					}						
				}
				printf("\nGiven Sudoku\n");
				printMatr(matr);
				n=solveSudoku(matr,0,0,0);
				if(n==1){
					printf("\nSolved Sudoku\n");
					printMatr(matr);
				}
				else{
					printf("\nNo solution");
				}				
			}
			else{
				if(key=='R'||key=='r'){
					rulesSudoku();
				}
				else{
					printf("\nEntered symbol is wrong\n");
				}
			}
		}
			printf("\nDo you want to leave the game? Press ESC to exit, any key to continue: ");
			key=getch();
			printf("%c\n",key);
		} while(key!=27);		
	return 0;
}
