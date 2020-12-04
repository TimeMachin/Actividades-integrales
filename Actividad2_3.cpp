// Descripcion: Actividad Integral estructura de datos lineales
// Autor: Pedro Rodriguez Trevino A01235849
// Fecha: 10/10/2020

#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"
using namespace std;

// O(n)
// Crea y devuelve un string que es un identificador de la ip de entrada
string ipFormato(string ip){
	int cont = 0;
	int cont2 = 0;
	string resultado = "";
	while(cont != 4){
		if(ip[cont2] == ' '){
			cont++;
		}
		else if(cont == 3){
			resultado += ip[cont2];
		}
		cont2++;
	}
	return resultado;
}

// O(n)
// Convierte la ip a un string
long long ip2Long(string ip){
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
	datoFinal = datoFinal*10000 + dato;
	return datoFinal;
}

// O(n)
// Escribe el archivo de texto
void write(DoubleLinkedList &lista){
    Node *curr = lista.getHead();
    ofstream salida("bitacora_ordenada.txt");
    for(int i = 0; i < lista.getSize(); i++){
        salida << curr->getData().contenido << endl;
        curr = curr->getNext();
    }
    salida.close();
    cout << "Archivo creado" << endl;
}



int main(){
	DoubleLinkedList lista;
	Info data;
	char linea[90];
    ifstream fe("bitacora.txt");
	while(!fe.eof()){
		fe.getline(linea, 90);
		data.contenido = linea;
		data.key = ip2Long(ipFormato(linea));
		lista.addLast(data);
	}
	fe.close();
	lista.sort();
	write(lista);
	cout << "Tam de la lista: " << lista.getSize() << endl;
	//lista.print();
    long long iKey, fKey;
    string inicio, fin;
	cout << "\t |Busqueda| \n" << "Ingresa la ip de inicio (ej: 102.1.021.1456): ";
    cin >> inicio;
    cout << "Ingresa la ip final: ";
    cin >> fin;
    iKey = ip2Long(inicio);
    fKey = ip2Long(fin);
    lista.print(iKey, fKey);

	return 0;
}
