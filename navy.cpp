/*
	ESCUELA SUPERIOR DE CÓMPUTO 
	
	Proyecto final de Algoritmia y Programación Estructurada de datos
	
	Programa que emula el juego "Batalla Naval "
	
	Alumnos: 
			___________________________________
			| DOMINGUEZ ESPINOZA JORDAN       |
			| LAINE SANCHEZ MAURICIO          |
			| MEJIA PEREZ JAVIER              |
			| MORENO SANCHEZ GREEN KELVIN     |
			| TORRES ALVARADO MIGUEL ANGEL    |
			| POPOCA QUINTANAR DANIEL         |
			___________________________________
*/
//Librerias
//__________________
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<time.h>
//__________________
#define MAXV 8//Numero de filas en el tablero
#define MAXH 6 //Numero de columnas en el tablero
//Prototipos de funciones
void tablero(void);
void header(void);
void by(void);
void men1(void);
void initab(int jugador[][MAXH],int pc[][MAXH]);
void ubicah(int jugador[][MAXH]);
void ubicapc(int pc[][MAXH]);
void usuariot(int jugador[][MAXH]);
int main(void)
{
	int jugador[MAXV][MAXH];
	int pc[MAXV][MAXH];
	int flag=0,scent,ans,jj,oo;;
	char menu;
	system("clear");//Se limpia pantalla, en win: system(cls);
	while(menu!='s')
	{	
		//system("clear");
		header();//Encabezado "NAVY"
		men1();//Se muestra el menu de juego en pantalla
		scanf("%c",&menu);
		switch(menu)
		{
			case 'J' :case 'j':
			system ("clear");
				initab(jugador,pc);
				printf("¿Quien tira primero 1)tu o 2)yo?");
				scanf("%d",&ans);
				
				if(ans=1)
				{
					printf("Ubica tus barcos\n");
					ubicah(jugador);
					for(jj=0;jj<=7;jj++)
					{
						for(oo=0;oo<=5;oo++)
						{
							printf("\t%d",jugador[jj][oo]);
						}
						printf("\n");
					}
					printf("\n");
					ubicapc(pc);
				}
				else
				{
					ubicapc(pc);
					printf("Ubica tus barcos\n\n");
					ubicah(jugador);
					for(jj=0;jj<=7;jj++)
					{
						for(oo=0;oo<=5;oo++)
						{
							printf("\t%d",jugador[jj][oo]);
						}
						printf("\n");
					}
				}
				do
				{
				header();//Encabezado "NAVY"
				usuariot(jugador);//se muestra el tablero de juego en pantalla
				}while(flag=0);
				break;
		
			case 'C' :case 'c' :
				system ("clear");
				header();
				by();//creditos
				break;
	
			case 'S' :case 's' ://sale del juego
				system ("clear");
				printf("\t\tSaliendo...\n\n");
				sleep(2);
				exit(0);
				break;
	
			default:
				printf("\t\tOpcion Incorrecta, intente de nuevo");
			
	
		}
		getchar();//Toma la basura del scanf
	
	}
	return 0;
}


//Funciones usadas en main()

void tablero(void)//Función que dibuja el tablero de navi en pantalla
{
	printf("\n\n\t\t\t\t\t ::HUMAN::\t\t\t\t   ::MACHINE::\n\n\t\t             ");
	for(int y=0;y<=1;y++)//Numeracion de los 2 tableros
	{
		if(y)printf("\t  ");
		for(int z=1;z<=6;z++)//Numeracion de bloques en el tablero
		{
			printf("  %d    ",z);
		}
	}
	printf("\n\t\t\t    _________________________________________\t _________________________________________\n");
	for(int x=0;x<=7;x++)
	{
		printf(" \t\t\t %d |                                         |\t|                                         |\n\t\t\t   |______|______|______|______|______|______|\t|______|______|______|______|______|______|\n",x+1);
	}
	printf("\n\n\n\n");

}
	
void header(void)//Función que dibuja el titulo del juego 
{
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t   _______ _______ ___ ___ ___ ___ \n");
	printf("\t\t\t\t\t\t__|    |  |   _   |   |   |   |   |\n");
	printf("\t\t\t\t\t\t__|       |       |   |   |\\     / \n");
	printf("\t\t\t\t\t\t__|__|____|___|___|\\_____/  |___|  \n\n");
}
void men1(void)//menu
{
	printf("\t\t\t\t\t\t\tElije la opcion:\n\n\t\t\t\t\t\t\t<J>ugar\n\t\t\t\t\t\t\t<C>reditos\n\t\t\t\t\t\t\t<S>alir");
	printf("\n\t\t\t\t\t\t\t");
}

void by(void)
{
	printf("\n\n\n\t\t\t\t\tSiéntete libre de copiar, distribuir o modificar el código fuente de este programa\n\n\t\t\t\t\t\tElaborado por alumnos de la Escuela Superior de Cómputo\n\n\n\t| Domínguez Espinoza Jordan \n\t\t| Laine Sánchez Mauricio \n\t\t\t| Mejía Pérez Javier \n\t\t\t\t| Moreno Sánchez Green Kelvin \n\t\t\t\t\t| Popoca Quintanar Daniel \n\t\t\t\t\t\t\t| Torres Alvarado Miguel Ángel");
	printf("\n\n\n\nPresione cualquier tecla para continuar\n");
	getchar();
}

void initab(int jugador[][MAXH],int pc[][MAXH])
{
	int z2,w2,f,g;
	
	for(z2=0;z2<=7;z2++)
	{
		for(w2=0;w2<=5;w2++)
		{
			jugador[z2][w2]=0;
			pc[z2][w2]=0;
		}
	}
}

void ubicah(int jugador[][MAXH])//Posiciona los barcos de el jugador **(Falta restricción de barcos sobrepuestos)**
{	
	int x,y,ax=0,aux1,a=0,b,c,d,flag2=0;
	char ansd;
	for(aux1=3;aux1>=1;aux1--)
	{
		//while(flag2!=1&&aux1>=1)
		//{
			printf("\nBarco nivel %d(%dx):\nIngresa coordenada x: \t",aux1+1,aux1+1);
			scanf("%d",&x);
			if(x>MAXH)
			{
				printf("ERROR Imposible posicionar navío, elija otra coordenada\n");
				scanf("%d",&x);
			}
			printf("Ingresa coordenada y: \t");
			scanf("%d",&y);
			if(y>MAXV)
			{
				printf("ERROR Imposible posicionar navío, elija otra coordenada\n");
				scanf("%d",&y);
			}
			jugador[y-1][x-1]=aux1+1;
			getchar();
			printf("Dirección de la nave (d)erecha, (i)zquierda, (b)ajo, (a)rriba:\n");
			scanf("%c",&ansd);
			int k;
			switch(ansd)
			{
				case 'A':case 'a':
					if((y-(aux1+1))<=0)
					{
						printf("ERROR Imposible posicionar navío por que estaría fuera del tablero\n");
						a=0;
					}
					else
					{	
					
							printf("Posicionando navío nivel %d\n",aux1+1);
							for(k=1;k<=aux1;k++)
							{
								//if((jugador[y-2][x-1])=0)
								//{
									jugador[y-2][x-1]=aux1+1;
									y--;
									flag2=1;
								//}
								//else
								//{
									//printf("Error, nave sobrepuesta\n");
									//flag2=0;
								//}
							}
					
							a=1;
					}
					fflush(stdin);
					break;
				case 'B':case 'b':
					if((y+(aux1+1))>8)
					{
						printf("ERROR Imposible posicionar navío por que estaría fuera del tablero\n");
					}
					else
					{
						printf("Posicionando navío nivel %d",aux1+1);
						for(k=1;k<=aux1;k++)
						{
						jugador[y][x-1]=aux1+1;
						y++;
						}
					}fflush(stdin);
					break;
				
				case 'I':case 'i':
					if((x-(aux1+1))<=0)
					{
						printf("ERROR Imposible posicionar navío por que estaría fuera del tablero\n");
					}
					else
					{
						printf("Posicionando navío nivel %d\n",aux1+1);
						for(k=1;k<=aux1;k++)
						{
						jugador[y-1][x-2]=aux1+1;
						x--;
						}
					}fflush(stdin);
					break;
				
				case 'D':case 'd':
					if((x+(aux1+1))>6)
					{
						printf("ERROR Imposible posicionar navío por que estaría fuera del tablero\n");
					}
					else
					{
						printf("Posicionando navío nivel %d\n",aux1+2);
						for(k=1;k<=aux1;k++)
						{
						jugador[y-1][x]=aux1+1;
						x++;
						}
					}fflush(stdin);
					break;
				
				default:
					printf("No es una opción correcta\n(d)erecha, (i)zquierda, (b)ajo, (a)rriba\n Ingresa la letra entre paréntesis de la opcion deseada.\n");
		
			}getchar();//Toma la basura del scanf
		//}
	}
}
void ubicapc(int pc[][MAXH])//Ubica los barcos de la pc **(Falta restriccon de naves sobrepuestas)**
{
	int x,y,x1,y1;
	srand(time(NULL));
	//genera el barco de 4 casillas
	x=rand()%2;
	if(x==0)//decide si el barco sera horizontal (0) o vertical (1)
	{
		y=rand()%2;
		if(y==0)//decide si el barco sera a la derecha (0) o izquierda (1)
		{	
			do{
			x1=(rand()%6);
			y1=(rand()%8);
			}while((x1+3)>5);
			printf("d%d%d",x1,y1);
			for(int c=0;c<=3;c++)
			{
				pc[y1][x1]=4;
				x1++;
			}
		}
		else
		{
			do{
			x1=(rand()%6);
			y1=(rand()%8);
			}while((x1-3)<0);
			printf("i%d%d",x1,y1);
			for(int c=0;c<=3;c++)
			{
				pc[y1][x1]=4;
				x1--;
			}
		}
	}
	else
	{
		y=rand()%2;
		if(y==0)//decide si el barco sera hacia arriba (0) o abajo (1)
		{
			do{
			x1=(rand()%6);
			y1=(rand()%8);
			}while((y1-3)<0);
			printf("A%d%d",x1,y1);
			for(int c=0;c<=3;c++)
			{
				pc[y1][x1]=4;
				y1--;
			}
		}
		else
		{
			do{
			x1=(rand()%6);
			y1=(rand()%8);
			}while((y1+3)>7);
			printf("a%d%d",x1,y1);
			for(int c=0;c<=3;c++)
			{
				pc[y1][x1]=4;
				y1++;
			}
		}
	}	
	//genera el barco de 3 casillas
	x=rand()%2;
	if(x==0)//decide si el barco sera horizontal (0) o vertical (1)
	{
		y=rand()%2;
		if(y==0)//decide si el barco sera a la derecha (0) o izquierda (1)
		{	
			
			do{
			x1=(rand()%6);
			y1=(rand()%8);
			}while((x1+2)>5);
			for(int c=0;c<=2;c++)
			{
				pc[y1][x1]=3;
				x1++;
			}
		}
		else
		{
			do{
			x1=(rand()%6);
			y1=(rand()%8);
			}while((x1-2)<0);
			for(int c=0;c<=2;c++)
			{
				pc[y1][x1]=3;
				x1--;
			}
		}
	}
	else
	{
		y=rand()%2;
		if(y==0)//decide si el barco sera hacia arriba (0) o abajo (1)
		{
			do{
			x1=(rand()%6);
			y1=(rand()%8);
			}while((y1-2)<0);
			for(int c=0;c<=2;c++)
			{
				pc[y1][x1]=3;
				y1--;
			}
		}
		else
		{
			do{
			x1=(rand()%6);
			y1=(rand()%8);
			}while((y1+2)>7);
			for(int c=0;c<=2;c++)
			{
				pc[y1][x1]=3;
				y1++;
			}
		}
	}	
	//genera el barco de 2 casillas
	x=rand()%2;
	if(x==0)//decide si el barco sera horizontal (0) o vertical (1)
	{
		y=rand()%2;
		if(y==0)//decide si el barco sera a la derecha (0) o izquierda (1)
		{	
			do{
			x1=(rand()%6);
			y1=(rand()%8);
			}while((x1+1)>5);
			for(int c=0;c<=1;c++)
			{
				pc[y1][x1]=2;
				x1++;
			}
		}
		else
		{
			do{
			x1=(rand()%6);
			y1=(rand()%8);
			}while((x1-1)<0);
			for(int c=0;c<=1;c++)
			{
				pc[y1][x1]=2;
				x1--;
			}
		}
	}
	else
	{
		y=rand()%2;
		if(y==0)//decide si el barco sera hacia arriba (0) o abajo (1)
		{
			do{
			x1=(rand()%6);
			y1=(rand()%8);
			}while((y1-1)<0);
			for(int c=0;c<=1;c++)
			{
				pc[y1][x1]=2;
				y1--;
			}
		}
		else
		{
			do{
			x1=(rand()%6);
			y1=(rand()%8);
			}while((y1+1)>7);
			for(int c=0;c<=1;c++)
			{
				pc[y1][x1]=2;
				y1++;
			}
		}
	}
	int jj,oo;
	for(jj=0;jj<=7;jj++)
	{
		for(oo=0;oo<=5;oo++)
		{
			printf("\t%d",pc[jj][oo]);
		}
		printf("\n");
	}	
}

void usuariot(int jugador[][MAXH])//Función que dibuja el tablero (lleno) de navi en pantalla
{
	printf("\n\n\t\t\t\t\t ::HUMAN::\t\t\t\t   ::MACHINE::\n\n\t\t             ");
	for(int y=0;y<=1;y++)//Numeracion de los 2 tableros
	{
		if(y)printf("\t  ");
		for(int z=1;z<=6;z++)//Numeracion de bloques en el tablero
		{
			printf("  %d    ",z);
		}	
	}	       
	printf("\n\t\t\t    _________________________________________\t _________________________________________\n");
	for(int x=0;x<=7;x++)
	{
		printf(" \t\t\t %d |    %d     %d     %d      %d      %d      %d   |  |                                         |\n\t\t\t   |______|______|______|______|______|______|\t|______|______|______|______|______|______|\n",x+1,jugador[x][0],jugador[x][1],jugador[x][2],jugador[x][3],jugador[x][4],jugador[x][5]);
	}
	printf("\n\n\n\n");

}

