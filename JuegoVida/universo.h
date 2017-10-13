/*
 * Autor: José Rodrigo Pérez Beltrán
 * Versión: Qt Creator 4.4.0, MinGW 5.3.0 32 bits
 * Descripción: Clase para manipular la malla de celulas
 * y ayudar en su lectura y escritura.
*/
#ifndef UNIVERSO_H
#define UNIVERSO_H

#include <QObject>
#include <celula.h>

class Universo : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void setCelula(int x,int y, bool valor);
    Q_INVOKABLE void setCelulaI(int pos, bool valor);
    Q_INVOKABLE void evolucionarTablero();
    Q_INVOKABLE int numeroVecinos(int x, int y);
    Q_INVOKABLE bool celulaI(int pos);
    Q_INVOKABLE bool celula(int x, int y);
    Q_INVOKABLE void buscar(int pos,int &p1,int &p2);
private:
    Celula tablero[18][26];
};

#endif // UNIVERSO_H
