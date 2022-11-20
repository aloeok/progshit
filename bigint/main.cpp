#include "bigint.h"
#include <iostream>

int main () {
	bigint A ("-566");
	bigint B ("59");
	bigint::add(A, B).print();
}

bigint bigint::mul(const bigint& left, const bigint& right) {
	
}
