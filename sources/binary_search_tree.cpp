#include "binary_search_tree.hpp"

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	_root->value = 0;
	_root->leftNode = nullptr;
	_root->rightNode = nullptr;
}

template <typename T>
void BinarySearchTree<T>::insertElement(T value)
{
	if (_root == nullptr)
	{
		_root->value = value;
	}

	else 
	{
		Node* nNode = new Node;
		nNode->leftNode = nullptr;
		nNode->rightNode = nullptr;
		nNode->value = value;
		Node* currNode = new Node;
		Node* tempNode = new Node;
		currNode = _root;
		tempNode = _root;
		while (tempNode)
		{
			currNode = tempNode;
			if (nNode->value > currNode->value)
			{
				currNode = currNode->rightNode;
			}
			else currNode = currNode->leftNode;
		}
		if (!currNode)
			_root = nNode;
		else
		{
			if (value < currNode->value)
				currNode->leftNode = tempNode;

			else currNode->rightNode = tempNode;
		}
	}
}

template <typename T>
bool BinarySearchTree<T>::findElement(T value) const
{
	Node* currNode = _root;

	while (currNode)
	{
		if (currNode->value == value)
			break;

		if (value > currNode->value)
			currNode = currNode->rightNode;

		else currNode = currNode->leftNode;
	}

	if (currNode == nullptr)
		return false;

	if (currNode->value == value);
		return true;
}

template <typename T>
void BinarySearchTree<T>::infile(std::string filename)
{
	std::ifstream infile;
	infile.open(filename);
	int value;

	if (!infile)
		std::cout << "Error! Please, try again!" << std::endl;

	else 
		while (infile)
	{
		infile >> value;
		insertElement(value);
	}

	infile.close();
}

template <typename T>
void BinarySearchTree<T>::outfile(Node* root, std::ostream& ofile)
{
	if (root == nullptr)
		return;

	else
	{
		ofile << root->value << std::endl;
		outfile(root->rightNode, ofile);
		outfile(root->leftNode, ofile);
	}
}

template <typename T>
void BinarySearchTree<T>::out(std::string filename)
{
	Node* root;
	std::ofstream ofile(filename);

	if (!ofile)
		std::cout << "Error! Please, try again!" << std::endl;
	else
		out(root, ofile);
		ofile.close();
}
