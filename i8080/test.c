#include <stdio.h>
#include "cpu_i8080.h"

int main() {
    printf("%lu\n", sizeof(struct flags_i8080));
    struct cpu_i8080 cpu;

    printf("%d\n", nop(&cpu));
    return 0;
}
