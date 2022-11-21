#include "bigint.h"
#include <iostream>

using std::cout;
using std::endl;

int main () {
	for (long a = -800; a <= 800; a += 1) {
		for (long b = -700; b <= 700; b += 1) {
			bigint A (a);
			bigint B (b);
			cout << a << " " << b << " " << (a + b) << " ";
			bigint::add(A, B).print();
		}
	}
	for (long a = -800; a <= 800; a += 1) {
		for (long b = -700; b <= 700; b += 1) {
			bigint A (a);
			bigint B (b);
			cout << a << " " << b << " " << (a - b) << " ";
			bigint::sub(A, B).print();
		}
	}
	for (long a = -800; a <= 800; a += 1) {
		for (long b = -700; b <= 700; b += 1) {
			bigint A (a);
			bigint B (b);
			cout << a << " " << b << " " << (a * b) << " ";
			bigint::mul(A, B).print();
		}
	}
	for (long a = -800; a <= 800; a += 1) {
		for (long b = -700; b <= 700; b += 1) {
			if (b == 0)
				++ b;
			bigint A (a);
			bigint B (b);
			cout << a << " " << b << " " << (a / b) << " ";
			bigint::div(A, B).print();
		}
	}
	for (long a = -800; a <= 800; a += 1) {
		for (long b = -700; b <= 700; b += 1) {
			if (b == 0)
				++ b;
			bigint A (a);
			bigint B (b);
			bigint rem;
			cout << a << " " << b << " " << (a % b) << " ";
			bigint::div(A, B, rem);
			rem.print();
		}
	}
}
