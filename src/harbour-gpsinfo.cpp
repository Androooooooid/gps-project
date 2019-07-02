#include <QtQuick>

#include <sailfishapp.h>
#include <QTranslator>
#include "gpsdatasource.h"
#include "gpsinfosettings.h"
#include "app.h"
#include "connect_base.h"


int main(int argc, char *argv[]) {
    //migrate old configuration
    QDir configdir = QDir(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation));
    if (configdir.cd("gpsinfo")) {
        configdir.rename("gpsinfo.conf", "harbour-gpsinfo.conf");
        configdir.cdUp();
        configdir.rename("gpsinfo", "harbour-gpsinfo");
    }
    qmlRegisterType<Connect_Base>("harbour.connect_base", 1, 0, "Connect_Base");
    qmlRegisterType<GPSDataSource>("harbour.gpsinfo", 1, 0, "GPSDataSource");
    qmlRegisterType<GPSSatellite>();
    GPSInfoSettings* settings = new GPSInfoSettings();
    Connect_Base *connect_base = new Connect_Base();
    QGuiApplication* qGuiAppl = SailfishApp::application(argc, argv);
    App* app = new App();
    app->connect(settings, SIGNAL(localeChanged(QString)), app, SLOT(localeChanged(QString)));
    QStringList locales;
    QString baseName("/usr/share/harbour-gpsinfo/locales/");
    QDir localesDir(baseName);
    if (localesDir.exists()) {
        locales = localesDir.entryList(QStringList() << "*.qm", QDir::Files | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
    }
    locales.replaceInStrings(".qm", "");
    QString currentLocale = settings->getLocale();
    qDebug() << "loading language" << currentLocale;
    QTranslator* translator = new QTranslator();
    translator->load(currentLocale, "/usr/share/harbour-gpsinfo/locales", QString(), ".qm");
    QGuiApplication::installTranslator(translator);

    QQuickView *view = SailfishApp::createView();
    view->rootContext()->setContextProperty("settings", settings);
    view->rootContext()->setContextProperty("execqueru", connect_base);
    view->rootContext()->setContextObject(connect_base);
    view->setSource(SailfishApp::pathTo("qml/harbour-gpsinfo.qml"));
    view->showFullScreen();
    return qGuiAppl->exec();
}
