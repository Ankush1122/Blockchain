cmake_minimum_required(VERSION 3.0.0)
project(Communication VERSION 0.1.0)

include(CTest)
enable_testing()


add_executable(Communication main.cpp NodeServer.cpp Block.cpp Socket.cpp Communication.cpp BlockChain.cpp Transaction.cpp Output.cpp Input.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
