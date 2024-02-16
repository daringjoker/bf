#ifndef parser_h
#define parser_h

#include "../lexer/token.h"
#include "instruction.h"
#include <stack>
#include <vector>

class Parser {
private:
  Instr *begin;
  std::stack<Instr *> jumpStack;
  int loopEnd = -1;

public:
  Parser(std::vector<Token> tokenList);
  Instr *getBegin() { return this->begin; };
  static void visualize(Instr *beginning);
};

#endif // !parser_h
