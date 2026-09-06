#pragma once

#include "helpers.hpp"

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
  auto file_ext = funcs::lowercase(File::getExtension(filepath));
  for (const auto &ext : extensions_list) {
    if (funcs::lowercase(ext) == file_ext) {
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
    std::string filename = File::getFileName(file);
    std::string destination = "Others";
    if (shouldMoveFile(file, g.extensions.picture)) {
      destination = "Pictures";
    } else if (shouldMoveFile(file, g.extensions.video)) {
      destination = "Vidoes";
    } else if (shouldMoveFile(file, g.extensions.music)) {
      destination = "Music";
    } else if (shouldMoveFile(file, g.extensions.documents)) {
      destination = "Documents";
    } else if (shouldMoveFile(file, g.extensions.code)) {
      destination = "Code";
    } else if (shouldMoveFile(file, g.extensions.apk)) {
      destination = "APK";
    }

    fs::path new_path = path / destination / filename;

    File::movefile(file, new_path);

    LOG("Moved '" + file + "' to '" + fs::absolute(new_path).string() + "'");
  }
}

inline void removeEmptyDirs() {
  Globals &g = Globals::getInstance();
  fs::path path = g.orgdir;
  const std::vector<std::string> dirs = {
      "Others", "Pictures", "Vidoes", "Music", "Documents", "Code", "APK"};
  for (const auto &dir : dirs) {
    auto current_dir = path / dir;
    if (getfiles(current_dir).empty()) {
      if (File::removedir(current_dir)) {
        LOG("Removed empty directory '" + current_dir.string() + "'");
      }
    }
  }
}