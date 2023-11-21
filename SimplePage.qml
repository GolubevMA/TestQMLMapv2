import QtQuick 2.0
import QtCanvas3D 1.1
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import Qt3D.Extras 2.0
//базовый тип страниц stackView

Page {
    id : root
    property alias backgroudColor: backgroundRect.color
    property alias buttonText: navButton.text
    //сигнал изспускаемый при нажатии на кнокпку
    signal buttonClicked();

    background: Rectangle {
        id : backgroundRect
    }


    //нопка выводв окнка поиска
    Button {
        id :  searchButton
        checkable: true
        text : "sh"

        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: defMargin
    }

//    SkyboxEntity
//    {
//        id : skybpx
//        baseName: skyBox1;
//        extension: sky_box_name
//    }

    //модель спсика поиска
    ListView
    {
        id : searchLabel
        visible: searchButton.checked
        width : 50
        height: 50
        anchors.left:  parent.left
        anchors.top: parent.top
        anchors.margins: defMargin

//        text: qsTr("search")
//        color : "#21be2b"

    }

    //кнопка перключения (расположениа в правом нижем углу старницы)
    Button {
        id: navButton
        //скрываем конпку при отстутвеии текста
        visible: text.length > 0;
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: defMargin
        onClicked: {
            //испускае м сигнал
            root.buttonClicked();
        }
    }
}
