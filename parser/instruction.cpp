#include "instruction.h"
#include <ostream>
std::ostream &operator<<(std::ostream &os, InstrType const &instrType) {
  switch (instrType) {
  case InstrType::IndexOp:
    os << "IndexOp";
    break;
  case InstrType::ValueOp:
    os << "ValueOp";
    break;
  case InstrType::JumpIfZero:
    os << "JumpIfZero";
    break;
  case InstrType::JumpIfNotZero:
    os << "JumpIfNotZero";
    break;
  case InstrType::In:
    os << "In";
    break;
  case InstrType::Out:
    os << "Out";
    break;
  case InstrType::End:
    os << "End";
    break;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, Instr const &instr) {
  os << "Instr(" << instr.instr << ", value: " << instr.value
     << ", next: " << instr.next << ", jNext: " << instr.jNext << ")";
  return os;
}
