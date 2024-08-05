set(SOURCES
    "main.c"
)

add_executable("mathic-test" ${SOURCES})
target_link_libraries("mathic-test" PUBLIC ${LLVM_LIBRARIES} ${MATHIC_LIBRARIES})

install(TARGETS "mathic-test" DESTINATION "out/bin")

if (MATHIC_LIBRARIES)
    install(TARGETS ${MATHIC_LIBRARIES} DESTINATION "out/lib")
endif ()