########### next target ###############
SET(imitatortank_SRCS
	ImitatorTank_SK.cc
	ImitatorTank.cc
	imitatortank.cc
)

add_executable(imitatortank ${imitatortank_SRCS})
target_link_libraries(imitatortank ${UNISET_LIBRARIES}
		${UNISETALGORITHMS_LIBRARIES}
		${UNISETEXTENSION_LIBRARIES})

add_dependencies(imitatortank scripts)
###################### Генерим скелетоны ###########################
add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/ImitatorTank_SK.cc
		PRE_BUILD
		COMMAND uniset2-codegen -n ImitatorTank --topdir $(top_builddir)/ --ask --no-main imitatortank.src.xml WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		)
###################### Обвязка для запуска ###########################
add_custom_command(TARGET imitatortank
		PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy  ${CMAKE_CURRENT_SOURCE_DIR}/configure.xml ${CMAKE_CURRENT_BINARY_DIR}
		)
add_custom_command(TARGET imitatortank
		PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy  ${CMAKE_CURRENT_SOURCE_DIR}/start_fg.sh ${CMAKE_CURRENT_BINARY_DIR}
		)