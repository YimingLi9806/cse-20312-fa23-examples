/* duplicates2.c: table version */

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "library.h"

/* Functions */

bool has_duplicates(int *array, size_t n) {
    // Demo: malloc(n) -> segfault -> gdb
    bool *seen = calloc(n*n, sizeof(bool));

    for (size_t i = 0; i < n; i++) {
    	if (seen[array[i]])
    	    return true;
    	seen[array[i]] = true;
    }

    // Demo: forget to do this (valgrind)
    free(seen);
    return false;
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int numbers[NUMBERS_MAX] = {0};
    srand(time(NULL));
    make_random_array(numbers, NUMBERS_MAX);
    puts(has_duplicates(numbers, NUMBERS_MAX) ? "Yeah" : "Nope");
    return 0;
}
