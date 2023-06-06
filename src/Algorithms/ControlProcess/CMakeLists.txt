########### next target ###############
SET(controlprocess_SRCS
   ControlProcess_SK.cc
   ControlProcess.cc
   controlprocess.cc
)

add_executable(controlprocess ${controlprocess_SRCS})
target_link_libraries(controlprocess ${UNISET_LIBRARIES}
		${UNISETALGORITHMS_LIBRARIES}
		${UNISETEXTENSION_LIBRARIES})

add_dependencies(controlprocess scripts)
###################### Генерим скелетоны ###########################
add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/ControlProcess_SK.cc
		PRE_BUILD
		COMMAND uniset2-codegen -n ControlProcess --topdir $(top_builddir)/ --ask --no-main controlprocess.src.xml WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		)
###################### Обвязка для запуска ###########################
add_custom_command(TARGET controlprocess
		PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy  ${CMAKE_CURRENT_SOURCE_DIR}/configure.xml ${CMAKE_CURRENT_BINARY_DIR}
		)
add_custom_command(TARGET controlprocess
		PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy  ${CMAKE_CURRENT_SOURCE_DIR}/start_fg.sh ${CMAKE_CURRENT_BINARY_DIR}
		)