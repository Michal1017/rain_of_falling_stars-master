TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:/SFML-2.5.1/include"
SOURCES += \
        game_screen.cpp \
        hero.cpp \
        information.cpp \
        main.cpp \
        menu.cpp \
        meteorites.cpp \
        object.cpp \
        score.cpp

LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    game_screen.h \
    hero.h \
    information.h \
    menu.h \
    meteorites.h \
    object.h \
    score.h
