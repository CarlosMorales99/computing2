#include <iostream>
#include <string.h>
using namespace std;
//Clases
class BARCO
{
	public:
		void leer();
		void mostrar();
	private:
		char nombre[30];
	protected:
		char cond;//n=navegando, a = anclado en puerto
};
class CRUCERO:public BARCO
{
	public:
		void leer();
		void mostrar();
	private:
		int numTuris;
};
class PORTAAVIONES:public BARCO
{
	public:
		void leer();
		void mostrar();
	private:
		int cantAvio;
		int cantTrip;
};
class PESQUERO:public BARCO
{
	public:
		void leer();
		void mostrar();
	private:
		int numPesc;
		char clasif;//a=atunero,p=palangrero,c=cerquero
};
//Funciones globales
void validNat(int &objetivo)
{
	while(!(cin>>objetivo)||(objetivo<0))
	{
		cout<<"\nError: El valor debe ser entero y mayor a 0.\n"
		<<"Ingrese nuevamente su respuesta: ";
		cin.clear();
		cin.ignore();
	}
}
void mensajeEspera()
{
	std::cout<<"\n\nPresione una tecla para continuar . . .";
	std::cin.sync();
	std::cin.get();
}
//Diseño de los metodos de BARCO
void BARCO::leer()
{
	cout<<"Ingrese el nombre del barco: ";
	cin.ignore();
	cin.getline(nombre,30);
	do
	{
		cout<<"Ingrese el estado del barco(n=navegando, a= anclado en puerto): ";
		cin>>cond;
		cond=tolower(cond);
		if(cond!='n'&&cond!='a')
		{
			cout<<"\nERROR: Respuesta Incorrecta.\n";
		}		
	}while(cond!='n'&&cond!='a');
}
void BARCO::mostrar()
{
	cout<<"\n\nNombre="<<nombre;
}
//Diseño de los metodos CRUCERO
void CRUCERO::leer()
{
	BARCO::leer();
	cout<<"Ingrese el numero de turistas: ";
	validNat(numTuris);
}
void CRUCERO::mostrar()
{
	if(cond=='n')
	{
		BARCO::mostrar();
		cout<<"\nTuristas="<<numTuris;
	}
}
//Diseño de los metodos PORTAAVIONES
void PORTAAVIONES::leer()
{
	BARCO::leer();
	cout<<"\nIngrese el numero de aviones: ";
	validNat(cantAvio);
	cout<<"\nIngrese el numero de tripulates: ";
	validNat(cantTrip);	
}
void PORTAAVIONES::mostrar()
{
	if(cond=='n')
	{
	BARCO::mostrar();
	cout<<"\nTripulantes="<<cantTrip;
	}
}
//Diseño de los metodos PESQUERO
void PESQUERO::leer()
{
	BARCO::leer();
	do
	{
		cout<<"Ingrese la clasificacion(a=atunero,p=palangrero,c=cerquero): ";
		cin>>clasif;
		clasif=tolower(clasif);
		if(clasif!='a'&&clasif!='p'&&clasif!='c')
		{
			cout<<"\nERROR: Respuesta Incorrecta. \n";
		}
	}while(clasif!='a'&&clasif!='p'&&clasif!='c');
	cout<<"Ingrese el numero de pescadores: ";
	validNat(numPesc);
}
void PESQUERO::mostrar()
{
	if(cond=='n')
	{
		BARCO::mostrar();
		cout<<"\nPescadores="<<numPesc;
	}
}
//Cuerpo Principal
int main(int argc, char** argv) 
{
	CRUCERO listaCruc[50];
	PORTAAVIONES listaPorta[50];
	PESQUERO listaPesq[50];
	int selec,cantCruc=0,cantPorta=0,cantPesq=0;
	char resp;
	do
	{
		system("cls");
		cout<<"Bievenido al panel de control de embarcaciones de Puerto Cabello!\n"
		<<"Ingrese el numero correspondiente a la accion que desea realizar: \n\n"
		<<"(1)\tIngresar barco/s tipo crucero \n"
		<<"(2)\tIngresar barco/s tipo portaaviones \n"
		<<"(3)\tIngresar barco/s tipo pesquero \n"
		<<"(4)\t***ALERTA DE TIFON, MOSTRAR EMBARCACIONES EN PELIGRO*** \n"
		<<"(0)\tSalir\n\n"
		<<"Seleccion: ";
		validNat(selec);
		if(selec==1)
		{
			do
			{
				listaCruc[cantCruc].leer();
				do
				{
					cout<<"Desea ingresar otro barco?(s/n)";
					cin>>resp;
					resp=tolower(resp);
					if(resp!='s'&&resp!='n')cout<<"\nERROR: Respuesta Incorrecta. \n";
				}while(resp!='s'&&resp!='n');
				cantCruc++;
			}while(resp=='s'&&cantCruc<50);
			mensajeEspera();
		}
		if(selec==2)
		{
			do
			{
				listaPorta[cantPorta].leer();
				do
				{
					cout<<"Desea ingresar otro barco?(s/n)";
					cin>>resp;
					resp=tolower(resp);
					if(resp!='s'&&resp!='n')cout<<"\nERROR: Respuesta Incorrecta. \n";
				}while(resp!='s'&&resp!='n');
				cantPorta++;
			}while(resp=='s'&&cantPorta<50);
			mensajeEspera();
		}
		if(selec==3)
		{
			do
			{
				listaPesq[cantPesq].leer();
				do
				{
					cout<<"Desea ingresar otro barco?(s/n)";
					cin>>resp;
					resp=tolower(resp);
					if(resp!='s'&&resp!='n')cout<<"\nERROR: Respuesta Incorrecta. \n";
				}while(resp!='s'&&resp!='n');
				cantPesq++;
			}while(resp=='s'&&cantPesq<50);
			mensajeEspera();
		}
		if(selec==4)
		{
			if(cantCruc>0||cantPorta>0||cantPesq>0)
			{
				cout<<"Los siguientes barcos estan en peligro: \n";
				for(int i=0;i<cantCruc;i++){
					listaCruc[i].mostrar();
				}
				for(int i=0;i<cantPorta;i++){
					listaPorta[i].mostrar();
				}
				for(int i=0;i<cantPesq;i++){
					listaPesq[i].mostrar();
				}
			}
			else cout<<"\nNo hay barcos registrados, registre algun barco primero.\n";
			mensajeEspera();
		}
		if(selec<0||selec>4)
		{
			cout<<"\nRespuesta Incorrecta\n";
			mensajeEspera();
		}
	}while(selec!=0);
	return 0;
}

