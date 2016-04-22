/*
 *EightQueens
 *Autor: José Rodrigo Pérez Beltrán
 *Compiler: GNU project C and C++ compiler
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANIO 40

void Shown(char array[][TAMANIO]); 
int patern1(char array[][TAMANIO],int *X, int *Y, int lim);
int patern2(char array[][TAMANIO],int *X, int *Y, int lim);
int patern3(char array[][TAMANIO],int *X, int *Y, int lim);
int patern4(char array[][TAMANIO],int *X, int *Y, int lim);
int (*patterns[4]) (char array[][TAMANIO],int *min, int *max, int lim) = { patern1, patern2,patern3,patern4};


int main()
{



  //Function prototypes
  void Start(char array[][TAMANIO]);
  void Generate(char array[][TAMANIO], int min, int max, int *p2);
  void Rest(char array[][TAMANIO], int min, int max);
  int recorrerLaberinto(char array[][TAMANIO],int x, int y);
  
  char maze[TAMANIO][TAMANIO];
  int  s2;
  int r;
  int *ptrS2 = &s2;

  
  srand(time(NULL));

  Start(maze);
  Generate(maze,0,TAMANIO,ptrS2);
  Rest(maze,5,TAMANIO - 5);
  Rest(maze,5,TAMANIO - 5);
  Rest(maze,5,TAMANIO - 5);
  Rest(maze,5,TAMANIO - 5);
  Rest(maze,5,TAMANIO - 5);
  Rest(maze,5,TAMANIO - 5);





  r = recorrerLaberinto(maze , 0,s2);
  printf("\n%d\n",r);
  return 0;
  
}//**** end main

void Rest(char array[][TAMANIO], int min, int max)
{
  int x , y,r,flag;
  int *ptrX = &x,*ptrY = &y;
  for(int i = 0; i < TAMANIO - 10;i++)
    {
       x  = min + rand() % max;
       y  = min + rand() % max;
       r  = 0 + rand() % 3;
	   //  printf("\n%d\n",r);
	   switch(r)
	     {
	     case 0:
	       flag = (*patterns[r])(array,ptrX,ptrY,max);
	       break;
	     case 1:
	       flag = (*patterns[r])(array,ptrX,ptrY,max - 1);
	       break;
	     case 2:
	       flag = (*patterns[r])(array,ptrX,ptrY, min + 1);
	       break;
	     case 3:
	       flag = (*patterns[r])(array,ptrX,ptrY, min + 1);
	       break;
	     }
    }
}//**** end Rest


int patern1(char array[][TAMANIO],int *posX, int *posY,int lim)
{
  int length = 1 + rand() % 4, x = *posX;
 
  if(*posX + length < lim)
    {
      for(; *posX < x + length; *posX += 1)
	array[*posY][*posX] = ' ';

      return 1;
    }
  else
    {
      for(; *posX <= lim; *posX += 1)
	 array[*posY][*posX] = ' ';
      
      return 0;
    }
}//**** end patern1

int patern2(char array[][TAMANIO],int *posX, int *posY, int lim)
{

  int length = 1 + rand() % 4, y = *posY;

  if(y + length < lim)
    for(; *posY < y + length ; *posY += 1)
	array[*posY][*posX] = ' ';

  else for(; *posY < lim ; *posY += 1)
	array[*posY][*posX] = ' ';
  return 1;
}//**** end patern2

int patern3(char array[][TAMANIO],int *posX, int *posY, int lim)
{
   int length = 1 + rand() % 4, y = *posY;

  if(y - length > lim)
    for(; *posY > y - length ; *posY -= 1)
	array[*posY][*posX] = ' ';

  else for(; *posY > lim ; *posY -= 1)
	array[*posY][*posX] = ' ';
  return 1;
}//**** end patern3

int patern4(char array[][TAMANIO],int *posX, int *posY, int lim)
{
   int length = 1 + rand() % 4,x = *posX;
  if(x - length > lim)
    {
      for(; *posX > x - length; *posX -= 1)
	array[*posY][*posX] = ' ';

      return 1;
    }
  else
    {
      for(; *posX > lim;*posX -= 1)
	array[*posY][*posX] = ' ';
      return 1;
    }
} //**** end patern4


void Generate(char array[][TAMANIO],int min, int max, int *p2)
 {
   int x = min, y,flag = 1,r;
   int *ptrX = &x, *ptrY = &y;

   y =  0 + rand() % 11;
   *p2 = y;
   
   while(flag == 1)
     {

       if(x == min)	   
	 flag = (*patterns[0])(array,ptrX,ptrY,max);
	 
       else
	 {
	   r  = 0 + rand() % 3;
	   //  printf("\n%d\n",r);
	   switch(r)
	     {
	     case 0:
	       flag = (*patterns[r])(array,ptrX,ptrY,max);
	       break;
	     case 1:
	       flag = (*patterns[r])(array,ptrX,ptrY,max - 1);
	       break;
	     case 2:
	       flag = (*patterns[r])(array,ptrX,ptrY, min + 1);
	       break;
	     case 3:
	       flag = (*patterns[r])(array,ptrX,ptrY, min + 1);
	       break;
	     }

	 }
       if(r == 3)    Shown(array);
       //  	   printf("\n%d\n",x);
     }
    Shown(array);
    
 }//**** end Gen

void Shown(char array[][TAMANIO])
 {
    printf("\n\n");
   for(int y = 0; y < TAMANIO; y++)
     {
       for(int x = 0 ; x < TAMANIO; x++)
          printf("%c",array[y][x]);
       
       printf("\n");
     }
    printf("\n\n");
} //**** end Shown

 void Start(char array[][TAMANIO])
 {
   for(int y = 0; y < TAMANIO; y++)
     for(int x = 0 ; x < TAMANIO; x++)
       array[y][x] = '#';
 }//**** end start




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
  
  if( y + 1 < TAMANIO )
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
  
  
  
  if( x + 1 < TAMANIO)
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

  printf("%d",x);
  Shown(array);
  usleep(200000);
   
  //function prototypes
  int EvaluarCaminos(char array[][TAMANIO],int array2[4],int x, int y);
  
  int res ,exec,numero, caminos[4] = {0};

  if(x == TAMANIO -1 )
     return 1;
   

  numero = EvaluarCaminos(array,caminos,x,y);
  
  if(numero == 0)
     return numero;
    

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
      
      if(res == 0)
	  return recorrerLaberinto(array, x  ,  y );
      else return 1;
      
	  }	
    }
}//**** end rrecorer laberinto
