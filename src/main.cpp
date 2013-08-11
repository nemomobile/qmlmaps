#include <QGuiApplication>
#include <QQuickView>
#include <QtQml>
#ifdef __arm__
#include <applauncherd/MDeclarativeCache>
#endif


Q_DECL_EXPORT int main(int argc, char *argv[])
{
#ifdef __arm__
    QGuiApplication *app = MDeclarativeCache::qApplication(argc, argv);
    QQuickView *view = MDeclarativeCache::qQuickView();
    view->setSource(QUrl("qrc:/qml/main.qml"));
    view->showFullScreen();
#else
    QGuiApplication *app = new QGuiApplication(argc, argv);
    QQuickView *view = new QQuickView();
    view->setSource(QUrl("qrc:/qml/main.qml"));
    view->show();
#endif

    //Flickr removal

    QObject::connect(view->engine(), SIGNAL(quit()), view, SLOT(close()));

    return app->exec();

}
