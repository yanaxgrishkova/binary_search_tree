#include <iostream>
#include <fstream>
#include <string>

template <typename T>
struct Node
{
	Node<T>* leftNode;
	Node<T>* rightNode;
	T value;

	Node(int value)
	{
		this->value = value;
		leftNode = nullptr;
		rightNode = nullptr;
	}
};

template <typename T>
class BinarySearchTree
{
private:
	Node<T>* _root;
	void destroyTree(Node<T>* node);
	void insertElement(Node<T>* &node, const T &value);
	Node<T>* findElement(const T& value) const;
	

public:
	BinarySearchTree();
	~BinarySearchTree();

	T value_() const;
	int count_(const Node<T>* node) const;
	
	Node<T>* leftNode_() const;
	Node<T>* rightNode_() const;
	Node<T>* root() const;

	void insert(const T& value);
	bool isFound(const T& value) const;
	
	void infile(std::string filename);
	void outfile(Node<T>* root, std::ostream& outfile) const;
	void out(std::string filename) const;
	void paintTree(const Node<T>* node, int level) const;
};

template <typename T>
T BinarySearchTree<T>::value_() const
{
	return _root->value;
}

template <typename T>
int BinarySearchTree<T>::_count(const Node<T>* node) const
{
	if (!node)
		return 0;
	else
		return _count(node->leftNode) + _count(node->rightNode) + 1;
}

template <typename T>
Node<T>* BinarySearchTree<T>::root() const
{
	return _root;
}


template <typename T>
Node<T>* BinarySearchTree<T>::leftNode_() const
{
	return _root->leftNode;
}

template <typename T>
Node<T>* BinarySearchTree<T>::rightNode_() const
{
	return _root->rightNode;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	_root = nullptr;
}

template <typename T>
void BinarySearchTree<T>::destroyTree(Node<T>* node)
{
	if (!node)
		return;

	destroyTree(node->leftNode);
	destroyTree(node->rightNode);

	delete node;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	destroyTree(_root);
}

template <typename T>
void BinarySearchTree<T>::insertElement(Node<T>* &node, const T &value)
{
	if (node)
	{
		if (value < node->value)
		{
			insertElement(node->leftNode, value);
		}
		else if (value > node->value)
		{
			insertElement(node->rightNode, value);
		}
		else
		{
			return;
		}
	}
	else
	{
		node = new Node<T>(value);
	}
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value)
{
	insertElement(_root, value);
}

template <typename T>
Node<T>*  BinarySearchTree<T>::findElement(const T& value) const
{
	Node<T> *currNode = _root;

	while (currNode)
	{
		if (currNode->value == value)
			break;
		else
		{
			if (currNode->value < value)
				currNode = currNode->rightNode;
			else currNode = currNode->leftNode;
		}
	}
	return currNode;
}

template <typename T>
bool BinarySearchTree<T>::isFound(const T& value) const
{
	Node<T> *retNode = findElement(value);
	if (retNode) 
		return true;
	else   
		return false;
}

template <typename T>
void BinarySearchTree<T>::infile(std::string filename)
{
	std::ifstream infile;
	infile.open(filename);
	T value;
	int coun;
	infile >> count;

	while (count--)
	{
		infile >> value;
		insert(value);
	}

	infile.close();
}

template <typename T>
void BinarySearchTree<T>::outfile(Node<T>* root, std::ostream& ofile) const
{
	if (!root)
		return;

	else
	{
		ofile << root->value << "\t";
		outfile(root->rightNode, ofile);
		outfile(root->leftNode, ofile);
	}
}

template <typename T>
void BinarySearchTree<T>::out(std::string filename) const
{' 
	std::ofstream ofile(filename);
	int count = _count(_root);
	if (!ofile)
		std::cout << "Error! Please, try again!" << std::endl;
	else
		ofile << count << " ";
		outfile(root, ofile);
	ofile.close();
}

template <typename T>
void BinarySearchTree<T>::paintTree(const Node<T>* node, int level) const
{
	if (node)
	{
		paintTree(node->rightNode, level++);

		for (int i = 0; i < level; i++)
		{
			std::cout << "-";
		}	

		std::cout << node->value << std::endl;
		paintTree(node->leftNode, level++);
	}
}
