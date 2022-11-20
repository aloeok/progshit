#include "bigint.h"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cerr;
using std::endl;

size_t ulong_len (unsigned long n) {
	if (n == 0)
		return 1;
	size_t len = 0;
	while (n != 0) {
		++ len;
		n /= 10;
	}
	return len;
}

size_t long_len (long n) {
	if (n < 0)
		n = -n;
	return ulong_len(static_cast<unsigned long>(n));
}

bool is_digit (char c) {
	return c - 48 >= 0 && c - 48 <= 9;
}

size_t max_size_t (size_t a, size_t b) {
	if (a > b)
		return a;
	return b;
}

bigint::bigint() {
	data = NULL;
	size = 0;
	neg = false;
}

bigint::bigint(const bigint& o) : size(o.size), neg(o.neg) {
	try {
		data = new char[size];
	} catch (...) {
		cerr << "Memory allocation error" << endl;
		exit(1);
	}
	for (size_t i = 0; i < size; ++ i)
		data[i] = o.data[i];
}

bigint::~bigint() {
	delete[] data;
	data = NULL;
}

bigint::bigint(long n) {
	if (n < 0) {
		neg = true;
		n = -n;
	} else {
		neg = false;
	}
	size = long_len(n);
	try {
		data = new char[size];
	} catch (...) {
		cerr << "Memory allocation error" << endl;
		exit(1);
	}
	for (size_t i = 0; i < size; ++ i) {
		data[i] = n % 10;
		n /= 10;
	}
}

bigint::bigint(unsigned long n) {
	neg = false;
	size = ulong_len(n);
	try {
		data = new char[size];
	} catch (...) {
		cerr << "Memory allocation error" << endl;
		exit(1);
	}
	for (size_t i = 0; i < size; ++ i) {
		data[i] = n % 10;
		n /= 10;
	}
}

bigint::bigint(const char* s) {
	size_t size_ = 0;
	while (s[size_] != '\0')
		++ size_;
	size = size_;
	neg = s[0] == '-';
	if (neg)
		-- size;
	try {
		data = new char[size];
	} catch (...) {
		cerr << "Memory allocation error" << endl;
		exit(1);
	}
	for (size_t i = 0; i < size; ++ i)
		data[i] = s[size_ - 1 - i] - '0';
}

void bigint::print() const {
	if (neg)
		cout << "-";
	for (size_t i = 0; i < size; ++ i)
		cout << static_cast<char>(data[size - 1 - i] + '0');
	cout << endl;
}

bigint bigint::add(const bigint& left, const bigint& right) {
	size_t i, size_ = max_size_t(left.size, right.size) + 1;
	char ik = static_cast<char>(left.neg == right.neg);
	char* data_;
	bigint res;
	bool is_diff_pos = true;
	try {
		data_ = new char[size_];
	} catch (...) {
		cerr << "Memory allocation error" << endl;
		exit(1);
	}
	for (i = 0; i < size_; ++ i)
		data_[i] = 0;
	for (i = 0; i < left.size; ++ i)
		data_[i] += left.data[i];
	for (i = 0; i < right.size; ++ i)
		data_[i] += (2*ik-1) * right.data[i];
	for (i = 0; i < size_ - 2 && data_[size_ - 2 - i] == 0; ++ i);
	if (data_[size_ - 2 - i] < 0  || (i == size_ - 2 && data_[0] == 0 && left.neg && left.neg != right.neg)) {
		is_diff_pos = false;
		for (i = 0; i < size_ - 1; ++ i)
			data_[i] = - data_[i];
	}
	for (i = 0; i < size_ - 1; ++ i) {
		if ((-ik*2+1) * data_[i] < -ik*9) {
			data_[i] += (-ik*2+1) * 10;
			data_[i + 1] += (ik*2-1);
		}
	}
	res.data = data_;
	for (i = 0; size_ - 1 - i > 0 && data_[size_ - 1 - i] == 0; ++ i);
	res.size = size_ - i;
	res.neg = is_diff_pos == left.neg;
	return res;
}

bigint bigint::sub(const bigint& left, const bigint& right) {
	bigint op_right (right);
	op_right.neg = !op_right.neg;
	return add(left, op_right);
}

/*
static bigint mul(const bigint& left, const bigint& right);
static bigint div(const bigint& left, const bigint& right);
static bigint div(const bigint& left, const bigint& right, bigint& reminder);
*/
