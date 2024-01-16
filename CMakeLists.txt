cmake_minimum_required(VERSION 3.15)

#
#   Project details
#

project(
    "beautiful_nums"
    VERSION "0.0.1"
    LANGUAGES CXX
)

include(cmake/settings.cmake)
include(cmake/sources.cmake)

#
# Application
#

add_executable(beautiful_nums
    ${exe_sources}
)

target_link_libraries(beautiful_nums
    PRIVATE
    	
)




