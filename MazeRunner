/*
 *MazeRunner
 *Autor: José Rodrigo Pérez Beltrán
 *Compiler: GNU project C and C++ compiler
*/

#include <stdio.h>
#include <stdio.h>
#include <time.h>
#define TAMANIO 12

int main()
{

  //function prototypes
  int recorrerLaberinto(char array[][TAMANIO],int x, int y);

  char maze[TAMANIO][TAMANIO]
    =
    {
    {'#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#'},
    {' ',' ','#',' ','#',' ','#','#','#','#',' ','#'},
    {'#','#','#',' ','#',' ',' ',' ',' ','#',' ',' '},
    {'#',' ',' ',' ',' ','#','#','#',' ','#',' ','#'},
    {'#','#','#','#',' ','#',' ','#',' ','#',' ','#'},
    {'#',' ',' ','#',' ','#',' ','#',' ','#',' ','#'},
    {'#','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},
    {'#','#','#','#','#','#',' ','#','#','#',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#'},
  };

    recorrerLaberinto(maze , 0, 2);
  
  return 0;
  
}//**** end main


int EvaluarCaminos(char array[][TAMANIO],int array2[4],int x, int y)
{
  int numero = 0; 

  if( y - 1 > 0)
    {
      switch(array[y - 1][x])
	{
	case 'X':break;
	case '#':
	  array2[1] = -1;
	  break;
        default:
	   numero++;
	   array2[1] = 1;
	}             
    }
  
  if( y + 1 < 12 )
    {
      switch(array[y + 1][x])
	{
	case 'X':break;
	case '#':
	  array2[3] = -1;
	  break;
        default:
	   numero++;
	   array2[3] = 1;
	}
    }
  
  
  
  if( x + 1 < 12)
    {
      switch(array[y][x + 1])
	{
	case 'X':break;
	case '#':
	  array2[0] = -1;
	  break;
        default:
	   numero++;
	   array2[0] = 1;
	}
    }
  

  if( x -1 > 0)
    {
     switch(array[y][x - 1])
	{
	case 'X':break;
	case '#':
	  array2[2] = -1;
	  break;
        default:
	   numero++;
	   array2[2] = 1;
	}
    }
   
  return numero;
  
}//**** end evaluar caminos


int recorrerLaberinto(char array[][TAMANIO],int x, int y)
{

  array[y][x] = 'X';
  
  printf("\n\n");
  for(int y = 0; y < TAMANIO; y++)
    {
      for(int x = 0; x < TAMANIO; x++)
         printf("%c",array[y][x]);
      printf("\n");
    }
  
  usleep(200000);
   
  //function prototypes
  int EvaluarCaminos(char array[][TAMANIO],int array2[4],int x, int y);
  
  int res ,exec,numero, caminos[4] = {0};

  //si ya recorrio el laberinto termina
  if(x == 11)
     return 1;
   

  numero = EvaluarCaminos(array,caminos,x,y);


  //si no hay mas camino, regresa 
  if(numero == 0)
     return numero;
    

  //si hay un solo camino lo sigue
  if(numero == 1)
    {
      for(int i = 0; i < 4; i++)
	if(caminos[i] == 1)
	  switch(i)
	    {
	    case 0:	       
	      return recorrerLaberinto(array, x + 1,  y);
	      
	    case 1:
	      return recorrerLaberinto(array, x,  y - 1);
	      
	    case 2:
	      return recorrerLaberinto(array, x - 1,  y);
	      
	    case 3:
	      return recorrerLaberinto(array, x ,  y + 1);
	      
	    }
    }else
    {
      //si hay mas de uno,los recorre tocando la pared derecha con la mano
      for(int i = 0; i < 4; i++)
	if(caminos[i] == 0)
	  {
	    switch(i)
	    {
	    case 0:
	      
	      if(caminos[1] == 1)
	       res = recorrerLaberinto(array, x,  y - 1);
	      else if(caminos[2] == 1)
		res = recorrerLaberinto(array, x - 1,  y);
	      
	      break;
	    case 1:
	      
	      if(caminos[2] == 1)
		res = recorrerLaberinto(array, x - 1,  y);
	      else if(caminos[3] == 1)
		res = recorrerLaberinto(array, x ,  y + 1);
	       
	      break;
	    case 2:
	      
	      if(caminos[3] == 1)
	       res = recorrerLaberinto(array, x,  y +1);
	      else if(caminos[0] == 1)
		res = recorrerLaberinto(array, x + 1,  y);
      	       
	      break;
	    case 3:
	       if(caminos[0] == 1)
	        res = recorrerLaberinto(array, x + 1 ,  y );
	       else if(caminos[1] == 1)
		 res = recorrerLaberinto(array, x,  y - 1);
	      
	      break;
	      
	    }

	    //si el camino recorrido no funciono, recorre los que faltan
      if(res == 0)
	  return recorrerLaberinto(array, x  ,  y );
      else return 1;
      
	  }	
    }
    
}//**** end recorrer laberinto
