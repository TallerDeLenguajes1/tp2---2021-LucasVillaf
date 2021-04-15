#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    const int filas = 15; // filas matriz
    const int elem = 15; // elementos del vector

    //***FUNCION RAND*** variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior)

int main (){

    //Variables para matriz
    srand(time(NULL));
    int columnas, i, j, par=0;
    columnas= 5 + rand()%(15+1-5);
    int * pMatriz = (int *) malloc(sizeof(int)*filas*columnas); //reserva de memoria
    
    //Variables vector dinamico
    int * pVect;
    pVect = (int *) malloc(sizeof(int)*elem) ; //reserva de memoria
        
    printf ("   ****PUNTO 3****\n");
    printf("\n");
    //MiMatriz[i][j] = *(MiMatriz + i * numerodeColumnas + j);

    for (i=0;i<filas;i++){

        for (j=0;j<columnas;j++){

            *(pMatriz + i * columnas + j) = 100 + rand()%(999+1-100);
            
            printf("   %d ", *(pMatriz + i * columnas + j));
            
            if (*(pMatriz + i * columnas + j)%2 == 0){
                par++;                
            }                        
        }
        *(pVect+i) = par;
        printf ("  - %d numeros par en la fila %d", par,i);
        printf ("\n");
        par=0;        
    }    

    printf("\n\n   VECTOR DINAMICO CON LA CANTIDAD DE NUMEROS PARES POR FILA DE LA MATRIZ ANTERIOR\n");            
    printf("\n   Vector:");
        for(int k=0;k<elem;k++){
            printf(" %2d",*(pVect+k));
        }


    free(pMatriz);
    free(pVect); 

    return 0;
    getchar();
    
}