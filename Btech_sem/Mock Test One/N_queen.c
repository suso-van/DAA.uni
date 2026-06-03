#include<stdio.h>

int solutionCount = 0;

void printBoard(int board[10][10], int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {     
             printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int board[10][10], int row, int col, int N)
{
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return 0;   
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return 0;
    return 1;
}

void solveNQUtil(int board[10][10], int col, int N)
{
    if (col >= N) {
        solutionCount++;
        printf("Solution #%d:\n", solutionCount);
        printBoard(board, N);
        printf("\n");
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            solveNQUtil(board, col + 1, N);
            board[i][col] = 0; 
        }
    }
}

void solveNQ(int N)
{
    int board[10][10] = { 0 };
    solutionCount = 0;
    solveNQUtil(board, 0, N);
    
    if (solutionCount == 0) {
        printf("No solution exists for %d Queens\n", N);
        return;
    }
    printf("Total solutions for %d-Queens: %d\n", N, solutionCount);
}

int main()
{    int N;
    printf("N-Queens Problem\n");
    printf("Enter the number of queens: ");
    scanf("%d", &N);
    solveNQ(N);
    return 0;
}