import QtQuick 2.15
import QtQuick.Window 2.15
import QtGamepad 1.12
import QtQuick.Controls 2.5
import an.qt.GamePadInterFace 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    Connections {
        target: GamepadManager;
        onGamepadConnected: gamepad.deviceId = deviceId;
    }

    Gamepad {
        id: gamepad;
        //deviceId: GamepadManager.connectedGamepads.length > 0 ? GamepadManager.connectedGamepads[0] : -1;

        onAxisLeftXChanged: {
            //console.log(gamepad.axisLeftX);
            gamepadinterface.valueChanged(1,gamepad.axisLeftX);
        }


    }

    GamePadInterFace {
        id: gamepadinterface;
    }
    Connections {
        target: gamepad;
        onButtonAChanged: {
            gamepadinterface.valueChanged(2,gamepad.buttonA);
        }
    }

}


