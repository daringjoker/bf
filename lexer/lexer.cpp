#include "lexer.h"

bool Lexer::isValidChar(char ch) {
  return ch == '<' || ch == '>' || ch == '+' || ch == '-' || ch == '.' ||
         ch == ',' || ch == '[' || ch == ']' || ch == '\0';
}

Token Lexer::nextToken() {

  nextChar();
  switch (this->currentChar) {
  case '+':
    return Token(TokenType::Increment, '+');
  case '-':
    return Token(TokenType::Decrement, '-');
  case '>':
    return Token(TokenType::MoveRight, '>');
  case '<':
    return Token(TokenType::MoveLeft, '<');
  case '.':
    return Token(TokenType::Output, '.');
  case ',':
    return Token(TokenType::Input, ',');
  case '[':
    return Token(TokenType::LoopStart, '[');
  case ']':
    return Token(TokenType::LoopEnd, ']');
  case '\0':
    this->ended = true;
    return Token(TokenType::Eof, '\0');
  default:
    return Token(TokenType::Illegal, '\0');
  }
}

void Lexer::nextChar() {
  this->currentChar = '\0';
  while (!this->ended) {
    this->file >> this->currentChar;
    if (this->isValidChar(this->currentChar)) {
      break;
    }
  }
}
