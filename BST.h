#include "NodeT.h"
class BST{
	public:
		BST();
		~BST();
		void add(Info data);
		void print();
		int size();
        Info mayor();
		void printMax();

	private:
		NodeT *root;
		void inOrdenInv(NodeT *r);
		void destruye(NodeT *r);
		int count(NodeT *r);
		queue<Info> fila;
};

// O(1)
// Constructor
BST::BST(){
	root = nullptr;
}

// O(1)
// Destructor
BST::~BST(){
	destruye(root);
}

// O(n)
// Destruye todos los nodos de un arbol, elimina el objeto
void BST::destruye(NodeT *r){
	if (r != nullptr){
		destruye(r->getLeft());
		destruye(r->getRight());
		delete r;
	}
}

// O(n)
// Regresa el nodo con mayor valor
Info BST::mayor(){
	NodeT *curr = root;
	while (curr->getRight() != nullptr){
		curr = curr->getRight();
	}
	return curr->getData();
}

// O(n)
// Agrega nodos al arbol, para hacer esto tiene que recorrer el arbol basandose en si el valor a ingresar es mayor o menor que uno de sus descendientes
void BST::add(Info data){
	NodeT *curr = root;
	NodeT *father = nullptr;
	while (curr != nullptr){
		if (curr->getData().key == data.key){
			return;
		}
		father = curr;
		curr = (curr->getData().key > data.key) ? curr->getLeft() : curr->getRight();
	}
	if (father == nullptr){
		root = new NodeT(data);
	}
	else{
		father->getData().key > data.key ? father->setLeft(new NodeT(data)) : father->setRight(new NodeT(data));
	}

}

// Complejidad: O(n)
// Cuenta el numero de nodos en el arbol
int BST::count(NodeT *r){
	if (r == nullptr){
		return 0;
	}
	return 1 + count(r->getLeft()) + count(r->getRight());
}

// Complejidad: O(n)
// Llama a la funcion count
int BST::size(){
	return count(root);
}

// Complejidad: O(n)
// Se guardan los primeros 5 elementos que debieron ser imprimidos en inOrdenInverso
void BST::inOrdenInv(NodeT *r){
    if (r != nullptr){
        inOrdenInv(r->getRight());
        
		if(fila.size() < 5){
			fila.push(r->getData());
		}
        inOrdenInv(r->getLeft());
    }
}

// Complejidad: O(n)
// Llama a la funcion inOrdenInv
void BST::print(){
    inOrdenInv(root); //Imprime inOrden inverso
}

// O(1)
// Imprime las 5 ip's mas repetidas en el archivo
void BST::printMax(){
	for(int i = 0; i < 5; i++){
		cout << i+1 << " IP: " << fila.front().ip << " Entradas: " << fila.front().entryTimes << endl;
		fila.pop();
	}
}