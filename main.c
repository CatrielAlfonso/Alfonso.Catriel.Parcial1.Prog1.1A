#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int aplicarAumento(float* precio);
int reemplazarCaracteresCat(char cadena[50], char a, char b);
int reemplazarCaracteres(char cadena[], int tamanioCadena, char caracterAReemplazar, char caracterQueVaAReemplazar);

int main()
{
    //float precio=5000;
    char cadena[50]={"Desaprobado"};

   /* printf("el precio es de: %.2f \n",precio);

    aplicarAumento(&precio);

    printf("El precio con aumento es: %.2f ", precio);

    */

    //reemplazarCaracteres(cadena, 'A', 'B');

    printf("%s \n",cadena);

    reemplazarCaracteres(cadena, 20, 'a', 'b');

    printf("%s \n",cadena);

    return 0;
}


int aplicarAumento(float* precio)
{
   int todoOk=0;
   float porcentaje;

   if(precio>0)
   {

       porcentaje = ((*precio/100)*5);

       *precio = *precio + porcentaje;

       todoOk=1;
   }


   return todoOk;
}

int reemplazarCaracteres(char cadena[], int tamanioCadena, char caracterAReemplazar, char caracterQueVaAReemplazar)
{
    int cantidadReemplazos;
    int longitudDeCadena;

    cantidadReemplazos = -1;

    if (cadena != NULL)
    {
        cantidadReemplazos = 0;
        longitudDeCadena = strnlen(cadena, tamanioCadena);

        for (int i = 0; i < longitudDeCadena; i++)
        {

            if (cadena[i] == caracterAReemplazar)
            {
                cadena[i]=caracterQueVaAReemplazar;
                cantidadReemplazos++;
            }
        }
    }

    return cantidadReemplazos;
}

int reemplazarCaracteresCat(char cadena[100], char primerChar, char segundoChar)
{
    int todoOk=0;
    int contadorReemplazos=0;
    char auxCadena[100];

    if(cadena!=NULL)
    {

        printf("Ingrese caracter a reemplazar en el texto: ");
        fflush(stdin);
        scanf("%c", &primerChar);

        printf("Ingrese segundo caracter a reemplazar en el texto: ");
        fflush(stdin);
        scanf("%c", &segundoChar);

        for(int i=0; i < 100 ; i++)
        {
            if(stricmp(cadena[i],primerChar)==0)
            {
                auxCadena[i] = segundoChar;

                cadena= auxCadena;

                contadorReemplazos++;

            }
            else
            {
                if(stricmp(cadena[i],segundoChar)==0)
                {
                    auxCadena[i] = primerChar;

                    cadena= auxCadena;

                    contadorReemplazos++;

                }

            }
        }

        printf("\nNuevo texto (despues de reemplazar con %c y %c) = %s \n", primerChar,segundoChar, cadena);
        printf("Veces reemplazadas %c y %c: %d\n", primerChar, segundoChar, contadorReemplazos);

        todoOk=1;
    }


    return todoOk;
}


