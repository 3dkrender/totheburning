project(totheburning)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_contract( totheburning totheburning totheburning.cpp )
target_include_directories( totheburning PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( totheburning ${CMAKE_SOURCE_DIR}/../ricardian )