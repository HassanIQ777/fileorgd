#include "libutils/File.hpp"
#include "libutils/funcs.hpp"
#include <cstdlib>
using funcs::print;

inline std::string getHome() {
  auto home = getenv("HOME");
  if (home == nullptr) {
    return "";
  }
  return home;
}