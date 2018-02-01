#include <iostream>
#include <string.h>
#include <ctype.h>
class RECETA
{
	public:
		void registrar();
		void busquedaRec(char [50],char);
		float devolverCalorias();
		void mostrarSinIngredientes();
	private:
		char nombre[50], origen[50];
		char tipo; //entrada= e, principal = p, postre = d
		int cantIng;//Numero de ingredientes diferentes que posee la receta
		float cantidad[20],calorias[20];//Ingredientes
		char nombreIng[20][50];//Ingredientes
		float caloriasTot;
};
void RECETA::registrar()
{
	caloriasTot=0;
	std::cout<<"\n\nDar nombre de la receta: ";
	std::cin.sync();
	std::cin.getline(nombre,50);
	std::cout<<"Dar pais de origen de la receta: ";
	std::cin.sync();
	std::cin.getline(origen,50);
	do
	{
		std::cout<<"Dar tipo de plato(entrada=e,principal=p,postre=d): ";
		std::cin.sync();
		std::cin>>tipo;
		tipo=tolower(tipo);
		if(tipo!='e'&&tipo!='p'&&tipo!='d')	std::cout<<"Ingrese el caracter correspondiente a su tipo de plato correcto(e,p,d).";
	}while(tipo!='e'&&tipo!='p'&&tipo!='d');
	std::cout<<"Dar el numero de ingredientes posee la receta: ";
	std::cin>>cantIng;
	for(int i=0;i<cantIng;i++)
	{
		std::cout<<"\nINGREDIENTE "<<i+1<<":\n";
		std::cout<<"Dar nombre del ingrediente: ";
		std::cin.sync();
		std::cin.getline(nombreIng[i],50);
		std::cout<<"Dar cantidad del ingrediente: ";
		std::cin>>cantidad[i];
		std::cout<<"Dar cantidad de calorias del ingrediente: ";
		std::cin>>calorias[i];
		caloriasTot+=calorias[i]*cantidad[i];
	}
}
void RECETA::busquedaRec(char pais[50],char plato)
{
	if(strcmp(pais,origen)==0&&plato==tipo)
	{
		std::cout<<"\nNombre: "<<nombre;
		std::cout<<"\nIngredientes: \n";
		for(int k=0;k<cantIng;k++)
		{
			std::cout<<cantidad[k]<<" "<<nombreIng[k]<<", "<<calorias[k]<<" Cal\n";
		}
	}

}

float RECETA::devolverCalorias()
{
	return caloriasTot;
}
void RECETA::mostrarSinIngredientes()
{
	std::cout<<"\nNombre: "<<nombre;
	std::cout<<"\nPais: "<<origen;
	std::cout<<"\nTipo de plato: "<<tipo;
}
int main(int argc, char** argv)
{
	RECETA lista[100];
	int nRecetas;
	char pais[50],tipoPlato;
	int recMayCalorias;
	float mayCantCalorias;
	std::cout<<"Cuantas recetas desea registrar?: ";
	std::cin>>nRecetas;
	for(int i=0;i<nRecetas;i++)
	{
		lista[i].registrar();
	}

	std::cout<<"\n\nDar pais a buscar: ";
	std::cin.sync();
	std::cin.getline(pais,50);
	do
	{
		std::cout<<"Dar tipo de plato a buscar(entrada=e,principal=p,postre=d): ";
		std::cin.sync();
		std::cin>>tipoPlato;
		tipoPlato=tolower(tipoPlato);
		if(tipoPlato!='e'&&tipoPlato!='p'&&tipoPlato!='d')std::cout<<"Ingrese el caracter correspondiente a su tipo de plato correcto(e,p,d).";
	}while(tipoPlato!='e'&&tipoPlato!='p'&&tipoPlato!='d');
	std::cout<<"\nRecetas que coinciden: \n";
	for(int i=0;i<nRecetas;i++)
	{
		lista[i].busquedaRec(pais,tipoPlato);
	}

	for(int i=0;i<nRecetas;i++)
	{
		if(i==0||lista[i].devolverCalorias()>mayCantCalorias)
		{
			mayCantCalorias=lista[i].devolverCalorias();
			recMayCalorias=i;
		}
	}
	std::cout<<"\n\nEl tipo de plato con mayor valor calorico es: \n";
	lista[recMayCalorias].mostrarSinIngredientes();

	std::cout<<"\n\nPresione una tecla para continuar . . .";
	std::cin.sync();
	std::cin.get();
	return 0;
}
