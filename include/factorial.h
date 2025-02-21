#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <stdio.h>
#include <gmp.h>  // Include GMP library

// Function to calculate factorial using GMP
void factorial(mpz_t result, int n) {
    mpz_set_ui(result, 1);  // Initialize result to 1
    for (int i = 2; i <= n; i++) {
        mpz_mul_ui(result, result, i);  // Multiply result by i
    }
}

// Function to print factorials from 0 to a given limit
void print_factorial_table(int limit) {
    mpz_t result;
    mpz_init(result);  // Initialize GMP integer

    printf(" n | n!\n");
    printf("---|--------------------------------------------------\n");
    for (int n = 0; n <= limit; n++) {
        factorial(result, n);  // Calculate factorial
        gmp_printf("%2d | %Zd\n", n, result);  // Print using GMP's printf
    }

    mpz_clear(result);  // Free GMP integer
}

#endif // FACTORIAL_H
