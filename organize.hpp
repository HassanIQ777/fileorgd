#pragma once

#include "Globals.hpp"
#include "libutils/File.hpp"

// gets files only
inline std::vector<std::string> getfiles(const std::string &dir) {
  std::vector<std::string> files;
  for (const auto &entry : fs::directory_iterator(dir)) {
    if (entry.is_directory()) {
      continue;
    }
    files.push_back(entry.path().string());
  }

  return files;
}

inline void createDirs() {
  Globals &g = Globals::getInstance();
  fs::path path = g.orgdir;

  if (auto dir = path / "PDF"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }
  if (auto dir = path / "Vidoes"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }

  if (auto dir = path / "Pictures"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }

  if (auto dir = path / "APK"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }

  if (auto dir = path / "Code"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }

  if (auto dir = path / "Others"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }
  if (auto dir = path / "Music"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }
}

inline void organizeFiles() {
  Globals &g = Globals::getInstance();
  fs::path path = g.orgdir;
}