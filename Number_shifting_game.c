#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_MOVES 500
int x, y; // for setting the positon for shifting of the element
void gamerules();
void createMatrix(int[4][4]);
void inputMatrix(int[4][4]);
void displayMatrix(int[4][4]);
char getuserchoice();
int shiftUp(int[4][4]);
int shiftDown(int[4][4]);
int shiftRight(int[4][4]);
int shiftLeft(int[4][4]);
void loseMessage();
int winMessage(int[4][4]);
int main()
{
    int moves = MAX_MOVES;
    char name[30];
    char choice;
    int arr[4][4];

    // Getting the name of the user
    // ...........
    printf("Enter the User Name:");
    fflush(stdin);
    fgets(name, 30, stdin);
    name[strlen(name) - 1] = '\0';
    // ..........
    system("cls"); // used to clear the screen

    inputMatrix(arr);
    //  // rules
    gamerules(arr);
    system("cls");
    while (1)
    {
        if (winMessage(arr) && moves > 0) // 0 means win
        {
            system("cls");
            printf("Hello %s,   Move remaining : %d\n", name, moves);
            displayMatrix(arr);
        }
        else if (winMessage(arr) == 0 && moves > 0)
        {
            printf("!!!!!!!!!!!!!! Congratulations for Winning this game !!!!!!!!!!!!!!!!\n");
            // when exit the game
            printf("\nThanks for playing ! \n");
            printf("Hit 'Enter' to exit the game\n");
        }
        choice = getuserchoice();

        switch (choice)
        {
        case 'E':
        case 'e':
            printf("\tThanks for Playing !\n");
            printf("Hit 'Enter' to exit the game");
            choice = getuserchoice();
        case 13: // enter
            exit(0);
        case 77: // right arrow
            if (shiftRight(arr))
                moves--;
            break;
        case 75: // left arrow
            if (shiftLeft(arr))
                moves--;
            break;
        case 72:
            if (shiftUp(arr))
                moves--;
            break;
        case 80:
            if (shiftDown(arr))
                moves--;
            break;
        case 'y':
            system("cls");
            gamerules();
            createMatrix(arr);
            moves = MAX_MOVES;
            break;
        }
        if (moves == 0)
            loseMessage();
    }
    return 0;
}

void loseMessage()
{
    system("cls");
    printf("You Lose  !\n");
    printf("Want to play again?\n");
    printf("Enter y to play again: ");
}
int winMessage(int arr[4][4])
{
    int i, j, k = 1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++, k++)
            if (arr[i][j] != k && k != 16)
                break;
        if (j < 4)
            break;
    }
    if (j < 4)
        return 1;
    return 0;
}
void gamerules()
{
    // printf("\t\tMATRIX PUZZLE\n\n");
    printf("            RULE OF THE GAME\n");
    printf("1.You can move only one step at a time by using arrow key\n");
    printf("\tMove Up       :   by Up arrow key\n");
    printf("\tMove Down     :   by Down arrow key\n");
    printf("\tMove Right    :   by Right arrow key\n");
    printf("\tMove Left     :   by Left arrow key\n");
    printf("2.You can move numbers at an empty position only.\n\n");
    printf("3.For each valid move : your total number of moves will decrease by 1\n");
    printf("4.Winning Situation : Number in a 4*4 matrix should be in order from 1 to 15\n\n");
    printf("        Wining situation:\n");
    printf(".....................\n");
    printf("| 1  | 2  | 3  | 4  |\n");
    printf("| 5  | 6  | 7  | 8  |\n");
    printf("| 9  | 10 | 11 | 12 |\n");
    printf("| 13 | 14 | 15 |    |\n");
    printf(".....................\n");
    printf("You can exit the game at any time by pressing 'E' or 'e'\nso try to win in minimum no of move\n\n");
    printf("    Happy gaming , Good luck\n\n");
    printf("Enter any key to start.....");
    getuserchoice(); // used to receive character from user
                     // defined in conio.h
                     // character input by user is not visible on the output screen but stored in assigned variable which makes the best method for receiving password from user.

    system("cls"); // it is used to clear the screen
    // to clear the screen
    // ..........................
    // 1.By Using system(“clear”) // linux specific // Supported by all modern compilers.
    // 2.By using a regex “\e[1;1H\e[2J”
    // 3.by using clrscr() function // supported by old compilers
    // 4.System(“cls”) // windows specific Supported by all modern compilers.

    // printf("Hello %s,   Move remaining : %d\n", name, moves);
    // printf(".....................\n");
    // printf("| 5  | 8  | 6  | 9  |\n");
    // printf("| 14 | 13 | 3  | 1  |\n");
    // printf("| 2  | 7  | 15 | 4  |\n");
    // printf("| 12 | 11 | 10 |    |\n");
    // printf(".....................\n");

    // system("cls"); // to clear the screen
}
char getuserchoice()
{
    char choice = getch();
    return choice;
}
void createMatrix(int arr[4][4])
{
    // input
    inputMatrix(arr);
    // display
    displayMatrix(arr);
}
void inputMatrix(int arr[4][4])
{
    // to generate different random numbers we will use srand(time())
    // we use time library here to generate random number in every execution.
    int n = 15;
    int num[n];
    for (int i = 0; i < n; i++)
        num[i] = i + 1;

    // //  input
    srand(time(NULL));
    int index, lastposition = n - 1, i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (lastposition >= 0)
            {
                // it generated same number for every execution because value of srand is fixed which is 1
                index = rand() % (lastposition + 1); // % is used to recevie numbers under 15
                arr[i][j] = num[index];
                num[index] = num[lastposition--];
            }
        }
    }
    arr[i - 1][j - 1] = 0; // last position
    x = 3;
    y = 3;
}
void displayMatrix(int arr[4][4])
{
    // display
    int i, j;
    printf("....................\n");
    for (i = 0; i < 4; i++)
    {
        printf("|");
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] != 0)
                printf("%2d | ", arr[i][j]);
            else
                printf("   | ");
        }
        printf("\n");
    }
    printf("....................\n");
}
// new approach by karan
int shiftUp(int arr[4][4])
{
    if (x > 0) // x = 3
    {
        int temp;
        temp = arr[x][y];
        arr[x][y] = arr[x - 1][y];
        arr[x - 1][y] = temp;
        x = x - 1;
        return 1; // shifting done
    }
    else
        return 0; // no shifting
}
int shiftDown(int arr[4][4])
{
    if (x < 3) // x = 3
    {
        int temp;
        temp = arr[x][y];

        arr[x][y] = arr[x + 1][y];
        arr[x + 1][y] = temp;
        x = x + 1;
        return 1; // shifting done
    }
    else
        return 0; // no shifting
}
int shiftRight(int arr[4][4])
{
    int temp;
    if (y < 3) // y = 3
    {
        temp = arr[x][y];
        arr[x][y] = arr[x][y + 1];
        arr[x][y + 1] = temp;
        y = y + 1;
        return 1; // shifting done
    }
    else
        return 0; // no shifting
}
int shiftLeft(int arr[4][4])
{
    int temp;
    if (y > 0) // y = 3
    {
        temp = arr[x][y];
        arr[x][y] = arr[x][y - 1];
        arr[x][y - 1] = temp;
        y = y - 1;
        return 1; // shifting done
    }
    else
        return 0; // no shifting
    // previous approach
    // for (int i = 0; i < 4; i++)
    // {
    // temp = arr[i][3];
    // for (int j = 4; j > 0; j--)
    // {
    //     arr[i][j] = arr[i][j - 1];
    // }
    // printf("\n");
    // arr[i][0] = temp;
    // }
}
