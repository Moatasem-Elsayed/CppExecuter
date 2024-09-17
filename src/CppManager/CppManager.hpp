
#pragma once
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Tue Sep 17 05:36:03 PM EEST 2024
brief:
*/
#include "Clipboard.hpp"
#include "FileExecuter.hpp"

namespace cpp {
enum StatusFile { READY, SUCCESS, FAIL };

class CppManager {

public:
  CppManager();
  ~CppManager();
  void manage(Clipboard &content);
  struct StateFile {
    size_t id;
    StatusFile status;
  };

private:
  cpp::FileExecuter fileExecuter;
  static size_t m_id;
  StateFile m_currentFile;
};
} // namespace cpp
