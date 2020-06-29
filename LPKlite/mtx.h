#ifndef MTX_H
#define MTX_H
class Mtx {
private:
	int rows;
	int cols;
	double* elmt;
public:
	Mtx(int n, int m, double**); //�ö�ά�����ʼ��
	Mtx(int n, int m, double d = 0); //ָ����ʼ��ֵ
	Mtx(const Mtx&);
	~Mtx();

	Mtx& operator=(const Mtx&);
	Mtx& operator+=(const Mtx&);
	Mtx& operator-=(const Mtx&);
	// double* operator[](int i) const{return &elmt[i];}
	 //����[]����ȡ��i��
	double& operator()(int i, int j) const { return elmt[i * rows + j]; }
	//����[][] ����ȡ i��j��Ԫ��;
	//�ӷ�ʵ��Ϊ��Ա����
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