#include <binary_search_tree.hpp>
#include <catch.hpp>

SCENARIO("default constructor") {
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

