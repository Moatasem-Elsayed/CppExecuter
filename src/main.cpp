
#include "Clipboard.hpp"
#include "CppManager/CppManager.hpp"

int main() {
  cpp::Clipboard clipboard;
  cpp::CppManager cppManager;
  std::thread t1([&]() { cppManager.manage(clipboard); });

  t1.join();
  return 0;
}