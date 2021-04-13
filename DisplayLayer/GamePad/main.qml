/**********************************************************************
**File name:main.qml
**Author:hexiao<hexiao.hrbeu.edu.cn>    Version:1.0    Date:2020.12.19
**Description:
**GPL-3.0 License Usage
**********************************************************************/

import QtQuick 2.15
import QtQuick.Window 2.15
import QtGamepad 1.12
import QtQuick.Controls 2.5
import an.qt.GamePadIFS 1.0

Item {
    width: 405
    height: 370
    visible: true

    Gamepad {
        id: gamepad;


    }

    Connections {
        target: GamepadManager;
        function onGamepadConnected(deviceId)
        {
            gamepad.deviceId = deviceId;
        }
    }

    Connections{
        target: gamepad;
        function onButtonAChanged(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonA,value);
        }
        function onButtonBChanged(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonB,value);
        }
        function onButtonXChanged(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonX,value);
        }
        function onButtonYChanged(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonY,value);
        }
        function onButtonUpChanged(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonUp,value);
        }
        function onButtonDownChanged(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonDown,value);
        }
        function onButtonLeftChanged(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonLeft,value);
        }
        function onButtonRightChanged(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonRight,value);
        }
        function onAxisLeftXChanged(value)
        {

            circleL.x= rectangleL.x
                        + (rectangleL.width-circleL.width)/2
                        + (rectangleL.width-circleL.width)/2*value;
        }
        function onAxisLeftYChanged(value)
        {
            circleL.y= rectangleL.y
                        + (rectangleL.height-circleL.height)/2
                        + (rectangleL.height-circleL.height)/2*value;
        }
        function onAxisRightXChanged(value)
        {
            circleR.x= rectangleR.x
                        + (rectangleR.width-circleR.width)/2
                        + (rectangleR.width-circleR.width)/2*value;
        }
        function onAxisRightYChanged(value)
        {
            circleR.y= rectangleR.y
                        + (rectangleR.height-circleR.height)/2
                        + (rectangleR.height-circleR.height)/2*value;
        }
        function onButtonL1Changed(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonL1,value);
        }
        function onButtonL2Changed(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonL2,value);
        }
        function onButtonL3Changed(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonL3,value);
        }
        function onButtonR1Changed(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonR1,value);
        }
        function onButtonR2Changed(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonR2,value);
        }
        function onButtonR3Changed(value)
        {
            gamepadinterface.valueChanged(GamePadIFS.ButtonR3,value);
        }
    }

    GamePadIFS {
        id: gamepadinterface;
    }

    ProgressBar {
        id: progressBar
        x: 13
        y: 61
        width: 150
        height: 6
        value: gamepad.buttonL2
        indeterminate: false
    }

    ProgressBar {
        id: progressBar1
        x: 244
        y: 61
        width: 150
        height: 6
        value: gamepad.buttonR2
    }


    Button {
        id: buttonLT
        x: 38
        y: 8
        text: qsTr("LT")
        highlighted: gamepad.buttonL1

        onPressedChanged:{
            gamepadinterface.valueChanged(
                        GamePadIFS.ButtonL1,
                        buttonLT.pressed);
        }
    }

    Button {
        id: buttonRT
        x: 269
        y: 8
        text: qsTr("RT")
        highlighted: gamepad.buttonR1

        onPressedChanged:{
            gamepadinterface.valueChanged(
                        GamePadIFS.ButtonL1,
                        buttonRT.pressed);
        }
    }

    Rectangle {
        id: rectangleL
        x: 13
        y: 78
        width: 150
        height: 150
        color: "#a6c8a1"
        radius: 25
    }

    Rectangle {
        id: circleL
        x: 63
        y: 128
        width: 50
        height: 50
        color: "#000000"
        radius: 25

        onXChanged: {
            gamepadinterface.valueChanged(GamePadIFS.AxisLeftX,
                            ((x-rectangleL.x)/
                            (rectangleL.width-circleL.width))*2-1);
        }

        onYChanged: {
            gamepadinterface.valueChanged(GamePadIFS.AxisLeftY,
                            ((y-rectangleL.y)/
                            (rectangleL.height-circleL.height)*2)-1);
        }

        MouseArea {
            id: mouseArea
            x: 0
            y: 0
            width: circleL.width
            height: circleL.height
            drag.target: circleL
            drag.maximumX: rectangleL.x
                           + rectangleL.width
                           - circleL.width;
            drag.minimumX: rectangleL.x;
            drag.maximumY: rectangleL.y
                           + rectangleL.height
                           - circleL.height;
            drag.minimumY: rectangleL.y;

            onDoubleClicked: {
                circleL.x    = rectangleL.x
                                + rectangleL.width/2
                                - circleL.width/2;
                circleL.y    = rectangleL.y
                                + rectangleL.height/2
                                - circleL.height/2;
            }
        }
    }

    Column {
        id: column
        x: 31
        y: 245
        width: 114
        height: 119

        Button {
            id: buttonU
            x: 38
            width: 38
            height: 38
            text: qsTr("U")
            anchors.horizontalCenter: parent.horizontalCenter
            highlighted: gamepad.buttonUp

            onPressedChanged:{
                gamepadinterface.valueChanged(
                            GamePadIFS.ButtonUp,
                            buttonU.pressed);
            }
        }

        Item {
            id: row
            width: 114
            height: 38
            visible: true

            Button {
                id: buttonL
                width: 38
                height: 38
                text: qsTr("L")
                anchors.left: parent.left
                anchors.leftMargin: 0
                highlighted: gamepad.buttonLeft

                onPressedChanged:{
                    gamepadinterface.valueChanged(
                                GamePadIFS.ButtonLeft,
                                buttonL.pressed);
                }
            }

            Button {
                id: buttonR
                width: 38
                height: 38
                text: qsTr("R")
                anchors.right: parent.right
                anchors.rightMargin: 0
                highlighted: gamepad.buttonRight

                onPressedChanged:{
                    gamepadinterface.valueChanged(
                                GamePadIFS.ButtonRight,
                                buttonR.pressed);
                }
            }
        }

        Button {
            id: buttonD
            x: 38
            width: 38
            height: 38
            text: qsTr("D")
            anchors.horizontalCenter: parent.horizontalCenter
            highlighted: gamepad.buttonDown

            onPressedChanged:{
                gamepadinterface.valueChanged(GamePadIFS.ButtonDown,
                                              buttonD.pressed);
            }

        }
    }

    Column {
        id: column1
        x: 262
        y: 245
        width: 114
        height: 119
        Button {
            id: buttonY
            x: 38
            width: 38
            height: 38
            text: qsTr("Y")
            highlighted: gamepad.buttonY
            anchors.horizontalCenter: parent.horizontalCenter

            onPressedChanged:{
                gamepadinterface.valueChanged(
                            GamePadIFS.ButtonY,
                            buttonY.pressed);
            }
        }

        Item {
            id: row1
            width: 114
            height: 38
            visible: true
            Button {
                id: buttonX
                width: 38
                height: 38
                text: qsTr("X")
                anchors.left: parent.left
                highlighted: gamepad.buttonX
                anchors.leftMargin: 0

                onPressedChanged:{
                    gamepadinterface.valueChanged(
                                GamePadIFS.ButtonX,
                                buttonX.pressed);
                }
            }

            Button {
                id: buttonB
                width: 38
                height: 38
                text: qsTr("B")
                anchors.right: parent.right
                highlighted: gamepad.buttonB
                anchors.rightMargin: 0

                onPressedChanged:{
                    gamepadinterface.valueChanged(
                                GamePadIFS.ButtonB,
                                buttonB.pressed);
                }
            }
        }

        Button {
            id: buttonA
            x: 38
            width: 38
            height: 38
            text: qsTr("A")
            highlighted: gamepad.buttonA
            anchors.horizontalCenter: parent.horizontalCenter

            onPressedChanged:{
                gamepadinterface.valueChanged(
                            GamePadIFS.ButtonA,
                            buttonA.pressed);
            }
        }
    }

    Rectangle {
        id: rectangleR
        x: 244
        y: 78
        width: 150
        height: 150
        color: "#a6c8a1"
        radius: 25
    }

    Rectangle {
        id: circleR
        x: 294
        y: 128
        width: 50
        height: 50
        color: "#000000"
        radius: 25

        onXChanged: {
            gamepadinterface.valueChanged(GamePadIFS.AxisRightX,
                            ((x-rectangleR.x)/
                            (rectangleR.width-circleR.width))*2-1);
        }

        onYChanged: {
            gamepadinterface.valueChanged(GamePadIFS.AxisRightY,
                            ((y-rectangleR.y)/
                            (rectangleR.height-circleR.height)*2)-1);
        }

        MouseArea {
            id: mouseArea1
            x: 0
            y: 0
            width: circleR.width
            height: circleR.height
            drag.target: circleR
            drag.maximumX: rectangleR.x
                           + rectangleR.width
                           - circleR.width;
            drag.minimumX: rectangleR.x;
            drag.maximumY: rectangleR.y
                           + rectangleR.height
                           - circleR.height;
            drag.minimumY: rectangleR.y;

            onDoubleClicked: {
                circleR.x    = rectangleR.x
                                + rectangleR.width/2
                                - circleR.width/2;
                circleR.y    = rectangleR.y
                                + rectangleR.height/2
                                - circleR.height/2;
            }

        }
    }
}
