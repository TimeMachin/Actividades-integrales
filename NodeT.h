struct Info{
    long long key;
    std::string ip;
	int entryTimes;
};

class NodeT{
	public:
		NodeT(Info data);
		NodeT(Info data, NodeT *left, NodeT *right); // No se va requerir
		Info getData();
		void setData(Info data);
		NodeT* getLeft();
		void setLeft(NodeT *left);
		NodeT* getRight();
		void setRight(NodeT *right);
	private:
		Info data;
		NodeT *left;
		NodeT *right;
};

NodeT::NodeT(Info data){
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

NodeT::NodeT(Info data, NodeT *left, NodeT *right){
	this->data = data;
	this->left = left;
	this->right = right;
}

Info NodeT::getData(){
	return data;
}

void NodeT::setData(Info data){
	this->data = data;
}

NodeT* NodeT::getLeft(){
	return left;
}

void NodeT::setLeft(NodeT *left){
	this->left = left;
}

NodeT* NodeT::getRight(){
	return right;
}

void NodeT::setRight(NodeT *right){
	this->right = right;
}
