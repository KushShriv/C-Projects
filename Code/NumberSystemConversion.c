#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char *);

char* decimalToBinary(int decimal){
    char* binary = (char*)malloc(33);
    if (binary == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int i = 0;
    while (decimal) {
        binary[i++] = '0' + (decimal & 1);
        decimal >>= 1;
    }
    if (i == 0) {
        binary[i++] = '0';
    }
    binary[i] = '\0';
    reverseString(binary);
    return binary;
}

int binaryToDecimal(char binary[]){
    int decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}

void reverseString(char* str){
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
}

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