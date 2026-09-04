#pragma once

#include "libutils/CLIParser.hpp"
#include "libutils/File.hpp"
#include "libutils/funcs.hpp"
#include <filesystem>
#include <string>

using funcs::print;
namespace fs = std::filesystem;

struct FilePaths {
  std::string program_dir; // directories
  std::string logs_file, pid_file;   // files

  void assignPaths() { logs_file = fs::path(program_dir) / "logs.txt"; }
  void createFiles() {
    if (!File::isfile(logs_file)) {
      File::createfile(logs_file);
    }
    if (!File::isfile(pid_file)) {
      File::createfile(pid_file);
    }
  }
};

struct Globals {
  std::string VERSION = "v26.9.5";
  FilePaths files;
  CLIParser parser;

  static Globals &getInstance() {
    static Globals g;
    return g;
  }

  Globals(const Globals &) = delete;
  Globals(Globals &&) = delete;
  Globals &operator=(const Globals &) = delete;
  Globals &operator=(Globals &&) = delete;

private:
  Globals() = default;
}; // Singleton struct Globals