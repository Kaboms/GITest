cmake_minimum_required(VERSION 3.21)

project(GITest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        GameScene.h
        GameScene.cpp
        ScenarioManager.h
        ScenarioManager.cpp
        Printer.h
        Printer.cpp
        PathHelper.h
        MainMenu.h
        MainMenu.cpp
        ScenarioCommands/AbstractScenarioCommand.h
        ScenarioCommands/AbstractScenarioCommand.cpp
        ScenarioCommands/ShowItemCommand.h
        ScenarioCommands/ShowItemCommand.cpp
        ScenarioCommands/ShowCharacterCommand.h
        ScenarioCommands/ShowCharacterCommand.cpp
        ScenarioCommands/HideCharacterCommand.h
        ScenarioCommands/HideCharacterCommand.cpp
        ScenarioCommands/ShowBackgroundCommand.h
        ScenarioCommands/ShowBackgroundCommand.cpp
        ScenarioCommands/HideBackgroundCommand.h
        ScenarioCommands/HideBackgroundCommand.cpp
        ScenarioCommands/ShowPrinterCommand.h
        ScenarioCommands/ShowPrinterCommand.cpp
        ScenarioCommands/HidePrinterCommand.h
        ScenarioCommands/HidePrinterCommand.cpp
        ScenarioCommands/ShowTextCommand.h
        ScenarioCommands/ShowTextCommand.cpp
        ScenarioCommands/EndCommand.h
        ScenarioCommands/EndCommand.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GITest
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET GITest APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(GITest SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    elseif(WIN32)
        add_executable(GITest WIN32 ${PROJECT_SOURCES})
    else()
        add_executable(GITest ${PROJECT_SOURCES})
    endif()
endif()

target_link_libraries(GITest PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(GITest PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GITest)
endif()
