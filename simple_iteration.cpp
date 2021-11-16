#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

const unsigned int DIM1 = 2;
const unsigned int DIM2 = 2;
const float tau = 1;

int main(){ //program for solving 2x2 linear system
	float a[DIM1][DIM2], b[DIM1], x[DIM2], x_old[DIM2];
	int i = 0;

	cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1] >> b[0] >> b[1];
	x[0] = 0;
	x[1] = 0;
	x_old[0] = x[0];
	x_old[1] = x[1];
	for (i = 0; i < 10000; i++){
		x[0] = x[0] - tau * (a[0][0] * x[0] + a[0][1] * x[1] - b[0]);
		x[1] = x[1] - tau * (a[1][0] * x[0] + a[1][1] * x[1] - b[1]);
		if (((x_old[0] - x[0]) * (x_old[0] - x[0]) + (x_old[1] - x[1]) * (x_old[1] - x[1])) <= 1e-4)
			break;
		x_old[0] = x[0];
		x_old[1] = x[1];
	}
	cout << "The answer is: (" << x[0] << " " << x[1] << ")";
	return 0;


}
