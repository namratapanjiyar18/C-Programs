#include <stdio.h>
#include <stdlib.h>
void menu()
{
    printf("Simple Calculator\n");
    printf("1. Addition(+)\n");
    printf("2. Subtraction(-)\n");
    printf("3. Multiplication(*)\n");
    printf("4. Division(/)\n");
    printf("5. Modulus(%%)\n");
    printf("6. Exit\n");
}
int main()
{
    int choice;
    double num1, num2;
    while (1)
    {
        menu();
        printf("Enter your choice:");
        scanf("%d", &choice);
        if (choice == 6)
        {
            printf("Exiting calculator\n");
            break;
        }
        printf("Enter two numbers:");
        scanf("%lf %lf", &num1, &num2);
        switch (choice)
        {
        case 1:
            printf("Result:%.2lf\n", num1 + num2);
            break;
        case 2:
            printf("Result:%.2lf\n", num1 - num2);
            break;
        case 3:
            printf("Result:%.2lf\n", num1 * num2);
            break;
        case 4:
            if (num2 != 0)
                printf("Result:%.2lf\n", num1 / num2);
            else
                printf("Error! Division by zero\n");
            break;
        case 5:
            printf("Result:%d\n", (int)num1 % (int)num2);
            break;
        default:
            printf("Invalid choice! Try again\n");
        }
    }
    return 0;
}
