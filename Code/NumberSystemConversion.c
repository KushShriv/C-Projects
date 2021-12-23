#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Decimal to Octal\n");
        printf("4. Octal to Decimal\n");
        printf("5. Hexadecimal to Binary\n");
        printf("6. Binary to Hexadecimal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Goodbye!\n");
            break;
        }

        char input[100];
        int number;
        char* result;

        switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            result = decimalToBinary(number);
            printf("Decimal to Binary: %s\n", result);
            free(result);
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%s", input);
            int binaryResult = binaryToDecimal(input);
            printf("Binary to Decimal: %d\n", binaryResult);
            break;
        case 3:
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            result = decimalToOctal(number);
            printf("Decimal to Octal: %s\n", result);
            free(result);
            break;
        case 4:
            printf("Enter an octal number: ");
            scanf("%s", input);
            int octalResult = octalToDecimal(input);
            printf("Octal to Decimal: %d\n", octalResult);
            break;
        case 5:
            printf("Enter a hexadecimal number: ");
            scanf("%s", input);
            result = hexadecimalToBinary(input);
            printf("Hexadecimal to Binary: %s\n", result);
            free(result);
            break;
        case 6:
            printf("Enter a binary number: ");
            scanf("%s", input);
            result = binaryToHexadecimal(input);
            printf("Binary to Hexadecimal: %s\n", result);
            free(result);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}