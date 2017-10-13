/*
 * Autor: José Rodrigo Pérez Beltrán
 * Versión: Qt Creator 4.4.0, MinGW 5.3.0 32 bits
 * Descripción: Clase para aplicar las reglas geneticas
 * y cordinar la evolucion del juego
*/
#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <QObject>
#include <QQuickview>
#include <universo.h>

class Simulador : public QObject
{
    Q_OBJECT
public:
   Q_INVOKABLE bool celula(int pos);
   Q_INVOKABLE void setCelula(int pos,bool valor);
   Q_INVOKABLE void pasoDiscreto();
private:
    Universo miUniverso;
};

#endif // SIMULADOR_H
