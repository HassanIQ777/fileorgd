#pragma once

#include "libutils/CLIParser.hpp"
#include "libutils/File.hpp"
#include "libutils/funcs.hpp"
#include <filesystem>
#include <string>

using funcs::print;
namespace fs = std::filesystem;

struct FilePaths {
  std::string program_dir;         // directories
  std::string logs_file, pid_file; // files

  void assignPaths() {
    logs_file = fs::path(program_dir) / "logs.txt";
    pid_file = fs::path(program_dir) / ".pid";
  }
  void createFiles() {
    if (!File::isfile(logs_file)) {
      File::createfile(logs_file);
    }
    if (!File::isfile(pid_file)) {
      File::createfile(pid_file);
    }
  }
};

struct Extensions {
  const std::vector<std::string> apk = {".apk", ".xapk"};
  const std::vector<std::string> code = { // C Family
      ".c", ".h", ".cpp", ".cc", ".cxx", ".c++", ".hpp", ".hh", ".hxx", ".h++",
      ".m", ".mm",

      // C# / .NET / F# / VB
      ".cs", ".fs", ".fsx", ".vb",

      // Java / JVM
      ".java", ".kt", ".kts", ".scala", ".sc", ".groovy", ".gvy", ".clj",
      ".cljs", ".cljc", ".edn",

      // Python
      ".py", ".pyi", ".pyw", ".ipynb",

      // JavaScript / TypeScript / Web
      ".js", ".mjs", ".cjs", ".jsx", ".ts", ".tsx", ".vue", ".svelte", ".astro",
      ".html", ".htm", ".css", ".scss", ".sass", ".less", ".styl", ".xml",
      ".xsl", ".xslt", ".svg", ".wasm", ".wat",

      // Systems / Low-Level
      ".rs", ".go", ".zig", ".nim", ".d", ".v", ".vh", ".sv", ".svh", ".asm",
      ".s", ".S", ".ptx", ".cu", ".cuh", ".metal", ".glsl", ".vert", ".frag",
      ".geom", ".comp", ".hlsl", ".hlsli", ".wgsl", ".spv",

      // Scripting / Shell
      ".sh", ".bash", ".zsh", ".ksh", ".csh", ".tcsh", ".fish", ".ps1", ".psm1",
      ".psd1", ".bat", ".cmd", ".pl", ".pm", ".rb", ".gemspec", ".php",
      ".phtml", ".lua", ".tcl", ".r", ".R", ".jl",

      // Functional / Niche
      ".hs", ".lhs", ".ml", ".mli", ".elm", ".ex", ".exs", ".erl", ".hrl",
      ".scm", ".ss", ".lisp", ".lsp", ".agda", ".lean", ".coq", ".idr", ".purs",
      ".opa", ".io", ".haxe", ".hx", ".cr", ".dart",

      // Legacy
      ".bas", ".pas", ".pp", ".ada", ".adb", ".ads", ".for", ".f", ".f90",
      ".f95", ".f03", ".f08", ".cob", ".cbl", ".pl1", ".vhd", ".vhdl",

      // Databases
      ".sql", ".ddl", ".dml", ".prisma", ".graphql", ".gql",

      // Data / Config / Serialization
      ".json", ".json5", ".jsonc", ".yaml", ".yml", ".toml", ".ini", ".cfg",
      ".conf", ".properties", ".env", ".csv", ".tsv", ".proto", ".thrift",
      ".avsc", ".hcl", ".tf", ".tfvars", ".nix", ".flake.nix",

      // Build / Project
      ".cmake", ".mk", ".makefile", ".gradle", ".pom", ".csproj", ".sln",
      ".podspec", ".cabal", ".meson", ".meson.build", ".bazel", ".bzl",
      ".ninja", ".justfile", ".dub", ".nimble", ".gitignore", ".gitattributes",
      ".editorconfig",

      // Templates
      ".twig", ".njk", ".j2", ".ejs", ".hbs", ".handlebars", ".pug", ".jade",
      ".haml", ".slim", ".liquid", ".blade.php", ".mdx",

      // Mobile
      ".xib", ".storyboard", ".plist",

      // AI / ML
      ".onnx", ".pb", ".tflite", ".pt", ".pth", ".h5", ".hdf5", ".pkl",
      ".pickle", ".safetensors", ".gguf",

      // Game Engines
      ".gd", ".gml", ".tscn", ".tres",

      // Documentation / Markup
      ".md", ".markdown", ".rst", ".adoc", ".org", ".tex", ".bib", ".pod",
      ".rdoc", ".dox",

      // Lockfiles / Manifests
      ".lock", ".mod", ".sum"};

  const std::vector<std::string> documents = {
      // Word Processing
      ".doc", ".docx", ".docm", ".dot", ".dotx", ".dotm", ".odt", ".ott",
      ".rtf", ".txt", ".text", ".log", ".tex", ".md", ".markdown", ".epub",
      ".mobi", ".azw", ".azw3", ".fb2", ".djvu", ".djv", ".chm", ".hlp",

      // PDF & Related
      ".pdf", ".xps", ".oxps", ".cbz", ".cbr", ".cbt", ".cb7",

      // Spreadsheets
      ".xls", ".xlsx", ".xlsm", ".xlt", ".xltx", ".xltm", ".ods", ".ots",
      ".csv", ".tsv", ".gs", ".numbers", ".sxc",

      // Presentations
      ".ppt", ".pptx", ".pptm", ".pot", ".potx", ".potm", ".odp", ".otp",
      ".key", ".ppsx", ".ppsm",

      // Database
      ".mdb", ".accdb", ".db", ".sqlite", ".sqlite3", ".dbf", ".parquet",
      ".avro",

      // Markup & Data
      ".xml", ".xsl", ".xslt", ".json", ".json5", ".jsonc", ".yaml", ".yml",
      ".toml", ".ini", ".cfg", ".conf", ".plist", ".csv", ".rss", ".atom",
      ".html", ".htm", ".xhtml", ".svg",

      // Email
      ".eml", ".msg", ".mbox", ".mime",

      // Archives (document-adjacent)
      ".zip", ".rar", ".7z", ".tar", ".gz", ".bz2", ".xz", ".iso",

      // E-Book / Publishing
      ".epub", ".mobi", ".azw", ".azw3", ".fb2", ".fb2.zip", ".lit", ".lrf",
      ".pdb", ".ibooks",

      // LaTeX / Academic
      ".tex", ".bib", ".cls", ".sty", ".aux", ".toc", ".bbl",

      // Other
      ".rtf", ".wps", ".wpd", ".docbook", ".sgml", ".dtd", ".asciidoc", ".org",
      ".reStructuredText", ".rst", ".adoc", ".man", ".info", ".pdf", ".ps",
      ".eps"};

  const std::vector<std::string> music = {
      // Lossy Compressed
      ".mp3", ".aac", ".adts", ".adif", ".ogg", ".oga", ".opus", ".wma", ".m4a",
      ".mp4a", ".aac", ".amr", ".awb", ".dss", ".evo", ".f4a", ".mka", ".oga",
      ".opus", ".spx", ".vqf", ".wv", ".ape", ".tta", ".mlp", ".eac3", ".ac3",
      ".dts", ".ddp",

      // Lossless / Uncompressed
      ".flac", ".wav", ".wave", ".wve", ".aif", ".aiff", ".aifc", ".alac",
      ".wve", ".raw", ".au", ".snd", ".caf", ".w64", ".rf64", ".ape", ".tta",
      ".mlp", ".dsf", ".dff", ".mqa", ".pcm", ".aif", ".aiff", ".aifc",
      ".wma", // can be lossless too

      // MIDI / Sequencing
      ".mid", ".midi", ".kar", ".mxl", ".mxs", ".smf", ".smpl", ".smp", ".mml",
      ".abc", ".mus",

      // Audio-Only Containers / Codecs
      ".ac3", ".eac3", ".dts", ".dtshd", ".ddp", ".truehd", ".mlp", ".opus",
      ".vorbis", ".silk", ".g711", ".g726", ".g722", ".g729", ".ilbc", ".siren",
      ".atrac", ".atrac3", ".atrac3plus", ".atrac3p", ".atrac3pa", ".atrac3al",
      ".atrac3pal", ".atrac3pa", ".atrac3p", ".atrac3plus", ".atrac"};

  const std::vector<std::string> picture = { // Common & Modern Raster
      ".jpg", ".jpeg", ".jpe", ".jif", ".jfif", ".pjpeg", ".pjp", ".png",
      ".apng", ".gif", ".webp", ".avif", ".heic", ".heif", ".bmp", ".dib",
      ".tif", ".tiff", ".jxl", ".qoi",

      // Vector
      ".svg", ".svgz", ".ai", ".eps", ".ps", ".wmf", ".emf", ".cgm", ".vml",
      ".xps", ".xar", ".odg",

      // RAW Camera Formats
      ".raw", ".dng", ".cr2", ".cr3", ".nef", ".arw", ".orf", ".rw2", ".sr2",
      ".k25", ".nrw", ".pef", ".raf", ".x3f", ".gpr", ".erf", ".nrw",

      // Professional / Editing
      ".psd", ".xcf", ".indd", ".ind", ".indt", ".exr", ".hdr", ".dpx", ".fpx",
      ".pcd",

      // JPEG 2000 & XR
      ".jp2", ".j2k", ".j2c", ".jpf", ".jpx", ".jpm", ".mj2", ".jxr", ".wdp",

      // Obsolete & Legacy Raster
      ".pcx", ".tga", ".iff", ".ilbm", ".ras", ".rast", ".pgf", ".sgi", ".pic",
      ".mng", ".wbmp", ".ani",

      // Icons & Cursors
      ".ico", ".cur",

      // Netpbm Family
      ".pnm", ".pbm", ".pgm", ".ppm", ".pam",

      // Scientific / Specialized
      ".dcm", ".dicom", ".fits", ".fit", ".vicar", ".xisf", ".nrrd", ".sid",
      ".img", ".yuv", ".dds",

      // 3D / CAD (image-adjacent)
      ".3dm", ".3ds", ".max", ".glb", ".gltf", ".stl", ".obj", ".ply", ".blend",
      ".dwg", ".dxf",

      // GIS
      ".kml", ".kmz", ".gpx",

      // Other
      ".fui", ".tinyvg", ".bw"};

  const std::vector<std::string> video = {
      // modern
      ".mp4", ".m4v", ".m4p", ".webm", ".mov", ".qt", ".mkv", ".mks", ".mka",
      ".mk3d", ".avi", ".wmv", ".flv", ".f4v", ".f4p", ".f4a", ".f4b", ".ogv",
      ".ogg",

      // MPEG & Broadcast
      ".mpg", ".mpeg", ".mpe", ".mpv", ".mp2", ".m2ts", ".mts", ".ts", ".vob",
      ".dv", ".dif", ".mxf",

      // Mobile & Legacy
      ".3gp", ".3g2", ".rm", ".rmvb", ".ram", ".asf", ".wma", ".amv", ".svi",
      ".nsv", ".roq",

      // Niche, Raw & Obsolete
      ".yuv", ".gifv", ".mng", ".flic", ".fli", ".flc", ".mod", ".tod", ".r3d",
      ".xav", ".bik", ".bik2", ".c2", ".cdxl", ".cin", ".dpx", ".hdv", ".j2k",
      ".mjpg", ".mjpeg", ".p2", ".psp", ".qcif", ".svcd", ".vcd", ".xvid"};
};

struct Globals {
  std::string VERSION = "v26.9.5-2";
  std::string orgdir;
  FilePaths files;
  CLIParser parser;
  Extensions extensions;

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