/*
TicTacToe Videogame and Line factor heuristic
Autor: Jose Rodrigo Perez Beltran AKA FrikiPointer
Compile with the flag -std=c11
This game is for a  linux terminal, but can be modified for other console environment 
*/
#include <stdio.h>

//Functions used throughout the program
void gotoxy(int number1, int number2);
void Message(int number);
void PrintBoard();

int main() {
  //Functions used just by main function
  int Verify(long number);
  int Move(int number,int array[],char option);
  void putCursor(int number);
  char Promt();
  //Constants
  enum Estat{CONTINUE,END};
  enum Estat GameStat;
  //Variables
  int  turn, position, Num_mark , winner;
  long victory1 , victory2; //users status
  char option;
  
  do{
    //initializations
    GameStat = CONTINUE;
    int Board[] = {3,5,7,11,13,17,19,23,29};
    victory2 = victory1 = Num_mark = position = turn = 1;
    winner = 0;
    Message(11); PrintBoard(); Message(2);
    putCursor(position);
    
  while(GameStat == CONTINUE && Num_mark <= 9){
    //read the user request
    option = Promt();

    //do its request
    switch(option){
    case 'f': case 'F': case 'b': case 'B':
      //move cursor
      putCursor(position); printf("\b ");
      position = Move(position,Board,option); putCursor(position);
      Message(9);
    break;
    case 'c': case 'C':
      //mark
      putCursor(position);
      if(turn == 1){
        printf("\bX"); victory1 *= Board[position - 1];
	if(Num_mark > 4){ winner = Verify(victory1); }
	if(winner == 0){ --turn; Message(3); } else GameStat = END;	
      }
      else {
	printf("\bO"); victory2 *= Board[position - 1];
	if(Num_mark > 4){ winner = Verify(victory2);}
	if(winner == 0){ ++turn; Message(2);} else GameStat = END;
      }
      Num_mark++; Board[position - 1] = 0; Message(9);
      if(Num_mark < 10){ position = Move(position,Board,'f'); putCursor(position); }
   break;
   case 'r': case 'R':
     //surrender
     turn == 0 ? ++turn: --turn;  GameStat = END;
   break;
   default: Message(4); break;
   }
  }
  //clean the screen
  Message(12); Message(13);
  //shown the winner
  if(GameStat == CONTINUE)Message(7);
  else{ turn == 0 ? Message(6): Message(5);}
  int check = 0;
  //ask if user wants to play again
  do{
    Message(8); option = Promt();
    switch(option) { case 'y': case 'Y': case 'n': case 'N': check = 1; break;
    default: Message(4); break;
    }
  }while(check  == 0);

  }while(option == 'y' || option == 'Y');
  //clean the screen
    Message(11);
  return 0;
}

//This function moves the cursor when someone uses the interface
void putCursor(int numero) {
  switch(numero){
    case 1: gotoxy(76,21); break; case 2: gotoxy(84,21); break; case 3: gotoxy(92,21); break;
    case 4: gotoxy(76,25); break; case 5: gotoxy(84,25); break; case 6: gotoxy(92,25); break;
    case 7: gotoxy(76,29); break; case 8: gotoxy(84,29); break; case 9: gotoxy(92,29);  break;
    }
   printf("ǈ");
}

//This function searches for an useful place
int Move(int number,int array[],char option) {
  switch(option){
    case 'f': case 'F':
      do{ number == 9 ? number = 1: number++; }while(array[number - 1] == 0);
    break;
    case 'b': case 'B':
      do{ number == 1 ? number = 9: number--; }while(array[number - 1] == 0);
    break;
    }
  return number;
}

//gotoxy C version 
void gotoxy( int x, int y) { printf("%c[%d;%df",0x1B,y,x); }

//This function displays information to  users
void Message(int number) {
  switch(number) {
  case 1: gotoxy(70,15); printf("f.move forward  b.move back  c.mark r.surrender"); break;
  case 2: gotoxy(73,41); printf("Player X turn"); break;
  case 3: gotoxy(73,41); printf("Player O turn"); break;
  case 4: gotoxy(73,42); printf("Nonexistent option :("); break;
  case 5: gotoxy(70,18); printf("Player who has X wins :)"); break;
  case 6: gotoxy(70,18); printf("Player who has O wins :)"); break;
  case 7: gotoxy(70,18); printf("come on dudes, its a draft >:v"); break;
  case 8: gotoxy(70,19); printf("Does you want play again? (y. yes  n.no) "); break;
  case 9: gotoxy(73,42); printf("                     "); break;
  case 10: gotoxy(73,43); printf("                                                               "); break;
  case 11: gotoxy(1,1); for(register int x = 0; x < 500; x++)printf("\n"); break;
  case 12: gotoxy(70,15); printf("                                                                "); break;  
  case 13: gotoxy(73,41); printf("                     "); break;
  }
}

//Shows the board 
void PrintBoard() {
  //Displays the options
  Message(1); register int Y = 21;
  for(register int y = 1; y <= 10; y++) {
      gotoxy(72,Y);
      for(register int x  = 0; x <= 22; x++) {
	  if(x < 6 || (y % 4 != 0) && (x % 9 != 0)) printf(" ");
	  else printf("*");	  
	}
      printf("\n"); Y++;
    }
}

//this function gets the user's request
char Promt(){
   register char read;
  /*Avoid the ICANON flag to process input*/
    gotoxy(73,43); printf("give an option and press enter> ");
    /* system("/bin/stty raw");*/ read = getchar(); /*system("/bin/stty cooked");*/
    Message(10); return read;
}

//this function uses the  line factor heuristic to find a winner
int Verify(long number) {
  if(number % 12673 == 0 ) return 1; if(number % 3451 == 0 ) return 1;
  if(number % 2431 == 0 ) return 1; if(number % 1729 == 0 ) return 1;
  if(number % 1495 == 0 ) return 1; if(number % 1131 == 0 ) return 1;
  if(number % 627 == 0 ) return 1; if(number % 105 == 0 ) return 1;
  return 0;
}
