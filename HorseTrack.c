/*
 *Horse Track
 *Autor: Jose Rodrigo Perez Beltran
 *compiler: GNU project C and C++ compiler
*/
#include <stdio.h>

  static int horizontal[8] = {2,1,-1,-2,-2,-1,1,2};
  static int vertical[8] = {-1,-2,-2,-1,1,2,2,1};

  //****** function prototypes
  int Checker(const int array[][8],int p[]);

int main()
{

  //****** Function prototypes
  int moveHorse(int startX, int startY);

  printf("\n");

  //****** Move horse from all posible positions
  for(int y = 0; y < 7; y++)
    for(int x = 0; x < 7; x++)
      if( moveHorse(x,y) == 1 )
	printf("\nIt works for cords: [ %d,%d ]",x,y);

  printf("\n\n");
  return 0;
} //****** end main

void findBestDraft(int point[],int point2[], const int board[][8])
{
  
 /*
  point2 -> horse
 */


  int point3[2];
    //****** finds the best position
   for(int c = 0; c < 8; c++)
   {
	  
      point[0] = point2[0] + horizontal[c];
      point[1] = point2[1] + vertical[c];

   if( Checker(board,point) == 1)
   {

   for(int b = (c + 1) ; b < 8;b++)
   {
       point3[0] = point2[0] + horizontal[b];
       point3[1] = point2[1] + vertical[b];

    if( Checker(board,point3) == 1 )
       if(board[ point[1] ][ point[0] ] > board[ point3[1] ][ point3[0] ] )
	 {
            point[0] = point3[0];
            point[1] = point3[1];
         }
       
   }
      return;
   }

   }//****** end external for

   //****** signal value
   point[0] = -1;

}  //****** FindBestDraft


void findBest(int point[],int point2[], const int board[][8])
{

 /*
  point2 -> horse
 */


  int point3[2];
  int point4[2];
  int point5[2];
  //****** finds the best position
   for(int c = 0; c < 8; c++)
   {
	  
      point[0] = point2[0] + horizontal[c];
      point[1] = point2[1] + vertical[c];

   if( Checker(board,point) == 1)
   {

   for(int b = (c + 1) ; b < 8;b++)
   {
       point3[0] = point2[0] + horizontal[b];
       point3[1] = point2[1] + vertical[b];

    if( Checker(board,point3) == 1 )
       if(board[ point[1] ][ point[0] ] > board[ point3[1] ][ point3[0] ] )
	 {
            point[0] = point3[0];
            point[1] = point3[1];
         }
       else if(board[ point[1] ][ point[0] ] == board[ point3[1] ][ point3[0] ])
	 {
	   findBestDraft(point4,point,board);
	   findBestDraft(point5,point3,board);
	   if( (point5[0] != -1 && point4[0] != -1) &&   board[ point4[1] ][ point4[0] ] > board[ point5[1] ][ point5[0] ]  )
	     {
	   
	       point[0] = point3[0];
	       point[1] = point3[1];
	     
	     }

	 }
       
   }
      return;
   }

   }//****** end external for

   //****** signal value
   point[0] = -1;
} //****** end findBest


int moveHorse(int startX, int startY)
{
  
  //****** function prototypes
  void print(int array[][8]);
  void findBest(int point[],int point2[],const int board[][8] );
    
  //****** Chess board
  int board[8][8] = {
    {2,3,4,4,4,4,3,2},
    {3,4,6,6,6,6,4,3},
    {4,6,8,8,8,8,6,4},
    {4,6,8,8,8,8,6,4},
    {4,6,8,8,8,8,6,4},
    {4,6,8,8,8,8,6,4},
    {3,4,6,6,6,6,4,3},
    {2,3,4,4,4,4,3,2},
  };
  int answer[8][8];
   
  //****** mark the start point
  board[startY][startX] = 1;
  answer[startY][startX] = 1;
  //****** arrays
  int horse[2] = {startX,startY};
  int point[2];

  //****** Variables
  int i ;
  int movements = i = 1;

  while(1 == 1)
    {

      movements++;
      findBest(point, horse,board);

      if(point[0] != -1)
	{
         horse[0] = point[0];
         horse[1] = point[1];
         i++;
         board[ point[1] ][ point[0] ] = 1;
	 answer[ point[1] ][ point[0] ] = i;
         }

      
           
      if(i == 64)
	{
	  for(int x = 0; x < 8; x++)
	    if(answer[horse[1] + vertical[x] ][horse[0] + horizontal[x]] == 1)
	      printf("\n\nIt is close");
	  print(answer);
	  scanf("%d",&movements);
	  return 1;
	  
      }
      if(movements == 64)
       return 0;
     
    }

}   //****** end moveHorse

void print(int array[][8])
{
  printf("\n\n");
  for(int y = 0; y < 8; y++)
    {for(int x = 0; x < 8; x++)

	{
	  printf("%3d",array[y][x]);
	  
	}
      printf("\n");
    }
}   //****** end print

int Checker(const int array[][8], int point[])
{
  if(point[0] < 0 || point[0] > 7 || point[1] < 0 || point[1] > 7 || array[ point[1] ][ point[0] ] == 1)
    return 0;
  else return 1;
}   //****** end Checker
