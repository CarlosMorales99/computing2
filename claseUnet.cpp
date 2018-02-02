#include <iostream>
#include <string.h>
#include <ctype.h>
class UNET
{
    public:
        void leer();
        void mostrar();
    	void darCedula(char [12]);
	private:
        char id[10],nombre[12],apellido[12];
};
class ESTUDIANTE:public UNET
{
    public:
        void leer_e();
        void mostrar_e();
        void buscar(char[12]);
    private:
        float indice;
};
class EMPLEADO:public UNET
{
	public:
		void leer_emp();
		void mostrar_emp();
		void buscar(char[12]);
	private:
		float sueldo;
};
//Diseño de los metodos UNET
void UNET::leer()
{
    std::cout<<"Dar cedula: ";std::cin>>id;
    std::cout<<"Dar nombre: ";std::cin>>nombre;
    std::cout<<"Dar apellido: ";std::cin>>apellido;
}
void UNET::mostrar()
{
    std::cout<<id<<"\t\t"<<nombre<<"\t\t"<<apellido<<"\t\t";
}
void UNET::darCedula(char ci[12])
{
	strcpy(ci,id);
}
//Diseño de los metodos ESTUDIANTE
void ESTUDIANTE::leer_e()
{
    leer();
    do
	{
	std::cout<<"Dar indice: ";
	std::cin>>indice;
	if(!(indice>=1&&indice<=9))std::cout<<"\nERROR: El indice debe estar entre 1.0 y 9.0.\n";
	}while(!(indice>=1&&indice<=9));
}
void ESTUDIANTE::mostrar_e()
{
    mostrar();
    std::cout<<indice<<"\n";
}
void ESTUDIANTE::buscar(char cedulaPrueba[12])
{
	char cedulaReg[12];
	darCedula(cedulaReg);
	if(strcmp(cedulaPrueba,cedulaReg)==0) mostrar_e();
}
//Diseño de los metodos EMPLEADO
void EMPLEADO::leer_emp()
{
	leer();
	do
	{
	std::cout<<"Dar sueldo: ";
	std::cin>>sueldo;
	if(!(sueldo>0))std::cout<<"\nERROR: El sueldo debe ser mayor a 0.\n";
	}while(!(sueldo>0));
}
void EMPLEADO::mostrar_emp()
{
	mostrar();
	std::cout<<sueldo<<"\n";
}
void EMPLEADO::buscar(char cedulaPrueba[12])
{
	char cedulaReg[12];
	darCedula(cedulaReg);
	if(strcmp(cedulaPrueba,cedulaReg)==0) mostrar_emp();
}

//Cuerpo Principal
int main()
{
	int decision,estCarg=0,empCarg=0;
	ESTUDIANTE p[10];
	EMPLEADO lista[10];
	char cedulaBusq[12];
	do
	{
		do
		{
			system("cls");
			std::cout<<"Registrar y listar estudiante/s (1)\n"
			<<"Registrar y listar empleado/s (2)\n"
			<<"Buscar cedula (3)\n"
			<<"Salir (0)\n"
			<<"Bienvenido al portal UNET\n"
			<<"Escriba el numero correspondiente a la accion que desea realizar: ";
			std::cin>>decision;
			if(decision<0||decision>3){
				std::cout<<"\n\nERROR: Respuesta invalida, presione Enter para continuar . . .";
				std::cin.sync();
				std::cin.get();
			}
		}while(decision<0||decision>3);
		std::cout<<std::endl<<std::endl;
		if(decision==1)
		{
		    char resp;
		    do
		    {
		        p[estCarg].leer_e();
	   	    	std::cout<<"Existe otro estudiante(S/N): ";
	        	std::cin>>resp;
	        	resp=toupper(resp);
	        	estCarg++;
	    	}while(resp=='S'&&estCarg<10);
	    	system("cls");
	    	std::cout<<"\tListado de Estudiantes\n";
	    	std::cout<<"Cedula\t\tNombre\t\tApellido\tIndice\n";
	    	for(int k=0;k<estCarg;k++)
	        p[k].mostrar_e();	
			std::cout<<"\n\nPresione Enter para continuar . . .";
			std::cin.sync();
			std::cin.get();
		}
		if(decision==2)
		{
		    char cond;
		    do
		    {
		        lista[empCarg].leer_emp();
		        std::cout<<"Existe otro empleado?(S/N): ";
		        std::cin>>cond;
		        cond=toupper(cond);
		        empCarg++;
		    }while(cond=='S'&&empCarg<10);
		    system("cls");
		    std::cout<<"\tListado de Empleados\n";
		    std::cout<<"Cedula\t\tNombre\t\tApellido\tSueldo\n";
		    for(int k=0;k<empCarg;k++)
	        lista[k].mostrar_emp();		
			std::cout<<"\n\nPresione Enter para continuar . . .";
			std::cin.sync();
			std::cin.get();
		}
		if(decision==3)
		{	
			if(estCarg>0||empCarg>0)
			{
				std::cout<<"Dar cedula a buscar: ";std::cin>>cedulaBusq;
				std::cout<<"\nCoincidencias: \n";
				std::cout<<"\tEstudiantes:\n";
				std::cout<<"Cedula\t\tNombre\t\tApellido\tIndice\n";
				for(int i=0;i<estCarg;i++)
					p[i].buscar(cedulaBusq);		
				std::cout<<"\n\tEmpleados:\n";
				std::cout<<"Cedula\t\tNombre\t\tApellido\tSueldo\n";
				for(int i=0;i<empCarg;i++)
					lista[i].buscar(cedulaBusq);
			}
			else std::cout<<"\nERROR: Cargue estudiantes o empleados primero.\n\n";
			std::cout<<"\n\nPresione Enter para continuar . . .";
			std::cin.sync();
			std::cin.get();
		}
	}while(decision!=0);
    return 0;
}
