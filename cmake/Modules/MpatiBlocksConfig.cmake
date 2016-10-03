INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_MPATIBLOCKS MpatiBlocks)

FIND_PATH(
    MPATIBLOCKS_INCLUDE_DIRS
    NAMES MpatiBlocks/api.h
    HINTS $ENV{MPATIBLOCKS_DIR}/include
        ${PC_MPATIBLOCKS_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    MPATIBLOCKS_LIBRARIES
    NAMES gnuradio-MpatiBlocks
    HINTS $ENV{MPATIBLOCKS_DIR}/lib
        ${PC_MPATIBLOCKS_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(MPATIBLOCKS DEFAULT_MSG MPATIBLOCKS_LIBRARIES MPATIBLOCKS_INCLUDE_DIRS)
MARK_AS_ADVANCED(MPATIBLOCKS_LIBRARIES MPATIBLOCKS_INCLUDE_DIRS)
