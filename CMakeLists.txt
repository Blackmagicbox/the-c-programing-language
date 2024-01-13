cmake_minimum_required(VERSION 3.27)
project(the_c_programing_language C)

set(CMAKE_C_STANDARD 23)

add_executable(the_c_programing_language main.c)
add_executable(print-name print-name/print-name.c)
add_executable(fahrenheit-to-celsius-conversion-table fahrenheit-to-celsius-convertion-table/fahrenheit-to-celsius-converstion-table.c)
add_executable(number-guessing-game number-guessing-game/number-guessing-number.c)
add_executable(print-char print-char/print-char.c)
