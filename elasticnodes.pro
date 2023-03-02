QT += widgets

HEADERS += \
        Arc.h \
        ArcNotFoundException.h \
        Automate.h \
        EtatsAFD.h \
        Op.h \
        Pile.h \
        PileAutomate.h \
        Regex.h \
        State.h \
        StateNotFoundException.h \
        edge.h \
        etatsafd.h \
        node.h \
        graphwidget.h

SOURCES += \
        Arc.cpp \
        ArcNotFoundException.cpp \
        Automate.cpp \
        EtatsAFD.cpp \
        Op.cpp \
        Pile.cpp \
        PileAutomate.cpp \
        Regex.cpp \
        State.cpp \
        StateNotFoundException.cpp \
        edge.cpp \
        main.cpp \
        node.cpp \
        graphwidget.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target
