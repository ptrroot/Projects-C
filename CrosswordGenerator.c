/*
 *Crossword Gen
 *Autor: José Rodrigo Pérez Beltrán
 *Compiler: GNU project C and C++ compiler
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define DICCIONARIO 8
#define TAMANIOINFO 10
#define TAMANIOTABLERO 30
#define PALABRAS 9

//empaqueta la informacion sobre las palabras en el crucigrama
void NuevaPalabra(int Informacion[][TAMANIOINFO], int indexInfo,int x, int y,int posDiccionario,int numero);
//function prototypes
void ImprimirTablero(char Tablero [] [TAMANIOTABLERO],char *def  [TAMANIOTABLERO] , int Informacion[][TAMANIOINFO],int index);

int main()
{

  //dibujan el crucigrama
  int Buscar(int Informacion[][TAMANIOINFO], int indexInfo, char *dicc[], char **semejante,char Tablero [] [TAMANIOTABLERO],int *ptr);
  void Escribir(int Informacion[][TAMANIOINFO],int indexInfo,char *ptrNueva, char *semejante, char Tablero [] [TAMANIOTABLERO], int pos,int *ptr);

  int palabrasInfo[TAMANIOINFO][TAMANIOINFO], index = 0, x, y, result,numero,*distancia;
  int dis;
  distancia = &dis;
  char *ptrNueva,*ptrAnterior , *semejante, Tablero[TAMANIOTABLERO][TAMANIOTABLERO];
   
  char *Diccionario[DICCIONARIO] =
    {
      "amateur",
      "autopase",
      "calentar",
      "dopaje",
      "desmarcarse",
      "invicto",
      "liderar",
      "defensa"
    };

    char *Definiciones[DICCIONARIO] =
    {
      "aficionado o no profesional",
      "accion de soltar un balon y volverlo a tomar",
      "desentumeser los musculos antes de practicar un deporte",
      "tomar farmacos para mejorar el rendimiento",
      "desplazar al contrario que te marca",
      "grupo que aun no pierde ningun partido",
      "encabezar o dirigir",
      "persona que se encarga de defender"
    };
  

  srand(time(NULL));


  for(int y = 0; y < TAMANIOTABLERO ; y++)
    for(int x = 0; x < TAMANIOTABLERO ; x++)
      Tablero[y][x] = ' ';

  //Escribe la primer palabra

  numero = 0 + rand() % DICCIONARIO - 1;
  ptrNueva = Diccionario[ numero ]; 
  x = 10 + rand() % 15;
  y = 10 + rand() % 15;

  NuevaPalabra( palabrasInfo, index, x, y, numero, 1);
  
  Tablero[ y ][ x - 1 ] = palabrasInfo[ 4 ][ index ] + '0';
  
  for(;*ptrNueva != '\0'; ptrNueva++)
    Tablero[ y ][ x++ ] = *ptrNueva;

  

  //Dibuja el resto del crucigrama
   for(int i = 2; i <= PALABRAS; i++)
     if( (result = Buscar(palabrasInfo,index,Diccionario,&semejante,Tablero,distancia)) != -1)
       {
	 ptrNueva = Diccionario[result];
	 Escribir(palabrasInfo,++index,ptrNueva,semejante,Tablero,result,distancia);
       }

   ImprimirTablero( Tablero, Definiciones , palabrasInfo,index);
  
  return 0;
} //*** end main


void NuevaPalabra(int Informacion[][TAMANIOINFO], int indexInfo,int x, int y,int posDiccionario,int numero)
{
  if(indexInfo == 0)
    Informacion[3][indexInfo] = 0;
    
  else
    {
      if( Informacion[3][indexInfo - 1] == 0)
	Informacion[3][indexInfo] = 1;
      else  Informacion[3][indexInfo] = 0;
    }

  Informacion[0][indexInfo] = x;
  Informacion[1][indexInfo] = y;
  Informacion[2][indexInfo] = posDiccionario;
  Informacion[4][indexInfo] = numero;

} //*** Nueva palabra


void ImprimirTablero(char Tablero [] [TAMANIOTABLERO],char *def  [DICCIONARIO] , int Informacion[][TAMANIOINFO],int index)
 {
   for(int y = 0; y < TAMANIOTABLERO; y++)
     {
       for(int x = 0; x < TAMANIOTABLERO; x++)
	 if(isalpha(Tablero[y][x]))
	   printf("[ ]");
	 else if(isspace(Tablero[y][x]))
	 printf("   ");
         else
	  printf("%c  ",Tablero[y][x]);

	printf("\n");
     }

   printf("\nPistas:\n\nHorizontales:\n");
   for(int x = 0; x <= index; x+= 2)
     printf("%d.%s\n",Informacion[4][x],def[Informacion[2][x]]);
   printf("\nVerticales:\n");   
   for(int x = 1; x <= index; x+= 2)
   printf("%d.%s\n",Informacion[4][x],def[Informacion[2][x]]);
 }  //*** end Imprimir Tablero


int Buscar(int Informacion[][TAMANIOINFO],int indexInfo, char *dicc[], char ** semejante, char Tablero [] [TAMANIOTABLERO],int *ptrDis)
{
  
  //function prototypes
  int indexDisponible(int y, int array[][TAMANIOINFO]);
  int Validar(int Informacion[][TAMANIOINFO],int indexInfo, char *ptrNueva, char **semejante, char Tablero [] [TAMANIOTABLERO],int dist);
  
  int index = Informacion[2][ indexInfo];
  int orientacion = Informacion[3][ indexInfo];
  int x = Informacion[0][ indexInfo];
  int y = Informacion[1][ indexInfo];
  int dis;
  char *ptrAnt = dicc[ index], *ptr;

  for(;*ptrAnt != '\0'; ptrAnt++)
      for(int y = 0; y < DICCIONARIO; y++)
      if(indexDisponible(y, Informacion) == 1)
	{
	
	  ptr = strchr(dicc[y],*ptrAnt);

	  
	 while(ptr != NULL){ 
	    //lloop
	   dis = ptrAnt - dicc[index];
	   if(Validar(Informacion,indexInfo,dicc[y],&ptr,Tablero,dis) == 1)
		{

			       *ptrDis = dis;
			       
		  *semejante = ptr;
		  return y;
		}
	      ptr = strchr(ptr+1,*ptrAnt);
	    }
	    
	}
    
  return -1;
}  //*** end Buscar

int indexDisponible(int y, int array[][TAMANIOINFO])
{
  for(int x = 0; x < TAMANIOINFO; x++)   
      if(y == array[2][x])
	return 0;
    
  return 1;

}  //*** end indexDisponible

int Validar(int Informacion[][TAMANIOINFO],int indexInfo,  char *ptrNueva, char **semejante, char Tablero [] [TAMANIOTABLERO], int dist)
{
  
  char *medio =  *semejante;
  char *final  = ptrNueva;
  int dist2 = 0;
  while(*final != '\0')
    {final++;dist2++;}
  dist2--;
  final--;
  
  int  x = Informacion[0][indexInfo];
  int  y = Informacion[1][indexInfo];

  int orientacion = Informacion[3][indexInfo];
  
  //verificamos que no se salga de la matriz
  if(orientacion == 0)
    {
      x += dist;
      if(y  - (dist+1) < 0)
	return 0;
      
      if(y  + (dist2+1) >= TAMANIOTABLERO)
	return 0;
	
    }
  else
    {
      y += dist;
      if(x  - (dist+1) < 0)
	return 0;

      if(x  + (dist2+1) >= TAMANIOTABLERO) 
	return 0;
       
      }

  
  while( medio >= ptrNueva){      
      if(orientacion == 0)
	{
	  if(Tablero[y][x] != *medio && Tablero[y][x] != ' ')
	      return 0;
	    
	  y--;
	}
      else
	{
	  if(Tablero[y][x] != *medio && Tablero[y][x] != ' ')
	    return 0;
	  x--; 
	}
      medio--;
  }
  
  if(y >= 0 && x >= 0)
    if(Tablero[y][x] != ' ')
      return 0;
    
  
  medio =  *semejante;
  
  if(orientacion == 0 )
      y = Informacion[1][indexInfo];
    
  else
      x = Informacion[0][indexInfo];
    
    
  
  while( medio <=  final)      
    {
      if(orientacion == 0)
	{
	  if(Tablero[y][x] != *medio && Tablero[y][x] != ' ')
	      return 0;
	    
	  y++;
	}
      else
	{
	   if(Tablero[y][x] != *medio && Tablero[y][x] != ' ')
	       return 0;
	     
	  x++; 
	}
      medio++;
    }
 
  return 1;
} //*** end validar


void Escribir(int Informacion[][TAMANIOINFO],int indexInfo,char *ptrNueva, char *semejante, char Tablero [] [TAMANIOTABLERO], int pos,int *ptrDis)
{

  
  char *medio =  semejante;
  char *final  = ptrNueva;
  
  while(*final != '\0')final++;
  final--;
  
  int  x = Informacion[0][indexInfo - 1];
  int  y = Informacion[1][indexInfo - 1];
  int numero = Informacion[4][indexInfo - 1];
  int orientacion = Informacion[3][indexInfo - 1];


   if(orientacion == 0 )
     x += *ptrDis;
  else
    y += *ptrDis;
    
   
  
  while( medio >= ptrNueva)
    {
      Tablero[y][x] = *medio;
      medio--;
       if(orientacion == 0) y--;
       else x--;
    }

   
    
   
   medio =  semejante;


   if(orientacion == 0 )
    {
      Tablero[y][x] = numero + '0';
      NuevaPalabra( Informacion, indexInfo, x, y + 1, pos, numero);
      y = Informacion[1][indexInfo - 1];
       
    }
  else
    {
      Tablero[y][x] = ++numero + '0';
     NuevaPalabra( Informacion, indexInfo, x+1, y, pos, numero);
      x = Informacion[0][indexInfo - 1];
    }

   while(medio <= final)
     {
       Tablero[y][x] = *medio;
       medio++;
       if(orientacion == 0) y++;
       else x++;
     }

} //*** end Escribir
