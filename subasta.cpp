//Ejercicio en clase 31-01-2018
#include <iostream>
#include <ctype.h>
using namespace std;
class CASA
{
	public:
		void cargar();
		void mayorOferta();
		float ganancia();
	private:
		int id[50];
		float puja[50]; 
		int nPujas;
		int ganador;
};
void CASA::cargar()	
{
	char resp;
	int nPujas=0;
	do
	{
		do
		{
			cout<<"Dar puja del comprador "<<nPujas+1<<" en bsf: ";
			cin>>puja[nPujas];
			if(puja[nPujas]<1250000)cout<<"Puja demasiado baja, el minimo es 1250000 bsf\n";
		}while(puja[nPujas]<1250000);
		cout<<"\nDar cedula del comprador "<<nPujas+1<<": ";
		cin>>id[nPujas];
		nPujas++;
		cout<<"\nDesea ingresar otra puja?";
		cin>>resp;
		resp=toupper(resp);
	}while(resp=='S'&&nPujas<50);
}
void CASA::mayorOferta()	
{
	int mayorOferta=0;
	for(int i=0;i<nPujas;i++)
	{
		if(puja[i]>mayorOferta)
		{
			mayorOferta=puja[i];
			ganador=i;	
		}
	}
}
float CASA::ganancia()
{
	return puja[ganador];
}
int main()
{
	int nCasas;
	float acum=0;
	CASA lista[100];
	cout<<"Ingrese numero de casas a subastar: ";
	cin>>nCasas;
	for(int i=0;i<nCasas;i++)
	{
		lista[i].cargar();
		lista[i].mayorOferta();
		acum+=lista[i].ganancia();
	}
	cout<<"\nGanancia total: "<<acum;
	cout<<"\n Presione Enter para finalizar.";
    cin.sync();
    cin.ignore();
	return 0;
}


