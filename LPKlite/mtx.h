#ifndef MTX_H
#define MTX_H
class Mtx {
private:
	int rows;
	int cols;
	double* elmt;
public:
	Mtx(int n, int m, double**); //用二维数组初始化
	Mtx(int n, int m, double d = 0); //指定初始化值
	Mtx(const Mtx&);
	~Mtx();

	Mtx& operator=(const Mtx&);
	Mtx& operator+=(const Mtx&);
	Mtx& operator-=(const Mtx&);
	// double* operator[](int i) const{return &elmt[i];}
	 //重载[]，获取第i列
	double& operator()(int i, int j) const { return elmt[i * rows + j]; }
	//重载[][] ，获取 i行j列元素;
	//加法实现为成员函数
	Mtx& operator+();
	Mtx operator+(const Mtx&)const;
	Mtx operator-()
	{
		Mtx m(rows, cols);

		m = m - *this;
		//this = &ans;
		return m;
	}
	Mtx operator-(const Mtx&);

	double** operator&();

};

#endif