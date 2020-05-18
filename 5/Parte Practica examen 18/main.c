#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
    int isEmpty;
} eNotebook;

/*Crear una funcion llamada aplicarDescuento que reciba como
parametro el precio de un producto y devuelva el valor del
producto con un descuento del 5%.Realizar una llamada desde el main*/

float aplicarDescuento(float precio);

/*Crear una funcion que se llame contarCaracteres que reciba
una cadena de caracteres como primer parametro y un caracter
como segundo y devuelva la cantidad de veces que ese caracter
aparece en la cadena*/

int contarCaracteres(char cadena[],char caracter);

/*Dada la estructura Notebook(Id,procesador,marca,precio)generar una funcion
que permita ordenar un array de dicha estructura por marca. Ante igualdad de
marca debera ordenarse por precio, Harcodear datos y mostrarlos desde el main.*/

void mostrarNotebook(eNotebook emp);
void mostrarNotebooks(eNotebook vec[], int tam);
void ordenarNooteboks(eNotebook vec[],int tam);

int main()
{
    float costo=100;
    printf("El precio del producto es: %.2f\n",costo);
    printf("Pero con el descuento del 5 porciento el precio es: %.2f\n",aplicarDescuento(costo));

    printf("--------------------------------------------------------------\n");

    char nombre[50]={"aeroespacial"};
    char letra='a';
    printf("La palabra es: %s\n",nombre);
    printf("La cantidad de veces que se repite la letra a es: %d\n",contarCaracteres(nombre,letra));

    printf("--------------------------------------------------------------\n");

    eNotebook notebooks[5]={{100,"Procesador0","Marca45",150},{101,"Procesador1","Marca62",160},{102,"Procesador2","Marca10",180},{103,"Procesador3","Marca45",50},{104,"Procesador4","Marca34",90}};
    mostrarNotebooks(notebooks,5);
    printf("\n");
    ordenarNooteboks(notebooks,5);
    printf("\n");
    mostrarNotebooks(notebooks,5);
    return 0;
}

int contarCaracteres(char cadena[],char caracter)
{
    int contador=0;

    //for(int i=0;i<20;i++)
    for(int i=0;cadena[i]!='\0';i++)
    {
        if(cadena[i]==caracter)
            contador++;
    }
    return contador;
}

float aplicarDescuento(float precio)
{
     float descuento;
     float precioDescuento;
     descuento=(precio*5)/100;
     precioDescuento=precio-descuento;
     return precioDescuento;
}


void mostrarNotebooks(eNotebook vec[], int tam)
{
    int flag=0;
    printf("****** Listado de Notebooks *****\n\n");
    printf("  Id    Procesador    Marca    Precio\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarNotebook(vec[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\n******No hay empleados que listar******\n");
    }
}

void mostrarNotebook(eNotebook emp)
{
    printf(" %d    %10s  %7s   %.2f \n", emp.id,emp.procesador,emp.marca,emp.precio);
}

void ordenarNooteboks(eNotebook vec[],int tam)
{
    eNotebook auxNotebook;
    for(int i=0;i<tam;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(strcmp(vec[i].marca,vec[j].marca)>0)
            {
                auxNotebook=vec[i];
                vec[i]=vec[j];
                vec[j]=auxNotebook;
            }
            else if(strcmp(vec[i].marca,vec[j].marca)==0 && vec[i].precio>vec[j].precio)
            {
                auxNotebook=vec[i];
                vec[i]=vec[j];
                vec[j]=auxNotebook;
            }
        }
    }
    printf("Se ordenaron las notebooks por marca y por precio.\n");
}
