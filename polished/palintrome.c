#include <stdio.h>
// palindrome means if reversed of a number is same as the number

int reverse(int n)
{
    int s = 0; // variable to store the reversed number
    while (n != 0) // eventually n will be 0 as its divided by 10 each iteration
    {
        int r = n % 10; // r will be unit place
        n = n / 10; // unit placed will be removed due to division by 10
        s = s * 10 + r; // variable's unit place becomes 0 due multiplication and r becomes the new unit place
    }
    return s; // returning the reversed number
}

int main()
{
    while (1)
    {
        printf("********************\n\n  PALINTROME TEST  \n\n  (jayesh warhadi)  \n\n********************\n");
        int num;
        while (1)
        {
            printf("Enter the number : ");
            int validity = scanf("%d", &num); // any validity other than 1 is not valid
            if (validity == 1) // 1 means it has valid integer value
            {
                break;
            }
            else
            {
                printf("Invalid Input : Try again (Integers)\n");
                while (getchar() != '\n'); // clearing scanf cashe if any.
            }
        }
        int rev = reverse(num);
        if (rev == num)
        {
            printf("\nThe number is a palintrome\n");
        }
        else
        {
            printf("\nThe number is not a palintrome\n");
        }
        int resp = 0;
        while (1)
        {
            printf("Press 1 to continue and 0 to exit\n");
            int validity = scanf("%d", &resp); // any validity other than 1 is not valid
            if (validity == 1 & resp == 1) // validity 1 means it has valid integer value
            {
                break;
            }
            else if (validity == 1 && resp == 0) // validity 1 means it has valid integer value
            {
                return 0;
            }
            else
            {
                printf("Invalid input : Press 1 or 0\n");
                while (getchar() != '\n');// clearing scanf cashe if any.
            }
        }
    }
    return 0;
}