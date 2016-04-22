/*
 *Life
 *Autor: José Rodrigo Pérez Beltrán
 *Compiler: GNU project C and C++ compiler
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

 //******* Function prototypes
 void Gotoxy(int x, int y);
 int neighbors(int x,int y, int board[][500],int l);
 //******** Variables
 char answer;
 char option;
 int area;
 int length;
 int board[500][500] = {0};
 //******** Program controll
 do{
   
 //******** Prepare the simulation
   printf("\n\nGive me the grid length(-1.Exit)> ");
   scanf("%d", &length);
   if(length > 0){
   area = length * length;
  
   //Screen cleaner for linux

   system("clear");
   
   
   for(int  y = 1, x1 = 1, x = 1; x <= area ; x++, x1++)
     {
       Gotoxy(x1,y);
       printf("Ǒ");
       if(x % length == 0) {y++; x1 = 0;}
     }
   
   printf("\nPut the seed ( f.move forward r.return b.resuscitate g.kill s.start the simulation   c.Cancel )\n");
 
   int x = 1, y = 1;
   do{
     
     Gotoxy(99,99);
     system("/bin/stty raw");
     option = getchar();
    system("/bin/stty cooked");
     Gotoxy(99,99);
     printf("               ");
     switch(option)
       {
       case 'f':
       case 'F':
         Gotoxy(x,y);
         if(board[ y][x] == 0) printf("Ǒ");
	 if(x == length && y == length ){x = 1; y = 1;}
	 else if(x == length ){x = 1; y++;}
	 else x++;
	 Gotoxy(x,y);
	 if(board[y][x] == 0)printf("X");
	 break;
       case 'r':
       case 'R':
	 Gotoxy(x,y);
	 if(board[y][x] == 0)printf("Ǒ");
	 if(y == 1 && x == 1){x = length; y = length;}
	 else if(x == 1){y--; x = length;}
	 else x--;
	 Gotoxy(x,y);
	 if(board[y][x] == 0)printf("X");
	 break;
       case 'b': 
       case 'B':
	 board[ y][x] = 1;
	 Gotoxy(x,y);  
	 printf("O");
	 break;
       case 'g':
       case 'G':
	 board[ y][ x] = 0;
	 Gotoxy(x,y);
	 printf("Ǒ");
	 break;
       }

   }while(option != 's' && option != 'S' && option != 'c' && option != 'C');

   
   //******* Run the simulation
   if(option == 's' || option == 'S'){
     
     int currentNeighbors;
     while(1 == 1){
       system("clear");
       for (int y = 1; y <= length; y++)
	 for(int x = 1; x <= length; x++){
	   currentNeighbors = neighbors(x,y,board,length);
	  if(currentNeighbors < 2 || currentNeighbors > 3){printf("Ǒ");board[y][x] = 0;}
	  else if(currentNeighbors == 3){printf("O");board[y][x] = 1;}
	  else if(currentNeighbors < 2 && board[y][x] == 1)printf("O");
	  
	  if(x % length == 0 )printf("\n");
	}
	wait(2);
     }
   }
   if(option != 'C' && option != 'c'){
     printf("\nDo you want to run another simulation?");
     scanf("%c", &answer);
   }
   
   }
 }while(length > 0);
  
    return 0;
} //*** end main


void wait(int sec)
{
  int res = time(0) + sec;
  while(time(0) < res);
} //*** end wait

int neighbors(int x,int y, int board[][500],int length)
{

  int cellsNum = 0;

     if(y > 1 &&  x > 1 && board[y - 1][ x - 1] > 0) cellsNum++;
   if(y > 1 && board[y - 1][x] > 0) cellsNum++;
   if( y > 1 && x < length && board[y - 1][x + 1] > 0) cellsNum++;
   
   if(x > 1 && board[y][x - 1] > 0) cellsNum++;
   if(x < length && board[y][x + 1] > 0) cellsNum++;
   
   if(y < length && x > 1 && board[y +1][x - 1] > 0) cellsNum++;
   if(y < length && board[y + 1][x] > 0) cellsNum++;
   if(y < length && x < length && board[y + 1][x + 1] > 0) cellsNum++;

  return cellsNum;
} //*** end neighbors



void Gotoxy(int x, int y) { printf("%c[%d;%df",0x1B,y,x); }
