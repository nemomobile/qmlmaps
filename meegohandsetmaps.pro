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
CONFIG += link_pkgconfig

packagesExist(qdeclarative5-boostable) {
    message("Building with qdeclarative5-boostable support")
    DEFINES += HAS_BOOSTER
    PKGCONFIG += qdeclarative5-boostable
} else {
    warning("qdeclarative5-boostable not available; startup times will be slower")
}
