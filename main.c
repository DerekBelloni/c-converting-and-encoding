#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int decimalToBinary(int value) {
    int index = 0;
    char binary[33];

    for (int i = 31; i >= 0; i--) {
        binary[index++] = ((value >> i) & 1) ? '1' : '0';
    }

    binary[index] = '\0';
    printf("The decimal value you supplied is represented in binary as: %s\n", binary);

    return 0;
}

int hexDigitToBinary(char hex, char *binary) {
    int value;

    if (hex >= '0' && hex <= '9') {
        value = hex - '0';
    } else if (hex >= 'A' && hex <= 'F') {
        value = hex - 'A' + 10;
    } else if (hex >= 'a' && hex <= 'f') {
        value = hex - 'a' + 10;
    } else {
        printf("Invalid hex character: %c", hex);
        binary[0] = '\0';
        return -1;
    }

    for (int i = 3; i >= 0; i--) {
        binary[3 - i] = ((value >> i) & 1) ? '1' : '0';
    }
    binary[4] = '\0';
    return 0;
}

int hexToBinary(char *value) {
    int index  = 0;
    char binary[129];
    binary[0] = '\0';

    for (int i = 0; value[i] != '\0'; i++) {
        char binDigit[5];
        hexDigitToBinary(value[i], binDigit);
        strcat(binary, binDigit);
    }
    printf("The hexadecimal value you supplied is represented in binary as: %s \n", binary);
    return 0;
}

int binaryToDecimal(char *value) {
    int decimal = 0;
    int power;

    int length = strlen(value);

    for (int i = 0; i < length; i++) {
        power = length - 1 - i;

        if (value[i] == '1') {
            decimal += 1 << power;
        }
    }
    printf("The binary value you supplies is represented in decimal as: %d\n", decimal);
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

    if (strcmp(inputFormat, "hexadecimal") == 0 && strcmp(outputFormat, "binary") == 0) {
        hexToBinary(stringInput);
    }
    return 0;
}