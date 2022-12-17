cmake_minimum_required(VERSION 3.0)

project(BotInMaze)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Maze)

add_subdirectory(Bot)

target_include_directories(Bot PUBLIC Maze)

target_include_directories(RandomBot PUBLIC Bot Maze)

target_include_directories(RightHandRuleBot PUBLIC Bot Maze)

target_include_directories(${PROJECT_NAME} PUBLIC Maze ${CMAKE_SOURCE_DIR}/Bot/RightHandRuleBot ${CMAKE_SOURCE_DIR}/Bot/RandomBot)

target_link_libraries(${PROJECT_NAME} Maze Bot RandomBot RightHandRuleBot)