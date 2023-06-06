########### next target ###############
SET(gui_SRCS
   gui.cc
)
add_executable(gui ${gui_SRCS})
target_link_libraries(gui ${UNISET_LIBRARIES}
		${UNISETEXTENSION_LIBRARIES}
		${UNISETUNET_LIBRARIES}
		${UNISETMBTCPMASTER_LIBRARIES}
		${UNISETSHAREDMEMORY_LIBRARIES}
		${UNISETALGORITHMS_LIBRARIES}
		${GLADEMM_LIBRARIES}
		${UNIWIDGETS_LIBRARIES})

###################### Копируем картинки и glade ###########################
add_custom_command(TARGET gui
		PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory  ${CMAKE_CURRENT_SOURCE_DIR}/svg ${CMAKE_CURRENT_BINARY_DIR}/svg
		)
add_custom_command(TARGET gui
		PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/test.glade ${CMAKE_CURRENT_BINARY_DIR}
		)
###################### Обвязка для запуска ###########################
add_custom_command(TARGET gui
		PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/configure.xml ${CMAKE_CURRENT_BINARY_DIR}
		)
add_custom_command(TARGET gui
		PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/start_fg.sh ${CMAKE_CURRENT_BINARY_DIR}
		)