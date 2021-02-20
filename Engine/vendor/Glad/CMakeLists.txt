add_library (Glad
	"src/glad.c"
	)

target_compile_options(Glad
	PRIVATE -fPIC
	)

target_include_directories(Glad
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
	)