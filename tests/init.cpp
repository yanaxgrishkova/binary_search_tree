#include <binary_search_tree.hpp>
#include <catch.hpp>

SCENARIO("default constructor") 
{
	BinarySearchTree<int> bst;
	REQUIRE(bst.root() == nullptr);
	REQUIRE(bst.count() == 0);
}

SCENARIO("insertElement")
{
	BinarySearchTree<int> bst;
	bst.insertElement(7);
	REQUIRE(bst.findElement() == 7);
	REQUIRE(bst.count() == 1);
}
