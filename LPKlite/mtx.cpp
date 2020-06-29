#include "mtx.h"
#include <iostream>
//���캯��,�ö�ά�����ʼ��
Mtx::Mtx(int n, int m, double** e) {
	rows = n;
	cols = m;

	elmt = new double[n * m];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			elmt[i * cols + j] = e[i][j];
		}
}
//���캯����ָ��ֵ��ʼ��
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

//�������캯��
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

//��������
inline Mtx::~Mtx() {
	delete[] elmt;

}

//������ֵ������ֵ��Mtx& һ��Ϊ��������ֵ�����Ǽ��ٹ������������
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
//�Ӹ�ֵ
Mtx& Mtx::operator+=(const Mtx& mat) {
	if (rows != mat.rows || cols != mat.cols)
		error("matrix size doesn't match");
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			elmt[i * cols + j] += mat(i, j);
	return *this;

}

//����ֵ
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