cmake_minimum_required(VERSION 3.5)

project(tryone VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        framework/gamescene.h framework/gamescene.cpp
        framework/gameobject.h framework/gameobject.cpp
        framework/component.h framework/component.cpp
        framework/transform.h framework/transform.cpp
        framework/imagetransform.h framework/imagetransform.cpp
        framework/transformbuilder.h framework/transformbuilder.cpp

        player.h player.cpp
        wall.h wall.cpp
        usercontroller.h usercontroller.cpp
        physics.h physics.cpp
        gamemap.h gamemap.cpp
        boom.h boom.cpp
        aicontroller.h aicontroller.cpp
        stoper.h stoper.cpp
        effect.h effect.cpp
        introduce.h introduce.cpp
        scoreboard.h scoreboard.cpp

        image/res.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(tryone
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET tryone APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(tryone SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(tryone
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(tryone PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(tryone PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(tryone)
endif()
