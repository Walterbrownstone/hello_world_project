#include "hello_world.h"
#include "factorial.h"

int main() {
    // Print "Hello, World!"
    print_hello_world();

    // Print the factorial table up to n = 50
    printf("\nFactorials from 0 to 50:\n");
    print_factorial_table(50);

    return 0;
}
