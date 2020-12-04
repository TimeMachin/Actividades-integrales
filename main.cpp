#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct nodo{
    int idNodo;
    int outDegree;
    string ip;
};

// O(n)
// Por medio de esta funcion, obtenemos las 2 ip's contenidas en los strings del archivo, regresamos ipRemitente e ipDestinatario
string ipFormato(string linea, string &ip1, string &ip2){
	int cont = 0;
	while(cont != 6){
		if(linea[0] == ' ' || (cont == 3 && linea[0] == ':') || cont == 5 && linea[0] == ':'){
			cont++;
		}
		else if(cont == 3){
			ip1 += linea[0];
		}
		else if(cont ==5){
            ip2 += linea[0];
		}
        linea.erase(0,1);
	}
	return (ip1, ip2);
}

int main(){
    // Valores y variables iniciales
    int nodos = 0;
    int arcos = 0;
    ifstream fe("bitacora.txt");
    fe >> nodos >> arcos;
    unordered_map<string, int> numNodo;
    string ip1 = "";
    string ip2 = "";
    char linea[100];
    vector<vector<int>> listaAdyacencia(nodos);
    vector<nodo> all(nodos);
    fe.getline(linea,100);

    // Guardado e identificacion de datos en vector auxiliar
    for (int i = 0; i < nodos; i++){
		fe.getline(linea, 100);
        numNodo[linea] = i;
        all[i].ip = linea;
        all[i].outDegree = 0;
    }

    // Guardado de ip's en lista de adyacencia
    int mayor = 0;
    for (int i = 0; i < arcos; i++){
        ip1 = ""; 
        ip2 = "";
        fe.getline(linea, 100);
        ipFormato(linea, ip1, ip2);
        listaAdyacencia[numNodo[ip1]].push_back(numNodo[ip2]);
        all[numNodo[ip1]].outDegree++;
        if(mayor < all[numNodo[ip1]].outDegree){
            mayor = all[numNodo[ip1]].outDegree;
        }
    }
    
    vector<int> mayores;
    for(int i = 0; i < all.size(); i++){
        if(all[i].outDegree == mayor){
            mayores.push_back(i);
        }
    }

    // Impresion de ip's con outdegree mayor
    cout << "Outdegree mayor: " << mayor << endl;
    cout << "Ip's con outdegree mayor: " << endl;
    for(int i = 0; i < mayores.size(); i++){
        cout << all[mayores[i]].ip << endl;
    }

    system("PAUSE");
    return 0;
}