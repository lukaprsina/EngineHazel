add_library (Glad
	"src/glad.c"
	"include/glad/glad.h"
	"include/KHR/khrplatform.h"
)

target_include_directories(Glad
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
	)