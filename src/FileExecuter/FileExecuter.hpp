
#pragma once
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Tue Sep 17 05:26:20 PM EEST 2024
brief:
*/
#include <fstream>

namespace cpp {
class FileExecuter {

public:
  FileExecuter();
  ~FileExecuter();
  void compile_run(std::string content);

private:
  std::fstream cppFile;
};
} // namespace cpp
