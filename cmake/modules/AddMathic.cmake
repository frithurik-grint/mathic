include(GNUInstallDirs)

set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_IMPORT_LIBRARY_PREFIX "")

set(MATHIC_LIBRARY_PREFIX "mathic-lib-")

function(add_mathic_library NAME SOURCES)
	set(_LIB_NAME "${MATHIC_LIBRARY_PREFIX}${NAME}")

	set(OPTIONS SHARED STATIC)
	set(PREFIXS DEPENDS)

	cmake_parse_arguments(_ARG
		"${OPTIONS}"
		""
		"${PREFIXS}"
		${ARGN}
	)

	if(_ARG_STATIC AND _ARG_SHARED)
		set(_LIB_TYPE STATIC SHARED)
	elseif(_ARG_STATIC)
		set(_LIB_TYPE STATIC)
	elseif(_ARG_SHARED)
		set(_LIB_TYPE SHARED)
	else()
		set(_LIB_TYPE)
	endif()

	add_library(${_LIB_NAME} ${_LIB_TYPE} ${SOURCES})

	set_property(GLOBAL APPEND PROPERTY MATHIC_LIBRARIES  ${_LIB_NAME})
	set_property(GLOBAL APPEND PROPERTY MATHIC_COMPONENTS ${_LIB_NAME})

	if(_ARG_DEPENDS)
		target_link_libraries(${_LIB_NAME} ${_ARG_DEPENDS})
	endif()

	install(TARGETS ${_LIB_NAME} DESTINATION "out/lib")
endfunction(add_mathic_library)
