#include<stdio.h>
#include<stdlib.h>

int rd()
{
    int rem;
    A: rem = rand() % 6+1;
    if (rem == 0)
        goto A;
    else
        return rem;
}

void displaychart(int curp1, int curp2)
{
    int i, j, t, c, row = 0, value;

    if (curp1 == 100 || curp2 == 100)
    {
        printf("*****Congratulations*****\n\n\nPlayer %s wins\n", (curp1 == 100) ? "$P1$" : "$P2$");
        scanf("%*s");
        exit(0);
    }

    for (i = 10; i > 0; i--)
    {
        t = i - 1;
        if ((row % 2) == 0)
        {
            c = 0;
            for (j = 10; j >= 1; j--)
            {
                value = (i * j) + (t * c++);

                if (curp1 == value)
                    printf("$P1$\t");
                else if (curp2 == value)
                    printf("$P2$\t");
                else
                    printf("%d\t", value);
            }
            row++;
        }
        else
        {
            c = 9;
            for (j = 1; j <= 10; j++)
            {
                value = (i * j) + (t * c--);

                if (curp1 == value)
                    printf("$P1$\t");
                else if (curp2 == value)
                    printf("$P2$\t");
                else
                    printf("%d\t", value);
            }

            row++;
        }
        printf("\n\n");
    }

    printf("--------------------------------------------------------------------------\n");
}

int main()
{
    int dice, cur_pos1 = 0, cur_pos2 = 0;
    char ch;
    while (1)
    {
        printf("\t\t\t**SNAKE AND LADDER GAME** \n");
        printf("Snakes:- 99 to 1, 65 to 40, 25 to 9.\nLadder:- 70 to 93, 60 to 83, 13 to 42.\n");
        printf("Choose your option\n");
        printf("1. Player 1 plays\n");
        printf("2. Player 2 plays\n");
        printf("3. Exit\n");
        scanf(" %c", &ch);

        switch (ch)
        {
        case '1':
            dice = rd();
            system("clear");
            printf("\t\t\t\tDice = %d\n\n", dice);
            if (dice == 6)
                printf("Dice=6: You have earned a chance to play one more time.\n");
            cur_pos1 = (cur_pos1+dice)>100?cur_pos1:cur_pos1+dice;
            if (cur_pos1 < 101)
            {
                if (cur_pos1 == 99 || cur_pos1 == 65 || cur_pos1 == 25)
                {
                    cur_pos1 = (cur_pos1 == 99) ? 1 : ((cur_pos1 == 65) ? 40 : 9); // Snake bites
                }
                else if (cur_pos1 == 70 || cur_pos1 == 60 || cur_pos1 == 13)
                {
                    cur_pos1 = (cur_pos1 == 70) ? 93 : ((cur_pos1 == 60) ? 83 : 42); // Climb the ladder
                }

                displaychart(cur_pos1, cur_pos2);
            }
            if (cur_pos1 + dice > 101)
            {
                printf("Range exceeded of Player 1.\n");
                displaychart(cur_pos1, cur_pos2);
            }
            printf("Player 2 position is %d\n", cur_pos2);
            break;

        case '2':
            dice = rd();
            system("clear");
            printf("\t\t\t\tDice = %d\n\n", dice);
            if (dice == 6)
                printf("Dice=6: You have earned a chance to play one more time.\n");
            cur_pos2 = (cur_pos2+dice)>100?cur_pos2:cur_pos2+dice;
            if (cur_pos2 < 101)
            {
                if (cur_pos2 == 99 || cur_pos2 == 65 || cur_pos2 == 25)
                {
                    cur_pos2 = (cur_pos2 == 99) ? 1 : ((cur_pos2 == 65) ? 40 : 9); // Snake bites
                }
                else if (cur_pos2 == 70 || cur_pos2 == 60 || cur_pos2 == 13)
                {
                    cur_pos2 = (cur_pos2 == 70) ? 93 : ((cur_pos2 == 60) ? 83 : 42); // Climb the ladder
                }

                displaychart(cur_pos1, cur_pos2);
            }
            if (cur_pos2 + dice > 101)
            {
                printf("Range exceeded of Player 2.\n");
                displaychart(cur_pos1, cur_pos2);
            }
            printf("Player 1 position is %d\n", cur_pos1);
            break;

        case '3':
            exit (0);
            break;

        default:
            printf("Incorrect choice. Try Again\n");
        }
    }

    return 0;
}

