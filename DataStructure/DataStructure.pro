QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Json_Minifying_Validation_Correction.cpp \
    compression_decompression.cpp \
    follower.cpp \
    followers.cpp \
    formating.cpp \
    main.cpp \
    mainwindow.cpp \
    post.cpp \
    posts.cpp \
    user.cpp \
    users.cpp

HEADERS += \
    Json_Minyfying_Validation_Correction.h \
    comperession_decompression.h \
    follower.h \
    followers.h \
    formating.h \
    mainwindow.h \
    posts.h \
    users.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc

DISTFILES += \
    New folder/104-1043692_search-icon-transparent-white-search-icon-apple-png.png \
    New folder/1189183 (1).png \
    New folder/1542437-200.png \
    New folder/157962-200.png \
    New folder/58197-200.png
