
add_library(simpleLibrary
    main.cpp
)

ADD_EXECUTABLE(runGame
  main.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})

