#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Main focus is to use "random" statistically and extensively

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

char *outcome(int x)
{
    // so that we can use standardized 1 , 2 , 3 integers instead of strings
    if (x == 1)
    {
        return "STONE";
    }
    else if (x == 2)
    {
        return "PAPER";
    }
    else if (x == 3)
    {
        return "SCISSORS";
    }
}

int *gameLogic(int CGuess, int UGuess, int Score, int Streak)
{
    // initializing array to output new score and new streak
    static int result[2];
    // win conditions
    if ((CGuess == 1 && UGuess == 3) || (CGuess == 2 && UGuess == 1) || (CGuess == 3 && UGuess == 2))
    {
        printf("Round Won\n");
        printf("Your choice : %s || computer choice %s\n", outcome(UGuess), outcome(CGuess));
        Score = Score + 100 + Streak * 20; // score increment by 100 with streak bonus
        printf("# Score => %d (%d - Streak bonus) #\n", Score, Streak * 20);
        Streak++; // streak increased because of right guess
        // new score and streak stored in array result
        result[0] = Score;
        result[1] = Streak;
    }
    // loss conditions
    else if ((CGuess == 1 && UGuess == 2) || (CGuess == 2 && UGuess == 3) || (CGuess == 3 && UGuess == 1))
    {
        printf("Round Lost\n");
        printf("Your choice : %s || computer choice %s\n", outcome(UGuess), outcome(CGuess));
        int prevScore = Score; // to later compare the loss recieved
        Score = Score * 0.1 + Streak * 5; // score decrease by 90% and small streak bonus
        printf("# Score => %d (%d - punish) #\n", Score, prevScore - Score);
        printf("# Streak reset #\n");
        Streak = 0; // streak reset because of wrong guess
        // new score and streak stored in array result
        result[0] = Score;
        result[1] = Streak;
    }
    //tie
    else if (CGuess == UGuess)
    {
        printf("Round Tie\n");
        printf("Your choice : %s || computer choice %s\n", outcome(UGuess), outcome(UGuess));
        Score = Score + Streak * 5; // only small streak bonus added
        printf("# Score => %d (%d - Streak bonus) #\n", Score, Streak * 5);
        Streak++; // streak considered valid hence increased
        // new score and streak stored in array result
        result[0] = Score;
        result[1] = Streak;
    }
    return result; // the result array containing score and streak
}

int main()
{
    // initial one time text decoration
    printf("********************\n\n STONE PAPER SCISSORS \n  (jayesh warhadi)  \n\n********************\n");
    int Score = 0;
    int Streak = 0;
    int Rounds = 0;
    int userguess;
    while (1)
    {
        int compguess = randint(1, 3); // computer guess using randint func we made
        printf("********************\n>\n> STONE - 1\n>\n> PAPER - 2\n>\n> SCISSORS - 3\n>\n********************\n");
        while (1)
        {
            printf("Enter input : ");
            int res = scanf("%d", &userguess); // if the input is valid , res should be 1
            if (res == 1 && userguess <= 3 && userguess >= 1)
            {
                break;
            }
            else
            {   // incase res isn't equal to 1 , input is invalid
                printf("Invalid input : Try again! (1~3)\n");
                while (getchar() != '\n'); // clearing the cashe in input if any.
            }
        }
        Rounds++; // increasing the rounds played regardless of the outcome
        //result is the array containing new score and streak
        int *result = gameLogic(compguess, userguess, Score, Streak);
        Score = result[0]; // updating
        Streak = result[1]; // updating
        printf("Press Enter to continue and any key to exit\n");
        while (getchar() != '\n'); // clearing the cashe in input if any.
        if (getchar() == '\n') // if enter key is registered i.e "\n"
        {
            continue;// as the user want to proceed
        }
        else
        {
            // display of final score and the Current streak and rounds played
            printf("********************\n\nCurrent Score is %d\nCurrent Streak is %d\n\nTotal rounds played -> %d\n\n********************", Score, Streak,Rounds);
            return 0;
        }
    }
    return 0;
}