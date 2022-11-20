#ifndef Matrixhpp
#define Matrixhpp 20221115L

#include <cstddef>

class Matrix {
	size_t rows;
	size_t cols;
	
	double *data;
	
  public:
	
	Matrix();
	Matrix(const Matrix&);
	Matrix(size_t rows, size_t cols);
	~Matrix();
	
	void print() const;
	static void print(const Matrix&);
	
	double& at (size_t r, size_t c);
	const double& at (size_t r, size_t c) const;
	
	static Matrix add (const Matrix& l, const Matrix& r);
	static Matrix mul (const Matrix& l, const Matrix& r);
	static Matrix mul (double a, const Matrix& m);
	
	void mul (double a);
	void Transpose ();
};

#endif
