#include <stdio.h>
#include "logic.h"
#include <time.h>

// Project started : 13/04/2024
// Project ended : 

int randint(int x, int y)
{
    srand(time(0));
    // random seed
    int a = (rand() % (y - x + 1)) + x;
    int b = (rand() % (y - x + 1)) + x;
    int c = (rand() % (y - x + 1)) + x;
    // returns a value which is remainder of product of these three divided by (max + 1)
    return (((a * b * c) % (y - x + 1)) + x);
}

int nextTurn(int x)
{
    if (x == 1)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}



int main()
{
    // R = ROOK || P = PAWN || N = KNIGHT || B = BISHOP || K = KING || Q = QUEEN
    char board[10][10] = {
        {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '0'},
        {'8', 'R', 'B', 'N', 'Q', 'K', 'N', 'B', 'R', '8'},
        {'7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '7'},
        {'6', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', '6'},
        {'5', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', '5'},
        {'4', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', '4'},
        {'3', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', '3'},
        {'2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', '2'},
        {'1', 'r', 'b', 'n', 'q', 'k', 'n', 'b', 'r', '1'},
        {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '0'},
    };
    printf("********************\n\n      CHESS      \n  (jayesh warhadi)  \n\n********************\n");
    printf("1. Player Vs Player\n");
    printf("2. Player Vs Computer (PENDING/DISABLED)\n");
    printf("Enter Player 1 name [10 charecters] : ");
    char player1[10];
    scanf("%d", player1);
    while (getchar() != '\n');
    printf("Enter Player 2 name [10 charecters] : ");
    char player2[10];
    scanf("%d", player2);
    while (getchar() != '\n');
    int turn = randint(1, 2);
    while (1)
    {
        printf("Player%d's turn",turn);
        break;
    }
    return 0;
}