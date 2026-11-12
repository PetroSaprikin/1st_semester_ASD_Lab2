#include <stdio.h>
#include <stdlib.h>

struct lst
{
    float * array;
    int size;
};

struct lst lst_init(int size)
{
    struct lst A;
    A.size = size;
    A.array = malloc(size * sizeof(float));
    return A;
}

struct lst lst_remove(struct lst *A, int elements_to_remove)
{
    A->array = realloc(A->array, (A->size - elements_to_remove) * sizeof(float));
    return *A;
}

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

void lst_fill(struct lst *A)
{
    for (int i = 0; i < A->size; i++)
    {
        printf("Enter the value of element %d: ", i + 1);
        A->array[i] = float_number_check();
    }
}

void lst_print(float *A, int lst_size)
{
    for (int i = 0; i < lst_size; i++)
        printf("[%.2f]", A[i]);
    printf("\n");
}



int main()
{
    while (1)
    {
        printf("Enter the size of the list (between 0 and 15): ");
        int lst_size = integer_number_check();
        lst_size = size_check(lst_size, 15);
        struct lst A = lst_init(lst_size);
        lst_fill(&A);
        printf("Enter the number of elements to remove (0 - %d): ", lst_size);
        int elements_to_remove = integer_number_check();
        elements_to_remove = size_check(elements_to_remove, lst_size);
        lst_size -= elements_to_remove;
        printf("New list: ");
        lst_print(A.array, lst_size);
        printf("Enter value. Elements less than or equal to this value will be printed: ");
        float element = float_number_check();
        free(A.array);
    }
}
