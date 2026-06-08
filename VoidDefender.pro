TEMPLATE = app
CONFIG += c++17 console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    basicopp.cpp \
    bullet.cpp \
    game.cpp \
    opponent.cpp \
    player.cpp \
    poziomy.cpp \
    przyciski.cpp \
    tankopp.cpp


win32 {
    INCLUDEPATH += C:/SFML-2.6.2/include
    LIBS += -LC:/SFML-2.6.2/lib -lsfml-graphics -lsfml-window -lsfml-system
}

unix:!macx {
    LIBS += -lsfml-graphics -lsfml-window -lsfml-system
}

HEADERS += \
    basicopp.h \
    bullet.h \
    game.h \
    opponent.h \
    player.h \
    poziomy.h \
    przyciski.h \
    tankopp.h
