/*
Descripcion: Actividad Integral de Conceptos B�sicos y Algoritmos Fundamentales
Autores: Jose Guadalupe Mireles Rosales A01235880
         Pedro Rodr�guez Trevi�o A01235849
Fecha: 12/09/2020
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// Estructura de datos con los atributos necesarios para el ordenamiento y busqueda de datos
struct Linea{
    unsigned long key, superKey;
    string all;
};

// O(n)
// Funcion auxiliar del ordenamiento merge: Divide el arreglo en 2 particiones para ordenarlos luego unirlos
void une(vector<Linea> &vec, vector<Linea> &aux, int ini, int fin){
    int m = (ini+fin)/2, i = ini, j = m+1, k = ini;
    while(i<=m && j<=fin){
        if (vec[i].superKey <= vec[j].superKey){
            aux[k++] = vec[i++];
        }
        else{
            aux[k++] = vec[j++];
        }
    }
    while (i<=m){
       aux[k++] = vec[i++];
    }
    while (j<=fin){
        aux[k++] = vec[j++];
    }
    for (int z=ini; z<=fin; z++){
        vec[z]=aux[z];
    }
}

// O(n log(n))
// Al dividir el arreglo en 2 subarreglos para despues ordenarlos y unirlos de forma ascendente
void merg(vector<Linea> &vec, vector<Linea> &aux, int ini, int fin){
    if(ini < fin){
        int m = (ini + fin)/2;
        merg(vec, aux, ini, m);
        merg(vec, aux, m+1, fin);
        une(vec, aux, ini, fin);
    }
}

// O(1)
// Genera y devuelve un valor entero que sirve como identificador del mes y la fecha
int createKey(string fecha){
    int x;
    string meses[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    string mes = {fecha[0],fecha[1],fecha[2]};
    fecha.erase(0,4);
    string dia = fecha;
    for (int j=1; j<=12; j++){
        if (mes == meses[j-1]){
            x = j*100+ stoi(dia);
        }
    }
    return x;
}

// O(n)
// Lee el archivo y genera un valor entero que sirve como identificador del mes, la fecha y la hora
void leerSuperKey(vector<Linea> &datos, vector<Linea> &aux){
    ifstream fe("bitacora.txt");
    char x[90];
    string fecha, hora, minutos, seg, line;
    int i=0;
    string meses[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    while(!fe.eof()) {
        fe.getline(x,90);
        fecha = {x[0],x[1],x[2],x[3],x[4],x[5]};
        datos[i].key = createKey(fecha);
        datos[i].all = x;
        line=x;
        if (x[5] == ' '){
            line.erase(0,6);
        }
        else{
            line.erase(0,7);
        }
        hora = {line[0],line[1]};
        line.erase(0,3);
        minutos = {line[0],line[1]};
        line.erase(0,3);
        seg = {line[0],line[1]};
        line.erase(0,3);


        datos[i].superKey = datos[i].key*1000000 + stoi(hora)*10000 + stoi(minutos)*100 + stoi(seg);
        i++;
    }
    fe.close();
}

// O(n)
// Mediante la libreria fstream, creamos un archivo .txt donde se guardan los datos ordenados ascendentemente del archivo proporcionado en la actividad
void almacenarResultado(vector<Linea> &datos){
    ofstream fs("bitacora_ordenada.txt");
    int n = datos.size();
    for (int i=0; i<n; i++){
        if (i!=n-1){
            fs << datos[i].all<< endl;
        }
        else{
            fs << datos[i].all;
        }
    }
    fs.close();
}

// O(nlog n)
// Busca un dato en un vector y devuelve el indice del mismo
int busqBin (vector<Linea> &v, int dato, bool aux){
    int ini = 0, fin = v.size()-1, mit;
    if (aux){
        if (dato <= v[ini].key){
        return ini;
        }
        else{
            if (dato == 731 || dato == 831){
                dato+=70;
            }
        }
    }
    else{
        if (dato >= v[fin].key){
        return fin;
        }
    }
    while (ini <= fin){
        mit = (ini+fin)/2;
        if (v[mit].key == dato){
            if (aux){
                if (v[mit].key == v[mit-1].key){
                    fin = mit-1;
                }
                else{
                    return mit;
                }
            }
            else if (v[mit].key==v[mit+1].key){
                    ini = mit+1;
                }
            else{
                return mit;
            }
        }
        else if (v[mit].key > dato){
            fin = mit-1;
        }
        else{
            ini = mit+1;
        }
    }
    return 0;
}

int main(){
    int n = 16807;
    vector<Linea> datos(n);
    vector<Linea> aux(n);
    leerSuperKey(datos, aux);
    merg(datos, aux, 0, n-1);
    almacenarResultado(datos);
    string inicio, fin;
    int iKey, fKey, a, b;
    cout << "\t |Busqueda| \n" << "Ingresa la fecha de inicio (ej: 'Ago/8'): ";
    cin >> inicio;
    cout << "Ingresa la fecha final (ej: 'Sep/21'): ";
    cin >> fin;
    iKey = createKey(inicio);
    fKey = createKey(fin);
    a = busqBin(datos, iKey, true);
    b = busqBin(datos, fKey, false);
    for (int i=a; i<=b; i++){
    cout << datos[i].all << endl;
    }
    return 0;
}


