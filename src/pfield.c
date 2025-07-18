#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <math.h>

// Renamed this function to avoid naming conflict
bool check_prime(unsigned long num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (unsigned long i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void generate_prime_pattern(unsigned long n, const char *output_file) {
    mpz_t factorial;
    mpz_init(factorial);
    mpz_fac_ui(factorial, n);
    unsigned long factorial_val = mpz_get_ui(factorial);

    char *pattern = malloc(factorial_val + 1);
    memset(pattern, '*', factorial_val);
    pattern[factorial_val] = '\0';

    FILE *fp = fopen(output_file, "w");
    if (!fp) {
        perror("Error opening file");
        free(pattern);
        mpz_clear(factorial);
        return;
    }

    fprintf(fp, "Prime Factorization Pattern for %lu! (%lu characters):\n", n, factorial_val);
    fprintf(fp, "Initial pattern: %s\n\n", pattern);

    // Mark multiples of primes ≤ n
    for (unsigned long prime = 2; prime <= n; prime++) {
        if (check_prime(prime)) {
            fprintf(fp, "Marking multiples of prime %lu:\n", prime);
            for (unsigned long multiple = prime; multiple <= factorial_val; multiple += prime) {
                if (pattern[multiple-1] == '*') {
                    pattern[multiple-1] = '-';
                }
            }
            fprintf(fp, "Current pattern: %s\n\n", pattern);
        }
    }

    // Count and list prime-positioned stars
    unsigned long prime_stars = 0;
    fprintf(fp, "Prime positions with stars:\n");
    for (unsigned long pos = 1; pos <= factorial_val; pos++) {
        if (pattern[pos-1] == '*') {
            bool is_prime_pos = (pos == 1) || check_prime(pos);
            if (is_prime_pos) {
                prime_stars++;
                fprintf(fp, "Position %lu (%s)\n", pos, pos == 1 ? "unity" : "prime");
            }
        }
    }
    fprintf(fp, "Total prime-positioned stars: %lu\n", prime_stars);
    fprintf(fp, "Final pattern:\n%s\n", pattern);

    free(pattern);
    mpz_clear(factorial);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <n> <output_file>\n", argv[0]);
        return 1;
    }
    
    errno = 0;
    unsigned long n = strtoul(argv[1], NULL, 10);
    if (n == 0 && errno == EINVAL) {
        fprintf(stderr, "Invalid number format\n");
        return 1;
    }
    
    generate_prime_pattern(n, argv[2]);
    return 0;
}
