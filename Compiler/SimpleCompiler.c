/*
 *Simple Compiler
 *Autor: José Rodrigo Pérez Beltrán
 *Compiler: GNU project C and C++ compiler
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAMANIO 7

#define TAMANIODOS 1000

struct entradaTabla
{
   int simbolo;
   char tipo;
   int ubicacion;
};


struct entradaTabla Tabla[1000];


struct nodoPila{
   char *dato ; 
   struct nodoPila *siguiente;
 };

typedef struct nodoPila nodo;
typedef nodo *ptrNodo;


int  getValue(char a);
int buscar(int lin);
int IsOpp( char  curr);
void push(ptrNodo  *cima,char *info);
const char * peek(ptrNodo *cima);
const char * sacar(ptrNodo *cima);
int estaVacia(ptrNodo *cima);
int TablaIndex = 0;

int main()
{
  
  void Generar(char array[],int array2[], int array3[], int *ptr);
  void Simbolos(char array[], int *ptrSimboloPos,int InstruccionIndex);
  void Complementar(int array[],int array2[]);
  
  char read[30] = {"Programa2.txt"};
  char write[30] = {"CodigoLMS.txt"};
  char instruccion[100] = " \0";
  char lector[50];
    FILE *ptrCF;

  int simboloPos = 998, InstruccionIndex = 0;

  int *ptrIndex1 = &simboloPos;
  int *ptrIndex3 = &InstruccionIndex;
  int instrucciones[1000], banderas[1000];

  for(int x = 0; x < 100; x++)banderas[x] = -1;
  /*  printf("\n\n*** Compilador Simple              ***\n"
         "*** Por favor , introduzca el nombre del archivo de su programa simple ***\n"
	 );

  printf("? ");
  scanf("%s",read);
 
  */

  if((ptrCF = fopen(read,"r")) == NULL)
	{
	  printf("\nArchivo no encontrado\n");
	}
      else
	{
	  fgets(lector, 100, ptrCF);
	  while(!feof(ptrCF)){


	    strcpy(instruccion,lector);
	    Simbolos(instruccion,ptrIndex1,InstruccionIndex);
	    strcpy(instruccion,lector);
	    
	    Generar(instruccion,banderas,instrucciones,ptrIndex3);

	    fgets(lector, 100, ptrCF);
	  }

	   fclose(ptrCF);
	}

  Complementar(instrucciones,banderas);

  
  if((ptrCF = fopen(write,"w")) == NULL)
	{
	  printf("\nArchivo no encontrado\n");
	}
      else
	{
	  for(int x = 0; x < TablaIndex ; x++ )
	    if(Tabla[x].tipo == 'C')
	      fprintf(ptrCF,"%d %d\n",Tabla[x].simbolo,Tabla[x].ubicacion);

	  fprintf(ptrCF,"_\n");
	  
	  for(int x = 0; x < InstruccionIndex; x++ )
	    fprintf(ptrCF,"%x\n",instrucciones[x]);
	}
  
  return 0;
} //*** end main


void Complementar(int instrucciones[],int banderas[])
{
  int numeroLinea;
  int ubicacion;
  for(int x = 0; x < 100; x++)
    if(banderas[x] != -1)
      {
	numeroLinea = banderas[x];
	ubicacion = buscar(numeroLinea);
	instrucciones[x] += ubicacion;
      }
} //*** end Complementar


int operar(int op2,char ptr)
{
  int res = 0;
  switch(ptr)
    {
    case '+':res = (30 * 1000) + op2; break;
    case '-':res = (31 * 1000) + op2; break;
    case '*':res = (33 * 1000) + op2; break;
    case '/':res = (32 * 1000) + op2; break;
    case 'e':res = (35 * 1000) + op2; break;
    case '%':res = (34 * 1000) + op2; break;
    }
  return res;
} //*** end operar


void Evaluar(int array2[],char array[], int *indexI, int varpos)
{

  char *ptr = strtok(array," ");

  int ubicacion;
  
  if(isdigit(*ptr) || isdigit(*(ptr+1)))
    ubicacion = buscar(atoi(ptr));
  else ubicacion = buscar(getValue(*ptr));

  array2[*indexI] = (20 * TAMANIODOS) + ubicacion;
  (*indexI)++;
  
  char *op2;
  char arr[10];
  int operar(int op2,char ope);
  ptrNodo pila;
   
   while(ptr != NULL){
    if(isdigit(*ptr) || isalpha(*ptr))
      push(&pila,ptr);
    else if(IsOpp(*ptr) == 1)
      {
	op2 =  sacar(&pila);

	if(isdigit(*op2) || isdigit(*(op2+1)))
	  array2[*indexI] = operar(buscar(atoi(op2)), *ptr);
	else
	  array2[*indexI] = operar(buscar(getValue(*op2)), *ptr);
	
	(*indexI)++;
      }
    ptr = strtok(NULL," ");
   }
  
} //*** end evaluar

int getValue(char let)
{

  int resp = 1;
  char ASCII[51] =
    {
      'A','B','C','D','E','F','G','H','I','J','K','L','M','N'
      ,'O','P','Q','S','T','U','V','W','X','Y','Z','a','b','c','d'
      ,'e','f','g','h','i','j','k','l','m','n','o','p','q','r'
      ,'s','t','u','v','w','x','y','z'
  };

  for(int x = 0; x < 51; x++)
    if(let == ASCII[x]){resp = x - 51; break;}
  return resp;
  
} //*** end getvalue

void let(char var,char *expresion,int instrucciones[], int *indexI)
{

  void Evaluar(int array2[],char array[], int *indexI, int varpos);
  void convertirP(char array[], char array2[]);

  char * normal , posfijo[50];
  int varpos = buscar(getValue(var));

 
  normal  = strcpy(malloc(strlen(expresion) * sizeof(char)),expresion);
  while(*normal != '=')normal++;
  normal++;
  convertirP(normal,posfijo);
  Evaluar(instrucciones, posfijo,indexI,varpos);
  instrucciones[*indexI] = (21 * TAMANIODOS) + varpos;
  (*indexI)++;
} //*** end let

void convertirP(char array[],char array2[])
{
  char *ptrTok;
  char cur[10];
   char cur2[10];
  char current;
  ptrNodo pila = NULL;

  int Mayor(char curr,const char * stack);
  void add(char array[],char c);
  
  strcat(array," )");
  ptrTok = strtok(array," ");
   sprintf(cur,"%c",'(');
    push(&pila, cur);
    
    while(!estaVacia(&pila) && ptrTok != NULL)
    {
      
      current = *ptrTok;
      if(isdigit(current) || isalpha(current))
	{
	 
	  sprintf(cur2," %c",current);
	  strcat(array2, cur2);
	}
      if(current == '(')
	{
	  sprintf(cur,"%c",current);
	  push(&pila,cur);
	}
      else if(IsOpp(current) == 1)
	  {

	    while(IsOpp(*(peek(&pila))) == 1 && Mayor(current,peek(&pila)) >= 0 )
	    {

	      sprintf(cur," %c",*(sacar(&pila)));
	      strcat(array2, cur);      
		  }
	  
	  sprintf(cur,"%c",current);
	  push(&pila,cur);
	  }
      
	 else if(current == ')')
	{
	  while( *(peek (&pila)) != '(')
	    {
	      	  sprintf(cur," %s",sacar(&pila));
		  
		  strcat(array2, cur);

		  }
	  sacar(&pila);

	  }

    	ptrTok = strtok(NULL, " ");
	}
} //*** end convertirP



void ifgotoI(int instrucciones[],int simbolo,int simbolo2,char *operador,int simbolo3, int *indexI, int banderas[])
{
  char * operadores[6] =
    {
      ">",
      "<",
      ">=",
      "<=",
      "==",
      "!="
    };
  int ubicacion = buscar(simbolo);
  int ubicacion2 = buscar(simbolo2);
  int ubicacion3 = buscar(simbolo3);

  if(ubicacion != -1 && ubicacion2 != -1 )
  {
    for(int x = 0; x < 6; x++)
      {
	if(!strcmp(operador,operadores[x]))
	switch(x)
	{

	case 0:
        case 5:
	  instrucciones[*indexI] = (20 * TAMANIODOS) + ubicacion2;
	    (*indexI)++;
	  instrucciones[*indexI] = (31 * TAMANIODOS) + ubicacion;
           (*indexI)++;

	 if( ubicacion3 != -1)
	      instrucciones[*indexI] = (41 * TAMANIODOS)+ ubicacion3;
	 else
	   {
	     instrucciones[*indexI] = (41 * TAMANIODOS);
	     banderas[*indexI] = simbolo3;
	   }
	  (*indexI)++;
	  break;
	  
	case 1:
	  instrucciones[*indexI] = (20 * TAMANIODOS) + ubicacion;
	    (*indexI)++;
	  instrucciones[*indexI] = (31 * TAMANIODOS) + ubicacion2;
           (*indexI)++;

	 if( ubicacion3 != -1)
	      instrucciones[*indexI] = (41 * TAMANIODOS)+ ubicacion3;
	 else
	   {
	     instrucciones[*indexI] = (41 * TAMANIODOS);
	     banderas[*indexI] = simbolo3;
	   }
	  (*indexI)++;
	  break;
	case 2:
	  instrucciones[*indexI] = (20 * TAMANIODOS) + ubicacion2;
	    (*indexI)++;
	  instrucciones[*indexI] = (31 * TAMANIODOS) + ubicacion;
           (*indexI)++;

	 if( ubicacion3 != -1)
	   {
	     instrucciones[*indexI] = (42 * TAMANIODOS)+ ubicacion3;
	      (*indexI)++;
	      instrucciones[*indexI] = (41 * TAMANIODOS)+ ubicacion3;
	      (*indexI)++;
	   }else
	   {
	     instrucciones[*indexI] = (42 * TAMANIODOS);
	      banderas[*indexI] = simbolo3;
	     (*indexI)++;
	     instrucciones[*indexI] = (41 * TAMANIODOS);
	     banderas[*indexI] = simbolo3;
	     (*indexI)++;
	   }
	  break;
	case 3:
	   instrucciones[*indexI] = (20 * TAMANIODOS) + ubicacion;
	    (*indexI)++;
	  instrucciones[*indexI] = (31 * TAMANIODOS) + ubicacion2;
           (*indexI)++;

	 if( ubicacion3 != -1)
	   {
	     instrucciones[*indexI] = (42 * TAMANIODOS)+ ubicacion3;
	     (*indexI)++;
	     instrucciones[*indexI] = (41 * TAMANIODOS)+ ubicacion3;
	     (*indexI)++;
	   }else
	   {
	     instrucciones[*indexI] = (42 * TAMANIODOS);
	     banderas[*indexI] = simbolo3;
	     (*indexI)++;
	     instrucciones[*indexI] = (41 * TAMANIODOS);
	     banderas[*indexI] = simbolo3;
	     (*indexI)++;
	   }
	  break;
	case 4:
	  instrucciones[*indexI] = (20 * TAMANIODOS) + ubicacion2;
	    (*indexI)++;
	  instrucciones[*indexI] = (31 * TAMANIODOS) + ubicacion;
           (*indexI)++;

	 if( ubicacion3 != -1)
	      instrucciones[*indexI] = (42 * TAMANIODOS)+ ubicacion3;
	 else
	   {
	     instrucciones[*indexI] = (42 * TAMANIODOS);
	     banderas[*indexI] = simbolo3;
	   }
	     (*indexI)++;
	  break;
	}
      }
  }
} //*** end ifgotoI



void gotoI(int instrucciones[],int simbolo, int *indexI, int banderas[])
{
  int ubicacion = buscar(simbolo);
  if(ubicacion != -1)
  {
    instrucciones[*indexI] = (40 * TAMANIODOS)+ ubicacion;
  }
  else
    {
      instrucciones[*indexI] = (40 * TAMANIODOS);
      banderas[*indexI] = simbolo;
    }
  (*indexI)++;
} //*** gotoI

void print(int instrucciones[],char simbolo, int *indexI)
{
  int ubicacion = buscar(getValue(simbolo));
  if(ubicacion != -1)
  {
    instrucciones[*indexI] = (11 * TAMANIODOS)+ ubicacion;
    (*indexI)++;
  }
} //*** print

void Input(int instrucciones[],char simbolo, int *indexI)
{
  
  int ubicacion = buscar(getValue(simbolo));
  
  if(ubicacion != -1)
  {
    instrucciones[*indexI] = (10 * TAMANIODOS)+ ubicacion;
    (*indexI)++;
  }
} //*** Input

 void Generar(char array[],int array2[], int array3[],int *ptr)
{

  char * tokarray = strcpy(malloc( strlen(array) * sizeof(char ) ), array);
  
  void Input(int instrucciones[],char simbolo, int *indexI);
  void let(char var,char *expresion,int instrucciones[], int *indexI);
  void print(int instrucciones[],char simbolo, int *indexI);
  void gotoI(int instrucciones[],int simbolo, int *indexI, int banderas[]);
  void ifgotoI(int instrucciones[],int simbolo,int simbolo2,char *operador,int simbolo3, int *indexI, int banderas[]);
  
  char *commands[TAMANIO] =
  { 
    "rem",
    "let",
    "input",
    "print",
    "goto",
    "if",
    "end\n"

  };
  
  char *ptrTok;
  char *op,*op2,*op3,*ope;
  int opv1, opv2, opv3;

  
  ptrTok = strtok(tokarray," ");

  ptrTok = strtok(NULL," ");
  
  
  for(int x = 0; x < TAMANIO; x++)
    { 
      if(strcmp(commands[x],ptrTok) == 0){
	ptrTok = strtok(NULL," ");

	switch(x)
	{
	case 0:
	  return;
	case 1:
	  let(*ptrTok,array,array3, ptr);
	  return;
	case 2:
	  Input(array3,*ptrTok,ptr);
	  return;
	case 3:
	  print(array3,*ptrTok,ptr);
	  return;
	case 4:
	  gotoI(array3,atoi(ptrTok),ptr,array2);
	  return;
	case 5:
	  
          op = strcpy(malloc(strlen(ptrTok) * sizeof(char)),ptrTok);
	  ptrTok = strtok(NULL," ");
	  ope = strcpy(malloc(strlen(ptrTok) * sizeof(char)),ptrTok);
           ptrTok = strtok(NULL," ");
	  op2 = strcpy(malloc(strlen(ptrTok) * sizeof(char)),ptrTok);
          ptrTok = strtok(NULL," ");
	  ptrTok = strtok(NULL," ");
	  op3 = strcpy(malloc(strlen(ptrTok) * sizeof(char)),ptrTok);

	  if(isdigit(*op) || isdigit(*(op+1)))
	    opv1 = atoi(op);
	  else opv1 = getValue(*op);
	  if(isdigit(*op2) || isdigit(*(op2+1)))
	    opv2 = atoi(op2);
	  else opv2 = getValue(*op2);
	  if(isdigit(*op3) || isdigit(*(op3+1)))
	    opv3 = atoi(op3);
	  else opv3 = getValue(*op3);
	  
	  
	  ifgotoI(array3,opv1,opv2,ope,opv3,ptr,array2);

	   return;
	case 6:
	 
	  array3[*ptr] = 43000;
	  (*ptr)++;
	  return;
	  }
      }
    }
} //*** end generar

int buscar(int lin)
{
  int resp = -1;
  
   for(int x = 0; x < TablaIndex; x++)
    if( Tabla[x].simbolo == lin)
      resp = Tabla[x].ubicacion;
   
   return resp;
} //*** end buscar

int guardar(int lin,char tip, int ubi)
{

   if(buscar(lin) != -1) return 0;


  Tabla[TablaIndex].simbolo = lin; 
  Tabla[ TablaIndex].tipo = tip;
  Tabla[ TablaIndex].ubicacion = ubi; 
  TablaIndex++;
  return 1;
} //*** end guardar

void Simbolos(char array[], int *ptrSimboloPos, int InstruccionIndex)
{
  char *ptrTok;
  int linea, value;
  char tipo;
  int error;

  int guardar(int lin,char tip, int ubi);

  ptrTok = strtok(array," ");


  linea = atoi(ptrTok);
  
  tipo = 'L';

  //simbolo, tipo, ubicacion, indextabla
   guardar(linea, tipo ,InstruccionIndex);

   ptrTok = strtok(NULL," ");
    
   if(!strcmp(ptrTok ,"rem")) return;
  
    ptrTok = strtok(NULL," ");
    
  
  while(ptrTok != NULL)
  {
    if(!strcmp(ptrTok ,"goto"))return;
   if(isalpha(*ptrTok))
     {
       value = getValue(*ptrTok);
       tipo = 'V';
     }
   else if(isdigit(*ptrTok) || isdigit(*(ptrTok + 1)))
      {
	value = atoi(ptrTok);
	tipo = 'C';
      }
   
    if( guardar(value,tipo,*ptrSimboloPos) == 1)
     {
       (*ptrSimboloPos)--;
     }
  

    ptrTok = strtok(NULL," ");
      
    }
  
}  //*** end simbolos

int IsOpp( char curr)
{
   char array[6] =
    {
      '+','-','*','/','e','%'
    };


  for(int x = 0; x < 6; x++)
    
    if(curr == array[x])return 1;

  return 0;
    
} //*** end IsOpp

int Mayor(char curr, const char * stack)
{
   char array[2][6] =
    {
      {'+','-','*','/','e','%'},
      {'1','1','2','2','3','3'}
    };

  int val1 = 0, val2 = 0;

  for(int x = 0; x < 6; x++)
    {
      if(curr == array[0][x]) val1 = array[1][x] + '0';
      if(*stack == array[0][x])val2 = array[1][x] + '0';
    }

   if(val1 == val2) return 0;
  else if(val1 > val2) return 1;
  else return -1;
} //*** end Mayor
 

void push(ptrNodo * cima,char *info)
{
  ptrNodo Nuevo;
   Nuevo = malloc(sizeof(nodo));
 
  if(Nuevo != NULL){
    Nuevo->dato = strcpy(malloc( strlen(info) * sizeof(char)),info);
  Nuevo->siguiente = *cima;
  *cima = Nuevo;
 
  }
  else printf("\n\nNo se pudo ingresar nuevo elemento\n\n");
}  //*** end push

const char * sacar(ptrNodo *cima)
{
  char * lastval;
  ptrNodo temp;
  temp = malloc(sizeof(nodo));
  temp = *cima;
  lastval = strcpy(malloc(strlen(temp->dato)* sizeof(char)), temp->dato); 
  *cima = (*cima)->siguiente;
   free(temp);
   return lastval;
}  //*** end sacar

const char * peek(ptrNodo *cima)
{
  char *l;
  l = strcpy(malloc(strlen((*cima)->dato)* sizeof(char) ),(*cima)->dato);
  return l;
} //*** end peek
 
int estaVacia(ptrNodo *cima)
{
  return *cima == NULL;
} //***end estaVacia
