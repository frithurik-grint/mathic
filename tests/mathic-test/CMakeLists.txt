set(SOURCES
    "main.cc"
)

get_property(MATHIC_LIBRARIES GLOBAL PROPERTY MATHIC_LIBRARIES)

add_executable("mathic-test" ${SOURCES})
target_link_libraries("mathic-test" PUBLIC ${LLVM_LIBRARIES} ${MATHIC_LIBRARIES})

install(TARGETS "mathic-test" DESTINATION "out/bin")