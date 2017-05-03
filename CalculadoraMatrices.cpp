/*
Programa: Calculadora de matrices
Autor: Alejandro Santibañez Sanchez
Fecha: 01/05/2017
Resumen: Realiza las operaciones de suma, resta, multiplicacion de matrices, ademas de traspuesta, determinante, escalar y potencia
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define fil 3
#define col 3

void menu(int matriz[fil][col]);
void Llenar_Matriz(int [fil][col]);
int LlenarAutomatica(int [fil][col]);
int LlenarTeclado(int [fil][col]);
void contenido_menu();

int Mostrar_Matriz(int [fil][col]);
int MatrizTranspuesta(int [fil][col]);
int Determinante_Matriz(int [fil][col]);
int MultiplicacionPorEscalar(int [fil][col]);
int Potencia_de_Matriz(int [fil][col]);
int MatrizA_Mas_MatrizB(int matriz[fil][col]);
int MatrizA_Menos_MatrizB(int matriz[fil][col]);
int MatrizA_Por_MatrizB(int matriz[fil][col]);
int matriz_2[fil][col];

int main() {
    system("color f2");
	int matriz[fil][col], matriz_2[fil][col];
	Llenar_Matriz(matriz);
	menu(matriz);

	return 0;
}
void Llenar_Matriz(int matriz[fil][col]){
    int opcion;
	do{
		printf("\t\tWELCOME TO THE FIRST MENU\n");
	    printf("\n 1. Llenar Matriz Automaticamente\n");
	    printf("\n 2. Llenar Matriz Manualmente\n");
		printf("\n 3. Salir\n");
		printf("\n Ingrese La Opcion Deseada: ");
		scanf("%d", &opcion);
		switch(opcion){
		case 1: LlenarAutomatica(matriz);
			break;
		case 2:  LlenarTeclado(matriz);
			break;
		case 3: exit(0);
			break;
		default: printf("\nNo es una opcion valida\n");
            break;
        }
    system("pause");
	}while(opcion < 0 || opcion > 3);
}

int LlenarAutomatica(int matriz[fil][col]){
	srand(time(0));
    int f, c;
       for (f = 0; f < fil; f++){
         for (c = 0; c < col; c++){
            matriz[f][c]=rand()%(20);
            printf("\t%d",matriz[f][c]);
         }
       printf("\n");
    }
    return 0;
}

int LlenarTeclado(int matriz[fil][col]){
    int f, c;
    for(f = 0; f < fil; f++){
        for(c = 0; c < col; c++){
           printf("Ingrese un numero  en la posicion [%d][%d]: ", f,c);
           scanf("%d", &matriz[f][c]);
           printf("%d",matriz[f][c]);
        }
        printf("\n");
    }
    return (matriz[f][c]);
}
void contenido_menu(int opcion){
    printf("  |---------------------CALCULADORA DE MATRICES--------------------|\n");
    printf("  |                                 |                              |\n");
    printf("  |   1. Mostrar Matriz             |   6. Matriz A + Matriz B     |\n");
    printf("  |   2. Matriz Transpuesta         |   7. Matriz A - Matriz B     |\n");
    printf("  |   3. Determinante de Matriz     |   8. Matriz A * Matriz B     |\n");
    printf("  |   4. Multiplicacion Por Escalar |   0. Salir.                  |\n");
    printf("  |   5. Potencia de una Matriz     |                              |\n");
    printf("  |----------------------------------------------------------------|\n");
}
void menu(int matriz[fil][col]){
    int opcion;
    char ese;
    int contador = 0;
    int matriz1[fil][col];
    do{
       system("cls");
       contenido_menu(opcion);
       if(contador > 0){
            printf("\n Opcion invalida, es un numero del 0 al 8");
       }
       printf("\nIngrese su opcion: ");
       scanf("%d", &opcion);
       contador += 1;
       switch(opcion){
        case 1: Mostrar_Matriz(matriz);
            break;
        case 2: MatrizTranspuesta(matriz);
            break;
        case 3: Determinante_Matriz(matriz);
            break;
        case 4: MultiplicacionPorEscalar(matriz);
            break;
        case 5: Potencia_de_Matriz(matriz);
            break;
        case 6: MatrizA_Mas_MatrizB(matriz);
            break;
        case 7: MatrizA_Menos_MatrizB(matriz);
            break;
        case 8: MatrizA_Por_MatrizB(matriz);
            break;
        case 0: exit(0);
            break;
        default: printf("\nNo es una opcion valida");
            break;
        }
        printf("\nPresione una letra para continuar: ");
        scanf(" %c", &ese);
        menu(matriz);
    }while(opcion > 9 || opcion < 0);
}

int Mostrar_Matriz( int matriz[fil][col]){
	void Llenar_Matriz();
	int f, c;
    for(f = 0; f < fil; f++){
        for(c = 0; c < col; c++){
            printf("%d ", matriz[f][c]);
        }
        printf("\n");
    }
    return 0;
}

int MatrizTranspuesta(int matriz[fil][col]){
	int f, c, matrizT[fil][col];
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            matrizT[f][c] = matriz[c][f];
        }
    }
    Mostrar_Matriz(matrizT);
    return 0;
}
int Determinante_Matriz(int matriz[fil][col]){
    int resultado_determinante,diagonal_1,diagonal_2;
    diagonal_1 = matriz[0][0] * matriz[1][1] * matriz[2][2] + matriz[0][1]*matriz[1][2]*matriz[2][0] + matriz[0][2]*matriz[1][0]*matriz[2][1];
    diagonal_2 = matriz[0][2] * matriz[1][1] * matriz[2][0] + matriz[0][0]*matriz[1][2]*matriz[2][1] + matriz[0][1]*matriz[1][0]*matriz[2][2];
    resultado_determinante = diagonal_1 - diagonal_2;
    printf("\nEl resultado de la determinante es: %d ",resultado_determinante);

    return 0;
}
int MultiplicacionPorEscalar(int matriz[fil][col]){
	int f, c, num,escalar[fil][col];
	printf("\n ingrese el numero para efectuar la multiplicacion: ");
	scanf("%d", &num);
	printf("\n la multiplicacion del numero por la matriz es:\n");
    for(f = 0; f < fil; f++){
		for(c = 0; c < col; c++){
			escalar[f][c] = matriz[f][c] * num;
			printf(" %d ", escalar[f][c]);
       }
	  printf("\n");
   }
   return 0;
}
int Potencia_de_Matriz(int matriz[fil][col]){
	int f, c, poten, potencia[fil][col];
	printf("\n ingrese la potencia a la cual desea elevar la matriz: ");
	scanf("%d", &poten);
	if(poten >= 2 && poten <= 3){
        for (f = 0; f < 3; f++){
            for (c = 0; c < 3; c++){
                potencia[f][c] = pow (matriz[f][c], poten);
                printf("%d  ",potencia[f][c]);
            }
            printf("\n");
        }
	}else{
        printf("\nNo es una opcion valida");
	}
	return 0;
}

int MatrizA_Mas_MatrizB(int matriz[fil][col]){
	int f, c,matriz_2[fil][col],Suma_matrices[f][c];
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            printf ("\ningrese el valor en la posicion [%d][%d] ",f,c);
            scanf ("%d ", &matriz_2[f][c]);
        }
    }
      for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
             printf ("%d ",matriz_2[f][c]);
        }
        printf("\n");
    }
     printf("\n Suma de dos matrices \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            Suma_matrices[f][c] = matriz[f][c] + matriz_2[f][c];
            printf("%d ",Suma_matrices[f][c]);
        }
        printf("\n");
    }
    return 0;
}

int MatrizA_Menos_MatrizB(int matriz[fil][col]){
	int f, c,matriz_2[fil][col],resta_matriz[f][c];
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            printf ("\ningrese el valor en la posicion [%d][%d] ",f,c);
            scanf ("%d ", &matriz_2[f][c]);
        }
    }
      for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
             printf ("%d ", matriz_2[f][c]);
        }
        printf("\n");
    }
     printf("\n Resta de dos matrices \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            resta_matriz[f][c] = matriz[f][c] - matriz_2[f][c];
            printf("%d ",resta_matriz[f][c]);
        }
        printf("\n");
    }
    return 0;
}

int MatrizA_Por_MatrizB(int matriz[fil][col]){
	int f, c,matriz_2[fil][col],producto_matriz[f][c];
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            printf ("\ningrese el valor en la posicion [%d][%d] ",f,c);
            scanf ("%d", & matriz_2[f][c]);
        }
    }
      for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
             printf ("%d ",matriz_2[f][c]);
        }
        printf("\n");
    }
     printf("\n Producto de dos matrices \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            producto_matriz[f][c] = matriz[f][c] * matriz_2[f][c];
            printf("%d ",producto_matriz[f][c]);
        }
        printf("\n");
    }
    return 0;
}
