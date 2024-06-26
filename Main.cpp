/****************************************************************************
**
**      Titles  :   软件入口
**
**
****************************************************************************/
#include <QApplication>
#include <QTranslator>
#include <QString>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString translatorPath("");

#ifdef Q_OS_LINUX

    translatorPath = "/usr/share/qt4/translations/qt_zh_CN.qm";

#endif

#ifdef Q_OS_WIN

    translatorPath =
        "C:\\Qt\\Tools\\QtCreator\\share\\qtcreator\\translations\\qt_zh_CN.qm";

#endif

    QTranslator translator;
    (void)translator.load(translatorPath);
    app.installTranslator(&translator);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
