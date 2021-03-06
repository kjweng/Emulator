#ifndef _CPU_I8080
#define _CPU_I8080

#include <stdint.h>
// Typedefs
typedef uint8_t reg_t;
typedef uint16_t ptr_t;
typedef unsigned char byte_t;

// Struct definitions
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

struct memory {
    byte_t ram[UINT16_MAX];
    byte_t stk[UINT16_MAX];
    byte_t data[UINT16_MAX];
};

struct cpu_i8080 {
    reg_t registers[7];
    struct flags_i8080 flags;
    ptr_t pc;
    ptr_t sp;
    struct memory* mem;
};

// Enums
typedef enum opcode_i8080 {
    NOP,
    LXI_B,
    STAX_B,
    INX_B,
    INR_B,
    DCR_B,
    MVI_B,
    RLC,
    NOP_8,
    DAD_B,
    LDAX_B,
    DCX_B,
    INR_C,
    DCR_C,
    MVI_C,
    RRC,
    NOP_10,
    LXI_D,
    STAX_D,
    INX_D,
    INR_D,
    DCR_D,
    MVI_D,
    RAL,
    NOP_18,
    DAD_D,
    LDAX_D,
    DCX_D,
    INR_E,
    DCR_E,
    MVI_E,
    RAR,
    NOP_20,
    LXI_H,
    SHLD,
    INX_H,
    INR_H,
    DCR_H,
    MVI_H,
    DAA,
    NOP_28,
    DAD_H,
    LHLD,
    DCX_H,
    INR_L,
    DCR_L,
    MVI_L,
    CMA,
    NOP_30,
    LXI_SP,
    STA,
    INX_SP,
    INR_M,
    DCR_M,
    MVI_M,
    STC,
    NOP_38,
    DAD_SP,
    LDA,
    DCX_SP,
    INR_A,
    DCR_A,
    MVI_A,
    CMC,
    MOV_B_B,
    MOV_B_C,
    MOV_B_D,
    MOV_B_E,
    MOV_B_H,
    MOV_B_L,
    MOV_B_M,
    MOV_B_A,
    MOV_C_B,
    MOV_C_C,
    MOV_C_D,
    MOV_C_E,
    MOV_C_H,
    MOV_C_L,
    MOV_C_M,
    MOV_C_A,
    MOV_D_B,
    MOV_D_C,
    MOV_D_D,
    MOV_D_E,
    MOV_D_H,
    MOV_D_L,
    MOV_D_M,
    MOV_D_A,
    MOV_E_B,
    MOV_E_C,
    MOV_E_D,
    MOV_E_E,
    MOV_E_H,
    MOV_E_L,
    MOV_E_M,
    MOV_E_A,
    MOV_H_B,
    MOV_H_C,
    MOV_H_D,
    MOV_H_E,
    MOV_H_H,
    MOV_H_L,
    MOV_H_M,
    MOV_H_A,
    MOV_L_B,
    MOV_L_C,
    MOV_L_D,
    MOV_L_E,
    MOV_L_H,
    MOV_L_L,
    MOV_L_M,
    MOV_L_A,
    MOV_M_B,
    MOV_M_C,
    MOV_M_D,
    MOV_M_E,
    MOV_M_H,
    MOV_M_L,
    HLT,
    MOV_M_A,
    MOV_A_B,
    MOV_A_C,
    MOV_A_D,
    MOV_A_E,
    MOV_A_H,
    MOV_A_L,
    MOV_A_M,
    MOV_A_A,
    ADD_B,
    ADD_C,
    ADD_D,
    ADD_E,
    ADD_H,
    ADD_L,
    ADD_M,
    ADD_A,
    ADC_B,
    ADC_C,
    ADC_D,
    ADC_E,
    ADC_H,
    ADC_L,
    ADC_M,
    ADC_A,
    SUB_B,
    SUB_C,
    SUB_D,
    SUB_E,
    SUB_H,
    SUB_L,
    SUB_M,
    SUB_A,
    SBB_B,
    SBB_C,
    SBB_D,
    SBB_E,
    SBB_H,
    SBB_L,
    SBB_M,
    SBB_A,
    ANA_B,
    ANA_C,
    ANA_D,
    ANA_E,
    ANA_H,
    ANA_L,
    ANA_M,
    ANA_A,
    XRA_B,
    XRA_C,
    XRA_D,
    XRA_E,
    XRA_H,
    XRA_L,
    XRA_M,
    XRA_A,
    ORA_B,
    ORA_C,
    ORA_D,
    ORA_E,
    ORA_H,
    ORA_L,
    ORA_M,
    ORA_A,
    CMP_B,
    CMP_C,
    CMP_D,
    CMP_E,
    CMP_H,
    CMP_L,
    CMP_M,
    CMP_A,
    RNZ,
    POP_B,
    JNZ,
    JMP,
    CNZ,
    PUSH_B,
    ADI,
    RST_0,
    RZ,
    RET,
    JZ,
    JMP_CB,
    CZ,
    CALL,
    ACI,
    RST_1,
    RNC,
    POP_D,
    JNC,
    OUT,
    CNC,
    PUSH_D,
    SUI,
    RST_2,
    RC,
    RET_D9,
    JC,
    IN,
    CC,
    CALL_DD,
    SBI,
    RST_3,
    RPO,
    POP_H,
    JPO,
    XTHL,
    CPO,
    PUSH_H,
    ANI,
    RST_4,
    RPE,
    PCHL,
    JPE,
    XCHG,
    CPE,
    CALL_ED,
    XRI,
    RST_5,
    RP,
    POP_PSW,
    JP,
    DI,
    CP,
    PUSH_PSW,
    ORI,
    RST_6,
    RM,
    SPHL,
    JM,
    EI,
    CM,
    CALL_FD,
    CPI,
    RST_7
} Opcode_i8080;

typedef enum register_i8080 {
    // Actual registers
    A,
    B,
    C,
    D,
    E,
    H,
    L,
    // Combination of registers
    M // (HL)
} Register_i8080;

typedef enum result {
    OK,
    FAIL
} Result;

// Function signatures
// Opcodes
Result nop(struct cpu_i8080* cpu);
Result mov(struct cpu_i8080* cpu, Register_i8080 dest, Register_i8080 src);
Result add(struct cpu_i8080* cpu, Register_i8080 reg);
Result adi(struct cpu_i8080* cpu, byte_t byte);
Result adc(struct cpu_i8080* cpu, Register_i8080 reg);
Result aci(struct cpu_i8080* cpu, byte_t byte);
Result sub(struct cpu_i8080* cpu, Register_i8080 reg);
Result sui(struct cpu_i8080* cpu, byte_t byte);
Result sbb(struct cpu_i8080* cpu, Register_i8080 reg);
Result sbi(struct cpu_i8080* cpu, byte_t byte);
Result inr(struct cpu_i8080* cpu, Register_i8080 reg);
Result dcr(struct cpu_i8080* cpu, Register_i8080 reg);
Result inx(struct cpu_i8080* cpu, Register_i8080 reg);
Result dcx(struct cpu_i8080* cpu, Register_i8080 reg);
Result ana(struct cpu_i8080* cpu, Register_i8080 reg);
Result ani(struct cpu_i8080* cpu, byte_t byte);
Result xra(struct cpu_i8080* cpu, Register_i8080 reg);
Result xri(struct cpu_i8080* cpu, byte_t byte);
Result ora(struct cpu_i8080* cpu, Register_i8080 reg);
Result ori(struct cpu_i8080* cpu, byte_t byte);
Result cmp(struct cpu_i8080* cpu, Register_i8080 reg);
Result cpi(struct cpu_i8080* cpu, byte_t byte);
Result jmp(struct cpu_i8080* cpu, ptr_t addr);


#endif
