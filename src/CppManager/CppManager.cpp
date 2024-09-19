
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Tue Sep 17 05:36:04 PM EEST 2024
brief:
*/
#include "CppManager.hpp"
#include "Clipboard.hpp"
#include "FileExecuter.hpp"
#include <functional>
#include <iostream>
/*
while (1) {
      cpp::Optional data = clipboard.getContent();
      while (!data.isenabled) {
        data = clipboard.getContent();
      }
      if (data.isenabled) {
        std::cout << data.data << std::endl;
        fileExecuter.compile_run(data.data);

      }
    }*/
size_t cpp::CppManager::m_id = 0;
namespace cpp {
CppManager::CppManager() {}
CppManager::~CppManager() {}

void CppManager::manage(Clipboard &content) {
  while (1) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    if (m_currentFile.status == StatusFile::SUCCESS) {
      std::cout << "exit" << std::endl;
      std::cout << content.getContent().data << std::endl;
      break;
    }
    if (m_currentFile.id ==
        std::hash<std::string>{}(content.getContent().data)) {
      continue;
    }

    Optional optdata = content.getContent();
    while (!optdata.isenabled) {
      optdata = content.getContent();
    }
    m_currentFile = {std::hash<std::string>{}(optdata.data), StatusFile::READY};
    if (optdata.isenabled) {
      fileExecuter.compile_run(optdata.data);
      m_currentFile.status = StatusFile::SUCCESS;
    }
  }
}
} // namespace cpp
