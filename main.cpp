#include "matrix.h"
#include <iostream>
 
using namespace std;

int main(void)
{
	// test our matrix
	
	matrix m1(3,3);
	
	m1[2][1] = 20.5;

	cout << "m1 - should be all zeros" << endl;
	cout << m1 << endl;
	
	matrix m2 = matrix::identity(3);

	cout << "m2 - should be 3 x 3 identity matrix" << endl;
	cout << m2 << endl;

	matrix m3 = m1 + m2;

	cout << "m3 - should be 3 x 3 identity matrix" << endl;
	cout << m3 << endl;
	
	try
	{
		matrix m4(0,0);	// should throw
		cout << "m4 - exception not thrown (but should have)" << endl;
	}
	catch (matrixException me)
	{
		cout << "m4 - exception expected and thrown" << endl;
	}
	
	matrix m5(2,2);
	m5[0][0] = 1; m5[1][0] = 1; m5[0][1] = 2; m5[1][1] = 3;
	cout << "m5 - should be 2 x 2 identity matrix" << endl;
	cout << m5 << endl;

	matrix m6(2,2);
	m6 = m5 * 10;
	cout << "m6 - should be the value of m2*10" << endl;
	cout << m6 << endl;

	return 0;
}		
