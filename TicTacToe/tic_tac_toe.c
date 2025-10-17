#include <stdio.h>
char board[3][3];
void initializeBoard()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}
void printBoard()
{
    printf("\n");
    printf("%c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf("%c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf("%c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;
    return 0;
}
int isDraw()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}
void playGame()
{
    int row, col;
    char currentPlayer = 'X';
    initializeBoard();
    while (1)
    {
        printBoard();
        printf("Player %c, enter row and column (1-3 1-3):", currentPlayer);
        scanf("%d %d", &row, &col);
        if (row < 1 || row > 3 || col < 1 || col > 3)
        {
            printf("Invalid position! Try again.\n");
            continue;
        }
        board[row - 1][col - 1] = currentPlayer;
        if (checkWinner())
        {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        if (isDraw())
        {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}
int main()
{
    printf("===== TIC TAC TOE =====\n");
    playGame();
    return 0;
}