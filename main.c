#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int decimalToBinary(int value) {
    int index = 0;
    char binary[33];

    for (int i = 31; i >= 0; i--) {
        int bit = (value >> i) & 1;
        binary[index++] = bit + '0';
    }

    binary[index] = '\0';
    printf("The decimal value you supplied is represented in binary as: %s\n", binary);

    return 0;
}

int binaryToDecimal(char *value) {
    int decimal = 0;
    int power;
    printf("binary input in binary to decimal function: %s\n", value);
    int length = strlen(value);

    for (int i = 0; i < length; i++) {
        power = length - 1 - i;

        if (value[i] == '1') {
            decimal += 1 << power;
        }
    }
    printf("decimal representation of binary value: %d\n", decimal);
    return 0;
}

int main() {
    char stringInput[33];
    char inputFormat[20];
    char isString[20];
    char outputFormat[20];
    int initValue = 0;

    printf("Are you converting a string represented value such as a binary value or hexadecimal value? YES or NO?: \n");
    scanf("%s", isString);

    printf("Please supply the value to be converted:\n");
    if (strcmp(isString, "NO") == 0) {
        scanf("%d", &initValue);
    } else if (strcmp(isString, "YES") == 0) {
        scanf("%s", stringInput);
    }

    printf("Please supply the input format:\n");
    scanf("%s", inputFormat);

    printf("Please supply the output format:\n");
    scanf("%s", outputFormat);

    if (strcmp(inputFormat, "decimal") == 0 && strcmp(outputFormat, "binary") == 0) {
        decimalToBinary(initValue);
    }

    if (strcmp(inputFormat, "binary") == 0 && strcmp(outputFormat, "decimal") == 0) {
        binaryToDecimal(stringInput);
    }
    return 0;
}