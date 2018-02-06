#include <iostream>
#include <string.h>
using namespace std;
void validFloat(float &objetivo)
{
    while(!(cin>>objetivo))
    {
        cout<<"\nError, debe ingresar un valor numerico.\n";
        cin.clear();
        cin.ignore();
    }
}
void validInt(int &objetivo)
{
    while(!(cin>>objetivo))
    {
        cout<<"\nError, debe ingresar un valor numerico.\n";
        cin.clear();
        cin.ignore();
    }
}
//Clase
class Tapista
{
	public:
        Tapista();
        Tapista(char *,char*,char*);
        void iAMayASiete(int );
        float mayPasante(int, int &, float);
        void mostrar();
	private:
        char cedula[12], nombre[20], titulo[50];
        int carrera;//1=Electronica, 2=Mecanica
        int tipo; //1=Tesis, 2=Pasantias
        float indice;
};
//Diseño de los metodos de Tapista

void Tapista::mostrar(){
		cout<<"\nNombre="<<nombre<<"\nCedula="<<cedula<<"\nTitulo="<<titulo<<"\nEspecialidad=";
        if(carrera==1)cout<<"Electronica";
        else cout<<"Mecanica\n";
        cout<<"\nTipo de trabajo=";
        if(tipo==1)cout<<"Tesis";
        else cout<<"Pasantias";
        cout<<"\nIndice="<<indice<<"\n";
}

Tapista::Tapista(char *ced,char *nomb, char *titu)
{
    strcpy(cedula,ced);
    strcpy(nombre,nomb);
    strcpy(titulo,titu);
    do
    {
        cout<<"Ingrese la especialidad del tapista(1=Electronica, 2=Mecanica): ";
        validInt(carrera);
        if(carrera!=1&&carrera!=2)cout<<"\nOpcion Invalida.\n";
    }while(carrera!=1&&carrera!=2);
    do
    {
        cout<<"Ingrese el tipo de tap(1= Tesis,2= Pasantia): ";
        validInt(tipo);
        if(tipo!=1&&tipo!=2) cout<<"\nOpcion Invalida. \n";
    }while(tipo!=1&&tipo!=2);
    do
    {
        cout<<"Ingrese el indice academico: ";
        validFloat(indice);
        if(indice<1.0||indice>9.0) cout<<"\nError, el indice debe ser mayor a 1.0 y menor a 9.0";
     }while(indice<1.0||indice>9.0);
}
Tapista::Tapista(){
}
void Tapista::iAMayASiete(int selec)
{
    if(tipo==1 && indice>7.0 && carrera==selec )
    {
        mostrar();
    }
}

float Tapista::mayPasante(int p, int &aux, float ind){
	if (tipo==2 && indice>ind){
		aux = p;
		return indice;
	}
}

//Cuerpo Principal
int main()
{
    Tapista lista[20];
    int cantTap=0,carr,aux;	//Aux = mayor promedio
    char nombre[20],cedula[12],titulo[50];
    char resp;
    float mayInd;
    do
    {
        cout<<"Ingrese la cedula del tapista: ";
        cin.sync();
        cin.getline(cedula,12);
        cout<<"Ingrese el nombre del tapista: ";
        cin.sync();
        cin.getline(nombre,20);
        cout<<"Ingrese el titulo del trabajo: ";
        cin.sync();
        cin.getline(titulo,50);
        Tapista ind(cedula,nombre,titulo);
        lista[cantTap]=ind;
        do
        {
            cout<<"\nDesea ingresar otro tapista?(S/N): ";
            cin>>resp;
            resp=toupper(resp);
            if(resp!='S'&&resp!='N')cout<<"\nCaracter Invalido.\n";
        }while(resp!='S'&&resp!='N');
    cantTap++;
    }while(resp=='S'&&cantTap<50);
    do
    {
        cout<<"Ingrese la especialidad a consultar(1=Electronica, 2=Mecanica): ";
        validInt(carr);
        if(carr!=1&&carr!=2)cout<<"\nOpcion Invalida.\n";
    }while(carr!=1&&carr!=2);
    for(int i=0;i<cantTap;i++)
    {
        lista[i].iAMayASiete(carr);
    }
    for (int j=0;j<cantTap;j++){
    	mayInd = lista[j].mayPasante(j,aux,mayInd);
	}
	cout<<"El tapista pasante con mayor indice academico fue: "<<endl;
	lista[aux].mostrar();
    cout<<"Presione Enter para continuar...";
	cin.sync();
	cin.get();
	return 0;
}
