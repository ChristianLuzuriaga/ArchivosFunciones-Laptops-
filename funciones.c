#include <stdio.h>
#include <string.h>
#include "funciones.h"

int crearArchivo(char nombreArchivo[])
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "w+");
    if (archivo == NULL)
    {
        printf("No se puede crear el archivo\n");
        return 0;
    }
    else
    {
        printf("Se ha creado el archivo: %s\n", nombreArchivo);
        fclose(archivo);
    }
    return 1;
}

int abrirArchivo(char nombreArchivo[])
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return 0;
    }
    fclose(archivo);
    return 1;
}

void guardarInventarioArchivo(char nombreArchivo[], char inventario[5][4][50])
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede guardar en el archivo\n");
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            fprintf(archivo, "%s %s %s %s\n", inventario[i][0], inventario[i][1], inventario[i][2], inventario[i][3]);
        }
        fclose(archivo);
    }
}

void leerInventarioArchivo(char nombreArchivo[])
{
    char id[50];
    char marca[50];
    char procesador[50];
    char almacenamiento[50];
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
        while (!feof(archivo))
        {
            fscanf(archivo, "%s %s %s %s", id, marca, procesador, almacenamiento);
            printf("%s %s %s %s\n", id, marca, procesador, almacenamiento);
        }
        fclose(archivo);
    }
}

long buscarLaptopPorId(char nombreArchivo[], char id[])
{
    FILE *archivo;
    char idBuscado[50];
    char marca[50];
    char procesador[50];
    char almacenamiento[50];
    long posicion;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
        while (!feof(archivo))
        {
            posicion = ftell(archivo);
            fscanf(archivo, "%s %s %s %s", idBuscado, marca, procesador, almacenamiento);
            if (strcmp(idBuscado, id) == 0)
            {
                printf("Se encontró el ID %s con la marca %s\n", idBuscado, marca);
                break;
            }
        }
        fclose(archivo);
    }
    return posicion;
}

void reemplazarLaptopPorId(char nombreArchivo[], long posicion, char id[], char marca[], char procesador[], char almacenamiento[])
{
    FILE *archivo;
    char idAntiguo[50];
    char marcaAntigua[50];
    char procesadorAntiguo[50];
    char almacenamientoAntiguo[50];
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
        fseek(archivo, posicion, 0);
        fscanf(archivo, "%s %s %s %s", idAntiguo, marcaAntigua, procesadorAntiguo, almacenamientoAntiguo);
        fseek(archivo, posicion, 0);
        fprintf(archivo, "\n%s %s %s %s", id, marca, procesador, almacenamiento);
        fclose(archivo);
    }
}

void ingresarLaptop(char nombreArchivo[], char id[], char marca[], char procesador[], char almacenamiento[])
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
        fseek(archivo, 0, 2);
        fprintf(archivo, "\n%s %s %s %s", id, marca, procesador, almacenamiento);
        fclose(archivo);
    }
}
