//Esta aplicacion genera el calendario del año que reciba
//Autor: José Rodrigo Pérez Beltrán
#include <stdio.h>

int main()
{													//Inicio funcion main
	
	int Anio, diaFecha, 
	    dia, diaPos, mes, 
	    limite, biciesto = 0, 
	    a, b, c;

	printf("\n\n\tIngrese un año de entre 1900 y 2099> ");
	scanf("%d", &Anio);

	if(Anio >= 1900 && Anio <= 2099)
	{												//Inicio if 1
	   a = (Anio % 4 == 0), b = (Anio % 100 == 0), c = (Anio % 400 == 0);
	   dia = diaPos = mes = 1;
	   limite = 2;
	   diaFecha = 1 + (Anio % 100) + ( (Anio % 100) / 4 );
	
	if(Anio >= 2000) diaFecha += 6;
	
	diaFecha %= 7;
/*************************************************************Calendario******************************************************/

	if(diaFecha == 0) diaFecha = 7;

	if( (a &&  b &&  c ) || (a &&  !b) )
	{												//Inicio if 2

	biciesto = 1;

	if(diaFecha == 1)diaFecha = 7;
	else diaFecha--;

	}												//Fin if 2
 	
	for( ;dia <= limite; )
	{												//Inicio for

	if(diaPos == 1){										//Inicio if 3

	switch(mes)
	{												//Inicio switch
	case 1:
	   printf("\n\tEnero\n");
	   limite = 31;
	break;
	case 2:
	   printf("\n\tFebrero\n");

	 if(biciesto) limite = 29;
	 else limite = 28;
	break;
	case 3:
	   printf("\n\tMarzo\n");
	   limite = 31;
	break;
	case 4:
	   printf("\n\tAbril\n");
	   limite = 30;
	break;
	case 5:
	   printf("\n\tMayo\n");
	   limite = 31;
	break;
	case 6: 
	   printf("\n\tJunio\n");
	   limite = 30;
	break;
	case 7:
	   printf("\n\tJulio\n");
	   limite = 31;
	break;
	case 8:
	   printf("\n\tAgosto\n");
	   limite = 31;
	break;
	case 9:
	   printf("\n\tSeptiembre\n");
	   limite = 30;
	break;
	case 10:
	   printf("\n\tOctubre\n");
	   limite = 31;
	break;
	case 11:
	   printf("\n\tNoviembre\n");
	   limite = 30;
	break;
	case 12:
	   printf("\n\tDiciembre\n");
	   limite = 31;
	break;
	}												//Fin switch
	
	printf("%4s%4s%4s%4s%4s%4s%4s\n", "L","M","MI","J","V","S","D");
	}												//Fin if 3
	
	if(diaPos < diaFecha)
	{												//Inicio if 4
	   printf("%4s","**");
	   diaPos++;
	}												//Fin if  4
	else
	{												//Inicio else
	   printf("%3d ",dia);
	   diaPos++;
	   diaFecha++;
	   dia++;
	
	if(diaFecha == 8)
	{												//Inicio if 5
	   printf("\n");
	   diaFecha = 1;
	}												//Fin  if 5
	
	if(dia > limite)
	{												//Inicio if 6
	   diaPos = dia = 1;
	   printf("\n\n");
	
	if(mes < 12) mes++;
	else dia = limite + 1;
	}												//Fin if 6

	}												//Fin else

	}												//Fin for

	}												//Fin if 1
	else printf("NUmero fuera de rango");
	return 0;											//Terminacion exitosa
}													//Fin funcion main
