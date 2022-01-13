FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
set(gtest_force_shared_crt ON CACHE INTERNAL "")
set(CMAKE_MACOSX_RPATH ON CACHE INTERNAL "")
FetchContent_MakeAvailable(googletest)