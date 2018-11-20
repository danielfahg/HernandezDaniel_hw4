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

float tMax=2.0;//segundos, tiempo maximo

float dt=0.00001;//delta t, en segundos

int tieNumInt=(int) (tMax/dt);

int tieNumPun=( (int) (tMax/dt) )+1;

//funciones

float DaMagVel(float vx, float vy);

float funDer_xUno(float t, float xUno, float xDos, float yUno, float yDos);

float funDer_xDos(float t, float xUno, float xDos, float yUno, float yDos);

float funDer_yUno(float t, float xUno, float xDos, float yUno, float yDos);

float funDer_yDos(float t, float xUno, float xDos, float yUno, float yDos);

float DaArchivoYxMax(float varAngGra, int numAng);

int main()
	{
	cout<<"Punto 2 ODE con el metodo de Runge Kutta de orden 4" <<endl;
	
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
	//cout<<funDer_xDos(1.0, 2.0, 1.0, 4.0, 5.0)<<endl;
	
	//cout<< DaArchivoYxMax(10.0, 0)<< endl;

	float arreXMax[8];
	for(int k=0; k<8; k++)//for(int k=0; k<=8; k++)
		{
		arreXMax[k]=DaArchivoYxMax(angulos[k], k);
		}
	cout<<"La distancia recorrida por el proyectil para el angulo "<< angulos[0]<<" es "<<arreXMax[0]<<endl;

	float distMayor=0.0;
	float angDeDistMayor=0.0;
	for(int l=1; l<8; l++)
		{
		if(arreXMax[l]>=distMayor)
			{
			distMayor=arreXMax[l];
			angDeDistMayor=angulos[l];
			}
		}
	cout<<"La distancia recorrida por el proyectil para el angulo "<< angDeDistMayor<<" es la mayor entre los angulos sin tener en cuenta el de 45.0 grados, esta distancia maxima es "<<distMayor<<endl;

	//BORRA BLOQUE O LINEA
	//cout<<DaMagVel(3.0, 4.0) <<endl;
	//cout<<abs (-100.0)<<endl;
	
	return 0;	
	}

//da la magnitud del vector velocidad dadas las componentes
float DaMagVel(float vx, float vy)
	{
	return pow( (vx*vx)+(vy*vy) , 0.5);
	}

float funDer_xUno(float t, float xUno, float xDos, float yUno, float yDos)
	{
	return xDos;
	}

float funDer_xDos(float t, float xUno, float xDos, float yUno, float yDos)
	{
	return (-1.0*c*DaMagVel(xDos, yDos)*xDos)/(m);
	}

float funDer_yUno(float t, float xUno, float xDos, float yUno, float yDos)
	{
	return yDos;
	}

float funDer_yDos(float t, float xUno, float xDos, float yUno, float yDos)
	{
	return -1.0*( g+( (c*DaMagVel(xDos, yDos)*yDos)/(m) ) );
	}

//primer numero de angulo numAng es 0, hasta 7 el ultimo
float DaArchivoYxMax(float varAngGra, int numAng)
	{
	//cout<<funDer_xDos(1.0, 2.0, 1.0, 4.0, 5.0)<<endl;

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

	//LP dado el angulo varAngGra y el numero de el numAng solucionamos la
	//ecua. diferencial y hallamos la distancia horizontal maxima alcanzada cuando el proyectil toca el piso con altura y=0.0
	float arret[tieNumPun];//float arre_t[tieNumPun];	//float arr_t[tieNumPun];	
	float arrex[tieNumPun];//float arre_x[tieNumPun];//float arr_x[tieNumPun];
	float arrey[tieNumPun];//float arre_y[tieNumPun];//float arr_y[tieNumPun];
	float arrevx[tieNumPun];//float arre_vx[tieNumPun];//float arr_vx[tieNumPun];
	float arrevy[tieNumPun];//float arre_vy[tieNumPun];//float arr_vy[tieNumPun];

	//LP Leap Frog necesita posiciones y velocidades para dos indices del tiempo antes, por eso usamos Backward difference
	//para calcular las posiciones y velocidades en un tiempo antes del inicial, como para tiempo i=-1	
	/*float xPas=xIni-( var_vxIni*dt );
	float yPas=yIni-( var_vyIni*dt );
	float vxPas=var_vxIni+( (c*dt*DaMagVel(var_vxIni, var_vyIni)*var_vxIni)/(m) );
	float vyPas=var_vyIni+( dt*( g+( (c*DaMagVel(var_vxIni, var_vyIni)*var_vyIni)/(m) ) ) );*/

	//LP tiempo i=0:	
	//ponemos en posiciones y velocidades del presente las posiciones y velocidades del tiempo i=0
	float tPre=0.0;	
	float xPre=xIni;
	float yPre=yIni;
	float vxPre=magVelTot*cos(varAng);//float vxPre=var_vxIni;
	float vyPre=var_vyIni;
	//LP las ponemos en .txt 
	outfile<<xPre<<" "<<yPre<<" "<<vxPre<<" "<<vyPre<<" "<<tPre <<endl;
	//LP ponemos esto en los arreglos de posicion y velocidad para al final hallar la x maxima
	arret[0]=0.0;//float arre_t[0]=0.0;//float arr_t[0]=0.0;	
	arrex[0]=xPre;//float arre_x[0]=xPre;//float arr_x[0]=xPre;
	arrey[0]=yPre;//float arre_y[0]=yPre;//float arr_y[0]=yPre;
	arrevx[0]=vxPre;//float arre_vx[0]=vxPre;//float arr_vx[0]=vxPre;
	arrevy[0]=vyPre;//float arre_vy[0]=vyPre;//float arr_vy[0]=vyPre;
	//LP termina lo de tiempo i=0

	//LP para el resto de tiempos i usamos en cada uno las posiciones y velocidades de las variables
	//del presente y pasado para calcularlas, y despues acomodamos el nuevo pasado y presente
	float tFut=0.0;
	float xFut=0.0;
	float yFut=0.0;
	float vxFut=0.0;
	float vyFut=0.0;
	
	//cout<<tPre<< xPre<< vxPre<< yPre<< vyPre<<endl;


	for(int i=1; i<=tieNumInt; i++ )//HAY QUE CAMBIAR NOMBRES DE LOS ARREGLOS, SON COMO USADOS POR C++!!!
		{
		//por runge kutta de orden 4to basadndonos en el repositorio de la clase en https://github.com/ComputoCienciasUniandes/MetodosComputacionales/blob/master/secciones/10.ODEs/SecondOrder_ODE.ipynb		
		//los cuatro kUno sin las *h
		float kUnoDer_xUno=funDer_xUno(tPre, xPre, vxPre, yPre, vyPre);
		float kUnoDer_xDos=funDer_xDos(tPre, xPre, vxPre, yPre, vyPre);
		float kUnoDer_yUno=funDer_yUno(tPre, xPre, vxPre, yPre, vyPre);
		float kUnoDer_yDos=funDer_yDos(tPre, xPre, vxPre, yPre, vyPre);

		//cout<<funDer_xDos(1.0, 2.0, 1.0, 4.0, 5.0)<<endl;
		//cout<<tPre<< xPre<< vxPre<< yPre<< vyPre<<endl;

		//los cuatro kDos sin las *h, paso uno
		//para variables:
		float tUno=tPre+(dt/2.0);	
		float xUno_Uno=xPre+( (dt*kUnoDer_xUno)/(2.0) );
		float xDos_Uno=vxPre+( (dt*kUnoDer_xDos)/(2.0) );
		float yUno_Uno=yPre+( (dt*kUnoDer_yUno)/(2.0) );
		float yDos_Uno=vyPre+( (dt*kUnoDer_yDos)/(2.0) );
		//hallamos los cuatro kDos sin las *h
		float kDosDer_xUno=funDer_xUno(tUno, xUno_Uno, xDos_Uno, yUno_Uno, yDos_Uno);
		float kDosDer_xDos=funDer_xDos(tUno, xUno_Uno, xDos_Uno, yUno_Uno, yDos_Uno);
		float kDosDer_yUno=funDer_yUno(tUno, xUno_Uno, xDos_Uno, yUno_Uno, yDos_Uno);
		float kDosDer_yDos=funDer_yDos(tUno, xUno_Uno, xDos_Uno, yUno_Uno, yDos_Uno);

		//los cuatro kTres sin las *h, paso dos
		//para variables:
		float tDos=tPre+(dt/2.0);
		float xUno_Dos=xPre+( (dt*kDosDer_xUno)/(2.0) );
		float xDos_Dos=vxPre+( (dt*kDosDer_xDos)/(2.0) );
		float yUno_Dos=yPre+( (dt*kDosDer_yUno)/(2.0) );
		float yDos_Dos=vyPre+( (dt*kDosDer_yDos)/(2.0) );
		//hallamos los cuatro kTres sin las *h
		float kTresDer_xUno=funDer_xUno(tDos, xUno_Dos, xDos_Dos, yUno_Dos, yDos_Dos);
		float kTresDer_xDos=funDer_xDos(tDos, xUno_Dos, xDos_Dos, yUno_Dos, yDos_Dos);
		float kTresDer_yUno=funDer_yUno(tDos, xUno_Dos, xDos_Dos, yUno_Dos, yDos_Dos);
		float ktresDer_yDos=funDer_yDos(tDos, xUno_Dos, xDos_Dos, yUno_Dos, yDos_Dos);

		//los cuatro kCuatro sin las *h, paso 3
		//para variables:
		float tTres=tPre+dt;
		float xUno_Tres=xPre+( dt*kTresDer_xUno );
		float xDos_Tres=vxPre+( dt*kTresDer_xDos );
		float yUno_Tres=yPre+( dt*kTresDer_yUno );
		float yDos_Tres=vyPre+( dt*ktresDer_yDos );
		//hallamos los cuatro kCuatro sin las *h
		float kCuatroDer_xUno=funDer_xUno(tTres, xUno_Tres, xDos_Tres, yUno_Tres, yDos_Tres);
		float kCuatroDer_xDos=funDer_xDos(tTres, xUno_Tres, xDos_Tres, yUno_Tres, yDos_Tres);
		float kCuatroDer_yUno=funDer_yUno(tTres, xUno_Tres, xDos_Tres, yUno_Tres, yDos_Tres);
		float kCuatroDer_yDos=funDer_yDos(tTres, xUno_Tres, xDos_Tres, yUno_Tres, yDos_Tres);

		//hallamos promedios y con ellos loa posiciones y velocidades en el siguiente tiempo
		float pro_k_xUno=((1.0)/(6.0))*( kUnoDer_xUno+( 2.0*kDosDer_xUno )+( 2.0*kTresDer_xUno )+kCuatroDer_xUno );
		float pro_k_xDos=((1.0)/(6.0))*( kUnoDer_xDos+( 2.0*kDosDer_xDos )+( 2.0*kTresDer_xDos )+kCuatroDer_xDos );
		float pro_k_yUno=((1.0)/(6.0))*( kUnoDer_yUno+( 2.0*kDosDer_yUno )+( 2.0*kTresDer_yUno )+kCuatroDer_yUno );
		float pro_k_yDos=((1.0)/(6.0))*( kUnoDer_yDos+( 2.0*kDosDer_yDos )+( 2.0*ktresDer_yDos )+kCuatroDer_yDos );
		
		//cout<< kUnoDer_xUno<<endl;

		//asignamos los valores de posiciones y velocidades en el siguiente tiempo
		tFut=tPre+dt;
		xFut=xPre+( dt*pro_k_xUno );
		vxFut=vxPre+( dt*pro_k_xDos );//yFut=yPre+( dt*pro_k_xDos );
		yFut=yPre+( dt*pro_k_yUno );//vxFut=vxPre+( dt*pro_k_yUno );
		vyFut=vyPre+( dt*pro_k_yDos );
		
		//LF para cada tiempo i usamos en cada uno las posiciones y velocidades de las variables
		//lo del presente y pasado para calcular el los valores del futuro
		/*tFut=( (float) (i) )*dt;		
		xFut=( vxPre*2.0*dt )+( xPas );
		yFut=( vyPre*2.0*dt )+( yPas );
		vxFut=( ( -1.0*c*2.0*dt*DaMagVel(vxPre, vyPre)*vxPre )/(m) )+( vxPas );
		vyFut=( -2.0*dt*( g+( ( c*DaMagVel(vxPre, vyPre)*vyPre )/(m) ) ) )+( vyPas );*/
		
		//LF a(n)adimos estos valores al arreglo con todo y tiempo
		arret[i]=tFut;
		arrex[i]=xFut; 
		arrey[i]=yFut;
		arrevx[i]=vxFut;
		arrevy[i]=vyFut;
		
		//LF a(n)adimos estos valores al .txt dado por los condicionales de arriba con todo y tiempo
		outfile<<xFut<<" "<<yFut<<" "<<vxFut<<" "<<vyFut<<" "<<arret[i] <<endl;

		//LF le ponemos a variables del pasado la informacion de las del presente
		/*xPas=xPre;
		yPas=yPre;
		vxPas=vxPre;
		vyPas=vyPre;*/

		//LF le ponemos a variables del presente la informacion del futuro 
		xPre=xFut;
		yPre=yFut;
		vxPre=vxFut;
		vyPre=vyFut;
		
		}

	int ind_xMax=1;
	float yMin=1000.0;
	float xPeque=0.1;

	for(int j=0; j<=tieNumInt; j++)
		{
		if( ( abs (arrey[j]) )<=( abs (yMin) ) && ( (arrex[j])>=xPeque ) )
			{
			var_xMax=arrex[j];
			yMin=arrey[j];
			ind_xMax=j;
			}
		}

	outfile.close();
	return var_xMax;
	}


