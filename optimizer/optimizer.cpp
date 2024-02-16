#include "../parser/instruction.h"
// #include "../parser/parser.h"

void RemoveMultiOps(Instr **first_instr) {
  Instr *instr = *first_instr;
  while (instr != nullptr) {
    if (instr->instr == InstrType::IndexOp) {
      Instr *next = instr->next;
      while (next != nullptr && next->instr == InstrType::IndexOp) {
        instr->value += next->value;
        Instr *tmp = next;
        if (tmp == *first_instr) {
          *first_instr = next->next;
        }
        next = next->next;
        delete tmp;
      }
      instr->next = next;
    } else if (instr->instr == InstrType::ValueOp) {
      Instr *next = instr->next;
      while (next != nullptr && next->instr == InstrType::ValueOp) {
        instr->value += next->value;
        Instr *tmp = next;
        if (tmp == *first_instr) {
          *first_instr = next->next;
        }
        next = next->next;
        delete tmp;
      }
      instr->next = next;
    }
    instr = instr->next;
  }
}

void RemoveZeroOps(Instr **first_instr) {
  Instr *instr = *first_instr;
  while (instr != nullptr) {
    if (instr->instr == InstrType::IndexOp && instr->value == 0) {
      Instr *tmp = instr;
      if (tmp == *first_instr) {
        *first_instr = instr->next;
      }
      instr = instr->next;
      delete tmp;
    } else if (instr->instr == InstrType::ValueOp && instr->value == 0) {
      Instr *tmp = instr;
      if (tmp == *first_instr) {
        *first_instr = instr->next;
      }
      instr = instr->next;
      delete tmp;
    } else {
      instr = instr->next;
    }
  }
}

void RemoveJumpOps(Instr **first_instr) {
  Instr *instr = *first_instr;
  while (instr != nullptr) {
    if (instr->instr == InstrType::JumpIfZero &&
        instr->next->instr == InstrType::JumpIfNotZero &&
        instr->jNext == instr->next->next) {
      instr->instr = InstrType::IndexOp;
      instr->value = 0;
      instr->next = instr->jNext;
      instr->jNext = nullptr;
    } else if (instr->instr == InstrType::JumpIfNotZero &&
               instr->jNext == instr->next) {
      instr->instr = InstrType::IndexOp;
      instr->value = 0;
      instr->next = instr->jNext;
      instr->jNext = nullptr;
    }
    instr = instr->next;
  }
}

void RemoveDeadCode(Instr **first_instr) {
  Instr *instr = *first_instr;
  while (instr != nullptr) {
    if (instr->instr == InstrType::JumpIfZero && instr->jNext == nullptr) {
      instr->instr = InstrType::IndexOp;
      instr->value = 0;
      instr->next = nullptr;
    } else if (instr->instr == InstrType::JumpIfNotZero &&
               instr->jNext == nullptr) {
      instr->instr = InstrType::IndexOp;
      instr->value = 0;
      instr->next = nullptr;
    }
    instr = instr->next;
  }
}

int CountOps(Instr **first_instr) {
  int count = 0;
  Instr *instr = *first_instr;
  while (instr != nullptr) {
    count++;
    instr = instr->next;
  }
  return count;
}
void OptimizePass(Instr **first_instr) {
  RemoveMultiOps(first_instr);
  RemoveZeroOps(first_instr);
  // std::cout << "======================" << std::endl;
  // std::cout << "Ops: " << CountOps(first_instr) << std::endl;
  // Parser::visualize(*first_instr);
  // std::cout << "======================\n\n" << std::endl;
}

void Optimize(Instr **first_instr) {
  int initialCount = 0;
  int finalCount = 0;
  int midCount = 0;
  do {
    initialCount = CountOps(first_instr);
    OptimizePass(first_instr);
    finalCount = CountOps(first_instr);
  } while (initialCount > finalCount);
}
