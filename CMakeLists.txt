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
    26.remove_duplicates_sorted
    27.remove_element
    28.index_of_occurance
    58.length_of_last_word
    88.merge_sorted_array
    121.max_profit_stocks
    169.majority_element
    217.contains_duplicates
    242.valid_anagram
    283.move_zeroes
    345.reverse_vowels_strings
    392.is_subsequance
    643.maximum_avarage_subarray1
    605.can_place_flowers
    1071.greatest_common_divisor_strings
    1431.kids_with_greatest_candy
    1768.merge_strings_alternately
    )

set(medium
    2.add_two_numbers
    3.longest_substring_without_rerpeating_chars
    7.reverse_integer
    11.container_with_most_water
    15.3sum
    16.3sum_closest
    19.remove_nth_node_from_end
    48.rotate_image
    49.group_anagrams
    80.remove_duplicates_sorted_2
    151.reverse_words_string
    189.rotate_array
    198.house_robber1
    213.house_robber2
    215.kth_largest_element
    229.majority_element_2
    238.product_of_array_except_self
    1441.build_array
    1679.max_number_of_sum_pairs
    1921.eliminate_monsters
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
