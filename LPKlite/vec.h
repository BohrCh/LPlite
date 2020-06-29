#ifndef VEC_H
#define VEC_H
#include "IOlite.h"
class Vec {
private:
	int lenth;
	double* e;
public:
	Vec(int, double*);                 //���캯�����������ʼ��
	Vec(int x = 0, double = 0);   //����Ԫ�ص���int i
	Vec(const Vec& );                 //cpy construction 
	~Vec() { delete[] e; }

	int size() const { return  lenth;  }   //get lenth
	Vec& operator=(const Vec&);     //assignment
	Vec& operator+=(const Vec&);   //v += v0
	Vec& operator -=(const Vec&);   //v -+v0
	double maxnorm() const;            //����������Ԫ��
	double twonorm() const;             //������ 
	double& operator[](int i) const { return ets[i]; }
	                                                  //�±�����
	friend Vec operator+(const Vec&); // return + v0
	friend Vec operator-(const Vec&);  // return -v0
	friend Vec operator+(const Vec&, const Vec&); //retrun v0+v1
	friend Vec operator-(const Vec&, const Vec&);

	friend Vec operator*(double, const Vec&);//return k*v0
	friend Vec operator*(const Vec&, double);
	friend Vec operator/(const Vec&, double);
	friend Vec operator*(const Vec&, const Vec&); //return v0*v1
	
	friend double dot(const Vec&, const Vec&);//return v0 ��v1
	//To do
	//friend ostream& operator<<(ostream&, const Vec&);
};
inline void erro(char* v) {
	std::cout << v << "./program exited\n";
	exit(1);
}




#endif
