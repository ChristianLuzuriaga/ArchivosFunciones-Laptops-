int abrirArchivo(char nombreArchivo[]);
int crearArchivo(char nombreArchivo[]);
void guardarInventarioArchivo(char nombreArchivo[], char inventario[5][4][50]);
void leerInventarioArchivo(char nombreArchivo[]);
long buscarLaptopPorId(char nombreArchivo[], char id[]);
void reemplazarLaptopPorId(char nombreArchivo[], long posicion, char id[], char marca[], char procesador[], char almacenamiento[]);
void ingresarLaptop(char nombreArchivo[], char id[], char marca[], char procesador[], char almacenamiento[]);
