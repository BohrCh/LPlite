#include"IOlite.h"
#include"vec.h"
#include"erro.h"
#include<cmath>




Vec::Vec(int len, double* array) {
	e = new double[ lenth = len];
	for (int j = 0; j < lenth; j++)
	{
		e[j] = *(array + j);
	}
}

Vec::Vec(int len, double val) {
	e = new double[lenth = len];
	for (int i = 0; i < len; i++) {
		e[i] = val;
	}
}

Vec::Vec(const Vec& vin) {
	lenth = vin.lenth;
	e = new double[lenth];
	for (int i = 0; i < lenth; i++) {
		e[i] = vin.e[i]; //对[]进行了重载
	}
}

Vec& Vec::operator=(const Vec& vin) {
	if (this != &vin) {
		if (lenth != vin.lenth) {
			erro("vector size doesn't match!");
		}
		else {
			for (int i = 0; i < lenth; i++) {
				e[i] = vin.e[i];
			}
			return *this;
		}
	}
}

Vec& Vec::operator+=(const Vec& vin) {
	if (lenth != vin.lenth) {
		erro("vector size doern't match!");
	}
	else {
		for (int i = 0; i < lenth; i++)
			e[i] += vin.e[i];
	}
	return *this;
}

Vec& Vec::operator-=(const Vec& vin) {
	if (lenth != vin.lenth) {
		erro("vector size doern't match!");
	}
	else {
		for (int i = 0; i < lenth; i++)
			e[i] -= vin.e[i];
	}
	return *this;
}

double Vec::maxnorm() const{
	double max = e[0];
	for (int i = 1; i < lenth; i++) {
		if (e[i] > max) {
			max = e[i];
		}
	}
	return max;
}

double Vec:: twonorm() const {
	double temp = 0;
	int i;
	for (i = 0; i < lenth; i += 4) {
		temp += e[i] * e[i] + e[i + 1] * e[i + 1];
		temp += e[i + 2] * e[i + 2] + e[i + 3] * e[i + 3];
	}
	for (i=0; i < lenth; i++){
		temp += e[i] * e[i];
	}
	return sqrt(temp);
}

 Vec operator+(const Vec& vin) {
	return vin;
}

 Vec operator-(const Vec& vin) {
	Vec vtemp(vin.lenth, 0.0);
	return vtemp - vin;
}

//
Vec operator+(const Vec& v0, const Vec& v1) {
	if (v0.lenth != v1.lenth) {
		erro("size doesn't match");
	}
	else {
		Vec sum = v0;   //v0 v1都是常数，不能直接改变
		sum += v1;        //输入参数一般const 放置被改
		return sum;        //函数目的是返回正确的表达式的值
	}
}

Vec operator-(const Vec& v0, const Vec& v1) {
	if (v0.lenth != v1.lenth) {
		erro("size doesn't match");
	}
	else {
		Vec sum = v0;   //v0 v1都是常数，不能直接改变
		sum -= v1;        //输入参数一般const 放置被改
		return sum;        //函数目的是返回正确的表达式的值
	}
}

Vec operator*(double q, const Vec& vin) {
	if (q == 0){
		return Vec(vin.size(), 0.0);
	}
	else{
		Vec vtemp = vin;
		for (int i = 0; i < vin.size(); i++)
			vtemp[i] *= q;
		return vtemp;
	}
}

Vec operator*(const Vec& vin, double q) {
	return q * vin;
}

Vec operator*(const Vec & v0, const Vec& v1) {
	if (v0.lenth != v1.lenth) {
		erro("size erro");
	}
	else {
		Vec vtemp = v0;
		for (int i = 0; i < v0.lenth; i++) {
			vtemp.e[i] *= v1.e[i];
		}
		return vtemp;
	}
}



double dot(const Vec& v0, const Vec& v1) {
	if (v0.lenth != v1.lenth) {
		erro("size erro");
	}
	else {
		double sum= 0;
		for (int i = 0; i < v0.lenth; i++) {
			sum += v0.e[i] * v1.e[i];
		}
		return sum;
	}
}

Vec operator/(const Vec& vin, double d) {
	for (int i = 0; i < vin.lenth; i++) {
		vin[i] /= d;
	}
	return vin;
}


