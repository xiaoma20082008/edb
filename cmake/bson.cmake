ExternalProject_Add(
        mongo-cxx-driver
        GIT_REPOSITORY      https://github.com/mongodb/mongo-cxx-driver.git
        GIT_TAG             r3.6.6
        PREFIX              ${CMAKE_HOME_DIRECTORY}/external/mongo-cxx-driver
        TIMEOUT             100
        CMAKE_ARGS          "-DCMAKE_BUILD_TYPE=Release"
        CONFIGURE_COMMAND   ""
        BUILD_COMMAND       ""
        INSTALL_COMMAND     ""
        UPDATE_COMMAND      ""
)