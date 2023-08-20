cmake_minimum_required(VERSION 3.5)

project(problems)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


set(PROBLEMS
    easy
    medium
    hard)

set(easy
    1.two_sum
    9.palindrome_number
    13.roman_to_int
    14.longest_common_prefix
    21.merge_two_sorted_lists
    )

set(medium
    2.add_two_numbers
    7.reverse_integer
    11.container_with_most_water
    15.3sum
    16.3sum_closest
    19.remove_nth_node_from_end
    49.group_anagrams
    213.house_robber
    )

set(hard
    )

function(create_project_from_sources chapter demo)
    # copy source files
    file(GLOB SOURCE
        "src/${chapter}/${demo}/*.h"
        "src/${chapter}/${demo}/*.cpp"
        )
    if(demo STREQUAL "")
        set(replaced "")
        string(REPLACE "/" "_" replaced ${chapter})
    else()
        set(NAME "${chapter}__${demo}")
    endif()
    add_executable(${NAME} ${SOURCE})
    if(WIN32)
        set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
        set_target_properties(${NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
    elseif(UNIX AND NOT APPLE)
        set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
    endif(WIN32)

endfunction()


# create project file per problem
foreach(PROBLEM ${PROBLEMS})
    foreach(DEMO ${${PROBLEM}})
        create_project_from_sources(${PROBLEM} ${DEMO})
    endforeach(DEMO)
endforeach(CHAPTER)
