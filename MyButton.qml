import QtQuick 2.4
import QtCanvas3D 1.1
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Item {
    id: root
    property int size: 100
    property color color: "lightgray"
    //по своуюству name можно задать парметры текста
    property alias name: caption.text
    signal clicked()
    
    width: size
    height: size
    
    Rectangle {
        anchors.fill: parent
        radius: root.size /2
        color : mouseArea.containsPress ? Qt.darker(root.color, 1.2) : root.color
        
        //область вывода текста
        Text {
            id: caption
            anchors.centerIn: parent
            text: qsTr("text")
        }
        //облоатсь обработки мыши
        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked:
                root.clicked();
        }
    }
}
