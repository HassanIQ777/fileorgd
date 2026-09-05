#include "Globals.hpp"
#include "libutils/File.hpp"
#include "libutils/Log.hpp"
#include "libutils/funcs.hpp"
#include <cstdlib>
#include <filesystem>
#include <fstream>
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
      // print("Created home directory.\n");
    } else {
      // print("Failed to create home directory.\n");
    }
  } else {
    // print("Home directory already exists.\n");
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

inline void printHelp(Globals &globals) {
  const std::string program_name = globals.parser.getArg(0);
  print("Usage:\n");
  print("  ", program_name, " <dir to organize>\n");
  print("  ", program_name, " -h    print this help message\n");
  print("  ", program_name, " -v    print version\n");
  print("  ", program_name, " -s    stop program\n");
}

inline void parseArgs() {
  Globals &g = Globals::getInstance();
  if (int argc = g.parser.getArgc(); argc != 2) {
    if (argc == 1) {
      Log::error(0, "One argument is required but nothing was provided.");
    } else {
      Log::error(0, "One argument is required but " +
                        funcs::str(g.parser.getArgc() - 1) +
                        " arguments were provided.");
    }
    printHelp(g);
    exit(EXIT_FAILURE);
  }

  const std::string first_arg = g.parser.getArg(1);
  if (first_arg == "-h") {
    printHelp(g);
    exit(0);
  } else if (first_arg == "-v") {
    print("fileorgd version ", g.VERSION, "\n");
    exit(0);
  } else if (first_arg == "-s") {
    std::ofstream file(g.files.pid_file, std::ios::trunc); // truncate file
    std::system("pkill fileorgd");
  }

  if (File::isdirectory(first_arg)) {
    g.orgdir = first_arg;
  } else {
    Log::error(1, "The provided path is not a directory.");
  }
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