cmake_minimum_required(VERSION 3.20)

set(project_name jezhened)

set(CMAKE_CXX_STANDARD 			20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS		OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wpedantic -Werror")
	
project(${project_name}
	LANGUAGES CXX
)

add_executable(jezhened-cli
	main.cc
	Activity.cc
	Weekbook.cc
	Date.cc
)
