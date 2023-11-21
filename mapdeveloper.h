#ifndef MAPDEVELOPER_H
#define MAPDEVELOPER_H
/*--------------------------------------------------------------------------
основноей класс логики приложениея

работаем с классами классы карты и точки,

при перключении карты обрабатывем сигнал с помощью слота,
в котором переключаем текущую карту и загрзужаем в соотвствеувюи
стек карты все уровни карт

при переключеннии точик в режиме перемещения по точкам проходимся по страницам стека точек
если в дальнеймем эленты карты (т.е точки) будут реализованы в виде узлов графа (для опрределения сотсяяния и расичтае маршрута)
 - необходмио либо сразу в стеке располагать ближайшие элменты, либо при переключениии каждый разм определять, какой элмент ближайший,
 и вывывать push котроуму будет предешевтовать изменение стека точек

карты и точки могут загружатся из внешенгог ini файла

обновление предствления осщуствеялется через с++ классы наследники QQuickItem
//-------------------------------------------------------------------------*/
#include <QObject>
#include <QPoint>
//-------------------------------------------------------------------------
class TPoint
{
public:
    //координат точки относительно bmp карты
    QPoint p_pos;
    QString p_name;
    QString p_descript;
    QString p_texFileName;

    TPoint ()
        : p_pos(), p_name(),
        p_descript(), p_texFileName()
    {}
    TPoint (QPoint pos, QString name,
        QString descr, QString texPath)
    {
        p_pos = pos;
        p_name = name; p_descript = descr;
        p_texFileName = texPath;
    }
};
//-------------------------------------------------------------------------
typedef QList<TPoint> TPointList;
//-------------------------------------------------------------------------
class TMap
{
public:
    //количчетво слоев карты
    int layersCount;
    int curLayer;

    QStringList images;
    //список точек по слоям
    QList<TPointList> l_points;

    TMap (int l_count, QStringList img, QList<TPointList> l_pt)
    {
        layersCount = l_count;
        curLayer = 0;
        images = img;
        l_points = l_pt;
    }

};
//-------------------------------------------------------------------------
class MapDeveloper : public QObject
{
    Q_OBJECT
public:

    MapDeveloper(QObject *parent = nullptr);
    void InitMaps();

public slots:
    //void SetMap();

private :
    int CurrentMap;
    QList<TMap> Maps;
};
//-------------------------------------------------------------------------
#endif // MAPDEVELOPER_H
