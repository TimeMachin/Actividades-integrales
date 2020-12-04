#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
#include "BST.h"


// O(n)
// Convierte la ip en un entero largo, ademas de incluir el numero de veces que esta presente la ip en el archivo
long long ip2Long(string ip, int times){
	int idX = 0;
	long long datoFinal = 0;
	int dato = 0;
	while(idX < ip.size()){
		if(ip[idX] != '.' && ip[idX] != ':'){
			dato = dato*10 + ip[idX]-'0';
		}
		else{
			datoFinal = datoFinal*1000 + dato;
			dato = 0;
		}
		idX++;
	}
	datoFinal = times*100000 + datoFinal;
	return datoFinal;
}

// O(n)
// A partir de la linea obtenida del archivo, esta funcion regresa solo la ip de esa linea
string ipFormato(string ip){
	int cont = 0;
	int cont2 = 0;
	string resultado = "";
	while(cont != 4){
		if(ip[cont2] == ':' && cont == 3){
			return resultado;
		}
		if(ip[cont2] == ' '){
			cont++;
		}
		else if(cont == 3){
			resultado += ip[cont2];
		}
		cont2++;
	}
}

int main(){
    BST arbol;
    char linea[90];
    ifstream fe("bitacoraOrdenada.txt");
	string prev = "";
	int cont = 0;
	int contAux = 0;
	Info structAux;
	while(!fe.eof()){
		fe.getline(linea, 90);
        if(contAux == 0){
			prev = linea;
			contAux++;
		}
		if(ipFormato(prev) == ipFormato(linea)){
			cont++;
		}
		else{
			structAux.entryTimes = cont;
			structAux.ip = ipFormato(prev);
			structAux.key = ip2Long(structAux.ip, cont);
			arbol.add(structAux);
			prev = linea;
			cont = 1;
		}
	}
	structAux.entryTimes = cont;
	structAux.ip = ipFormato(prev);
	structAux.key = ip2Long(structAux.ip, cont);
	arbol.add(structAux);
    fe.close();
	arbol.print();
	arbol.printMax();
    return 0;
}