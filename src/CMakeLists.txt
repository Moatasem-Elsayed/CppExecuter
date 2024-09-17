cmake_minimum_required(VERSION 3.27)

set(SRC_FILES main.cpp
    clipboard/Clipboard.cpp
    FileExecuter/FileExecuter.cpp
    CppManager/CppManager.cpp
)
include_directories(${SFML_INCLUDE_DIRS}
    clipboard
    FileExecuter
    CppManager
)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})