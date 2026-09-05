#pragma once

#include "Globals.hpp"
#include "libutils/File.hpp"
#include "libutils/funcs.hpp"
#include <vector>

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

  if (auto dir = path / "APK"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }
  if (auto dir = path / "Code"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }
  if (auto dir = path / "Documents"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }
  if (auto dir = path / "Music"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }
  if (auto dir = path / "Others"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }
  if (auto dir = path / "Pictures"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }
  if (auto dir = path / "Vidoes"; !File::isdirectory(dir)) {
    File::createdir(dir);
  }
}

inline bool shouldMoveFile(const std::string &filepath,
                           const std::vector<std::string> &extensions_list) {
  auto ext = funcs::lowercase(File::getExtension(filepath));
  for (const auto &ext : extensions_list) {
    if (funcs::lowercase(ext) == ext) {
      return true;
    }
  }
  return false;
}

inline void organizeFiles() {
  Globals &g = Globals::getInstance();
  fs::path path = g.orgdir;

  auto files = getfiles(path);
  for (const auto &file : files) {
    if (shouldMoveFile(file, g.extensions.picture)) {
      File::movefile(file, path / "Pictures" / file);
    } else if (shouldMoveFile(file, g.extensions.video)) {
      File::movefile(file, path / "Videos" / file);
    } else if (shouldMoveFile(file, g.extensions.music)) {
      File::movefile(file, path / "Music" / file);
    } else if (shouldMoveFile(file, g.extensions.documents)) {
      File::movefile(file, path / "Documents" / file);
    } else if (shouldMoveFile(file, g.extensions.code)) {
      File::movefile(file, path / "Code" / file);
    } else if (shouldMoveFile(file, g.extensions.apk)) {
      File::movefile(file, path / "APK" / file);
    }

    else {
      File::movefile(file, path / "Others" / file);
    }
  }
}