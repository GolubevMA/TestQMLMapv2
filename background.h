//#ifndef BACKGROUND_H
//#define BACKGROUND_H
///****************************************************************************
//Класс реаckлизует отрисвоку фона окна (в виде скайбокса или 2d image)

//Экземпляр рендеринга отделен от Графичского элемента, поскольку QQucikItem
//отрисовывается  в основноим потоке GUI, а рендеринг opengl может проихводиться в другом потоке

//QML_ELEMNT максро позволяет связыывать войства с++ класса  со свойстваим QMl класса
//****************************************************************************/
////--------------------------------------------------------------------------
//#include <QObject>
//#include <QQuickItem>
//#include <QtOpenGL/QtOpenGL>
//#include "GL/gl.h"
////--------------------------------------------------------------------------
////класс рендеригна
////--------------------------------------------------------------------------
//class BackgroundRenderer : public QObject, protected QOpenGLFunctions
//{
//    Q_OBJECT
//public:
//    ~BackgroundRenderer();

//    void setColor(QRgb col) {m_color = col;}
//    void setViewportSize(const QSize &size) { m_viewportSize = size; }
//    void setWindow(QQuickWindow *window) { m_window = window; }

//public slots:
//    void init();
//    void initCubeGeomrtry();
//    void paint();

//private:
//    QSize m_viewportSize;
//    QRgb m_color = qRgb(0,0,0);
//    QOpenGLShaderProgram *m_program = nullptr;
//    QQuickWindow *m_window = nullptr;
//};
////--------------------------------------------------------------------------
////Графичский элмент сцены
////--------------------------------------------------------------------------
//class BackGround : public QQuickItem
//{
//    Q_OBJECT
//    Q_PROPERTY(QRgb color READ getColor WRITE setColor NOTIFY colChanged)

//public:
//    BackGround();

//    void setColor(QRgb color);
//    QRgb getColor() {return  m_color;}

//signals:
//    colChanged();

//public slots:
//    void sync();
//    void cleanup();

//private slots:
//    void handleWindowChanged(QQuickWindow *win);

//private:
//    void releaseResources() override;

//    QRgb m_color;
//    BackgroundRenderer *m_renderer;
//};
////--------------------------------------------------------------------------
//#endif // BACKGROUND_H
