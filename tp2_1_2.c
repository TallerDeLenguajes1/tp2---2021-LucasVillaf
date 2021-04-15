#include <stdio.h>
#define N 4
#define M 5
void cargarMatriz(double matriz[N][M]);

int main (){
    int f,c;
    double mt[N][M];
    double *pVector= &mt[0][0];
    
    cargarMatriz(mt); //Cargar matriz
       
    for(f=0;f<N; f++){ //Mostrar matriz
        for(c=0;c<M; c++){
        printf("%6.2lf ", *(pVector+f*M+c));
        }
        printf("\n");
    }
    
    return 0;
    getchar();
}  

void cargarMatriz(double matriz[N][M]){
    for (int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            matriz[i][j]= i*M+j;
        }
    }
}