#include "cpu_i8080.h"
#include <stdint.h>

// Opcode implementation
Result nop() {
    return OK;
}

Result mov(struct cpu_i8080* cpu, Register_i8080 dest, Register_i8080 src) {
    if (dest == M && dest == src) return FAIL;

    if (src == M) {
        ptr_t addr = (ptr_t)(cpu->registers + H);
        byte_t data = cpu->mem->ram[addr];
        cpu->registers[dest] = data;

    } else if (dest == M) { 
        ptr_t addr = (ptr_t)(cpu->registers + H);
        cpu->mem->ram[addr] = cpu->registers[src];
    } else {
        cpu->registers[dest] = cpu->registers[src];
    }
    // TODO:Set status registers
    return OK;
}
