// C program to implement 2048 game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXRANDOMVALUE 3
#define MAXPREV 500
int arr[4][4] = { 0 }, c[4], temp = 0, len = 0, score = 0,
    highscore = 0, count = 0,
    ch = 0; // COUNT WILL COUNT THE NO OF STEPS

int findlen(int n);

// Function to print the game board
void print()
{
    int i, j, k, len1;

    printf(
        "\n\t\t\t\t\t===============2048==============\n");
    printf("\t\t\t\t\tYOUR SCORE=%d\n\t\t\t\t\t", score);
    if (score < highscore) {
        printf("HIGH SCORE=%d\t\t\t\t\t\n", highscore);
    }
    else {
        highscore = score;
        printf("HIGH SCORE=%d\t\t\t\t\t\n", highscore);
    }
    printf("\t\t\t\t\t---------------------------------\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j == 0) {
                printf("\t\t\t\t\t|");
            }
            if (arr[i][j] != 0) {
                len1 = findlen(arr[i][j]);
                // printf("%d:",len);

                for (k = 0; k < 4 - len; k++) {
                    printf(" ");
                }
                printf("%d", arr[i][j]);

                for (k = 0; k < 4 - len; k++) {
                    printf(" ");
                }
                for (k = 0; k < len - 1; k++) {
                    printf(" ");
                }
                printf("|");
            }
            else {
                for (k = 0; k < 8 - 2 * len - 1; k++) {
                    printf(" ");
                }
                printf("|");
            }
            len = 0;
        }
        if (i != 3) {
            printf("\n");
            printf("\t\t\t\t\t-----------------------------"
                   "----\n");
        }
    }
    printf(
        "\n\t\t\t\t\t---------------------------------\n");
    printf("\t\t\t\t\tPREV-> P\t\t\t\t\t\n");
    printf("\t\t\t\t\tRESTART-> R\t\t\t\t\t\n");
    printf("\t\t\t\t\tEXIT-> U\t\t\t\t\t\n");
    printf("\t\t\t\t\tENTER YOUR CHOISE -> "
           "W,S,A,D\n\t\t\t\t\t");
}

// Function to move values in the array
void movevalue(int k)
{
    int i;
    if (k == 3) {
        return;
    }
    for (i = k; i < 4; i++) {
        if (c[i] != 0) {
            movevalue(i + 1);
            for (; i < 4; i++) {
                if (c[i + 1] != 0) {
                    break;
                }
                c[i + 1] = c[i];
                c[i] = 0;
            }
        }
    }
}

// Function to find the length of a number (count of digits)
int findlen(int n)
{

    if (n == 0) {

        return len;
    }
    else {
        len++;
        findlen(n / 10);
    }
}

// Function to add a random number to the game board
void addrandomno()
{
    int no;
    srand(time(NULL));
    int i, j; // RANDOM INDEX
    do {
        i = (rand()) % (MAXRANDOMVALUE + 1);
        j = (rand()) % (MAXRANDOMVALUE + 1);
    } while (arr[i][j] != 0);
    // printf("%d %d",i,j);
    no = 2 * ((rand() % 10) + 1);
    if (no == 3 || no == 2) {
        arr[i][j] = 4;
    }
    else {
        arr[i][j] = 2;
    }
}

// Function to update the array after moving values
void rupdate()
{
    int i, j;
    for (i = 3; i > 0; i--) {
        if (c[i] == c[i - 1]) {
            c[i] += c[i - 1];
            score = score + c[i];
            if (score > highscore) {
            }
            temp = 1;
            c[i - 1] = 0;
        }
        else if (c[i - 1] == 0 && c[i] != 0) {
            c[i - 1] = c[i];
            c[i] = 0;
            temp = 1;
        }
        else if (c[i] == 0) {
            temp = 1;
        }
    }
    movevalue(0);
}

// Function to create a previous state in the history
void createprev(int*** p)
{
    int i, j, k;
    FILE* ptr;
    ptr = fopen("hstr.txt", "a");
    fprintf(ptr, "%d ", score);
    fclose(ptr);

    if (count == MAXPREV + 1) {
        for (i = MAXPREV; i > 0; i--) {
            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    p[i][j][k] = p[i - 1][j][k];
                }
            }
        }
        count = MAXPREV;
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            p[MAXPREV - count][i][j] = arr[i][j];
        }
    }
}

// Function to update the array to a previous state
void updatearrtoprev(int*** p)
{
    int data, i, j;
    if (count == 0) {
        printf("\n******FURTHER MORE PREV NOT "
               "POSSIBLE********");
        return;
    }
    FILE* ptr = fopen("hstr.txt", "r+");
    for (i = 0; i < count; i++) {
        fscanf(ptr, "%d ", &data);
    }
    score = data;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr[i][j] = p[MAXPREV - count][i][j];
        }
    }
    count--;
}

// Function to reset the game
void resetgame()
{
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr[i][j] = 0;
        }
    }
    system("clear || cls");
    score = 0;
    addrandomno();
}
int main()
{
    int i, j, k, m, n, same = 0;
    char choise, s = -33, reschk;
    printf("===============2048==============\n");
    printf("WELCOME TO PUZZLE 2048\n");
    printf("> CONTROLS\n");
    printf("  FOR MOVES:- 'W','S','A','D'\n");
    printf("  GO BACKWARD:- 'P'\n");
    printf("  RESTAT THE GAME:- 'R'\n");
    printf("  EXIT:-'U'\n");

    printf("\nPRESS ANY KEY TO START THE GAME....");

    getchar();
    system("clear || cls");
    printf("\n===============2048==============\n");
    printf("\nLOADING...\n");
    for (int i = 0, j; i < 35; i++) {
        printf("%c", s);
        j = i;
        if (i % 2 != 0 && i < 20) {
            usleep(1000);
        }
    }
    usleep(1000);
    system("clear || cls");
    int*** p;
    p = (int***)malloc(sizeof(int*) * (MAXPREV + 1));
    for (int i = 0; i < MAXPREV + 1; i++) {
        *(p + i) = (int**)malloc(sizeof(int*) * 4);
    }
    for (int i = 0; i < MAXPREV + 1; i++) {
        for (int j = 0; j < 4; j++) {
            p[i][j] = (int*)malloc(sizeof(int) * 4);
        }
    }
    createprev(p);

    FILE* ptr;
    ptr = fopen("highscore.txt", "r");
    fscanf(ptr, "%d", &highscore);
    fclose(ptr);
    ptr = fopen("hstr.txt", "w");
    fclose(ptr);
    addrandomno();
    print();
    while (1) {
        if (score > highscore) {

            ptr = fopen("highscore.txt", "w");
            fprintf(ptr, "%d", score);
            fclose(ptr);
        }
        choise = getchar();
        // Clear the input buffer
        while (getchar() != '\n')
            ;
        if (choise == 'D' || choise == 'd') {
            count++;
            ch++;
            createprev(p);
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    c[j] = arr[i][j];
                }
                rupdate();
                for (k = 0; k < 4; k++) {
                    arr[i][k] = c[k];
                }
            }
        }
        else if (choise == 'a' || choise == 'A') {
            count++;
            ch++;
            createprev(p);
            for (i = 0; i < 4; i++) {
                for (j = 3; j >= 0; j--) {
                    c[3 - j] = arr[i][j];
                }
                rupdate();
                for (k = 0; k < 4; k++) {
                    arr[i][3 - k] = c[k];
                }
            }
        }
        else if (choise == 's' || choise == 'S') {
            count++;
            ch++;

            createprev(p);
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    c[j] = arr[j][i];
                }
                rupdate();
                for (k = 0; k < 4; k++) {
                    arr[k][i] = c[k];
                }
            }
        }
        else if (choise == 'w' || choise == 'W') {
            count++;
            ch++;

            createprev(p);
            for (i = 0; i < 4; i++) {
                for (j = 3; j >= 0; j--) {
                    c[3 - j] = arr[j][i];
                }
                rupdate();
                for (k = 0; k < 4; k++) {
                    arr[3 - k][i] = c[k];
                }
            }
        }
        else if (choise == 'p' || choise == 'p') {

            updatearrtoprev(p);

            temp = 8;
        }
        else if (choise == 'R' || choise == 'r') {
            count = 0;
            resetgame();
            print();
            continue;
        }
        else if (choise == 'u' || choise == 'U') {
            exit(0);
        }

        if (temp == 1) {
            temp = 0;
            system("clear || cls");
            printf("\n%c\n", choise);
            addrandomno();
            print();
        }
        else if (temp == 8) {
            temp = 0;
            print();
        }
        else {
            for (m = 0; m < 4; m++) {
                for (n = 3; n > 0; n--) {
                    if (arr[m][n] == arr[m][n - 1]
                        || arr[m][n] == 0
                        || arr[m][n - 1] == 0) {
                        same = 1;
                        break;
                    }
                    if (arr[n][m] == arr[n - 1][m]
                        || arr[m][n] == 0
                        || arr[m][n - 1] == 0) {
                        same = 1;
                        break;
                    }
                }
                if (same == 1)
                    break;
            }
            if (same == 1) {
                printf("\n============INVALID "
                       "KEY==========\n");
                same = 0;
            }
            else {
                printf(
                    "\n=============GAME OVER============");
                printf("\nWANT TO PLAY MORE?? Y/N??\n");
                reschk = getchar();
                while (getchar() != '\n')
                    ; // Clear the input buffer
                switch (reschk) {
                case 'Y':
                case 'y':
                    resetgame();
                    print();
                    break;
                case 'n':
                case 'N':
                    exit(0);
                }
                continue;
            }
        }
    }
    return 0;
}

