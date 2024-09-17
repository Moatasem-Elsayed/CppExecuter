
#pragma once
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Tue Sep 17 03:34:32 PM EEST 2024
brief:
*/
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
namespace cpp {
/*
- Listen to shortcut ctrl + c
- grap the latest into the cliboard
- store into string stream
*/
struct Optional {
  bool isenabled;
  std::string data;
};
class Clipboard {

public:
  Clipboard();
  ~Clipboard();
  const Optional getContent() {
    std::unique_lock<std::mutex> lk(m_mutex_content);
    Optional opt{m_content_stream.str().size() > 0, m_content_stream.str()};
    return opt;
  }

private:
  void listen();
  void press_copy_handler();
  void enableClipboard();
  void startFormatingStream();
  std::condition_variable m_cv;
  std::mutex m_mutex;
  std::mutex m_mutex_content;
  std::atomic<bool> m_running;
  std::atomic<bool> m_activate;
  std::vector<std::string> m_content;
  std::stringstream m_content_stream;
  std::thread m_thread;
};
} // namespace cpp
