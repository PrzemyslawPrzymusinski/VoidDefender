TEMPLATE = app
CONFIG += c++17 console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    game.cpp \
    opponent.cpp \
    player.cpp

# --- SEKCJA DLA WINDOWS (dla Twojego współpracownika) ---
win32 {
    INCLUDEPATH += C:/SFML-2.6.2/include
    LIBS += -LC:/SFML-2.6.2/lib -lsfml-graphics -lsfml-window -lsfml-system
}

# --- SEKCJA DLA LINUXA (dla Ciebie) ---
unix:!macx {
    # Na Linuksie pliki nagłówkowe i biblioteki są w standardowych ścieżkach systemowych,
    # dlatego nie podajemy INCLUDEPATH ani ścieżki -L. Wystarczą same nazwy modułów.
    LIBS += -lsfml-graphics -lsfml-window -lsfml-system
}

HEADERS += \
    game.h \
    opponent.h \
    player.h
