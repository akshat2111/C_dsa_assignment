#include <stdio.h>
#include <string.h>

void add_large_numbers(char *num1, char *num2) {
    int max_len = strlen(num1) > strlen(num2) ? strlen(num1) : strlen(num2);
    char result[100];
    int carry = 0,digit1,digit2,sum;

    for (int i = 0; i < max_len; i++) {
           digit1 = num1[max_len - i - 1] - '0';
           digit2 = num2[max_len - i - 1] - '0';
           sum = digit1 + digit2 + carry;
        result[max_len - i - 1] = sum % 10 + '0';
        carry = sum / 10;
    }

    if (carry > 0) {
        result[max_len] = carry + '0';
        max_len++;
    }

    result[max_len] = '\0';
    printf("%s\n", result);
}

int main() {
    char num1[] = "12345678901234567890";
    char num2[] = "98765432109876543210";
    add_large_numbers(num1, num2);
    return 0;
}