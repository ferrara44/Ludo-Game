#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
/*Cada jugador debe leer el tablero al principio de su turno, para ver cuántos peones tiene y dónde están.*/

int d1, d2, seis, dados; /*Cada uno de los dados y si sale un seis*/
int i, op, n, play[4]; /*Iteraciones y opciones de movimiento, 1 al 4 son peones, 5 pasa*/
int np1=0, pj1[4]={-1,-1,-1,-1};
int np2=0, pj2[4]={-1,-1,-1,-1};
int np3=0, pj3[4]={-1,-1,-1,-1};
int np4=0, pj4[4]={-1,-1,-1,-1};/*Peones en juego y ubicaciones le da el valor inicial de la casilla primera del jugador, respectivamente: (0,6,12,18)*/
int fj[4]={0,0,0,0};/*Cantidad de peones que han dado vuelta al tablero.*/
int turno; /*A qué jugador le toca, se usa para definir sobre qué entidades actúan las funciones de la IA.*/
int summoned=0; /* Es 1 si se ha agregado un peón al juego este turno */
char tablerovacio[24]; /*Tablero vacío*/
char lista[24]; /*Este es el tablero si fuera una línea*/

void tablero(){
	for (i=0;i<28;i++){
		printf("%-15c", lista[i]);
	}
	return;
}

void roll(){/* La tirada de los dados. También se encarga de chequear seis*/
	printf("Presione cualquier tecla para arrojar los dados.\n");
	system("pause");
	d1 = (rand()%6)+1; 
	d2 = (rand()%6)+1; 
	dados = d1+d2;
	if (d1==6||d2==6) seis=1;
	else seis=0;
	printf ("\n%d y %d", d1,d2);
	if (seis==1) printf(".¡Seis!\n");
	else printf(".\n");
}

void aiRoll(){ /*Tirada de dados para jugadores de la IA.*/
	d1 = (rand()%6)+1; 
	d2 = (rand()%6)+1; 
	dados = d1+d2;
	if (d1==6||d2==6) seis=1;
	else seis=0;
	printf ("\n Jugador %d ha tirado %d y %d \n\n", turno,d1,d2);
	if (seis==1) printf(".¡Seis!\n");
	else printf(".\n");
}

int choice(int a){ /*Cuando la AI tiene más de una opción, elige qué hacer al azar. "a" es la cantidad de opciones.*/
	int b=(rand()%a)+1;
	return b;
}

void summon(int pnum){ /*Invoca peones*/
	switch (turno){
	case 2:
		if (np2<4){
			pj2[np2]=7+dados;
		}
		break;
	}
}

void turnoj1(){
	turno=1;
	return;
}

void turnoj2(){
	
	turno=2;
	printf("\4\4 Turno del jugador 2. \4\4\n\n");
	aiRoll();
	n=0;
	np2=0;
	for(i=0;i<20;i++){
		if(lista[i]=='\4'){
			play[n]=lista[i];
			n++;
			np2++;
		}
	}
	
	if (seis==1 && np2<4){ /*Si saca 6 en algún dado, intenta invocar*/
		summon(2);
	}
	else{
		if(n>0){
			
		}
		else {
			printf("Jugador 2 no tiene movimientos legales: Debe pasar su turno.");
		}
	}
	getchar();
	return;
}

void clear(){
	/*Debe inicializar variables como move,n y op, np, se usa al final de cada turno*/
}

int main(){
	
	srand(time(NULL));/*Seedea el rand, mantener al principio de main.*/
	
	for(;;){
		clear();
		turnoj1;
		if(fj[0]=4){
		printf("Gana \3 \n\n\n");
		return 0;
		}
		clear();
		turnoj2;
		if(){
			printf("Gana el jugador 2. \n\n\n");
			return 0;
		}
		clear();
		turnoj3;
		if(){
			printf("Gana el jugador 3. \n\n\n");
			return 0;
		}
		clear();
		turnoj4;
		if(){
			printf("Gana el jugador 3. \n\n\n");
			return 0;
		}
	}
	
	return 0;
}
