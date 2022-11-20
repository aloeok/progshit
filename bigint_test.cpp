#include "bigint.h"
#include <iostream>

using std::cout;
using std::endl;

int main () {
	for (long a = -3000; a <= 3000; ++ a) {
		for (long b = -600; b <= 600; ++ b) {
			bigint A (a);
			bigint B (b);
			cout << a << " " << b << " " << (a + b) << " ";
			bigint::add(A, B).print();
		}
	}
}
