#ifndef vm_h
#define vm_h
#include "../parser/instruction.h"
#include "../parser/parser.h"
#include <cstddef>
#include <vector>
class VM {
private:
  std::vector<unsigned char> tape;
  std::size_t index = 0;
  std::size_t tapeSize = 0;
  Instr *nextInstr;
  void runInstr(Instr *instr);

public:
  VM(Instr *begin);
  void next();
  void run();
};

#endif // !vm_h
