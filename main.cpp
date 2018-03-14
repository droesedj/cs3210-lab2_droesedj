#include "matrix.h"
#include <iostream>
 
using namespace std;

int main(void)
{
	// test our matrix
	
	matrix m1(3,3);
	
	m1[2][1] = 20.5;

	cout << "m1 - should be mostly zeros, (2,1) is 20.5" << endl;
	cout << m1 << endl;
	
	matrix m2 = matrix::identity(3);
	m2[0][0] = 1; m2[0][1] = 2; m2[0][2] = 3;
	m2[1][0] = 4; m2[1][1] = 5; m2[1][2] = 6;
	m2[2][0] = 7; m2[2][1] = 8; m2[2][2] = 9;


	cout << "m2 - should be 3 x 3 identity matrix with a bunch of values" << endl;
	cout << m2 << endl;

	matrix m3 = m1 + m2;

	cout << "m3 - should be 3 x 3 identity matrix, the sum of m1 and m2" << endl;
	cout << m3 << endl;
	
	try
	{
		matrix m4(0,0);	// should throw
		cout << "m4 - exception not thrown (but should have)" << endl;
	}
	catch (matrixException)
	{
		cout << "m4 - exception expected and thrown" << endl;
	}
	
	matrix m5(2,2);
	m5[0][0] = 1; m5[1][0] = 1; m5[0][1] = 2; m5[1][1] = 3;
	cout << "m5 - should be 2 x 2 identity matrix" << endl;
	cout << m5 << endl;

	matrix m6(2,2);
	m6 = m5 * 10;
	cout << "m6 - should be the value of m5*10" << endl;
	cout << m6 << endl;

	matrix m7(1,2);
	m7[0][0] = 1; m7[1][0] = 2;

	cout << "m7 - should be a 1x2 matrix" << endl;
	cout << m7 << endl;

	matrix m8 = ~m7;

	cout << "m8 - should be the transpose of m7" << endl;
	cout << m8 << endl;

	matrix m9 = ~m2;
	cout << "m9 - should be the transpose of m2" << endl;
	cout << m9 << endl;

	matrix m10 = m5 * m6;
	cout << "m10 - should be the product of m5*m6" << endl;
	cout << m10 << endl;

	try{
		matrix m11 = m8 * m10;
		cout << "m11 - product of incompatible matrices m8*m10, did not throw." << endl;
	} catch(matrixException){
		cout << "m11 - product of incompatible matrices m8*m10, properly threw." << endl;
	}
	try{
		matrix m12 = m8 + m10;
		cout << "m12 - sum of incompatible matrices m8+m10, did not throw." << endl;
	} catch(matrixException){
		cout << "m12 - sum of incompatible matrices m8+m10, properly threw." << endl;
	}

	return 0;
}		
