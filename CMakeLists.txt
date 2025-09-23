cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
cmake_policy(SET CMP0042 NEW)

project (Wolfram)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include_directories(${CMAKE_JS_INC})
include_directories(include/)

#file(GLOB SOURCE_FILES "src/plugin_impl.cpp" "include/*.hh")

#set_property(TARGET wolfram PROPERTY IMPORTED_LOCATION "./libs/cami-core")



add_library(${PROJECT_NAME} SHARED
    src/init.cpp
    src/Wrapper/wrapper_wolfram.cpp
    src/Plugin/Wolfram.cpp
    #    ${SOURCE_FILES}
    ${CMAKE_JS_SRC}
)

if (WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/DELAYLOAD:node.exe")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})
execute_process(COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
        )
string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${NODE_ADDON_API_DIR})
target_include_directories(${PROJECT_NAME}
    PUBLIC
    include/
    include/Plugin/
    include/Wrapper/)
add_definitions(-DNAPI_VERSION=4)

if (MSVC)
    execute_process(COMMAND ${CMAKE_AR} /def:${CMAKE_JS_NODELIB_DEF} /out:${CMAKE_JS_NODELIB_TARGET}
${CMAKE_STATIC_LINKER_FLAGS})
endif()

