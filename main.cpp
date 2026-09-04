#include "Globals.hpp"
#include "helpers.hpp"
#include "libutils/funcs.hpp"
#include <libutils/funcs.hpp>
#include <unistd.h>

int main() {
  daemonize();

  Globals &g = Globals::getInstance();

  g.files.program_dir = getProgramHome();
  createHomeDir(g.files.program_dir);
  g.files.assignPaths();
  g.files.createFiles();
  LOG("Program started with PID " + funcs::str(getpid()));

  while (1) {
    funcs::msleep(1000);
  }
}