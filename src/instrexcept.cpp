#include "instrexcept.hpp"

InstrExcept::InstrExcept(const std::string &wArg) : std::runtime_error(wArg)
{
}


