#include"IOlite.h"
#include"vec.h"

Vec::Vec(int len, double* array) {
	double* vec = new double[ lenth = len];
	for (int j = 0; j < lenth; j++)
	{
		vec[i] = *(array + j);
	}
}

Vec::Vec(int len, double val) {
	double* vec = new double[lenth = len];
	for (int i = 0; i < len; i++) {
		vec[i] = val;
	}
}

Vec::Vec(const)