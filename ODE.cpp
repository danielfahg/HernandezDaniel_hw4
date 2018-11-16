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

int main()
	{
	cout<<"Punto 2 ODE con el metodo de Leap Frog" <<endl;
	
	//BORRA BLOQUE
	//cout<< cos(3.1416/2.0)<<" y M_PI es "<< M_PI <<endl;
	//cout<< vxIni<<" y "<<vyIni <<endl;

	//PODRIA FUNCIONAR AQUI HACER UN FOR QUE VALLA CAMBIANDO LOS ANGULOS Y SEGUN EL ANGULO O EL
	//INDICE IR CAMBIANDO LO QUE IMPRIME Y GUARDA, REVISAR RAPIDAMENTE SI ASI 
	return 0;	
	}
