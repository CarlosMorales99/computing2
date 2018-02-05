//Ejemplo clase 02-02-18 Herencia multiple

#include <iostream>
#include <ctype.h>
#include <conio.h>

using namespace std;

//CLASES

class TARJETA{
	public:
		void leer();
		void mostrar();
	private:
		char cpu[10];
		float velocidad;
};

class MONITOR{
	public:
		void leer();
		void mostrar();
	private:
		char marca[10];
		char resolucion[12];
};

class COMPUTADORA:public TARJETA, public MONITOR{
	public:
		void leer();
		void mostrar();
	private:
		float precio;
};
class USUARIO:public COMPUTADORA{
        public:
                void leer();
                void mostrar();
        private:
                char usuario[20];
                char clave[20];
};
//Diseño de los metodos tarjeta
void TARJETA::leer(){
	cout << "-Datos de la tarjeta-" <<endl;
	cout << "CPU: ";
	cin >> cpu;
	cout << "Velocidad: ";
	while(!(cin >> velocidad)){
                cin.clear();
                cin.ignore();
                cout<<"Error, ingrese solo valores numericos: ";
        }
	cout << endl;
}

void TARJETA::mostrar(){
	cout<<"CPU="<<cpu<<endl<<"Velocidad="
		<<velocidad<<endl;
}
//Diseño de los metodos monitor
void MONITOR::leer(){
	cout<<"\n-Datos del monitor-"<<endl;
	cout<<"Resolucion: ";
	cin>>resolucion;
	cout<<"Marca: ";
	cin>>marca;
}
void MONITOR::mostrar(){
	cout<<"Resolucion="<<resolucion<<endl<<"Marca="
		<<marca<<endl;
}
//Diseño de los metodos computadora
void COMPUTADORA::leer(){
	cout<<"-Datos de la computadora-"<<endl;
	cout<<"Precio: ";
	while(!(cin >> precio)){
                cin.clear();
                cin.ignore();
                cout<<"Error, ingrese solo valores numericos: ";
        }
	TARJETA::leer();
	MONITOR::leer();
}
void COMPUTADORA::mostrar(){
	cout<<"Precio="<<precio<<endl;
	TARJETA::mostrar();
	MONITOR::mostrar();
}
//Diseño de los metodos USUARIO
void USUARIO::leer(){
        cout<<"Ingrese usuario: "; cin>>usuario;
        cout<<"Ingrese clave: "; cin>>clave;
        COMPUTADORA::leer();
}
void USUARIO::mostrar(){
        cout<<"Usuario="<<usuario<<endl;
        cout<<"Clave="<<clave<<endl;
        COMPUTADORA::mostrar();
}
//CUERPO PRINCIPAL
int main(){
	USUARIO unet[15];
	char resp;
	int cc=0;
	do{
		unet[cc].leer();
		cout<<"Procesar otro usuario?(S/N):";
		cin>>resp;
		resp=toupper(resp);
		cin.get();
		cc++;
	}while(resp=='S'&&cc<15);
	system("cls");
	cout<<"\tListado de usuarios procesados\n"<<endl;
	for (int p=0;p<cc;p++){
		cout<<"Usuarios No."<<p+1<<endl;
		unet[p].mostrar();
		cout<<endl;
	}
	cout<<"\nFin del programa, presione Enter para cerrar . . .";
	cin.get();
}
