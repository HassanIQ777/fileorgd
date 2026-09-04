#include "Globals.hpp"
#include "libutils/File.hpp"
#include "libutils/funcs.hpp"
#include <cstdlib>
#include <filesystem>
#include <libutils/funcs.hpp>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
using funcs::print;

inline std::string getProgramHome() {
  auto home = getenv("HOME");
  if (home == nullptr) {
    return "";
  }
  // $HOME/.local/fileorgd/
  return fs::absolute(std::string(home) / fs::path(".local/share/fileorgd"))
      .string();
}

inline void createHomeDir(const std::string &path) {
  if (!File::isdirectory(path)) {
    if (File::createdirs(path)) {
      print("Created home directory.\n");
    } else {
      print("Failed to create home directory.\n");
    }
  } else {
    print("Home directory already exists.\n");
  }
}

inline void LOG(const std::string &msg) {
  Globals &g = Globals::getInstance();
  if (!File::isfile(g.files.logs_file))
    return;
  auto date = funcs::currentTime();
  std::string output = date + " -> " + msg;
  File::appendline(g.files.logs_file, output);
}

inline void daemonize() {
  pid_t pid = fork();
  if (pid < 0)
    exit(EXIT_FAILURE);
  if (pid > 0)
    exit(EXIT_SUCCESS); // let parent process exit

  if (setsid() < 0)
    exit(EXIT_FAILURE); // become session leader

  pid = fork(); // detach from terminal
  if (pid < 0)
    exit(EXIT_FAILURE);
  if (pid > 0)
    exit(EXIT_SUCCESS);

  umask(0);
  chdir("/");

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
}