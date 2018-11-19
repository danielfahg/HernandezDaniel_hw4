#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

//constantes
float g=10.0;//m/s gravedad

float c=0.2;//coeficioente de friccion

float m=0.2;//Kg masa

//condiciones iniciales
float xIni=0.0;//m, para tiempo=0.0

float yIni=0.0;//m, para tiempo=0.0

float magVelTot=300.0;//m/s magnitud de velocidad total

float angGra=45.0;//angulo respecto a la horizontal en grados

float ang=(angGra*2.0*M_PI)/(360.0);//rads, angulo respecto a la horizontal

float vxIni=magVelTot*cos(ang);

float vyIni=magVelTot*sin(ang);

float tMax=100.0;//segundos, tiempo maximo

float dt=0.001;//delta t, en segundos

int tieNumInt=(int) (tMax/dt);

int tieNumPun=( (int) (tMax/dt) )+1;

//funciones

float DaMagVel(float vx, float vy);

float DaArchivoYxMax(float varAngGra, int numAng);

int main()
	{
	cout<<"Punto 2 ODE con el metodo de Leap Frog" <<endl;
	
	//BORRA BLOQUE
	//cout<< cos(3.1416/2.0)<<" y M_PI es "<< M_PI <<endl;
	//cout<< vxIni<<" y "<<vyIni <<endl;

	//PODRIA FUNCIONAR AQUI HACER UN FOR QUE VALLA CAMBIANDO LOS ANGULOS Y SEGUN EL ANGULO O EL
	//INDICE IR CAMBIANDO LO QUE IMPRIME Y GUARDA, REVISAR RAPIDAMENTE SI ASI
	float angulos[8]={45.0, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0};
	//char nombre="lala";
	/*for(int a=0; a<8; a++)
		{
		//BORRA LINEA O BLOQUE
		//cout<< angulos[0]<<endl;
		//ofstream outfile;//ofstream.outfile;
		//outfile.open(nombre);
		//outfile<<"funciono"<<endl;
		//outfile.close();

		//angGra=angulos[a];
		

		}*/
	
	//Bloque para al iniciar el programa ODE.cpp nuevamente borrar lo que halla en PosVelTieTodAng.txt, pues abajo por
	//el modo ::app no lo borraria y se desordenaria todo. Con esto PosVelTieTodAng.txt queda en blanco para volver a hacerlo 	
	ofstream outfile;
	outfile.open("PosVelTieTodAng.txt");
	outfile.close();	
	
	/*//BORRA BLOQUE
 	DaArchivoYxMax(45.0, 0);
	DaArchivoYxMax(45.0, 1);
	DaArchivoYxMax(45.0, 0);
	DaArchivoYxMax(45.0, 1);
	DaArchivoYxMax(45.0, 0);
	DaArchivoYxMax(45.0, 1);*/

	//BORRA BLOQUE O LINEA
	//cout<<DaMagVel(3.0, 4.0) <<endl;
	
	return 0;	
	}

//da la magnitud del vector velocidad dadas las componentes
float DaMagVel(float vx, float vy)
	{
	return pow( (vx*vx)+(vy*vy) , 0.5);
	}

//primer numero de angulo numAng es 0, hasta 7 el ultimo
float DaArchivoYxMax(float varAngGra, int numAng)
	{
	float var_xMax=0.0;

	float varAng=(varAngGra*2.0*M_PI)/(360.0);//rads, angulo respecto a la horizontal
	float var_vxIni=magVelTot*cos(varAng);
	float var_vyIni=magVelTot*sin(varAng);

	ofstream outfile;
	if(numAng==0)
		{
		outfile.open("PosVelTie45.txt");
		}
	else
		{
		outfile.open("PosVelTieTodAng.txt", ios::app); //ios::app mode 
		}
	
	//BORRA BLOQUE	
	//outfile<<"Hola mundo sobrescribe?"<< numAng <<endl;
	//outfile<<"si! parece que si:)"<< numAng <<endl;

	//dado el angulo varAngGra y el numero de el numAng solucionamos la
	//ecua. diferencial y hallamos la distancia horizontal maxima alcanzada cuando el proyectil toca el piso con altura y=0.0
	float arr_t[tieNumPun];	
	float arr_x[tieNumPun];
	float arr_y[tieNumPun];
	float arr_vx[tieNumPun];
	float arr_vy[tieNumPun];

	//Leap Frog necesita posiciones y velocidades para dos indices del tiempo antes, por eso usamos Backward difference
	//para calcular las posiciones y velocidades en un tiempo antes del inicial, como para tiempo i=-1	
	float xPas=xIni-( var_vxIni*dt );
	float yPas=yIni-( var_vyIni*dt );
	float vxPas=var_vxIni+( (c*dt*DaMagVel(var_vxIni, var_vyIni)*var_vxIni)/(m) );
	float vyPas=var_vyIni+( dt*( g+( (c*DaMagVel(var_vxIni, var_vyIni)*var_vyIni)/(m) ) ) );

	//tiempo i=0:	
	//ponemos en posiciones y velocidades del presente las posiciones y velocidades del tiempo i=0
	float xPre=xIni;
	float yPre=yIni;
	float vxPre=var_vxIni;
	float vyPre=var_vyIni;
	//las ponemos en .txt 
	outfile<<xPre<<" "<<yPre<<" "<<vxPre<<" "<<vyPre<<" "<<0.0 <<endl;
	//ponemos esto en los arreglos de posicion y velocidad para al final hallar la x maxima
	float arr_t[0]=0.0;	
	float arr_x[0]=xPre;
	float arr_y[0]=yPre;
	float arr_vx[0]=vxPre;
	float arr_vy[0]=vyPre;
	//termina lo de tiempo i=0

	//para el resto de tiempos i usamos en cada uno las posiciones y velocidades de las variables
	//del presente y pasado para calcularlas, y despues acomodamos el nuevo pasado y presente
	float xFut=0.0;
	float yFut=0.0;
	float vxFut=0.0;
	float vyFut=0.0;
	for(int i=1; i<=tieNumInt; i++ )//HAY QUE CAMBIAR NOMBRES DE LOS ARREGLOS, SON COMO USADOS POR C++!!!
		{
		//para cada tiempo i usamos en cada uno las posiciones y velocidades de las variables
		//lo del presente y pasado para calcular el los valores del futuro
		xFut=( vxPre*2.0*dt )+( xPas );
		yFut=( vyPre*2.0*dt )+( yPas );
		vxFut=( ( -1.0*c*2.0*dt*DaMagVel(vxPre, vyPre)*vxPre )/(m) )+( vxPas );
		vyFut=( -2.0*dt*( g+( ( c*DaMagVel(vxPre, vyPre)*vyPre )/(m) ) ) )+( vyPas );
		//a(n)adimos estos valores al arreglo con todo y tiempo  

		//a(n)adimos estos valores al .txt dado por los condicionales de arriba con todo y tiempo

		//le ponemos a variables del pasado la informacion de las del presente

		//le ponemos a variables del presente la informacion del futuro
		
		}


	outfile.close();
	return var_xMax;
	}


