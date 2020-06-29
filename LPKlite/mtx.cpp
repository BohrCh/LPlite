#include "mtx.h"
#include <iostream>
//构造函数,用二维数组初始化
Mtx::Mtx(int n, int m, double** e) {
	rows = n;
	cols = m;

	elmt = new double[n * m];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			elmt[i * cols + j] = e[i][j];
		}
}
//构造函数，指定值初始化
Mtx::Mtx(int n, int m, double d) {
	rows = n;
	cols = m;
	elmt = new double[n * m];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			elmt[i * cols + j] = d;
		}
	}
}

//拷贝构造函数
Mtx::Mtx(const Mtx& mat) {
	rows = mat.rows;
	cols = mat.cols;
	elmt = new double[rows * cols];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			elmt[i * cols + j] = mat(i, j);
		}
	}

}

void error(const char* v)
{
	std::cout << v << ".Program exit!\n";
}

//析构函数
inline Mtx::~Mtx() {
	delete[] elmt;

}

//拷贝赋值。返回值是Mtx& 一是为了连续赋值，二是减少构造和析构次数
Mtx& Mtx::operator=(const Mtx& mat) {
	if (this != &mat) {
		if (rows != mat.rows || cols != mat.cols)
			error("matrix sizes doesn't match!");
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				elmt[i * cols + j] = mat(i, j);
	}
	return *this;
}

//double ** Mtx::operator&(){
//    return &(*this->elmt);
//}
//加赋值
Mtx& Mtx::operator+=(const Mtx& mat) {
	if (rows != mat.rows || cols != mat.cols)
		error("matrix size doesn't match");
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			elmt[i * cols + j] += mat(i, j);
	return *this;

}

//减赋值
Mtx& Mtx::operator-=(const Mtx& mat) {
	if (rows != mat.rows || cols != mat.cols)
		error("matrix size doesn't match");
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			elmt[i * cols + j] -= mat(i, j);
	return *this;
}

inline  Mtx& Mtx::operator+() {
	return   *this;
}

//inline Mtx Mtx::operator-() {
//    Mtx m(rows,cols);
//
//    *this = (m - *this);
//    //this = &ans;
//    return *this;
//}

Mtx Mtx::operator+(const Mtx& mat)const {
	if (rows != mat.rows || cols != mat.cols)
		error("matrix size doesn't match");
	Mtx sum = *this;
	sum += mat;
	return sum;
}

Mtx Mtx::operator-(const Mtx& m2) {
	if (rows != m2.rows || cols != m2.cols)
		error("matrix size doesn't match");
	Mtx sum = *this;
	sum -= m2;
	return sum;
}