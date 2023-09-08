// This is a recursive solution for 0-1 knapsack
#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsack(int weights[], int value[], int size, int capacity)
{
    if (size == 0 || capacity == 0)
    {
        return 0;
    }
    else if (weights[size - 1] <= capacity)
    {
        return max(value[size - 1] + knapsack(weights, value, size - 1, capacity - weights[size - 1]), knapsack(weights, value, size - 1, capacity));
    }
    else
    {
        return knapsack(weights, value, size - 1, capacity);
    }
}

void main()
{
    int size;
    printf("Enter the size of weight array: ");
    scanf("%d", &size);
    int weights[size], value[size], capacity;
    printf("Enter the weights and corresponding values: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &weights[i]);
        scanf("%d", &value[i]);
    }
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);
    printf("Max profit: %d", knapsack(weights, value, size, capacity));
}