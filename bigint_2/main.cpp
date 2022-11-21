#include "bigint.h"
#include <iostream>

int main () {
	long a = 1;
	//long b = 0;
	bigint A (a);
	bigint B ("0");
	bigint::div(A, B).print();
}

