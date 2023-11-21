import QtQuick 2.0
import QtCanvas3D 1.1
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import Qt3D.Extras 2.0

ApplicationWindow {
    id : win
    title: qsTr("TestQMLMAp")
    width: 360
    height: 640
    visible: true    

    function popPage() {
        stackView.pop();
    }

    //тетстовый стек( в дальнейшем туда можно грзуитьт другие карты)
    property int defMargin: 10;

    header : ToolBar
    {
        height: 50
        ToolButton
        {
            text : "<"
            visible:  stackView.depth > 1
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                popPage()
            }
        }
        Text
        {
            anchors.centerIn: parent
            font.pointSize: 16
            text: stackView.currentItem.title
        }
    }

    StackView
    {
        id :stackView;
        anchors.fill: parent;
        initialItem: page1
    }

    SimplePage
    {
        id :page1
        title: sky_box_name
        backgroudColor: "red"
        buttonText: "next"
        onButtonClicked: {
            //добавим новую страницу
            stackView.push(page2)
        }

    }
    SimplePage
    {
        id :page2
        title: "FLoor 1"
        //visible: false
        backgroudColor: "blue"
        buttonText: "next"
        onButtonClicked: {
            //извлечени предыдущю странцу
            //(pop извслекает указанную странуцу и все предыдущеи)
            stackView.push(page3)
        }
    }

    SimplePage
    {
        id :page3
        title: "FLoor 2"
        visible: false
        backgroudColor: "green"
        buttonText: ""
        onButtonClicked: {
            //извлечени предыдущю странцу
            //(pop извслекает указанную странуцу и все предыдущеи)
            stackView.pop(page1)
        }
    }

//    Keys.onBackPressed:  {
//        popPage();
//    }
//    Keys.onEscapePressed:  {
//        popPage();
//    }


    //создадим кастумную кнпку
//    MyButton {
//        id: root
//        anchors.centerIn: parent
//        onClicked: {
//            win.color = Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
//        }
//    }
}
