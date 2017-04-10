#include <binary_search_tree.hpp>
#include <catch.hpp>

SCENARIO("default constructor") 
{
	Node<int> n;
	REQUIRE(n.root() == nullptr);
	REQUIRE(n.count() == 0);
}

SCENARIO("insertElement")
{
	Node<int> n;
	n.insert(7);
	REQUIRE(n.findElement() == 7);
	REQUIRE(n.count() == 1);
}

SCENARIO("findElement")
{
	Node<int> n;
	bool a;
	tree.insert(7);
	a = tree.isFound(7);
	REQUIRE(a == true);
}

SCENARIO("out")
{
	  Node<int> n1;
	  n.out("file3.txt");
	  Node<int> n2;
	  n2.out("file3.txt");
	  REQUIRE(n1.count() == n2.count());
}
