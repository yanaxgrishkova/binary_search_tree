#pragma once

#include <iostream>
#include <fstream>


template <typename T>
class BinarySearchTree
{
public:
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

private:
	Node<T>* _root;
	int _count;

public:
	BinarySearchTree();

	void destroyTree(Node<T>* node);

	~BinarySearchTree();

	T value_() const;
	
	Node<T>* leftNode_() const;

	Node<T>* rightNode_() const;
	
	Node<T>* root() const;

	void insertElement(Node<T>* &node, const T &value);

	bool isInserted(const T& value);

	Node<T>* findElement(const T& value) const;

	bool isFound(const T& value) const;

	void infile(std::string filename);

	void outfile(Node<T>* root, std::ostream& outfile);

	void out(std::string filename);

	void paintTree(const Node<T>* node, int level) const;
};

template <typename T>
BinarySearchTree<T>::T value_() const
{
	return _root->value;
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
	_count = 0;
}

template <typename T>
void BinarySearchTree<T>::destroyTree(Node<T>* node)
{
	if (!node)
		return;

	if (node->leftNode)
	{
		destroyTree(node->leftNode);
		node->leftNode = nullptr;
	}

	if (temp->pRight)
	{		
		destroyTree(node->rightNode);
		node->rightNode = nullptr;
	}
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
			insert(node->leftNode, value);
		}
		else if (value > node->value)
		{
			insert(node->rightNode, value);
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
	_count++;
}

template <typename T>
bool BinarySearchTree<T>::isInserted(const T& value)
{
	Node<T> *retNode = insertElement(value);
	if (retNode)
		return true;
	else
		return false;
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
	infile >> _count;
	infile >> value;

	while (infile)
	{
		infile >> value;
		insertElement(value);
	}

	infile.close();
	_count /= 2;
}

template <typename T>
void BinarySearchTree<T>::outfile(Node<T>* root, std::ostream& ofile)
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
void BinarySearchTree<T>::out(std::string filename)
{
	Node<T>* root;
	std::ofstream ofile(filename);

	if (!ofile)
		std::cout << "Error! Please, try again!" << std::endl;
	else
		out(root, ofile);
	ofile.close();
}

template <typename <T>
void BinarySearchTree::paintTree(const Node<T>* node, int level) const
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
