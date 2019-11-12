#include <stdio.h>
//autor José Rodrigo Pérez Beltrán
int main()
{
int numero;
printf("\nIngresa el numero: ");
scanf("%d",&numero);

if(numero > 0){

int Ceros = 0;
int potencia = 5;

while(numero - potencia >= 0)
{
Ceros += numero/potencia;
potencia *= 5;
}

printf("\n EL numero de ceros del factorial sera: %d",
Ceros);
}
else printf("\nEse numero no es entero positivo");

return 0;
}
