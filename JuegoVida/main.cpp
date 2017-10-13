#include <QGuiApplication>
//libreria para registrar clases definidas por el programador
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "simulador.h"
#include "universo.h"
#include "celula.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    //Registra los clases para poder usarlas con qml
    Simulador simul;
    Universo uni;
    Celula cel;
    engine.rootContext()->setContextProperty("obj3",&cel);
    engine.rootContext()->setContextProperty("obj2",&uni);
    engine.rootContext()->setContextProperty("obj",&simul);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
