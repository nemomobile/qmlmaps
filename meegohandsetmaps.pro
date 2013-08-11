CONFIG += mobility
CONFIG += qdeclarative-boostable 
MOBILITY += location
QT+= qml quick location
TEMPLATE = app
TARGET = meego-handset-maps
DESTDIR = bin

include(src/src.pri)

include(deployment.pri)
qtcAddDeployment()
