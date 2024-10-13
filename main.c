#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int piecNumber = 1;
char board[8][8];
char playerTurn; //will hold 'b' or 'r' for whoevers turn in currently is
//add [] to board
//Functions
char makeBoard(char even, char odd, int outIt, int inIt);
void printBoard();
void turn();
void getUserInput();

//Main function
int main() {
    //Sets black to have the first turn
    playerTurn = 'b';
    //Sets ups the board with pieces in place
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            //0, 2, 4, 6 rows
            if(i % 2 == 0) {
                
                if((i == 6)) {
                    makeBoard('r', '2', i, j);
                }else if ((i==0)||(i==2)) {
                    makeBoard('b', '2', i, j);
                }else {
                    makeBoard('1', '2', i, j);
                }
            // 1, 3, 5, 7 rows
             }else {
                if((i == 7)||(i == 5)) {
                    makeBoard('2', 'r', i, j);
                }else if(i==1) {
                    makeBoard('2', 'b', i, j);
                }else {
                    makeBoard('2', '1', i, j);
                }
             }        
        }
        // r == 72
        // b == 62
        printf("\n");
    }
    printf("\n");
    printBoard();
    turn();
}

char makeBoard(char even, char odd, int outIt, int inIt) {
    if(inIt % 2 == 0) {
        if(inIt != 7) {
            board[outIt][inIt] = odd;
            printf("%c  ", board[outIt][inIt]);
        }else {
             board[outIt][inIt] = odd;
            printf("%c", board[outIt][inIt]);
        }
    }else {
        if(inIt != 7) {
            board[outIt][inIt] = even;
            printf("%c  ", board[outIt][inIt]);
        }else {
            board[outIt][inIt] = even;
            printf("%c", board[outIt][inIt]);
        }
    }
}

void printBoard() //for printing the board after every turn (we can add the graphics corresponding to values of the board later)
{
    printf("   a  b  c  d  e  f  g  h\n");
    printf("\n");
    for(int i=0; i<8; i++)
    {
        printf("%d  ",8-i);
        for(int j=0; j<8;j++)
        {
            printf("%c  ", board[i][j]);
        }
        printf("\n");
    }

}

void turn()
{
    if(playerTurn =='b')
    {
        printf("It's Black's turn!\n");
        printf("Please enter the piece you want to move.\n");
        char input[3];
        getUserInput(input);
        
    }
    else
    {
        printf("It's Red's turn!\n");
    }
    
}
void getUserInput(char input[])
    {
    printf("Please enter the location in the form LetterNumber (EX: a5): ");
    scanf("%2s", input);
    printf("\nYou inputed: %s\n",input);
    while(!((input[0] >= 'a' && input[0] <= 'h') || (input[0] >= 'A' && input[0] <= 'H')) || !(input[1] >= '1' && input[1] <= '8'))
    {
        printf("Error please correct your input: ");
        scanf("%2s", input);
        printf("\nYou inputed: %s\n",input);
    }
    }


