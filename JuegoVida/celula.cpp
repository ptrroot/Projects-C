#include "celula.h"

Celula::Celula()
{
    m_estado = false;
    m_estadoFuturo = false;
}

bool Celula::estado() const
{
    return m_estado;
}

void Celula::evolucionarCelula()
{
    m_estado = m_estadoFuturo;
}

bool Celula::estadoFuturo() const
{
    return m_estadoFuturo;
}

void Celula::setEstado(const bool edo)
{
    m_estado = edo;
}

void Celula::setEstadoFuturo(const bool edo)
{
    m_estadoFuturo = edo;
}
