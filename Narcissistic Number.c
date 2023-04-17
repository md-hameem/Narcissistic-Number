#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is narcissistic
bool is_narcissistic(int num, int digit);

int main() {
    int digit;

    // Prompt user to enter the number of digits and read input from user
    printf("Enter the number of digits: ");
    if (scanf("%d", &digit) != 1 || digit <= 0) {
        // If scanf() fails to read input or entered value is not positive, print an error message and exit program with failure status
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    // Calculate the range of numbers to check based on the number of digits
    int start = 1 + ((pow(10, digit - 1) - 1) / 9) * 9;
    int end = ((pow(10, digit) - 1) / 9) * 9;

    // Print the header for the list of narcissistic numbers
    printf("Narcissistic numbers with %d digits are:\n", digit);

    // Loop over each number in the range and check if it is narcissistic
    for (int i = start; i <= end; i++) {
        if (is_narcissistic(i, digit)) {
            printf("%d\n", i);
        }
    }

    return 0;
}

// Function definition for is_narcissistic()
bool is_narcissistic(int num, int digit) {
    int sum = 0, mod, real_num = num;
  
    // Calculate the sum of each digit raised to the power of the number of digits
    while (num != 0) {
        mod = num % 10;
        sum += pow(mod, digit);
        num /= 10;
    }

    // Check if the sum is equal to the original number and return true or false accordingly
    return (sum == real_num);
}
