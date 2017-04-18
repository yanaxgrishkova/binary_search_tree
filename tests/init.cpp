#include <binary_search_tree.hpp>
#include <catch.hpp>

SCENARIO("default constructor") 
{
	BinarySearchTree<int> bst;
	REQUIRE(bst.root() == nullptr);
}

SCENARIO("insertElement")
{
	BinarySearchTree<int> bst;
	bst.insert(7);
	REQUIRE(bst.value_() == 7);
	REQUIRE(bst.leftNode_() == nullptr);
	REQUIRE(bst.rightNode_() == nullptr);
}

SCENARIO("findElement")
{
	BinarySearchTree<int> bst;
	bst.insert(7);
	REQUIRE( bst.isFound(7) == 1);
}

SCENARIO("infile")
{
	BinarySearchTree<int> bst;
	bst.infile("file.txt");
	REQUIRE( bst.count() == 0);
}

SCENARIO("_count")
{
	BinarySearchTree<int> bst;
	int count = 0;
	bst.insert(7);
	count = bst._count();
	REQUIRE( count == 1);
}
