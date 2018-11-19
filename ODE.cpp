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

//funciones

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
		
 	DaArchivoYxMax(45.0, 0);
	DaArchivoYxMax(45.0, 1);
	
	DaArchivoYxMax(45.0, 0);
	DaArchivoYxMax(45.0, 1);
	return 0;	
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
	outfile<<"Hola mundo sobrescribe?"<< numAng <<endl;
	outfile<<"si! parece que si:)"<< numAng <<endl;

	outfile.close();

	return var_xMax;
	}


