
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Tue Sep 17 05:26:21 PM EEST 2024
brief:
*/
#include "FileExecuter.hpp"

namespace cpp {
FileExecuter::FileExecuter() {}
FileExecuter::~FileExecuter() {}

void FileExecuter::compile_run(std::string content) {
  cppFile.open("temp.cpp", std::ios::out);
  cppFile << content;
  cppFile.close();
  system("g++ temp.cpp -o temp");
  system("/usr/bin/x-terminal-emulator -e \"./temp && read -p '\n' test\" ");
  system("rm temp.cpp temp");
}
} // namespace cpp
