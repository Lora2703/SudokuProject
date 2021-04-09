#define N 9
#define EASY 35
#define MEDIUM 30
#define COMPLEX 25

void baseMatr(int matr[][N]);
void copyArea(int matr[][N],int n);
void shiftRows(int matr[][N],int n);
void shuffleMatr(int matr[][N]);
void transpMatr(int matr[][N]);
void swapRows(int matr[][N]);
void swapColumns(int matr[][N]);
void swapAreaRows(int matr[][N]);
void swapAreaColumns(int matr[][N]);
void copyMatr(int matr[][N],int matrBase[][N]);
void delNum(int matr[][N],int difficult);
void printMatr(int matr[][N]);
int checkMatr(int matr[][N],int row,int col,int num);
int solveSudoku(int matr[][N],int row,int col,int tmp);
void choiceRowsOrColumns(int *rowOrColumn1,int *rowOrColumn2,int *area);
void choiceArea(int *area1,int *area2);
void rulesSudoku();
