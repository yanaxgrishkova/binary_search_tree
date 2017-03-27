#include <complex_t.hpp>
#include <catch.hpp>

SCENARIO("default constructor") {
	complex_t complex;
	REQUIRE(complex.real_() == 0);
	REQUIRE(complex.imaginary_() == 0);
}

SCENARIO("constructor with params") {
	complex_t complex(1, 2);
	REQUIRE(complex.real_() == 1);
	REQUIRE(complex.imaginary_() == 2);
}

SCENARIO("copy constructor") {
	complex_t complex(1, 2);
	complex_t copy(complex);
	REQUIRE(copy.real_() == 1);
	REQUIRE(copy.imaginary_() == 2);
}

SCENARIO("operator *") {
	complex_t c1(7, 6);
	complex_t c2(5, 4);
	complex_t c3(11, 58);
	REQUIRE((c1*c2)==c3);
}

SCENARIO("operator /") {
	complex_t c1(7, 6);
	complex_t c2(7, 6);
	complex_t c3(1, 0);
	REQUIRE((c1/c2)==c3);
}

SCENARIO("operator +=") {
	complex_t c1(13, 1); 
	complex_t c2(7, 6);
	complex_t c3(20, 7);
	REQUIRE((c1+=c2)==c3);
}

SCENARIO("operator -=") {
	complex_t c1(13, 10); 
	complex_t c2(7, 6);
	complex_t c3(6, 4);
	REQUIRE((c1-=c2)==c3);
}

SCENARIO("operator *=") {
	complex_t c1(7, 6); 
	complex_t c2(5, 4);
	complex_t c3(11, 58);
	REQUIRE((c1*=c2)==c3);
}

SCENARIO("operator /=") {
	complex_t c1(7, 6); 
	complex_t c2(7, 6);
	complex_t c3(1, 0);
	REQUIRE((c1/=c2)==c3);
}

SCENARIO("operator =") {
	complex_t c1(7, 6); 
	complex_t c2=c1;
	REQUIRE(c2==c1);
}

SCENARIO("operator ==") {
	complex_t c1(7, 6); 
	complex_t c2(7, 6);
	REQUIRE(c1==c2);
}
