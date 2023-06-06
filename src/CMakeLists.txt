add_subdirectory(Algorithms)
#add_subdirectory(GUI)
###################### Для отладки ###########################
add_custom_target(scripts)
add_custom_command(TARGET scripts
		PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory  ${CMAKE_CURRENT_SOURCE_DIR}/Services ${CMAKE_CURRENT_BINARY_DIR}/Services
		)
add_custom_command(TARGET scripts
		PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory  ${CMAKE_CURRENT_SOURCE_DIR}/SharedMemory ${CMAKE_CURRENT_BINARY_DIR}/SharedMemory
		)
