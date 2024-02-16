#include "lexer/lexer.h"
#include "optimizer/optimizer.h"
#include "parser/parser.h"
#include "vm/vm.h"
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <filename>" << endl;
    return 1;
  }
  ifstream inputFile(argv[1]);
  Lexer l(inputFile);
  vector<Token> tokenList;
  while (!inputFile.eof()) {
    const Token &t = l.nextToken();
    // cout << t << endl;
    tokenList.push_back(t);
  }
  Parser p(tokenList);
  Instr *begin = p.getBegin();
  // p.visualize(begin);
  Optimize(&begin);
  VM vm(begin);
  vm.run();
  return 0;
}
