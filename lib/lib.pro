QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lib.cpp \
    tienda.cpp \
    producto.cpp \
    biblioteca.cpp \

HEADERS += \
    lib.h \
    tienda.h \
    producto.h \
    biblioteca.h \
    excepcionesProducto.h \
    excepcionesTienda.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
