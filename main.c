#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
//#include <conio.h> for include getch

#define player1 'X'
#define player2 'O'

void xotable(char tab[9]) {
    printf("\033[1;34m  %c | %c | %c \n", tab[0], tab[1], tab[2]);
    printf("\033[1;34m ____________\n");
    printf("\033[1;34m  %c | %c | %c \n", tab[3], tab[4], tab[5]);
    printf("\033[1;34m ____________\n");
    printf("\033[1;34m  %c | %c | %c \n", tab[6], tab[7], tab[8]);
}

int a;

void insert(char tab[9], char b) {
    do {
        printf("\033[1;33mChoose a case: ");
        scanf("%d", &a);
    } while (a < 1 || a > 9);

    if (tab[a - 1] == 'o') {
        tab[a - 1] = 'o';
    }
    if (tab[a - 1] == 'x') {
        tab[a - 1] = 'x';
    } else {
        tab[a - 1] = b;
    }
}

bool checkWin(char tab[9], char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if ((tab[i] == player && tab[i + 3] == player && tab[i + 6] == player) || // Check columns
            (tab[i * 3] == player && tab[i * 3 + 1] == player && tab[i * 3 + 2] == player)) { // Check rows
            return true;
        }
    }

    // Check diagonals
    if ((tab[0] == player && tab[4] == player && tab[8] == player) ||
        (tab[2] == player && tab[4] == player && tab[6] == player)) {
        return true;
    }

    return false;
}

int main() {
    printf("\033[1;33mWelcome to Tic-Tac-Toe game\n");
    sleep(2);
    int match = 0;
    printf("\033[1;36mMatches played: %d\n", match);
    sleep(2);  
    /*do{
    printf("\033[1;90m//if u want to start just press enter");
    int key ;
    key = getch();
    }while(key != 13);*/
    // this part of code is for windows users because function getch dosent work in linux os
    int key;
    do {
        printf("\033[1;33mIf you want to start, press 13: ");
        scanf("%d", &key);
    } while (key != 13);

    match++;
    char game[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int turn = 0;
    printf("Started\n");
    sleep(2);
    printf("\033[1;36mStarted\n");
    xotable(game);
    sleep(2);
    printf("\033[1;31mNote: To choose a case, simply enter the corresponding number based on the previous table\n");
    
    char player;
    bool won = false;
    int i;
    for(i=1;i<9;i++) {
        game[i] = ' ';
    }

    for (i = 1; i <= 9; i++) {
        if (turn % 2 == 0) {
            player = 'x';
        } else {
            player = 'o';
        }
        insert(game, player);
        printf("\n");
        xotable(game);
        turn++;

        // Check for a win after every player's move
        if (i >= 5) { // Minimum moves required for a win
            if (checkWin(game, player)) {
                printf("\033[1;32mPlayer %c wins!\n", player);
                won = true;
                break;
            }
        }
    }

    if (!won) {
        printf("\033[1;31mIt's a draw!\n");
    }

    return 0;
}

