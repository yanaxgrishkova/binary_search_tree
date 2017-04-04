#pragma once

#include <iostream>
#include <fstream>

template <typename T>
class BinarySearchTree
{
public:
	struct Node
	{
		Node* leftNode;
		Node* rightNode;
		T value;
	};

private:
	Node* _root;

public:
	BinarySearchTree();
	~BinarySearchTree();
	void insertElement(T value);
	bool findElement(T value) const;
	void infile(std::string filename);
	void outfile(Node* root, std::ostream& outfile);
	void out(std::string filename);
};
