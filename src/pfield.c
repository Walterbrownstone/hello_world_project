// pfield.c - Prime Factorial Field Generator
// Compile with: gcc -O3 -lgmp -o pfield pfield.c
#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_pfield(const mpz_t n, const char *output_file) {
    FILE *fp = fopen(output_file, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening output file\n");
        return;
    }

    mpz_t current, prime, factorial;
    mpz_init_set_ui(current, 1);
    mpz_init(prime);
    mpz_init_set_ui(factorial, 1);

    char *n_str = mpz_get_str(NULL, 10, n);
    fprintf(fp, "Prime Factorial Field Generator\n");
    fprintf(fp, "Calculating up to: %s\n\n", n_str);
    free(n_str);

    while (mpz_cmp(current, n) <= 0) {
        // Calculate factorial
        if (mpz_cmp_ui(current, 1) > 0) {
            mpz_mul(factorial, factorial, current);
        }

        // Find next prime
        mpz_nextprime(prime, current);

        // Convert GMP numbers to strings for output
        char *current_str = mpz_get_str(NULL, 10, current);
        char *fact_str = mpz_get_str(NULL, 10, factorial);
        char *prime_str = mpz_get_str(NULL, 10, prime);

        fprintf(fp, "n = %s\n", current_str);
        fprintf(fp, "  Factorial: %s\n", fact_str);
        fprintf(fp, "  Next prime: %s\n\n", prime_str);

        free(current_str);
        free(fact_str);
        free(prime_str);

        mpz_add_ui(current, current, 1);
    }

    mpz_clears(current, prime, factorial, NULL);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 5 || strcmp(argv[1], "-n") != 0 || strcmp(argv[3], "-o") != 0) {
        fprintf(stderr, "Usage: %s -n <number> -o <output.txt>\n", argv[0]);
        return 1;
    }

    mpz_t n;
    mpz_init(n);
    if (mpz_set_str(n, argv[2], 10) != 0) {
        fprintf(stderr, "Invalid number format\n");
        mpz_clear(n);
        return 1;
    }

    generate_pfield(n, argv[4]);

    mpz_clear(n);
    return 0;
}
