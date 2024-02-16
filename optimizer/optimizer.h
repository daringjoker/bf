#include "../parser/instruction.h"

void Optimize(Instr **first_instr);
int CountOps(Instr **first_instr);
void RemoveDeadCode(Instr **first_instr);
void RemoveJumpOps(Instr **first_instr);
void RemoveZeroOps(Instr **first_instr);
void RemoveMultiOps(Instr **first_instr);
