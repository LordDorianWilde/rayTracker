TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lgdi32 -lcomdlg32

SOURCES += main.cpp \
    vecteur.cpp \
    scene.cpp \
    sphere.cpp

HEADERS += \
    CImg.h \
    vecteur.h \
    scene.h \
    sphere.h

