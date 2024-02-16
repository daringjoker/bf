#include "parser.h"
using namespace std;

#include "instruction.h"
Parser::Parser(std::vector<Token> tokenList) {
  Instr *prev = nullptr;
  for (auto token : tokenList) {
    Instr *newInstr = new Instr();
    switch (token.type) {
    case TokenType::MoveLeft:
      newInstr->instr = InstrType::IndexOp;
      newInstr->value = -1;
      break;
    case TokenType::MoveRight:
      newInstr->instr = InstrType::IndexOp;
      newInstr->value = 1;
      break;
    case TokenType::Increment:
      newInstr->instr = InstrType::ValueOp;
      newInstr->value = 1;
      break;
    case TokenType::Decrement:
      newInstr->instr = InstrType::ValueOp;
      newInstr->value = -1;
      break;
    case TokenType::Output:
      newInstr->instr = InstrType::Out;
      newInstr->value = 0;
      break;
    case TokenType::Input:
      newInstr->instr = InstrType::In;
      newInstr->value = 0;
      break;
    case TokenType::LoopStart:
      newInstr->instr = InstrType::JumpIfZero;
      this->jumpStack.push(newInstr);
      newInstr->value = 0;
      break;
    case TokenType::LoopEnd:
      newInstr->instr = InstrType::JumpIfNotZero;
      newInstr->jNext = this->jumpStack.top();
      this->loopEnd = 1;
      newInstr->value = 0;
      break;
    case TokenType::Eof:
      newInstr->instr = InstrType::End;
      newInstr->value = 0;
      break;
    case TokenType::Illegal:
      newInstr->instr = InstrType::End;
      newInstr->value = 0;
      break;
    }
    if (this->loopEnd >= 0) {
      if (this->loopEnd == 0) {
        this->jumpStack.top()->jNext = newInstr;
        this->jumpStack.pop();
      }
      this->loopEnd--;
    }
    if (prev != nullptr) {
      prev->next = newInstr;
    } else {
      this->begin = newInstr;
    }
    prev = newInstr;
  }
}

void Parser::visualize(Instr *beginning) {
  Instr *instr = beginning;
  unsigned int numTabs = 0;
  while (instr != nullptr) {
    for (unsigned int i = 0; i < numTabs; i++) {
      cout << "    ";
    }
    cout << instr << ": " << *instr << endl;
    if (instr->instr == InstrType::JumpIfZero) {
      numTabs++;
    }
    if (instr->instr == InstrType::JumpIfNotZero) {
      numTabs--;
    }
    instr = instr->next;
  }
}
