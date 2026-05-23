TEMPLATE = app
CONFIG += c++17 console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += C:/SFML-2.6.2/include
LIBS += -LC:/SFML-2.6.2/lib -lsfml-graphics -lsfml-window -lsfml-system