#include <stdio.h>

int integer_number_check()
{
    int number = 0;
    char ch = 0;

    while (1)
    {
        if (scanf("%d%c", &number, &ch) == 2 && ch == '\n')
        {
            return number;
        }
        printf("Invalid input. Enter an integer: ");
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
}

int main()
{
    while (1)
    {
        printf("Enter the size of the list (between 0 and 15): ");
        int N = integer_number_check();
        if (0 < N && N <= 15)
        {
            printf("success");
        }
        else
        {
            printf("Must be between 0 and 15!\n");
        }
    }
}
