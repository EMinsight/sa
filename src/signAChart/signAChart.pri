INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD
# user need add 
#include($$PWD/../3rdParty/qwt/qwt_set.pri)
# user need add 
#include($$PWD/../3rdParty/qtpropertybrowser/src/qtpropertybrowser.pri)#propertybrowser support
DEFINES -= SA_CHART_MAKE #定义此变量后将会构建库
DEFINES += USE_QWT
CONFIG += qwt
QWT_CONFIG  += QwtDll
LIBS += -L$$PWD/../bin/libs/ -lsignAChart
