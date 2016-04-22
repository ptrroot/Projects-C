/*
 *EightQueens
 *Autor: José Rodrigo Pérez Beltrán
 *Compiler: GNU project C and C++ compiler
*/

#include <stdio.h>
#define TAMANIO 8

void print(int array[][TAMANIO]);

int main()
{

  //******* function prototypes
  int Run(int posX,int posY);

  for(int y = 0; y < TAMANIO; y++)
  for(int x = 0; x < TAMANIO ; x++){
    
  int result = Run( x,y );

  if(result > 0)
    printf("\n\nit works\n");
     
  }

  return 0;
}   //******* end main

int Run(int posX,int posY)
{

  //****** function prototypes
  void mark(int array[][TAMANIO],int point[]);
  
  int board[TAMANIO][TAMANIO] =
    {
      {22,21,21,21,21,21,21,22},
      {21,23,23,23,23,23,23,21},
      {21,23,25,25,25,25,23,21},
      {21,23,25,27,27,25,23,21},
      {21,23,25,27,27,25,23,21},
      {21,23,25,25,25,25,23,21},
      {21,23,23,23,23,23,23,21},
      {22,21,21,21,21,21,21,22}
    };

  int Queen[2] = {posX,posY};
  int cell = 0, i = 1, min;

  mark(board,Queen);

  if(Queen[1] == (TAMANIO - 1))
    Queen[1] = 0;
  else Queen[1]++;
  
  while(i < TAMANIO)
  {

  
  for(int x = 0; x < TAMANIO; x++)
    if(board[Queen[1]][x] != 1)
       cell = board[Queen[1]][x]; 

  if(cell > 0)
    {

   min = 27;

   for(int x = 0; x < TAMANIO; x++)
    if(board[Queen[1]][x] != 1 && min > board[Queen[1]][x])
      {
	min = board[Queen[1]][x];
        Queen[0] = x;
      }
   i++;
   cell = 0;
 
  mark(board,Queen);

  if(Queen[1] == (TAMANIO - 1))
    Queen[1] = 0;
  else Queen[1]++;
  
  }
  else  return 0;

  } //****** end while

  print(board);

  return 1;
}   //****** end Run

void mark(int array[][TAMANIO], int point[])
{
  
    for(int i = 1;  i < TAMANIO; i++)
      {

	  if(point[0] + i < TAMANIO )
	  {
	    
	    array[ point[1] ][ point[0] + i ] = 1;

	    if(point[1] - i >= 0)    
		array[ point[1] - i ][ point[0] + i ] = 1;

	    if(point[1] + i < TAMANIO )
	      array[ point[1] + i ][ point[0] + i ] = 1;
	      
	  }

	
	if(point[0] - i >= 0)
	  {
	    
	    array[ point[1] ][ point[0] - i ] = 1;

	    if(point[1] - i >= 0)    
		array[ point[1] - i ][ point[0] - i ] = 1;

	    if(point[1] + i < TAMANIO )
	      array[ point[1] + i ][ point[0] - i ] = 1;
	      
	  }

	  if(point[1] - i >= 0)
	   {
		array[ point[1] - i ][ point[0]] = 1;
	   }

	  if(point[1] + i < TAMANIO )
	    {
		array[ point[1] + i ][ point[0]] = 1;
	    }
	
      }
}   //******* end mark


void print(int array[][TAMANIO])
{
   printf("\n\n");

   for(int y = 0; y < TAMANIO; y++)
    {
      for (int x = 0; x < TAMANIO; x++)
	if(array[y][x] == 1)printf("%d",array[y][x]);
	else printf("*");
      printf("\n");
    }

  printf("\n\n");
}   //****** end print
