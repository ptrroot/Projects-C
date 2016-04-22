/*
 *Rabbit and turtle race
 *Autor: Jose Rodrigo Perez Beltran
 *compiler: GNU project C and C++ compiler
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{


  //Function prototypes
  void MoverTortuga(int *pos, int percent);
  void MoverLiebre(int *pos, int percent);
  
  srand(time(NULL));
  int LiebrePos = 1, TortugaPos = 1, porcentajeLiebre, porcentajeTortuga;
  int *Liebre = &LiebrePos, *Tortuga = &TortugaPos;

  printf("\n\nARRANCA!\n\n");

  while(LiebrePos <= 70 && TortugaPos  <= 70)
    {
      porcentajeLiebre = 1 + rand() % 10;
      porcentajeTortuga = 1 + rand() % 10;
      MoverTortuga(Tortuga, porcentajeTortuga);
      MoverLiebre(Liebre,porcentajeTortuga);

      printf("\n\n");
       printf("|");
      for(int x = 0; x < 70; x++)
	{
	  if(LiebrePos == x && TortugaPos == x)
	     printf("OUCH!!!");
	  else if(LiebrePos == x) printf("L");
	  else if(TortugaPos == x) printf("T");
	  else printf(" ");
	}
      printf("|");
      usleep(200000);
      system("clear");
    }

  printf("\n\n"); 

  if (LiebrePos >= 70 && TortugaPos  >= 70)
    printf("Empate");
  else if( LiebrePos >= 70 )
    printf("Gano la liebre :v");
  else if( TortugaPos >= 70 )
    printf("Gano la Torguga :v");

  printf("\n\n");
  
  return 0;
} //*** fin main

void MoverTortuga(int *pos, int percent)
{
  if(percent >= 1 && percent <= 5)
    *pos += 3;
  else if(percent >= 6 && percent <= 7)
    {
      if(*pos > 6)
         *pos -= 6;
      else *pos = 1;
    }
  else if(percent >= 8 && percent <= 10)
    *pos++;
}  //*** fin MoverTortuga

void MoverLiebre(int *pos, int percent)
{
  if(percent >= 1 && percent <= 2);
  else if(percent >= 3 && percent <= 4)
    {
      *pos += 9;
    }
  else if(percent == 5)
      if(*pos > 13)
         *pos -= 12;
      else *pos = 1;
  else if(percent >= 6 && percent <= 8)
    *pos++;
  else if(percent >= 9 && percent <= 10)
    *pos -= 2;
} //*** Fin MoverLiebre
