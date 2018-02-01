//---------------------------------------------------------------------------
#include <iostream>
#include <string.h>
#include <ctype.h>
class UNET
{
    public:
        void leer();
        void mostrar();
    private:
        char id[10],nombre[12],apellido[12];
};
class ESTUDIANTE:public UNET
{
    public:
        void leer_e();
        void mostrar_e();
    private:
        float indice;
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
    std::cout<<id<<"\t"<<nombre<<"\t"<<apellido<<"\t\t";
}
//Diseño de los metodos ESTUDIANTE
void ESTUDIANTE::leer_e()
{
    leer();
    std::cout<<"Dar indice:";std::cin>>indice;
}
void ESTUDIANTE::mostrar_e()
{
    mostrar();
    std::cout<<indice<<"\n";
}
//Cuerpo Principal
int main()
{
    ESTUDIANTE p[10];
    char resp;
    int ce=0;
    do
    {
        p[ce].leer_e();
        std::cout<<"Existe otro estudiante(S/N): ";
        std::cin>>resp;
        resp=toupper(resp);
        ce++;
    }while(resp=='S'&&ce<10);
    std::system("cls");
    std::cout<<"\tListado de Estudiantes\n";
    std::cout<<"Cedula\tNombre\tApellido\tIndice\n";
    for(int k=0;k<ce;k++)
        p[k].mostrar_e();

    std::cout<<"\n\nPresione una tecla para continuar . . .";
    std::cin.sync();
    std::cin.get();
    return 0;
}


//---------------------------------------------------------------------------
