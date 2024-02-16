#ifndef token_h
#define token_h
#include <iostream>
enum class TokenType {
  MoveRight,
  MoveLeft,
  Increment,
  Decrement,
  Output,
  Input,
  LoopStart,
  LoopEnd,
  Eof,
  Illegal,
};

const char *tokenToStr(TokenType tok);

typedef struct Token {
  TokenType type;
  char literal;
  Token(TokenType tokenType, char lit) {
    this->type = tokenType;
    this->literal = lit;
  }
  friend std::ostream &operator<<(std::ostream &output, const Token &t) {
    output << "{ type: " << tokenToStr(t.type) << ", literal : '" << t.literal
           << "' }";
    return output;
  }

} Token;

#endif // !token_h
