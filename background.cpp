//--------------------------------------------------------------------------
//#include <QQuickWindow>
//#include "background.h"
////--------------------------------------------------------------------------
//BackGround::BackGround()
//{
//    m_renderer = NULL;
//    m_color = QRgb();

//    //соедими сигнал измениея со слотом
//    //(вызовается, когда генрирутеся событие repaint (по причиние измения размера и.т.д))
//    //подключение с помощбю namespaces, коткорые укзаывают, к каим классам относятся сигналы
//    connect(this, &QQuickItem::widthChanged, this, &BackGround::handleWindowChanged);
//}
////--------------------------------------------------------------------------
////обрабочик изменеия окна
////--------------------------------------------------------------------------
//void BackGround::handleWindowChanged(QQuickWindow *win)
//{
//    if (win)
//    {
//        //поскольку обьект   BackGround связан с потокм GUI
//        //а события (сигналы) передются из потока ренедера необходимо использовать Qt::directConnectio

//        //подключим слот сояздания средсвт ренеринга
//        connect(win, &QQuickWindow::beforeSynchronizing, this, &BackGround::sync, Qt::DirectConnection);
//        //подключим слот очистки рендера
//        connect(win, &QQuickWindow::sceneGraphInvalidated, this, &BackGround::cleanup, Qt::DirectConnection);

//        //очищаем канву
//        win->setColor(Qt::black);
//    }
//}
////--------------------------------------------------------------------------
////обнолвям состяние свойтс обьекта рендера исохдя из текущих парматров окна
////при необходости, иницилзурем обьект рендера
////--------------------------------------------------------------------------
//void BackGround::sync()
//{
//    if (!m_renderer)
//    {
//        m_renderer = new BackgroundRenderer;
//        //поскольку window и m_render работают в разных потоках - использользуем Qt::directConnection
//        //отрисоввыам под qitem
//        connect(window(), &QQuickWindow::beforeRendering, m_renderer, &BackgroundRenderer::paint, Qt::DirectConnection);
//    }
//    m_renderer->setViewportSize(window()->size() * window()->devicePixelRatio());
//    m_renderer->setColor(m_color);
//    m_renderer->setWindow(window());
//}
////--------------------------------------------------------------------------
////очистка обьект рендера
////--------------------------------------------------------------------------
//void BackGround::cleanup()
//{
//    delete m_renderer;
//    m_renderer = nullptr;
//}
////--------------------------------------------------------------------------
////класс проедоставляет метод, удаляющий все запущенные обьекта класса BackgroundRenderer
////--------------------------------------------------------------------------
//class CleanupJob : public QRunnable
//{
//public:
//    CleanupJob(BackgroundRenderer *renderer) : m_renderer(renderer) { }
//    void run() override { delete m_renderer; }
//private:
//    BackgroundRenderer *m_renderer;
//};
////удаляем все обьекты рендеринга
//void BackGround::releaseResources()
//{
//    window()->scheduleRenderJob(new CleanupJob(m_renderer), QQuickWindow::BeforeSynchronizingStage);
//    m_renderer = nullptr;
//}
////--------------------------------------------------------------------------
//BackgroundRenderer::~BackgroundRenderer()
//{
//    delete m_program;
//}
////--------------------------------------------------------------------------
////инициализирупем геметрию куба
////--------------------------------------------------------------------------
//void BackgroundRenderer::initCubeGeomrtry()
//{
////    //заполяем  указываем вершинные и  текстурные координаты для каждой точки
////    VertexData vertices[] = {

////        //передняя грань
////        {QVector3D(-1.0f, -1.0f,  1.0f), QVector2D(0.0f, 0.0f)},  // v0
////        {QVector3D( 1.0f, -1.0f,  1.0f), QVector2D(0.33f, 0.0f)}, // v1
////        {QVector3D(-1.0f,  1.0f,  1.0f), QVector2D(0.0f, 0.5f)},  // v2
////        {QVector3D( 1.0f,  1.0f,  1.0f), QVector2D(0.33f, 0.5f)}, // v3

////        //правая грань
////        {QVector3D( 1.0f, -1.0f,  1.0f), QVector2D( 0.0f, 0.5f)}, // v4
////        {QVector3D( 1.0f, -1.0f, -1.0f), QVector2D(0.33f, 0.5f)}, // v5
////        {QVector3D( 1.0f,  1.0f,  1.0f), QVector2D(0.0f, 1.0f)},  // v6
////        {QVector3D( 1.0f,  1.0f, -1.0f), QVector2D(0.33f, 1.0f)}, // v7

////        //задняя грань
////        {QVector3D( 1.0f, -1.0f, -1.0f), QVector2D(0.66f, 0.5f)}, // v8
////        {QVector3D(-1.0f, -1.0f, -1.0f), QVector2D(1.0f, 0.5f)},  // v9
////        {QVector3D( 1.0f,  1.0f, -1.0f), QVector2D(0.66f, 1.0f)}, // v10
////        {QVector3D(-1.0f,  1.0f, -1.0f), QVector2D(1.0f, 1.0f)},  // v11

////        //левая грань
////        {QVector3D(-1.0f, -1.0f, -1.0f), QVector2D(0.66f, 0.0f)}, // v12
////        {QVector3D(-1.0f, -1.0f,  1.0f), QVector2D(1.0f, 0.0f)},  // v13
////        {QVector3D(-1.0f,  1.0f, -1.0f), QVector2D(0.66f, 0.5f)}, // v14
////        {QVector3D(-1.0f,  1.0f,  1.0f), QVector2D(1.0f, 0.5f)},  // v15

////        //нижняя грань
////        {QVector3D(-1.0f, -1.0f, -1.0f), QVector2D(0.33f, 0.0f)}, // v16
////        {QVector3D( 1.0f, -1.0f, -1.0f), QVector2D(0.66f, 0.0f)}, // v17
////        {QVector3D(-1.0f, -1.0f,  1.0f), QVector2D(0.33f, 0.5f)}, // v18
////        {QVector3D( 1.0f, -1.0f,  1.0f), QVector2D(0.66f, 0.5f)}, // v19

////        //верзняя грань
////        {QVector3D(-1.0f,  1.0f,  1.0f), QVector2D(0.33f, 0.5f)}, // v20
////        {QVector3D( 1.0f,  1.0f,  1.0f), QVector2D(0.66f, 0.5f)}, // v21
////        {QVector3D(-1.0f,  1.0f, -1.0f), QVector2D(0.33f, 1.0f)}, // v22
////        {QVector3D( 1.0f,  1.0f, -1.0f), QVector2D(0.66f, 1.0f)}  // v23
////    };

////    arrayBuf.bind();
////    arrayBuf.allocate(vertices, 24 * sizeof(VertexData));
//}
////--------------------------------------------------------------------------
//void BackgroundRenderer::paint()
//{
//    if (!m_program)
//    {
//        //привязываем контекст opengl к оьбьетуу window
//        //(разрешаем исоплзование opanglApI для отрисвоки графическогоо элемента)
//        //QSGRendererInterface *rif = m_window->rendererInterface();
//        //Q_ASSERT(rif->graphicsApi() == QSGRendererInterface::OpenGL);

//        initializeOpenGLFunctions();

//        //грузим тексутур из локального паметра
//        //(пока что можем прсто созадать Image и запольнт его m_clolr)

//        m_program = new QOpenGLShaderProgram();
//        m_program->addCacheableShaderFromSourceFile(QOpenGLShader::Vertex, ":/vshader.glsl");
//        m_program->addCacheableShaderFromSourceFile(QOpenGLShader::Fragment, ":/fshader.glsl");
//        m_program->link();
//    }

//    m_program->bind();
//    m_program->enableAttributeArray(0);

//    float values[] = {
//        -1, -1,
//        1, -1,
//        -1, 1,
//        1, 1
//    };

//   // This example relies on (deprecated) client-side pointers for the vertex
//   // input. Therefore, we have to make sure no vertex buffer is bound.
//   glBindBuffer(GL_ARRAY_BUFFER, 0);

//   m_program->setAttributeArray(0, GL_FLOAT, values, 2);
//   glViewport(0, 0, m_viewportSize.width(), m_viewportSize.height());

//   glDisable(GL_DEPTH_TEST);

//   glEnable(GL_BLEND);
//   glBlendFunc(GL_SRC_ALPHA, GL_ONE);

//   glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

//   m_program->disableAttributeArray(0);
//   m_program->release();
//}
////--------------------------------------------------------------------------
