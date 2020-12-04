#include "Node.h"

class DoubleLinkedList{
	public:
		DoubleLinkedList();//
		~DoubleLinkedList();//
		void addFirst(Info data);//
		void addLast(Info data);//
		int deleteAll();//
		void print(long long ini, long long fin);//
        void sort();
        Node* getHead() {return head;}
        int getSize();

	private:
		Node *head;
		Node *tail;
        int size;

};

// O(1)
// Constructor
DoubleLinkedList ::DoubleLinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// O(1)
// Destructor
DoubleLinkedList::~DoubleLinkedList(){
    deleteAll();
}

// O(1)
// Agrega un elemento a la primera posicion de la lista
void DoubleLinkedList::addFirst(Info data){ // Revisar
    if(size == 0){
        head = new Node(data, head, nullptr);
        tail = head;
        size++;
    }
    else{
        head = new Node(data, head, nullptr);
        Node *curr = head->getNext();
        curr->setPrevious(head);
        size++;
    }
}

// O(n)
// Agrega un elemento a la ultima posicion de la lista
void DoubleLinkedList::addLast(Info data){ // Revisar
	if (size == 0){
		addFirst(data);

	}
	else{
		tail = new Node(data, nullptr, tail);
        Node *curr = tail->getPrevious();
        curr->setNext(tail);
        size++;
	}
}

// O(n)
// Borra todos los elementos de una lista
int DoubleLinkedList::deleteAll(){ //O(n)
    Node *curr = head;
    int sizeAux = size;
    while(head != nullptr){
        head = head->getNext();
        delete curr;
        curr = head;
    }
    size = 0;
    return sizeAux;
}

// O(n)
// Imprime los elementos contenidos en una lista
void DoubleLinkedList::print(long long inicio, long long fin){
	std::cout << "La LinkedList contiene:" << std::endl;
	Node *curr = head;
    for (int i=0; (i<size) && (curr->getData().key<=fin);i++){
        if(curr->getData().key >= inicio){
            std::cout << curr->getData().contenido << std::endl;
        }
        curr = curr->getNext();
    }
}

// O(n^2)
// Ordena la lista doblemente encadenada
void DoubleLinkedList::sort(){
    Node *curr;
    Node *currNext;
    Info temporalSave;
    bool interruptor = true;
    for(int i = 0; i < size && interruptor; i++){
        curr = head;
        currNext = curr->getNext();
        interruptor = false;
        for(int j = 0; j < size-i; j++){
            if(currNext != nullptr){
                if(currNext->getData().key < curr->getData().key){
                    temporalSave = currNext->getData();
                    currNext->setData(curr->getData());
                    curr->setData(temporalSave);
                    interruptor = true;
                }
                curr = curr->getNext();
                currNext = curr->getNext();
            }
        }
    }
}

// O(1)
// Regresa la cantidad de nodos en la lista
int DoubleLinkedList::getSize(){
    return size;
}
