#include "vm.h"
using namespace std;
void VM::runInstr(Instr *instr) {
  // if (instr->instr == InstrType::JumpIfZero ||
  //     instr->instr == InstrType::JumpIfNotZero) {
  //   cout << instr << ":" << *instr << "  Index: " << this->index
  //        << " Value: " << int(this->tape[index]);
  // }
  nextInstr = nullptr;
  switch (instr->instr) {
  case InstrType::IndexOp:
    // cout << "pre-index: " << index << " value: " << instr->value;
    index += instr->value;
    // cout << " post-index: " << index << endl;
    break;
  case InstrType::ValueOp:
    tape[index] += instr->value;
    break;
  case InstrType::JumpIfZero:
    if (tape[index] == 0) {
      nextInstr = instr->jNext;
    }
    break;
  case InstrType::JumpIfNotZero:
    if (tape[index] != 0) {
      nextInstr = instr->jNext;
    }
    break;
  case InstrType::In:
    tape[index] = fgetc(stdin);
    break;
  case InstrType::Out:
    // printf("out: '%c' 0x%02x\n", tape[index], tape[index]);
    putchar(tape[index]);
    break;
  case InstrType::End:
    exit(0);
    break;
  }
  if (index >= tapeSize) {
    tape.resize(index + 100);
    tapeSize = index + 100;
  }
  // printf("'%c' 0x%02x %d\n", tape[index], tape[index], tape[index]);
  if (nextInstr == nullptr) {
    nextInstr = instr->next;
  }
  // if (instr->instr == InstrType::JumpIfZero ||
  //     instr->instr == InstrType::JumpIfNotZero) {
  //   cout << " Next:" << nextInstr << endl;
  // }
}

VM::VM(Instr *begin) {
  tape.resize(1000);
  tapeSize = 1000;
  index = 500;
  nextInstr = begin;
}

void VM::next() { runInstr(nextInstr); }

void VM::run() {
  while (nextInstr != nullptr) {
    next();
  }
}
