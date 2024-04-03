#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void playwithcomputer(int[3][3]);
void display(int[3][3], int);
void displayUpdate(int[3][3], int, int);
int main()
{
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, choice;

    // printf("1. Play with computer\n");
    // printf("2. Play with your friend\n");
    // printf("3. Exit\n");
    // printf("Enter your choice: \n");
    // scanf("%d", &choice);
    // system("cls");
    // switch (choice)
    // {
    // case 1: // with computer
    playwithcomputer(arr);
    //     break;
    // case 2: // with friends
    //     break;
    // case 3: // exit
    //     exit(0);
    //     break;
    // }

    return 0;
}
void playwithcomputer(int arr[3][3])
{
    int choice, flag = 1;
    printf("################### Tic Tac Toe ###################\n\n");
    printf("First Player X\n");
    printf("Second Player O\n");
    printf("\n\n");
    display(arr, 0);
    printf("\n\n");
    printf("##################################################\n\n");
    while (1)
    {
        if (flag)
        {
            printf("Player 1, Enter the Marking Place: ");
        }
        else
        {
            printf("Player 2, Enter the Marking Place: ");
        }

        scanf("%d", &choice);
        system("cls");
        printf("################### Tic Tac Toe ###################\n\n");
        printf("First Player X\n");
        printf("Second Player O\n");
        printf("\n\n");
        displayUpdate(arr, choice, flag);
    }
}
void displayUpdate(int arr[3][3], int choice, int flag)
{
    // 88 -X
    // 79 -O
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == choice)
                arr[i][j] = 'X';
        }
    }
    display(arr, choice);
}
void display(int arr[3][3], int choice)
{
    // 88 -X
    // 79 -O

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (choice == arr[i][j])
                printf(" %c    |", arr[i][j]);
            printf(" %4d   |", arr[i][j]);
        }
        printf("\n");
        printf("        |");
        printf("        |");
        printf("        |");
        printf("\n");
        printf("---------------------------");
        printf("\n");
    }
}