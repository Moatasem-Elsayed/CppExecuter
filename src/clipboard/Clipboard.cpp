
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Tue Sep 17 03:34:33 PM EEST 2024
brief:
*/
#include "Clipboard.hpp"
#include <SFML/Window/Clipboard.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <mutex>

namespace cpp {
Clipboard::Clipboard() {
  m_thread = std::thread(&Clipboard::listen, this);
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  m_activate = false;
}

Clipboard::~Clipboard() {
  std::cout << "[DEBUG] destructor" << std::endl;
  m_running = false;
  m_cv.notify_all();
  m_thread.join();
}
void Clipboard::press_copy_handler() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C) &&
      sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) && m_activate) {
    // grab the latest into the cliboard
    std::unique_lock<std::mutex> lk_content(m_mutex_content);
    std::string data = sf::Clipboard::getString();
    if (m_content.size() == 0) {
      m_content.push_back(data);
    } else if (data.size() > 0 && m_content.back() != data) {
      m_content.push_back(data);
    } else {
    }
    lk_content.unlock();
  }
}
void Clipboard::enableClipboard() {
  if (!m_activate) {
    // Enable
    std::unique_lock<std::mutex> lk_content(m_mutex_content);
    std::cout << "Enable" << std::endl;
    m_content.clear();
    m_content_stream.str(""); // Clear the content
    m_content_stream.clear(); // Reset the internal state
    std::cout << m_content_stream.str() << std::endl;
    m_activate = true;
  }
}
void Clipboard::startFormatingStream() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) &&
      sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
      sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2) && m_activate) {
    // DISABLE
    m_activate = false;
    // EXECUTE
    std::cout << "EXECUTE" << std::endl;
    std::unique_lock<std::mutex> lk_content(m_mutex_content);
    for (auto &d : m_content) {
      m_content_stream << d << std::endl;
    }
  }
}
void Clipboard::listen() {
  std::cout << "listening" << std::endl;
  std::unique_lock<std::mutex> lk(m_mutex);
  m_running = true;
  while (m_running) {
    m_cv.wait(lk, [this] { return m_running.load(); });
    enableClipboard();
    press_copy_handler();
    startFormatingStream();

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

} // namespace cpp
