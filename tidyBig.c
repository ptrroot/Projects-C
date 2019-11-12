#include <stdio.h>

int main()
{
   char b[30], * p;
   int x, c;
   x = 0;
   FILE * f = fopen( "B-large-practice.in","r" );
   fscanf(f,"%s",b);
   sscanf(b, "%d", &c);
   while(x++ < c)
   {
     fscanf(f,"%s",b);
     p = b;
     while(*(p+1) != '\0')
       {
	 if(*p > *(p+1))
	   {
	     (*p)--;
	     if(*p == '0') *p = '\b';
	     p++;
	     while(*p != '\0')*p ='9',p++; 
	     p = b;
	   }else p++;
       }
     if(b[0]=='\b')printf("Case #%d:  %s\n",x,b);
     else printf("Case #%d: %s\n",x,b);
   } 
}
