cmake_minimum_required( VERSION 3.5 )

project(proton)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_contract(swap swap
   ${CMAKE_CURRENT_SOURCE_DIR}/src/swap.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/transfer.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/eosio.token/eosio.token.cpp
)

target_include_directories(swap
   PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(swap PRIVATE -D_LIBCPP_STRSTREAM -DBOOST_EXCEPTION_DISABLE=1 -D_GLIBCXX_SSTREAM=1 -D_LIBCPP_SSTREAM -DBOOST_NO_IOSTREAM -DBOOST_NO_STRINGSTREAM )

set_target_properties(swap
   PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)

target_compile_options( swap PUBLIC -R${CMAKE_CURRENT_SOURCE_DIR}/ricardian -R${CMAKE_CURRENT_BINARY_DIR}/ricardian)