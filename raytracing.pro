TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += static
LIBS += -lgdi32 -lcomdlg32 -fopenmp

SOURCES += main.cpp \
    vecteur.cpp \
    scene.cpp \
    sphere.cpp \
    rayon.cpp

HEADERS += \
    CImg.h \
    vecteur.h \
    scene.h \
    sphere.h \
    rayon.h

