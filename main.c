#include <stdio.h>
#include <stdlib.h>

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

float float_number_check()
{
    float number = 0.f;
    char ch = 0;

    while (1)
    {
        if (scanf("%f%c", &number, &ch) == 2 && ch == '\n')
        {
            return number;
        }
        printf("Invalid input. Enter a real number: ");
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
}

int size_check(int size, int real_size)
{
    while (size < 0 || size > real_size)
    {
        printf("Invalid size. Enter a value from 0 to %d: ", real_size);
        size = integer_number_check();
    }
    return size;
}

int main()
{
    while (1)
    {
        printf("Enter the size of the list (between 0 and 15): ");
        int lst_size = integer_number_check();
        lst_size = size_check(lst_size, 15);
        float *A = malloc(lst_size * sizeof(float));
        for (int i = 0; i < lst_size; i++)
        {
            printf("Enter the value of element %d: ", i + 1);
            A[i] = float_number_check();
        }
        printf("Enter the number of elements to remove (0 - %d): ", lst_size);
        const int elements_to_remove = integer_number_check();
        free(A);
    }
}
