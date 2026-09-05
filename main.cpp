#include "Globals.hpp"
#include "helpers.hpp"
#include "libutils/funcs.hpp"
#include "organize.hpp"
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
  Globals &g = Globals::getInstance();
  g.parser.setArgs(argc, argv);
  g.files.program_dir = getProgramHome();
  createHomeDir(g.files.program_dir);
  
  g.files.assignPaths();
  g.files.createFiles();
  parseArgs();
  daemonize();

  pid_t pid = getpid();
  LOG("Program started with PID " + funcs::str(pid));

  while (1) {
    createDirs();
    funcs::msleep(10000);
  }
}
