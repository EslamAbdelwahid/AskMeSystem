cmake_minimum_required(VERSION 3.22)
project(AskMe_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(AskMe_System main.cpp AskMeSystem.cpp AskMeSystem.h HelperFunctions.cpp HelperFunctions.h Question.cpp Question.h QuestionsManager.cpp QuestionsManager.h User.cpp User.h UsersManager.cpp UsersManager.h)
