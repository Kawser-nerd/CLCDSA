
################################################################################
### Boost
################################################################################
# TODO: add a flag NEED_BOOST
SET(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
#SET(Boost_DEBUG TRUE)
# temporary fix for CMAKE 2.8.0 rc3
IF(MSVC10) # MSVC100
  SET(Boost_COMPILER "-vc100")
ENDIF(MSVC10)
# temporary fix for CMAKE 2.8.0 rc3 and Boost 1.41
SET(Boost_ADDITIONAL_VERSIONS "1.41" "1.41.0" "1.42" "1.42.0" "1.43" "1.43.0")
FIND_PACKAGE(Boost 1.43.0 REQUIRED COMPONENTS thread program_options date_time system regex)
MESSAGE(STATUS "Boost found here: " ${Boost_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
#LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

SET_PROPERTY(DIRECTORY APPEND PROPERTY
  COMPILE_DEFINITIONS BOOST_ENABLE_ASSERT_HANDLER BOOST_ALL_NO_LIB)
SET_PROPERTY(DIRECTORY APPEND PROPERTY
  COMPILE_DEFINITIONS_RELEASE BOOST_DISABLE_ASSERTS)

