#ifndef instruction_h
#define instruction_h
#include <ostream>
enum class InstrType {
  IndexOp,
  ValueOp,
  JumpIfZero,
  JumpIfNotZero,
  In,
  Out,
  End
};
class Instr {
public:
  InstrType instr;
  int value;
  Instr *next;
  Instr *jNext;
};

std::ostream &operator<<(std::ostream &os, InstrType const &instrType);
std::ostream &operator<<(std::ostream &os, Instr const &instr);
#endif // !instruction_h
