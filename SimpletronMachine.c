/*
 *Simpletron virtual machine
 *Autor: José Rodrigo Pérez Beltrán
 *Compiler: GNU project C and C++ compiler
*/

#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define READ 10
#define WRITE 11
#define NL 12

#define LOAD 20
#define STORE 21

#define ADD 30
#define MIN 31
#define DIV 32
#define MUL 33
#define RES 34
#define EXP 35

#define JUMP 40
#define JUMPNEGATIVE 41
#define JUMPZERO 42
#define STOP 43

#define READSTRING 44
#define WRITESTRING 45

#define TAMANIO 1000
#define TAMANIODOS 11


int length(char *array);
double acumulator [TAMANIO] = {0};

int main()
{

  /* function prototypes */
  void Execute(long array [], int n);
  long Parse(char *array);
  int Check(char array[]);
  
  
  int  i = 0,instruction,ubicacion;
  long constante;
  char  read[20];
  char instruccion[5];
  char *ptrTok;
  long instructions[TAMANIO];
  FILE *ptrCF;
  

   while(1 == 1)
    {
  
  printf("\n\n*** Bienvenido a simpletron!              ***\n"
         "*** Por favor , introduzca el nombre del archivo de su programa ***\n"
	 );

  printf("? ");
      scanf("%s", read);
      
      if((ptrCF = fopen(read,"r")) == NULL)
	{
	  printf("\nArchivo no encontrado\n");
	}
      else
	{
	  fscanf(ptrCF,"%s",instruccion);
	  
	  while(strchr(instruccion,'_') == NULL){

	    ptrTok = strtok(instruccion, " ");
	    constante = atol(ptrTok);
	    
	   fscanf(ptrCF,"%s",instruccion);

	   ptrTok = strtok(instruccion, " ");
	    ubicacion = atoi(ptrTok);

	    acumulator[ubicacion] = constante;
	    
	    fscanf(ptrCF,"%s",instruccion);
	  }
	    
	  while(!feof(ptrCF)){
  
	    fscanf(ptrCF,"%s",instruccion);

	if(length(instruccion) == 4){	

        instruction = Parse(instruccion);
	
	instructions[i++] = instruction;
      
	} else {
	  printf("\nError!, instruccion no valida\n");
	  break;
	}
	
	}

	      printf(
	 "*** Carga del programa completa ***\n"
	 "*** Comienza la ejecucion del programa  ***\n"
	);
    

   Execute( instructions , i);

	  
	}
      
    }
   
  

   fclose(ptrCF);
   
  return 0;
} //**** end main

int Check(char read[])
{
  int a = 0;
      for(int x = 0; x < 4; x++)
	if(read[x] != '9' && read[x] != '-' && read[x] != '\0') a = 1;
  return a;
} //**** end check


int length(char *ptrArray)
{
   int exp = 0;

   for(;*ptrArray != '\0' && *ptrArray != ' '; ptrArray++)exp++;

  return exp;  
}//**** end length


int getValue(char letter)
{
  
  int digit = 0;
  char letras[2][15] = {
    {'1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ','a','b','c','d','e','f'}
  };

  for(int y = 0; y < 2; y++)
    for(int x = 0; x < 15; x++ )
      if(letras[y][x] == letter)
	{
	  digit = x + 1;
	  break;
	}
       
 return digit;
}//**** getValue


long Parse(char *ptrArray)
{
  int value = 0,ele = 0;
  
  for(;*ptrArray != '\0'; *ptrArray++) ele++;
  
  ptrArray--;

  for(int x = 0; x < ele; x++,ptrArray--)
      value += getValue(*ptrArray) * pow(16, x);
    
  return value;
} //**** end value



void Execute(long array[], int n)
{

  char ASCII[51] =
    {
      'A','B','C','D','E','F','G','H','I','J','K','L','M','N'
      ,'O','P','Q','S','T','U','V','W','X','Y','Z','a','b','c','d'
      ,'e','f','g','h','i','j','k','l','m','n','o','p','q','r'
      ,'s','t','u','v','w','x','y','z'
  };

  
  int i = 0, code, pos, error = 0;
  char word[100];


  void Vaciado(float acum, int i, int rInstruccion,int code,int pos, long array[]);
  double convert(char array[], int leng, char array2[]);
  void rebert(double number,char array[],char array2[]);
  
  while(i < n)
    {
      pos = array[ i ] % TAMANIO;
      code = array[ i++ ] / TAMANIO;

      switch(code)
      {
        case READ:
	  printf("?");
	  scanf("%lf",&acumulator[pos]);
        break;
       case WRITE:
          printf("%f\n",acumulator[pos]);
        break;
       case NL:
	 printf("\n");
        break;
       case LOAD:
	 acumulator[TAMANIODOS - 1] =  acumulator[pos];
	 break;
      case STORE:
	acumulator[pos] = acumulator[TAMANIODOS - 1];
	break;
      case ADD:
	if( sizeof(acumulator[TAMANIODOS - 1] + acumulator[pos])
	   > sizeof(double) )
	  printf( "*** Desbordamiento de memoria  ***\n"
                  "*** Lo siento pero el valor resultado es muy grande  ***\n");
	else acumulator[TAMANIODOS - 1] +=  acumulator[pos];
      	break;
      case MIN:
	if( sizeof(acumulator[TAMANIODOS - 1] - acumulator[pos])
	   > sizeof(double) )
	  printf( "*** Desbordamiento de memoria  ***\n"
                  "*** Lo siento pero el valor resultado es muy grande  ***\n");
	else acumulator[TAMANIODOS - 1] -=  acumulator[pos];
	 
	break;
      case MUL:
        if( sizeof(acumulator[TAMANIODOS - 1] * acumulator[pos])
	   > sizeof(double) )
	  printf( "*** Desbordamiento de memoria  ***\n"
                  "*** Lo siento pero el valor resultado es muy grande  ***\n");
	else acumulator[TAMANIODOS - 1] *=  acumulator[pos];
	break;
      case DIV:
	if( sizeof(acumulator[TAMANIODOS - 1] / acumulator[pos])
	   > sizeof(double) )
	 printf( "*** Desbordamiento de memoria  ***\n"
                  "*** Lo siento pero el valor resultado es muy grande  ***\n");
	else if(acumulator[pos] == 0)
	  {
	    printf( "*** Intento de division por cero ***\n");
	    i = n;
	    error = 1;
	  }
	else acumulator[TAMANIODOS - 1] /=  acumulator[pos];
	break;
      case RES:
	if( sizeof((int)acumulator[TAMANIODOS - 1] % (int)acumulator[pos])
	   > sizeof(double) )
	 printf( "*** Desbordamiento de memoria  ***\n"
                  "*** Lo siento pero el valor resultado es muy grande  ***\n");
	else if(acumulator[pos] == 0)
	  {
	    i = n;
	    error = 1;
	    printf( "*** Intento de division por cero  ***\n");
	  }
	else acumulator[TAMANIODOS - 1] = (int) acumulator[pos] % (int) acumulator[TAMANIODOS - 1];
	break;
       case EXP:
	 if( sizeof(pow(acumulator[TAMANIODOS - 1] ,acumulator[pos]))
	   > sizeof(double) )
	 printf( "*** Desbordamiento de memoria  ***\n"
                  "*** Lo siento pero el valor resultado es muy grande  ***\n");
	else acumulator[TAMANIODOS - 1] = pow(acumulator[TAMANIODOS - 1] ,acumulator[pos]);
	break;
      case JUMP:
	i  = pos;
	break;
      case JUMPNEGATIVE:
	if(acumulator[TAMANIODOS - 1] < 0)
	  i  = pos;
	break;
      case  JUMPZERO:
	if(acumulator[TAMANIODOS - 1] == 0)
	  i  = pos;
	break;
      case  STOP:
	 printf( "*** Finaliza la ejecucion de Simpletron  ***\n");
	   Vaciado(acumulator[TAMANIODOS - 1],i,array[i],code,pos,array);
	return;
      case READSTRING:

	scanf("%s",word);
	acumulator[pos] = convert(word, length(word),ASCII);
	printf("%f",	acumulator[pos]);

	break;
      case WRITESTRING:
	
	rebert(acumulator[pos],word,ASCII);
	printf("\n");

	
	for(int x  = length(word) ;x >= 0; x--)
	  printf("%c",word[x]);

	  printf("\n");
		
	break;
      default: 	 error = 1; i = n; printf( "*** Codigo de operacion invalido  ***\n");
      }
      if(error == 1) {
	Vaciado(acumulator[TAMANIODOS - 1],i,array[i],code,pos,array);
	break;
      }
   }
  
} //**** end Execute

double convert(char array[], int len,char Array[])
{  
  
  double number, i = 10,x = 0;

  number  = len * 100;
  

  for(;*array != '\0' &&  *array != ' ';array++)
    for(int x =0 ; x < length(Array); x++)
      if(*array == Array[x])
	{ 
	  number += (x + 10);
	  number *= 100;
     	  break;
	}    
  
     
  return number;
} //**** end convert

void rebert(double number,char array[],char array2[])
{
  number /= 100;

  int x  =0;
  
  while( (number / 100) - 1 > 0)
    {
      array[x++] = array2[ ((long)number - 10) % 100];
      number /= 100;        
   }
}  //**** end rebert

void Vaciado(float acum, int i, int rInstruccion,int code,int pos, long array[])
{

  FILE *ptrCF2;
  
  printf("\nRegistros" 
	 "\nAcumulador: %-5f"
	 "\nContador instrucciones: %-5d"
	 "\nRegistro instrucciones: %-5d"
	 "\ncodigo Operacion: %-5d"
	 "\nOperando: %-5d\nMemoria: \n",acum,i,rInstruccion,code,pos);
  
  for(int x = 0; x <TAMANIO ; x++)
    if(x %10 == 0)printf("0");
    else printf("   %-5d   ",array[x]);

  if((ptrCF2 = fopen("vaciado.txt","w+")) == NULL)
	{
	  printf("\nArchivo no se pudo crear\n");
	}
  else
    {

      fprintf(ptrCF2,"\nRegistros" 
	 "\nAcumulador: %-5f"
	 "\nContador instrucciones: %-5d"
	 "\nRegistro instrucciones: %-5d"
	 "\ncodigo Operacion: %-5d"
	 "\nOperando: %-5d\nMemoria: \n",acum,i,rInstruccion,code,pos);
      for(int x = 0; x <TAMANIO ; x++)
	if(x %10 == 0) fprintf(ptrCF2,"0");
	else fprintf(ptrCF2,"   %-5d   ",array[x]);

         fclose(ptrCF2);
    }
} //**** end Vaciado
