SET(EXE_SRC
	svg_test
    animation_test
    editing_test
)

FOREACH(FILE ${EXE_SRC})
  add_executable(${FILE} ${FILE}.cpp ${SOURCE_BASE_FILES} ${SOURCE_BASE_HEADER_FILES} )
ENDFOREACH(FILE)
