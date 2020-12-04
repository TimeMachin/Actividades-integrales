// Descripcion: Creacion de tabla de hash y busqueda de un elemento en base a una clave(ip)
// Autor: Pedro Rodriguez Trevino A01235849, Jose Guadalupe Mireles Rosales A01235880
// Fecha: 28/11/2020
#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
using namespace std;

struct ipStruct{
    int accesos = 0;
    vector<string> fallaRazon;
    vector<string> fechas;
};


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

// O(n)
// Muy parecida a ipFormato, a partir de la linea leida del archvivo de texto, la funcion obtiene la fecha y la razon de falla del acceso de la ip y las guarda 
// en su respectivo vector
void fillStrcut(ipStruct &object, string line){
	object.accesos++;
	int cont = 0;
	int cont2 = 0;
	string fecha = "";
	string razonFalla = "";
	while(cont2 < line.size()){
		if(cont < 3){
			fecha += line[cont2];
		}
		if(cont >= 4){
			razonFalla += line[cont2];
		}
		if(line[cont2] == ' '){
			cont++;
		}
		cont2++;
	}
	object.fechas.push_back(fecha);
	object.fallaRazon.push_back(razonFalla);
}

int main(){
	unordered_map<string, ipStruct> mapa; 
	char linea[90];
    ifstream fe("bitacora.txt");
	while(!fe.eof()){
		fe.getline(linea, 90);
		fillStrcut(mapa[ipFormato(linea)], linea);
	}
	fe.close();
	string ip = "";
	cout << "Ingrese ip a buscar: ";
	cin >> ip;
	auto x = mapa.find(ip);
	if(x == mapa.end()){
		cout << "La ip no es parte del mapa" << endl;
	}
	else{
		cout << "\nLa ip " << x->first << " contiene las siguientes caracteristicas: " << endl;
		cout << "La ip tuvo un total de " << x->second.accesos << " de accesos" << endl;
		cout << "Fechas de ingreso: " << x->second.fechas[0] << "\tRazones de fallo: " << x->second.fallaRazon[0] << endl;
		for(int i = 1; i < x->second.fechas.size(); i++){
			cout << "\t\t   " << x->second.fechas[i] << "\t\t\t  " << x->second.fallaRazon[i] << endl;
		}
	}
	system("pause");
    return 0;
}
