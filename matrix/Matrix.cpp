#include "Matrix.h"
#include <cstdlib>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

Matrix::Matrix() {
	rows = 0;
	cols = 0;
	data = NULL;
}

Matrix::Matrix(const Matrix& o) : rows(o.rows), cols(o.cols) {
	try {
		data = new double[rows * cols];
	} catch (...) {
		cerr << "Memory allocation error" << endl;
		exit(1);
	}
	for (size_t i = 0; i < rows * cols; ++ i)
		data[i] = o.data[i];
}

Matrix::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
	try {
		data = new double[rows * cols];
	} catch (...) {
		cerr << "Memory allocation error" << endl;
		exit(1);
	}
}

Matrix::~Matrix() {
	delete[] data;
	data = NULL;
}

void Matrix::print() const {
	for (size_t r = 0; r < rows; ++ r) {
		for (size_t c = 0; c < cols; ++ c)
			cout << at(r, c) << " ";
		cout << endl;
	}
}

void Matrix::print(const Matrix& m) {
	for (size_t r = 0; r < m.rows; ++ r) {
		for (size_t c = 0; c < m.cols; ++ c)
			cout << m.at(r, c) << " ";
		cout << endl;
	}
}

double& Matrix::at (size_t r, size_t c) {
	double& el = data[r * cols + c];
	return el;
}

const double& Matrix::at (size_t r, size_t c) const {
	const double& el = data[r * cols + c];
	return el;
}

Matrix Matrix::add (const Matrix& left, const Matrix& right) {
	Matrix res (left.rows, left.cols);
	for (size_t r = 0; r < res.rows; ++ r)
		for (size_t c = 0; c < res.cols; ++ c)
			res.at(r, c) = left.at(r, c) + right.at(r, c);
	return res;
}

Matrix Matrix::mul (double a, const Matrix& m) {
	Matrix res (m.rows, m.cols);
	for (size_t r = 0; r < res.rows; ++ r)
		for (size_t c = 0; c < res.cols; ++ c)
			res.at(r, c) = a * m.at(r, c);
	return res;
}

Matrix Matrix::mul (const Matrix& left, const Matrix& right) {
	Matrix res (left.rows, right.cols);
	for (size_t r = 0; r < res.rows; ++ r)
		for (size_t c = 0; c < res.cols; ++ c)
			res.at(r, c) = 0.0;
	for (size_t r = 0; r < res.rows; ++ r)
		for (size_t c = 0; c < res.cols; ++ c)
			for (size_t k = 0; k < left.cols; ++ k)
				res.at(r, c) += left.at(r, k) * right.at(k, c);	
	return res;
}

void Matrix::mul (double a) {
	for (size_t r = 0; r < rows; ++ r)
		for (size_t c = 0; c < cols; ++ c)
			at(r, c) *= a;
}

void Matrix::Transpose () {
	size_t rows_ = cols;
	size_t cols_ = rows;
	double* data_;
	try {
		data_ = new double[rows_ * cols_];
	} catch (...) {
		cerr << "Memory allocation error" << endl;
		exit(1);
	}
	for (size_t i = 0; i < rows_; ++ i)
		for (size_t j = 0; j < cols_; ++ j)
			data_[i * cols_ + j] = at(j, i);
	delete[] data;
	data = data_;
	rows = rows_;
	cols = cols_;
}

int main () {
	/*size_t R1 = 3, C1 = 6;
	Matrix m1 (R1, C1);
	
	for (size_t r = 0; r < R1; ++ r) {
		for (size_t c = 0; c < C1; ++ c) {
			m1.at(r, c) = r * c;
		}
	}
	Matrix::print(m1);
	
	m1.Transpose();
	
	cout << endl << endl;
	
	m1.print();*/
	
	return 0;
}
