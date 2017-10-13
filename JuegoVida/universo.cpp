#include "universo.h"
#include <QPointer>

void Universo::buscar(int pos,int &x,int &y)
{
    int i = 0;
    for(y = 0; y < 18; y++)
       for (x = 0; x < 26; x++)
           if(i++ == pos)
               return;
}

void Universo::setCelula(int x,int y, bool valor)
{
    tablero[y][x].setEstadoFuturo(valor);
}

void Universo::setCelulaI(int pos, bool valor)
{
    int x,y;
    buscar(pos,x,y);
    tablero[y][x].setEstado(valor);
}

void Universo::evolucionarTablero()
{
    Celula * muestra;
    for(int y = 0; y < 18; y++)
       for (int x = 0; x < 26; x++)
       {
           muestra = &tablero[y][x];
           muestra->evolucionarCelula();
       }
}

int Universo::numeroVecinos(int x, int y)
{
    int vecinos = 0;
    Celula *vecino;
    bool limite1 = false;
    bool limite2 = false;
    bool limite3 = false;
    bool limite4 = false;

   if(y - 1 >= 0) limite1 = true;
   if(y + 1 <= 17) limite3 = true;
   if(x + 1 <= 25) limite2 = true;
   if(x - 1 >= 0) limite4 = true;

   if(limite1)
   {
       vecino = &tablero[y-1][x];
       if(vecino->estado())
           vecinos++;
       if(limite4){
           vecino = &tablero[y-1][x-1];
           if(vecino->estado())
               vecinos++;
       }
       if(limite2){
           vecino = &tablero[y-1][x+1];
           if(vecino->estado())
               vecinos++;
         }
   }

   if(limite3)
   {
       vecino = &tablero[y+1][x];
       if(vecino->estado())
           vecinos++;
       if(limite4){
           vecino = &tablero[y+1][x-1];
           if(vecino->estado())
               vecinos++;
       }
       if(limite2){
           vecino = &tablero[y+1][x+1];
           if(vecino->estado())
               vecinos++;
       }
   }

   if(limite4){
       vecino = &tablero[y][x-1];
       if(vecino->estado())
           vecinos++;
    }
   if(limite2){
       vecino = &tablero[y][x+1];
       if(vecino->estado())
           vecinos++;
    }
    return vecinos;
}

bool Universo::celulaI(int pos)
{
   int x,y;
    buscar(pos,x,y);
    return tablero[y][x].estado();
}

bool Universo::celula(int x, int y)
{
    return tablero[y][x].estado();
}
