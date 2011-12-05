#ifndef _INSTREXCEPT_HPP_
#define _INSTREXCEPT_HPP_

#include <stdexcept>
#include <string>

class InstrExcept : public std::runtime_error{
 public:
  explicit InstrExcept(const std::string &wArg);
};

#endif
