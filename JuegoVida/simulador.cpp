#include "simulador.h"

bool Simulador::celula(int pos)
{
    return miUniverso.celulaI(pos);
}

void Simulador::setCelula(int pos,bool valor)
{
    miUniverso.setCelulaI(pos,valor);
}

void Simulador::pasoDiscreto()
{
    int vecinos = 0;
    bool valorFuturo;
    for(int y = 0; y < 18; y++)
        for(int x = 0; x < 26; x++)
        {
            valorFuturo = false;
            vecinos = miUniverso.numeroVecinos(x,y);
            //reglas geneticas
            if(vecinos == 3)
                valorFuturo = true;
            else if(miUniverso.celula(x,y))
            {
                if(vecinos ==2)
                    valorFuturo = true;
            }
            miUniverso.setCelula(x,y,valorFuturo);
        }
    miUniverso.evolucionarTablero();
}
