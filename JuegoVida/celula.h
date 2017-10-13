/*
 * Autor: José Rodrigo Pérez Beltrán
 * Versión: Qt Creator 4.4.0, MinGW 5.3.0 32 bits
 * Descripción: Clase para guardar el estado de las celulas
*/
#ifndef CELULA_H
#define CELULA_H

#include <QObject>

class Celula : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool estado READ estado WRITE setEstado )
    Q_PROPERTY(bool estadoFuturo READ estadoFuturo WRITE setEstadoFuturo )
public:
    Celula();
    bool estado() const;
    bool estadoFuturo() const;
    void setEstado(const bool valor);
    void setEstadoFuturo(const bool valor);
    Q_INVOKABLE void evolucionarCelula();
private:
    bool m_estado;
    bool m_estadoFuturo;
};

#endif // CELULA_H
