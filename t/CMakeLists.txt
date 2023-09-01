
function(cstl_add_dummy_test SOURCE_FILE)
    get_filename_component(TEST_NAME ${SOURCE_FILE} NAME_WE)

    add_executable(${TEST_NAME})
    target_sources(${TEST_NAME} PRIVATE ${SOURCE_FILE})
    target_link_libraries(${TEST_NAME} PRIVATE cstl::cstl-static)
    set_property(TARGET ${TEST_NAME} PROPERTY C_STANDARD 17)

    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endfunction(cstl_add_dummy_test)

set(CSTL_DUMMY_TESTS
    ./pproc/concat.c 
    ./pproc/count.c
    ./pproc/to_str.c

    ./vector/pushpop.c
)

foreach(DUMMY_TEST ${CSTL_DUMMY_TESTS})
    cstl_add_dummy_test(${DUMMY_TEST})
endforeach()
