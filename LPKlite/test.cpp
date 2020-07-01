#include "test.h"
#include "vec.h"
double array[100];

void vector_test(void ) {
	for (int i = 0; i < 100; i++)
		array[i] = i;
	Vec vconstruct(10, array);
	vconstruct.show();

	Vec vassiment(10, 7);
	vassiment.show();

	Vec vcpy(vassiment);
	vcpy.show();

	Vec vequal = vconstruct;
	vequal.show();

	std::cout <<"maxnorm: "<< vconstruct.maxnorm()<<std::endl;
	std::cout << "twonorm: " << vconstruct.twonorm()<<std::endl;
	
	Vec vposti = +vconstruct;
	vposti.show();

	Vec vneg = -vconstruct;
	vneg.show();

	Vec vprod = vposti * vneg;
	vprod.show();

	std::cout << "ÄÚ»ý:" << dot(vposti, vneg) << std::endl;

	Vec vscala = 1.5 * vposti;
	vscala.show();

	Vec vdiv = vscala / 1.5;
	vdiv.show();

}
