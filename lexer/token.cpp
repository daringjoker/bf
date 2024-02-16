#include "token.h"
const char *tokenToStr(TokenType tok) {
  switch (tok) {
  case TokenType::MoveLeft:
    return "MOVELEFT";
  case TokenType::MoveRight:
    return "MOVERIGHT";
  case TokenType::Increment:
    return "INCREMENT";
  case TokenType::Decrement:
    return "DECREMENT";
  case TokenType::Output:
    return "OUTPUT";
  case TokenType::Input:
    return "INPUT";
  case TokenType::LoopStart:
    return "LOOPSTART";
  case TokenType::LoopEnd:
    return "LOOPEND";
  case TokenType::Eof:
    return "EOF";
  case TokenType::Illegal:
    return "ILLEGAL";
  default:
    return "UNKNOWN";
  }
}
