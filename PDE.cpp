#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

float diaBar=10.0;

float k=1.62;

float Cp=820.0;

float rho=2.71;

float Tbar=100.0;

float ladCua=50.0;

float nu=(k)/(Cp*rho);

float tMax=2.0;//segundos, tiempo maximo

float dt=0.00001;//delta t, en segundos

int tieNumInt=(int) (tMax/dt);

int tieNumPun=( (int) (tMax/dt) )+1;

float dx=0.00001;
	
float numIntX=ladCua/dx;

float dy=dx;

float numIntY=ladCua/dy;


//cond frontera fijas
float TConFij=10.0;





int main()
	{
	for(int k=0; k<=tieNumInt; k++)
		{
		for(int i=0; i<=numIntX; i++)
			{
			cout<<"recorremos todas las posiciones horizontales y verticales"<<endl;
			}

		}
	
	return 0;
	}
