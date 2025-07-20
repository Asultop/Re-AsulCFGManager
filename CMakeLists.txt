cmake_minimum_required(VERSION 3.16)
project(AsulCFGManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # 不使用编译器特定的扩展

# 设置定义
add_definitions(
    -DQS_LOG_LINE_NUMBERS
)

# 查找Qt组件
find_package(Qt6 COMPONENTS Core Gui Network Widgets LinguistTools REQUIRED)
if(Qt6_FOUND)
    set(QT_LIBRARIES Qt6::Core Qt6::Gui Qt6::Network Qt6::Widgets )
else()
    find_package(Qt5 COMPONENTS Core Gui Network Widgets REQUIRED)
    set(QT_LIBRARIES Qt5::Core Qt5::Gui Qt5::Network Qt5::Widgets )
endif()

# 自动处理moc、uic和rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


# 源文件和头文件列表
set(SOURCES
    Sources/AsulWindow.cpp
    Sources/BanElaComboBox.cpp
    Sources/BaseScrollpage.cpp
    Sources/F_Collector.cpp
    Sources/F_SteamAvatarFetcher.cpp
    Sources/F_SteamUserQuery.cpp
    Sources/F_Translator.cpp
    Sources/GlobalSettings.cpp
    Sources/T_About.cpp
    Sources/T_BasePage.cpp
    Sources/T_CFGSettings.cpp
    Sources/T_Deploy.cpp
    Sources/T_FormatHelp.cpp
    Sources/T_Home.cpp
    Sources/T_Home2.cpp
    Sources/T_Manage.cpp
    Sources/T_Setting.cpp
    Sources/T_SplashScreen.cpp
    Sources/T_UserSetting.cpp
    Sources/W_DragFrame.cpp
    Sources/W_SCFGTransformer.cpp
    3rd/qmarkdowntextedit/qownlanguagedata.cpp
    3rd/qmarkdowntextedit/markdownhighlighter.cpp
    3rd/qmarkdowntextedit/qmarkdowntextedit.cpp
    3rd/qmarkdowntextedit/qplaintexteditsearchwidget.cpp

    3rd/QsLog/QsLogDest.cpp
    3rd/QsLog/QsLog.cpp
    3rd/QsLog/QsLogDestConsole.cpp
    3rd/QsLog/QsLogDestFile.cpp
    3rd/QsLog/QsLogDestFunctor.cpp

    main.cpp
    AsulCFGManager.cpp
)

set(HEADERS
    Headers/AsulWindow.h
    Headers/BanElaComboBox.h
    Headers/BaseInclude.h
    Headers/BaseScrollpage.h
    AsulCFGManager.h
    Headers/F_Collector.h
    Headers/F_SteamAvatarFetcher.h
    Headers/F_SteamUserQuery.h
    Headers/F_SystemInfo.h
    Headers/F_Translator.h
    Headers/GlobalSettings.h
    Headers/T_About.h
    Headers/T_BasePage.h
    Headers/T_CFGSettings.h
    Headers/T_Deploy.h
    Headers/T_FormatHelp.h
    Headers/T_Home.h
    Headers/T_Home2.h
    Headers/T_Manage.h
    Headers/T_Setting.h
    Headers/T_SplashScreen.h
    Headers/T_UserSetting.h
    Headers/W_DragFrame.h
    Headers/W_SCFGTransformer.h
    Headers/singleton.h
    Headers/stdafx.h

    3rd/qmarkdowntextedit/linenumberarea.h
    3rd/qmarkdowntextedit/qownlanguagedata.cpp
    3rd/qmarkdowntextedit/markdownhighlighter.h
    3rd/qmarkdowntextedit/qmarkdowntextedit.h
    3rd/qmarkdowntextedit/qplaintexteditsearchwidget.h
    
    3rd/ValveFileVDF-1.1.1/include/vdf_parser.hpp
    
    3rd/QsLog/QsLogDest.h
    3rd/QsLog/QsLog.h
    3rd/QsLog/QsLogDestConsole.h
    3rd/QsLog/QsLogLevel.h
    3rd/QsLog/QsLogDestFile.h
    3rd/QsLog/QsLogDisableForThisFile.h
    3rd/QsLog/QsLogDestFunctor.h
)
set (FORM
    3rd/qmarkdowntextedit/qplaintexteditsearchwidget.ui
)
# 资源文件
set(RESOURCES
    Resource.qrc
    3rd/qmarkdowntextedit/media.qrc
)



# 翻译文件
set(TS_FILES
    translations/AM_zh_CN.ts
    translations/AM_en_US.ts
)


# 添加资源文件
qt_add_resources(RESOURCE_FILES ${RESOURCES})
qt6_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

add_executable(${PROJECT_NAME} WIN32
    ${SOURCES}
    ${HEADERS}
    ${RESOURCE_FILES}
    ${FORM}
    ${RC_FILE}
    ${TS_FILES}
    ${QM_FILES}
)
# Windows资源文件
if(WIN32)
    set(RC_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Uac/res.rc)
    set_source_files_properties(${RC_FILE} PROPERTIES LANGUAGE RC)
    target_sources(${PROJECT_NAME} PRIVATE ${RC_FILE})
    # 链接psapi库
    find_library(PSAPI_LIBRARY psapi)
    if(PSAPI_LIBRARY)
        link_libraries(${PSAPI_LIBRARY})
    endif()
endif()

# 包含目录
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/install/include
)

# 链接库
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${QT_LIBRARIES}
)

# Windows特定设置
if(WIN32)
    # 链接ElaWidgetTools库
    if(MINGW)
        target_link_libraries(${PROJECT_NAME} PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/install/lib/libElaWidgetTools.a
        )
    else()
        target_link_libraries(${PROJECT_NAME} PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/install/lib/ElaWidgetTools.lib
        )
    endif()

    # 部署DLL
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/install/bin/ElaWidgetTools.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMENT "Copying ElaWidgetTools.dll to binary directory"
    )
endif()


# 安装设置
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)
install(FILES ${QM_FILES} DESTINATION translations)

# 开发阶段复制翻译文件到输出目录
# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     ${QM_FILES}
#     $<TARGET_FILE_DIR:${PROJECT_NAME}>/translations
#     COMMENT "Copying translation files to binary directory"
# )
