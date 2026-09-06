#include "organize.hpp"

int main(int argc, char **argv) {
  Globals &g = Globals::getInstance();
  g.parser.setArgs(argc, argv);
  g.files.program_dir = getProgramHome();
  createHomeDir(g.files.program_dir);

  g.files.assignPaths();
  g.files.createFiles();
  parseArgs();
  daemonize();

  g.pid = getpid();
  LOG("Program started with PID " + funcs::str(g.pid));
  LOG("Organizing directory '" + fs::absolute(g.orgdir).string());

  while (1) {
    funcs::msleep(10000);
    auto files = getfiles(g.orgdir);
    if (files.empty()) {
      continue;
    }
    createDirs();
    organizeFiles();
    removeEmptyDirs();
  }
}
