# CMake powered build system for CMVS
# Create by Pierre Moulon
# First draft the 4 june 2010
# Second draft 24 sept 2010
# Third draft (linux) 12 oct 2010
# 28 july 2014 Make VisualStudio Win32/Win64 detection automatic
# 15.01.2015 Added tinycthread, nlopt, CImg, removed BLAS, LAPACK, GSL, lmfit, winpthread (R. Hiestand)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(CMVS-PMVS2 C CXX)

set (CMAKE_CXX_STANDARD 11)

# By default build in Release mode
IF(NOT CMAKE_BUILD_TYPE AND NOT MSVC)
    SET(CMAKE_BUILD_TYPE "Release")
ENDIF(NOT CMAKE_BUILD_TYPE AND NOT MSVC)

INCLUDE_DIRECTORIES(
        ${CMAKE_SOURCE_DIR}/program/base/image
        ${CMAKE_SOURCE_DIR}/program/base/numeric
        ${CMAKE_SOURCE_DIR}/program/base/pmvs
        ${CMAKE_SOURCE_DIR}/thirdParty/
        ${CMAKE_SOURCE_DIR}/thirdParty/graclus1.2/metisLib
        ${CMAKE_SOURCE_DIR}/thirdParty/nlopt-2.4.2/api
        ${CMAKE_SOURCE_DIR}/thirdParty/cimg
        ${CMAKE_SOURCE_DIR}/thirdParty/tinycthread
)

# Threads
FIND_PACKAGE(Threads REQUIRED)
SET(PMVS_LIBRARIES ${PMVS_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

# Eigen
SET( EIGEN3_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/thirdParty/Eigen )
SET( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${EIGEN3_INCLUDE_DIR}/cmake" )
FIND_PACKAGE(Eigen3 3.0.0 REQUIRED)
MESSAGE("Found Eigen ${EIGEN3_VERSION}")
INCLUDE_DIRECTORIES( ${EIGEN3_INCLUDE_DIR} )

# Boost
SET(Boost_USE_STATIC_LIBS        ON)
SET(Boost_USE_MULTITHREADED      ON)
SET(Boost_USE_STATIC_RUNTIME     OFF)
FIND_PACKAGE(Boost)
IF(Boost_FOUND)
    message("Using system boost library: ${Boost_INCLUDE_DIRS}")
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
ELSE(Boost_FOUND)
    message("No system boost library found, using internal version")
    SET(PMVS_USE_INTERNAL_BOOST TRUE)
    INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdParty/miniBoost)
ENDIF(Boost_FOUND)


# JPEG
FIND_PACKAGE(JPEG)
IF(JPEG_FOUND)
    message("Using system JPEG library: ${JPEG_LIBRARIES}")
    INCLUDE_DIRECTORIES(${JPEG_INCLUDE_DIR})
    SET(PMVS_LIBRARIES ${PMVS_LIBRARIES} ${JPEG_LIBRARIES})
ELSE(JPEG_FOUND)
    message("No system JPEG library found, using internal version")
    SET(PMVS_USE_INTERNAL_JPEG TRUE)
    INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdParty/jpeg)
    INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/thirdParty/jpeg)	# For jconfig.h
    SET(PMVS_LIBRARIES ${PMVS_LIBRARIES} jpeg)
ENDIF(JPEG_FOUND)


# ZLIB
#FIND_PACKAGE(ZLIB REQUIRED)
#INCLUDE_DIRECTORIES(${ZLIB_INCLUDE_DIR})

# PNG
SET(PMVS_USE_PNG        OFF)
IF(PMVS_USE_PNG)
    FIND_PACKAGE(PNG)
    IF(PNG_FOUND)
        message("PNG library found, enabling support: ${PNG_LIBRARIES}")
        ADD_DEFINITIONS(-DPMVS_HAVE_PNG)
        INCLUDE_DIRECTORIES(${PNG_INCLUDE_DIRS})
        SET(PMVS_LIBRARIES ${PMVS_LIBRARIES} ${PNG_LIBRARIES})
    ENDIF(PNG_FOUND)
ENDIF(PMVS_USE_PNG)

# TIFF
SET(PMVS_USE_TIFF        OFF)
IF(PMVS_USE_TIFF)
    FIND_PACKAGE(TIFF)
    IF(TIFF_FOUND)
        message("TIFF library found, enabling support: ${TIFF_LIBRARIES}")
        ADD_DEFINITIONS(-DPMVS_HAVE_TIFF)
        INCLUDE_DIRECTORIES(${TIFF_INCLUDE_DIR})
        SET(PMVS_LIBRARIES ${PMVS_LIBRARIES} ${TIFF_LIBRARIES})
    ENDIF(TIFF_FOUND)
ENDIF(PMVS_USE_TIFF)


ADD_SUBDIRECTORY(base)
ADD_SUBDIRECTORY(main)
ADD_SUBDIRECTORY(thirdParty)