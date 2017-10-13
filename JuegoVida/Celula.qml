/*
 * Autor: José Rodrigo Pérez Beltrán
 * Versión: Qt Creator 4.4.0, MinGW 5.3.0 32 bits
 * Descripción: Dibuja un rectangulo con un MouseArea para
 * simular una celula
*/
import QtQuick 2.0

Rectangle{
    property int miId: 0
    width: 36;height: 36
    border.color: "#a6aab2"
    MouseArea{
        anchors.fill: parent
        onClicked: {
                      if(obj.celula(miId))
                      {
                          parent.color ="#00000000"
                         obj.setCelula(miId,false)
                      }
                       else {
                          parent.color = "red"
                          obj.setCelula(miId,true)
                        }
                   }
    }
}
