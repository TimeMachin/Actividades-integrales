struct Info{
    long long key;
    std::string contenido;
};

class Node{
    private:
        Info data;
        Node *next;
        Node *previous;
    public:
        Node(Info data);
        Node(Info data, Node *next, Node *previous);
        void setData(Info data);
        Info getData();
        void setNext(Node *next);
        Node *getNext();
        void setPrevious(Node *previous);
        Node *getPrevious();

};

// O(1)
// Constructor
Node::Node(Info data){
    this->data = data;
    this->next = nullptr;
    this->previous = nullptr;
}

// O(1)
// Constructor
Node::Node(Info data, Node *next, Node *previous){
    this->data = data;
    this->next = next;
    this->previous = previous;
}

// O(1)
// Asignar data
void Node::setData(Info data){
    this->data = data;
}

// O(1)
// Obtener data
Info Node::getData(){
    return data;
}

// O(1)
// Asignar next
void Node::setNext(Node *next){
    this->next = next;
}

// O(1)
// Obtener next
Node *Node::getNext(){
    return next;
}

// O(1)
// Asignar previous
void Node::setPrevious(Node *previous){
    this->previous = previous;
}

// O(1)
// Obtener previous
Node *Node::getPrevious(){
    return previous;
}
