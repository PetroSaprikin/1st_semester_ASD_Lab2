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

void lst_remove(struct lst *A, int elements_to_remove)
{
    A->size -= elements_to_remove;
    A->array = realloc(A->array, A->size * sizeof(float));
}

void lst_free(struct lst *A)
{
    free(A->array);
}

char lst_is_empty(struct lst *A)
{
    if (A->size == 0)
    {
        return 1;
    }
    return 0;
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

void lst_print_elements_less_than_value(const struct lst *A, const float element)
{
    char count = 0;
    for (int i = 0; i < A->size; i++)
    {
        if (A->array[i] < element)
        {
            count++;
            printf("[%.2f]", A->array[i]);
        }
    }
    if (count == 0)
    {
        printf("EMPTY LIST\n");
    }
    printf("\n");
}

void lst_print_bigger_than_average_value(const struct lst *A)
{
    float sum = 0;

    for (int i = 0; i < A->size; i++)
    {
        sum += A->array[i];
    }

    float average = sum / (float)A->size;

    printf("Average value: [%.2f]\n", average);
    printf("Elements bigger than average value: " );

    for (int i = 0; i < A->size; i++)
    {
        if (A->array[i] > average)
        {
            printf("[%.2f]", A->array[i]);
        }
    }

    printf("\n");

}

int main()
{
    while (1)
    {
        printf("Enter the size of the list (between 0 and 15): ");
        struct lst A = lst_init(size_check(integer_number_check(), 15));
        lst_fill(&A);
        printf("Enter the number of elements to remove (0 - %d): ", A.size);
        lst_remove(&A, size_check(integer_number_check(), A.size));
        if (lst_is_empty(&A))
        {
            printf("Lst is empty\n");
            continue;
        }
        printf("New list: ");
        lst_print(A.array, A.size);
        printf("Enter value. Elements less than this value will be printed: ");
        float element = float_number_check();
        printf("List with elements that less than this value: ");
        lst_print_elements_less_than_value(&A, element);
        lst_print_bigger_than_average_value(&A);
        lst_free(&A);
    }
}
