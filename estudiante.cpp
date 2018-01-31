#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class ESTUDIANTE
{
	public:
		void cargar();
		void promedio();
		void listar();
	private:
		char nom[12];
		int notas[3];
		float prom;
};
void ESTUDIANTE::cargar()
{
	std::cout<<"Ingrese el nombre: ";
	std::cin>>nom;
	for(int i =0;i<3;i++)
	{
		do{
			std::cout<<"Ingrese nota "<<i+1<<": ";
			std::cin>>notas[i];
		}while(notas[i]<1||notas[i]>9);
	}
}
void ESTUDIANTE::promedio()
{
	prom=0;
	for(int k=0;k<3;k++)
	{
		prom+=notas[k];
	}
	prom/=3;
}
void ESTUDIANTE::listar()
{
	std::cout<<nom<<"\t";
	for(int j=0;j<3;j++)
	{
		std::cout<<notas[j]<<" ";
	}
	std::cout<<"\t"<<prom<<std::endl;
}
int main(int argc, char** argv) 
{
	int cantAlumnos;
	ESTUDIANTE lista[100];
	std::cout<<"Cuantos alumnos va a registrar?(MAX 100): ";
	std::cin>>cantAlumnos;
	for(int i=0;i<cantAlumnos;i++)
	{
		lista[i].cargar();
		lista[i].promedio();
	}
	std::cout<<"Nombre\tNotas\tPromedio\n";
	for(int k=0;k<cantAlumnos;k++)
	{
		lista[k].listar();
	
	}
	std::cout<<"\nPresione una tecla para continuar . . .";
	std::cin.sync();
	std::cin.get();
	return 0;
}

