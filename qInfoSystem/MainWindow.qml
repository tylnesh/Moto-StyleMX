import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.2
//import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.11

ApplicationWindow {
    id: mainwindow
    width: 1280; height: 800

    Material.theme: Material.Dark
    Material.accent: Material.Yellow
    visible: true
    //color: "#000000"
    title: "Moto-StyleMX"

    TabBar{
        id: mainBar
        width: parent.width
        TabButton {
        text: qsTr("Production")
        }

        TabButton {
        text: qsTr("Stock")
        }


        TabButton {
        text: qsTr("New designs")
        }

    }

    StackLayout{
        width: mainwindow.width
        height: mainwindow.height - mainBar.height
        y: mainBar.height

        currentIndex: mainBar.currentIndex



        Rectangle{
            id: productionTab
            color: 'yellow'
            implicitWidth: 50
            implicitHeight: 50
            x: 200
            y: 500
        }
        Rectangle{
            id: stockTab
            color: 'green'
            width: 50
            height: 50
            x: 200
            y: 400
        }
//        Rectangle{
//            id: designsTab
//            color: 'red'
//            width: 50
//            height: 50
//            x: 200
//            y: 400
//        }

        ListView {
                id: listView
                anchors.fill: parent

                contentWidth: headerItem.width
                //flickableDirection: Flickable.HorizontalAndVerticalFlick

                header: Row {
                    spacing: 1
                    function itemAt(index) { return repeater.itemAt(index) }
                    Repeater {
                        id: repeater
                        model: ["Quisque", "Posuere", "Curabitur", "Vehicula", "Proin"]
                        Label {
                            text: modelData
                            font.bold: true
                            font.pixelSize: 20
                            padding: 10
                            background: Rectangle { color: "silver" }
                        }
                    }
                }

                model: 100
                delegate: Column {
                    id: delegate
                    property int row: index
                    Row {
                        spacing: 1
                        Repeater {
                            model: 5
                            ItemDelegate {
                                property int column: index
                                text: qsTr("%1x%2").arg(delegate.row).arg(column)
                                width: listView.headerItem.itemAt(column).width
                            }
                        }
                    }
                    Rectangle {
                        color: "silver"
                        width: parent.width
                        height: 1
                    }
                }

                ScrollIndicator.horizontal: ScrollIndicator { }
                ScrollIndicator.vertical: ScrollIndicator { }
            }
    }



}
