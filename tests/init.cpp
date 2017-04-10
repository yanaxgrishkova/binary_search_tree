#include <binary_search_tree.hpp>
#include <catch.hpp>

SCENARIO("default constructor") {
	Node<int> node;
	REQUIRE(node.root() == nullptr);
	REQUIRE(complex.count() == 0);
}
