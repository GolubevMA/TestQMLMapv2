#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include "background.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //создаен интерпритатор и загржуаем в него  файл qml
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    //элмент отрисовки фона
    //получаем QML контекст (совокпуность Обьектов, методов текущего QML докумнта)
    engine.rootContext()->setContextProperty("sky_box_name", ":/map1/A/back.png");
    engine.load(url);

//    QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);
//    QQuickView view;
//    view.setResizeMode(QQuickView::SizeRootObjectToView);
//    view.setSource(QUrl("qrc:///scenegraph/openglunderqml/main.qml"));
//    view.show();

    //engine.rootContext()->setContextProperty("sky_box_name", "Hello World");
    //engine.rootContext()->setContextProperty("sky_box_name", "Hello World");
    //engine.rootContext()->setContextProperty("sky_box_name", "Hello World");
    //BackGround view;

    return app.exec();
}
