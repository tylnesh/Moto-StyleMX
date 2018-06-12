import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.2
//import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2

ApplicationWindow {
    id: main
    Material.theme: Material.Dark
    Material.accent: Material.Purple
    visible: true
    width: 1280
    height: 720
    //color: "#000000"
    title: "Moto-StyleMX"

   // Material.theme: Material.Dark
   // Material.accent: Material.Yellow
    
    

    Image {
        id: image
        width: 484
        height: 100
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit
        source: "assets/images/motostyleLogo.png"
    }
    
    Rectangle {
        x: 202
        y: 240
        width: 100
        height: 20
        anchors.horizontalCenter: parent.horizontalCenter
        color: "white"
        border.color: "grey"
        border.width: 2
        radius: 5
            
        TextInput {
            id: login
            text: qsTr("Login")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            transformOrigin: Item.Center
            font.family: "Verdana"
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 12
            onEditingFinished: pass.forceActiveFocus()
            
            onActiveFocusChanged: {
                // When we first gain focus, save the old text and select everything for clearing.
                if (activeFocus) {
                    //oldText = text
                    selectAll()
                }
            }
            
            Keys.onEnterPressed: {
                pass.forceActiveFocus()
            }
            
            antialiasing: true
            
        }
        
        MouseArea {
            width: 100
            height: 20
            onClicked: {
            login.forceActiveFocus()
            }
        }
    }
    

    Rectangle {
        x: 202
        y: 265
        width: 100
        height: 20
        anchors.horizontalCenter: parent.horizontalCenter
        color: "white"
        border.color: "grey"
        border.width: 2
        radius: 5

        TextInput {
        
        id: pass
        text: qsTr("Pass")
        echoMode: TextInput.Password
        
        anchors.horizontalCenter: parent.horizontalCenter
        transformOrigin: Item.Center
        font.family: "Verdana"
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 12
        selectByMouse: true
        mouseSelectionMode: TextInput.SelectCharacters
        
        onActiveFocusChanged: {
            // When we first gain focus, save the old text and select everything for clearing.
            if (activeFocus) {
                //oldText = text
                selectAll()
            }
        }
        Keys.onReturnPressed: login.forceActiveFocus()
        Keys.onTabPressed: login.forceActiveFocus()
        antialiasing: true
        }

        MouseArea {
            width: 100
            height: 20
            onClicked: {
            pass.forceActiveFocus()
            }
        }

    }


        

    
    Button {
        
        id: send
        x: 202
        y: 300
        width: 100
        height: 40
        //color: "#000000"
        text: qsTr("Log in")
        antialiasing: true
        highlighted: true
        anchors.horizontalCenter: parent.horizontalCenter
        transformOrigin: Item.Center
        Material.accent: Material.Red

        contentItem: Text {
                text: send.text
                font: send.font
                opacity: enabled ? 1.0 : 0.3
                color: send.down ? "orange" : "yellow"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 40
                color: "grey"
                opacity: enabled ? 1 : 0.3
                border.color: send.down ? "" : "grey"
                border.width: 1
                radius: 2
            }

        onClicked: Animation.



    }

    Switch {
        id: switch1
        //anchors.horizontalCenter: parent.horizontalCenter
        anchors.left: send.right
        anchors.top: send.top
        anchors.leftMargin: 15;
        anchors.verticalCenter: send.verticalCenter
        transformOrigin: Item.Center
       // x: 714
       // y: 246
        width: 200
        height: 20
        Material.accent: Material.Yellow
        text: qsTr("Remember login")
    }



}






