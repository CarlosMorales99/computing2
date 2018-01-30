#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medallero {
	int oro,plata,bronce;
};
struct perfil_Asoc{
	char nombre_Univ[50];
	struct medallero total_Med;
	int atletas;
	float monto_Insc;
};
void cargar(struct perfil_Asoc asociaciones[18]){
	int i;
	for(i=0;i<18;i++){
		printf("\n\nIngrese el nombre de la universidad: ");
		fflush(stdin);
		gets(asociaciones[i].nombre_Univ);
		printf("Ingrese la cantidad de medallas de oro ganadas: ");
		fflush(stdin);
		scanf("%d",&asociaciones[i].total_Med.oro);
		printf("Ingrese la cantidad de medallas de plata ganadas: ");
		fflush(stdin);
		scanf("%d",&asociaciones[i].total_Med.plata);
		printf("Ingrese la cantidad de medallas de bronce ganadas: ");
		fflush(stdin);
		scanf("%d",&asociaciones[i].total_Med.bronce);
		printf("Ingrese el total de atletas participantes: ");
		fflush(stdin);
		scanf("%d",&asociaciones[i].atletas);
		printf("Ingrese el monto en bs. de la inscripcion: ");
		fflush(stdin);
		scanf("%f",&asociaciones[i].monto_Insc);
	}
}
void ganador(struct perfil_Asoc asociaciones[18], struct perfil_Asoc *asoc_Ganadora){
	int i, mayor_Oro=0, pos_Mayor_Oro;
	for(i=0;i<18;i++){
		if(asociaciones[i].total_Med.oro>mayor_Oro){
			mayor_Oro=asociaciones[i].total_Med.oro;
			pos_Mayor_Oro=i;
		}
	}
	*asoc_Ganadora=asociaciones[pos_Mayor_Oro];
	
}
int puntaje(struct perfil_Asoc asociacion){

		return (asociacion.total_Med.oro*15 + asociacion.total_Med.plata*10 + asociacion.total_Med.bronce*5);
}
int busqueda_Puntaje(struct perfil_Asoc asociaciones[18], char nombre[50]){
	int i=0;
	while(strcmp(asociaciones[i].nombre_Univ,nombre)&&i<18){
		i++;
	}
	if(i<18){
		return puntaje(asociaciones[i]);
	}
	else{
		printf("ERROR: ESA UNIVERSIDAD NO ESTA REGISTRADA\n");
		return -1;
	}
}
void listado(struct perfil_Asoc asociaciones[18]){
	int i;
	printf("Nombre de la Universidad\tPuntos Obtenidos\tRelacion monto/atletas\n");
	for (i=0;i<18;i++){
		if((asociaciones[i].total_Med.oro==0) && (asociaciones[i].atletas>100)){
			printf("%s",asociaciones[i].nombre_Univ);
			printf("\t%d",puntaje(asociaciones[i])); 
			printf("\t%f\n",asociaciones[i].monto_Insc / asociaciones[i].atletas);
		}
	}
}

int main(int argc, char *argv[]) {
	struct perfil_Asoc asoc_Prof[18],asoc_Gan;
	char nombre_Busqueda[50];
	
	cargar(asoc_Prof);
	ganador(asoc_Prof,&asoc_Gan);
	printf("La universidad ganadora fue: %s, con %d participantes\n",asoc_Gan.nombre_Univ,asoc_Gan.atletas);
	printf("Ingrese una universidad a buscar: ");
	fflush(stdin);
	gets(nombre_Busqueda);
	printf("La universidad buscada tuvo un puntaje de %d\n", busqueda_Puntaje(asoc_Prof,nombre_Busqueda));
	listado(asoc_Prof);
	
	
	return 0;
}
