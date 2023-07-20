#pragma once

#include <cstdlib>
#include <cfloat>
#include "mkl.h"

bool double_equals(double a, double b)
{
	return std::abs(a - b) < FLT_EPSILON;
};

class MyMatrix 
{
public:
	double* Mat;
	int rows;
	int cols;

	MyMatrix(int rows, int cols) {
		this->rows = rows;
		this->cols = cols;
		Mat = new double[rows * cols];
	};


	MyMatrix() {
		this->rows = 0;
		this->cols = 0;
		Mat = NULL;
	};

	~MyMatrix() {
		if (Mat != NULL) {
			delete[] Mat;
		}
	};

	void set(int i, int j, double val) {
		Mat[i * cols + j] = val;
	};

	double get(int i, int j) {
		return Mat[i * cols + j];
	};

	MyMatrix Mul(MyMatrix B) {
		int m = this->rows;
		int n = B.cols;
		int k = this->cols;
		double alpha = 1.0;
		double beta = 0.0;
		double* A = this->Mat;
		double* BMat = B.Mat;
		MyMatrix C(m, n);
		cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
			m, n, k, alpha, A, k, BMat, n, beta, C.Mat, n);
		return C;
	};

	MyMatrix(int rows, int cols, double* Mat) {
		this->rows = rows;
		this->cols = cols;
		this->Mat = Mat;
	}

	bool operator==( MyMatrix& other)
	{
		if (this->rows != other.rows || this->cols != other.cols) {
			return false;
		}
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->cols; j++) {
				if (!double_equals(this->get(i, j), other.get(i, j))) {
					return false;
				}
			}
		}
		return true;
	}
};


