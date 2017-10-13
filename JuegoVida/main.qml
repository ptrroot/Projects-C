/*
 * Autor: José Rodrigo Pérez Beltrán
 * Versión: Qt Creator 4.4.0, MinGW 5.3.0 32 bits
 * Descripción: Dibuja una ventana y le presenta al usuario
 la malla de celulas y un panel de control para iniciar o
 detener la animacion. Ocupa un Timer para controlar la velocidad
 con que se reproduce la animacion.
*/
import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick 2.0

Window {
    visible: true
    width: 1200
    height: 700
    title: qsTr("Juego de la vida")

    Timer {
            id:timer
            interval: 150; running: false; repeat: true
            onTriggered: juego()
        }

    function juego()
    {
        obj.pasoDiscreto()
        for(var i = 0; i < 468; i++)
        {
            if(obj.celula(i))
                tablero.children[i].color  = "red"
            else tablero.children[i].color  = "#00000000"
        }
    }

    //panel de celulas
    Rectangle{
        height: parent.height
        y:50
        anchors.left: parent.left
        anchors.leftMargin: 50
        Universo{
            id:tablero
            columns: 26
        }
    }

    //panel de control
    Rectangle{
        height: parent.height
        y:100
        anchors.right: parent.right
        anchors.rightMargin: 200
        Button{
            text:"Jugar"
            onClicked:timer.start()
        }
        Button  {
            text:"Pausar"
            y:200
            onClicked: timer.stop()
        }
    }

}
