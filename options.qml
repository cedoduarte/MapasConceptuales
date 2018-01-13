import QtQuick 2.5

Item {
    id: root
    width: mainWindow.quickWidgetSize().width
    height: mainWindow.quickWidgetSize().height

    Component.onCompleted: {
        optionsListView.model.append({ optionColor: 'orange',
                                       optionText: 'Documento nuevo',
                                       optionIndex: 0 });
        optionsListView.model.append({ optionColor: 'orange',
                                       optionText: 'Agregar cuadro',
                                       optionIndex: 1 });
        optionsListView.model.append({ optionColor: 'orange',
                                       optionText: 'Salir todo',
                                       optionIndex: 2 });
    }

    ListView {
        id: optionsListView
        anchors.fill: parent
        model: ListModel {}
        spacing: 2

        delegate: Rectangle {
            width: parent.width
            height: 50
            color: optionColor

            Text {
                anchors.centerIn: parent
                text: optionText
                color: 'white'
                font.pointSize: 18
                font.bold: true
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    mainWindow.executeOption(optionIndex);
                }
            }
        }
    }
}
