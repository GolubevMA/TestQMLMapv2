#include "mapdeveloper.h"
//-------------------------------------------------------------------------
MapDeveloper::MapDeveloper(QObject *parent)
    : QObject(parent)
{
    CurrentMap = 0;
}
//-------------------------------------------------------------------------
//загружаем карты
//-------------------------------------------------------------------------
    void MapDeveloper::InitMaps()
    {
        //создаем обьект на стеке и копирем егго в область
        //памяти глобальной переменной
        int lay1 = 1;
        QStringList nm1(QString("campus"));

        TPointList lay_1 = {
            TPoint(QPoint(4,4), QString("ffff"),  QString("dgdd"), QString("sdvfdv")),
            TPoint(QPoint(4,4), QString("dddd"),  QString("decsdrt"), QString("/sgdfh")),
            TPoint(QPoint(4,4), QString("me"),  QString("opids"), QString("/ing44")),
            TPoint(QPoint(4,4), QString("n2"),  QString("wwwwww"), QString("/imgg3"))
        };

        QList<TPointList> pts1 = {lay_1};
        TMap map1(lay1, nm1, pts1);
        //Maps.append(map1);

        int lay2 = 2;
        QStringList nm2 =  {
            QString("fistl floor"), QString("sec floor"), QString("third floor")
        };

        TPointList l1 = {
            TPoint(QPoint(4,4), QString("ffff"),  QString("dgdd"), QString("sdvfdv")),
            TPoint(QPoint(4,4), QString("dddd"),  QString("decsdrt"), QString("/sgdfh")),
            TPoint(QPoint(4,4), QString("me"),  QString("opids"), QString("/ing44")),
            TPoint(QPoint(4,4), QString("n2"),  QString("wwwwww"), QString("/imgg3"))
        };

        TPointList l2 = {
            TPoint(QPoint(4,4), QString("ffff"),  QString("dgdd"), QString("sdvfdv")),
            TPoint(QPoint(4,4), QString("dddd"),  QString("decsdrt"), QString("/sgdfh")),
            TPoint(QPoint(4,4), QString("me"),  QString("opids"), QString("/ing44")),
            TPoint(QPoint(4,4), QString("n2"),  QString("wwwwww"), QString("/imgg3"))
        };

        TPointList l3 = {
            TPoint(QPoint(4,4), QString("ffff"),  QString("dgdd"), QString("sdvfdv")),
            TPoint(QPoint(4,4), QString("dddd"),  QString("decsdrt"), QString("/sgdfh")),
            TPoint(QPoint(4,4), QString("me"),  QString("opids"), QString("/ing44")),
            TPoint(QPoint(4,4), QString("n2"),  QString("wwwwww"), QString("/imgg3"))
        };

        QList<TPointList> pts2 = {
            l1, l2, l3
        };

        TMap map2(lay2, nm2, pts2);
        Maps.append(map2);

        return;
    }
//-------------------------------------------------------------------------
