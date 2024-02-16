#ifndef lexer_h
#define lexer_h

#include "token.h"
#include <fstream>

class Lexer {
private:
  char currentChar = '\0';
  std::ifstream &file;
  bool ended = false;

  bool isValidChar(char ch);

public:
  Lexer(std::ifstream &file) : file{file} {};
  void nextChar();
  Token nextToken();
};
#endif // !lexer_h
