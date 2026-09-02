#include "helpers.hpp"
#include <cstdlib>
#include <iostream>
#include <libutils/funcs.hpp>
#include <sched.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  auto home = getProgramHome();
  if (!File::isdirectory(home)) {
    if (File::createdirs(home)) {
      print("Created home directory.\n");
    } else {
      print("Failed to create home directory.\n");
    }
  } else {
    print("Home directory already exists.\n");
  }
  print("Home directory: '", home, "'\n");
}