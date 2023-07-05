#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[])
{
    char inventario[5][4][50] = {
        {"a01", "Lenovo", "i5", "500GB"},
        {"a02", "HP", "i7", "1TB"},
        {"a03", "Dell", "i7", "1TB"},
        {"a04", "Asus", "i5", "256GB"},
        {"a05", "Acer", "i3", "256GB"}
    };
    
    char nombreArchivo[20] = "inventario.txt";
    long posicion;
    
    if (abrirArchivo(nombreArchivo))
    {
        printf("Mostrando el inventario actual:\n");
        leerInventarioArchivo(nombreArchivo);
        
        printf("Buscando una laptop por ID:\n");
        posicion = buscarLaptopPorId(nombreArchivo, "a02");
        
        printf("Reemplazando los datos de una laptop:\n");
        reemplazarLaptopPorId(nombreArchivo, posicion, "a02", "HP", "i7", "2TB");
        
        printf("Mostrando el inventario actualizado:\n");
        leerInventarioArchivo(nombreArchivo);
        
        printf("Ingresando una nueva laptop:\n");
        ingresarLaptop(nombreArchivo, "a06", "Apple", "M1", "512GB");
        
        printf("Mostrando el inventario actualizado:\n");
        leerInventarioArchivo(nombreArchivo);
    }
    else
    {
        crearArchivo(nombreArchivo);
        guardarInventarioArchivo(nombreArchivo, inventario);
    }

    return 0;
}
