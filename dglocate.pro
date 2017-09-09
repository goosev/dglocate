QT += core gui widgets positioning

TEMPLATE = app
CONFIG += c++11

QT += positioning

HEADERS       = dglocate.h
SOURCES       = dglocate.cpp \
                main.cpp

LIBS *="-framework CoreLocation" "-framework SystemConfiguration"
# install
#target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/shapedclock
#INSTALLS += target
