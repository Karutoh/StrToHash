cmake_minimum_required(VERSION 3.21)
project(StrToHash)

set(CMAKE_CXX_STANDARD 20)

if (DEFINED WIN32)
    #CXX Build Flags
    set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /DWIN32_LEAN_AND_MEAN /DEHS_NO_STD /Od /GS- /GR- /TP" CACHE STRING
            "Flags used by the CXX compiler during all build types."
            FORCE)
    set(CMAKE_CXX_FLAGS_DEBUG "/DEHS_DEBUG /Z7" CACHE STRING
            "Flags used by the CXX compiler during DEBUG builds."
            FORCE)
    set(CMAKE_CXX_FLAGS_RELEASE "" CACHE STRING
            "Flags used by the CXX compiler during RELEASE builds."
            FORCE)
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/DEHS_DEBUG" CACHE STRING
            "Flags used by the CXX compiler during RELWITHDEBINFO builds."
            FORCE)
    set(CMAKE_CXX_FLAGS_MINSIZEREL "" CACHE STRING
            "Flags used by the CXX compiler during MINSIZEREL builds."
            FORCE)

    #C Build Flags
    set(CMAKE_C_FLAGS "/DWIN32 /D_WINDOWS /DWIN32_LEAN_AND_MEAN /DEHS_NO_STD /Od /GS- /GR- /TP" CACHE STRING
            "Flags used by the CXX compiler during all build types."
            FORCE)
    set(CMAKE_C_FLAGS_DEBUG "/DEHS_DEBUG /Z7" CACHE STRING
            "Flags used by the C compiler during DEBUG builds."
            FORCE)
    set(CMAKE_C_FLAGS_RELEASE "" CACHE STRING
            "Flags used by the C compiler during RELEASE builds."
            FORCE)
    set(CMAKE_C_FLAGS_RELWITHDEBINFO "/DEHS_DEBUG" CACHE STRING
            "Flags used by the C compiler during RELWITHDEBINFO builds."
            FORCE)
    set(CMAKE_C_FLAGS_MINSIZEREL "" CACHE STRING
            "Flags used by the C compiler during MINSIZEREL builds."
            FORCE)

    #Linker Flags
    set(CMAKE_MSVC_RUNTIME_LIBRARY "" CACHE STRING
            ""
            FORCE)
    set(CMAKE_STATIC_LINKER_FLAGS "/NODEFAULTLIB" CACHE STRING
            "Flags used for linking binaries during all builds."
            FORCE)
    set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "" CACHE STRING
            "Flags used for linking binaries during debug builds."
            FORCE)
    set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "" CACHE STRING
            "Flags used for linking binaries during release builds."
            FORCE)
    set(CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO "" CACHE STRING
            "Flags used for linking binaries during RelWithDebInfo builds."
            FORCE)
    set(CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL "" CACHE STRING
            "Flags used for linking binaries during release builds."
            FORCE)

    #Standard Libraries
    set(CMAKE_CXX_STANDARD_LIBRARIES "kernel32.lib user32.lib Gdi32.lib ws2_32.lib" CACHE STRING
            "Libraries linked by default with all C++ applications."
            FORCE)

    set(CMAKE_C_STANDARD_LIBRARIES "kernel32.lib user32.lib Gdi32.lib ws2_32.lib" CACHE STRING
            "Libraries linked by default with all C applications."
            FORCE)

    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        if (CMAKE_BUILD_TYPE STREQUAL "Debug")
            link_directories("${PROJECT_SOURCE_DIR}/../EHS/cmake-build-debug-visual-studio-x64")
        elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
            link_directories("${PROJECT_SOURCE_DIR}/../EHS/cmake-build-release-visual-studio-x64")
        endif()
    elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
        if (CMAKE_BUILD_TYPE STREQUAL "Debug")
            link_directories("${PROJECT_SOURCE_DIR}/../EHS/cmake-build-debug-visual-studio-x86")
        elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
            link_directories("${PROJECT_SOURCE_DIR}/../EHS/cmake-build-release-visual-studio-x86")
        endif()
    endif()
endif()

add_executable(StrToHash main.cpp)

target_include_directories(StrToHash PUBLIC "${PROJECT_SOURCE_DIR}/..")

target_link_libraries(StrToHash PRIVATE EHS)