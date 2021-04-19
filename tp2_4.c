#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    typedef struct compu {  //estructura computadoras
        int velocidad;      //entre 1 y 3 Gherz
        int anio;           //entre 2000 y 2017
        int cantidad;       //entre 1 y 4
        char *tipo_cpu;     //valores del arreglo tipos
    } ordenador;
     //funciones
    ordenador cargarPC(ordenador computadora, char *tipo);
    void mostrarPC(ordenador computadora);
    ordenador enlistarPC(int cantidad, char *tipo, ordenador *pcIngresadas);
    void mostrarListaPc(int cantidad, ordenador *pcIngresadas);
    void mostrarVieja(int cantidad, ordenador *pcIngresadas);
    void mostrarRapida(int cantidad, ordenador *pcIngresadas);
    

int main(){
    //variables
    int cantidad;
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    char *tipo = tipos[0];

    printf("Ingrese la cantidad de Computadoras que desea mostrar: ");
    scanf("%d",&cantidad);
    ordenador *pcIngresadas = (ordenador *) malloc(sizeof(ordenador)*cantidad);  

    //llamado de funciones
    srand(time(NULL));
    enlistarPC(cantidad,tipo,pcIngresadas);
    mostrarListaPc(cantidad,pcIngresadas);
    mostrarVieja(cantidad,pcIngresadas);
    mostrarRapida(cantidad,pcIngresadas);
    
    getchar();
    free(pcIngresadas);
    return 0;
}
//***FUNCION RAND***//
// variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior)
ordenador cargarPC(ordenador computadora, char *tipo){
    srand(time(NULL));
    computadora.velocidad = 1+rand()%(3+1-1) ;
    computadora.anio = 2000+rand()%(2017+1-2000);
    computadora.cantidad = 1+rand()%(4+1-1);
    computadora.tipo_cpu = tipo+(rand() % 6*10);

    return computadora;
};

void mostrarPC(ordenador computadora){
    printf("\n-----------------------------\n");
    printf("  Velocidad: %d Ghz\n", computadora.velocidad);
    printf("  Anio: %d\n", computadora.anio);
    printf("  Nucleos: %d\n", computadora.cantidad);
    printf("  Procesador: %s\n", computadora.tipo_cpu);
    printf("-----------------------------\n");
};

ordenador enlistarPC(int cantidad, char *tipo, ordenador *pcIngresadas){
    ordenador pc;    
    for(int i=0;i<cantidad;i++){
        srand(time(NULL));
        pcIngresadas[i] = cargarPC(pc ,tipo);
    }    
};

void mostrarListaPc(int cantidad, ordenador *pcIngresadas){    
    printf("\n-----------------------------\n");    
    for (int i = 0; i < cantidad; i++) {
        srand(time(NULL));
        printf("      Computadora n %d",i+1);
        mostrarPC(*(pcIngresadas+i));
    }    
};

void mostrarVieja(int cantidad, ordenador *pcIngresadas){
    int mayor = 0;
    int vieja = 0;
    for (int i = 0; i < cantidad; i++){
        if (mayor<pcIngresadas[i].anio){
            mayor=pcIngresadas[i].anio;
            vieja=i;
        }
    }
    printf("      Computadora mas vieja");
    mostrarPC(pcIngresadas[vieja]);
    
};

void mostrarRapida(int cantidad, ordenador *pcIngresadas){
    int mayor = 4;
    int rapida = 0;
    for (int i = 0; i < cantidad; i++){
        if (mayor>pcIngresadas[i].velocidad){
            mayor=pcIngresadas[i].velocidad;
            rapida=i;
        }
    }
    printf("      Computadora mas rapida");
    mostrarPC(pcIngresadas[rapida]);
};

