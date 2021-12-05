#include<iostream>
#include<stdlib.h>
#include"simple_iteration.h"
using namespace std;

const unsigned int DIM1 = 2;
const unsigned int DIM2 = 2;
const float tau = 1;
const unsigned int SIZE = 3;
const int N = 3;
const double eps = 0.00001;

void simple_iteration(){
	cout << "This program can solve a system of linear equations: Ax = b, where A is a NxN matrix , x and b are Nx1 vectors. I have set N = 3.\n";
	double elem = 0;
	Matrix<double, N, N> A(0);
	Matrix<double, N, 1> b(0);

	cout << "Now you should enter A_ij:\n";
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> elem;
			A.setValue(elem, i, j);
		}
	}
	cout << "Please also enter b_i:\n";
	for (int i = 0; i < N; i++){
		cin >> elem;
		b.setValue(elem, i, 0);
	}
	cout << "Enter tau: \n";
	double tau;
	cin >> tau;

	Matrix<double, N, N> I(0);
	for (int i = 0; i < N; i++)
		I.setValue(1.0, i, i);

	Matrix<double, N, 1> x_old(0);
	Matrix<double, N, 1> x(0);
	Matrix<double, N, 1> delta;
	Matrix<double, N, N> B = I - A * tau;
	for (int i = 0; i < 10000; i++){
		x_old = x;
		x = B * x_old + b * tau;
		delta = x - x_old;
		if (delta.getNorm() < eps)
			break;
	}
	cout << "The solution is: \n";
	x.printMatrix();
}
