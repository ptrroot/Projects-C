/*
 * Autor: José Rodrigo Pérez Beltrán
 * Versión: Qt Creator 4.4.0, MinGW 5.3.0 32 bits
 * Descripción: Dibuja una malla de celulas y les da
 un identificador.
*/
import QtQuick 2.0

Grid{
    Repeater{
        model: 468
        delegate: Celula{
            miId:index
        }
    }
}
