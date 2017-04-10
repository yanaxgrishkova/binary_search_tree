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
	bst.insert(7);
	REQUIRE(bst.findElement() == 7);
	REQUIRE(bst.count() == 1);
}

SCENARIO("findElement")
{
	BinarySearchTree<int> bst;
	bool a;
	bst.insert(7);
	a = bst.isFound(7);
	REQUIRE(a == true);
}

SCENARIO("out")
{
	  BinarySearchTree<int> bst1;
	  bst1.out("file3.txt");
	  BinarySearchTree<int> bst2;
	  bst2.out("file3.txt");
	  REQUIRE(bst1.count() == bst2.count());
}
