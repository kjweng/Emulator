#include "cpu_i8080.h"
#include <stdint.h>

struct flags_i8080 {
    unsigned char s:1;
    unsigned char z:1;
    unsigned char i:1;
    unsigned char h:1;
    unsigned char pad1:1;
    unsigned char p:1;
    unsigned char pad2:1;
    unsigned char c:1;
};

struct cpu_i8080 {
    uint8_t reg_A;
    uint8_t reg_B;
    uint8_t reg_C;
    uint8_t reg_D;
    uint8_t reg_E;
    uint8_t reg_H;
    uint8_t reg_L;
    struct flags_i8080 flags;
    uint16_t pc;
    uint16_t sp;
};

