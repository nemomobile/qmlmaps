#include <QGuiApplication>
#include <QQuickView>
#include <QtQml>
#ifdef HAS_BOOSTER
#include <MDeclarativeCache>
#endif

#ifdef HAS_BOOSTER
Q_DECL_EXPORT
#endif
int main(int argc, char *argv[])
{
#ifdef HAS_BOOSTER
    QGuiApplication* app = MDeclarativeCache::qApplication(argc, argv);
    QQuickView* view = MDeclarativeCache::qQuickView();
#else
    QGuiApplication* app = new QGuiApplication(argc, argv);
    QQuickView* view = new QQuickView;
#endif
    view->setSource(QUrl("qrc:/qml/main.qml"));
    view->showFullScreen();

    QObject::connect(view->engine(), SIGNAL(quit()), view, SLOT(close()));

    return app->exec();

}
