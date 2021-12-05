#ifndef MATRIX_H
#define MATRIX_H


#include<iostream>
#include<math.h>
//#include "matrix.h"

template <typename T, int STR, int COL>
class Matrix {
private:
	int str, col;
	T arr[STR*COL];
public:
	Matrix();
	explicit Matrix(T init);

	T getValue(int i, int j) const;
	int getCol() const;
	int getStr() const;
	void setValue(T val, int i, int j);
	void setByIndex(T val, int n);
	double getNorm() const;
	void printMatrix() const;
	T getByIndex(int n) const;

	Matrix operator+(const Matrix &B) const;
	Matrix operator-(const Matrix &B) const;
	Matrix operator*(const T n) const;
};


template <typename T, int STR, int COL>
void Matrix<T, STR, COL>::printMatrix() const{
	for (int i = 0; i < STR; i++){
		for (int j = 0; j < COL; j++){
			std::cout << arr[i * COL + j] << " ";
		}
		std::cout << std::endl;
	}
}


template <typename T, int STR, int COL, int N>
Matrix<T, STR, COL> operator*(const Matrix<T, STR, N> &A, const Matrix<T, N, COL> &B){
	double s = 0;
        Matrix<T, STR, COL> b(0);
        for (int i = 0; i < STR; i++){
                for (int j = 0; j < COL; j++){
			for (int k = 0; k < N; k++)
                        	s += A.getValue(i, k) * B.getValue(k, j);
			b.setValue(s, i, j);
			s = 0;
                }
        }
        return b;
}

template <typename T, int STR, int COL>
double Matrix<T, STR, COL>::getNorm() const{
	double s = 0;
	for (int i = 0; i < STR; i++)
		for (int j = 0; j < COL; j++)
			s+= arr[i* COL + j] * arr[i*COL + j];
	s = sqrt(s);
	return s;
}

template<typename T, int STR, int COL>
Matrix<T, STR, COL>::Matrix() : str(STR) {
	str = STR;
	col = COL;
}

template<typename T, int STR, int COL>
Matrix<T, STR, COL>::Matrix(T init) {
	str = STR;
	col = COL;

	for (auto &number : arr) {
		number = init;
	}
}

template<typename T, int STR, int COL>
T Matrix<T, STR, COL>::getValue(int i, int j) const {
	if (i >= 0 && j >= 0 && i < str && j < col) {
		return arr[i*COL + j];
	} else {
		std::cout << "Out of bound\n";
		return 0;
	}
}

template<typename T, int STR, int COL>
int Matrix<T, STR, COL>::getCol() const {
	return COL;
}

template<typename T, int STR, int COL>
int Matrix<T, STR, COL>::getStr() const {
	return STR;
}

template<typename T, int STR, int COL>
void Matrix<T, STR, COL>::setValue(T val, int i, int j) {
	if (i >= 0 && j >= 0 && i < str && j < col) {
		arr[i*COL + j] = val;
	} else {
		std::cout << "Out of bound\n";
	}
}

template<typename T, int STR, int COL>
Matrix<T, STR, COL> Matrix<T, STR, COL>::operator+(const Matrix &B) const {
	if (col != B.getCol() || str != B.getStr()) {
		std::cout << "Matrices have different size" << '\n';
		return Matrix<T, STR, COL>();
	} else {
		Matrix<T, STR, COL> ret;
		for (int i = 0; i < STR*COL; i++) {
			ret.setByIndex(arr[i] + B.getByIndex(i), i);
		}
		return ret;
	}
}

template<typename T, int STR, int COL>
void Matrix<T, STR, COL>::setByIndex(T val, int n) {
	arr[n] = val;
}

template<typename T, int STR, int COL>
T Matrix<T, STR, COL>::getByIndex(int n) const {
	return arr[n];
}

template<typename T, int STR, int COL>
Matrix<T, STR, COL> Matrix<T, STR, COL>::operator-(const Matrix &B) const {
	if (col != B.getCol() || str != B.getStr()) {
		std::cout << "Matrices have different size" << '\n';
		return Matrix<T, STR, COL>();
	} else {
		Matrix<T, STR, COL> ret;
		for (int i = 0; i < STR*COL; i++) {
			ret.setByIndex(arr[i] - B.getByIndex(i), i);
		}
		return ret;
	}
}

template<typename T, int STR, int COL>
Matrix<T, STR, COL> Matrix<T, STR, COL>::operator*(const T n) const {
	Matrix<T, STR, COL> ret;
	for (int i = 0; i < STR*COL; i++) {
		ret.setByIndex(arr[i]*n, i);
	}
	return ret;
}

//template<typename T, int STR, int COL>
//Matrix<T, STR, 1> Matrix<T, STR, COL>::multiply(const Matrix<T, STR, COL> &A, const Matrix<T, STR, 1> &B) const {
	//if (COL != B.getStr()){
	//	std::cout << "Shapes don't match\n";
	//	return -1;
	//}
	//int s = 0;
	//Matrix<T, STR, 1> b(0);
	//for (int i = 0; i < STR; i++){
	//	for (int j = 0; j < COL; j++){
	//		s += this->arr[i * STR + j] * B.getValue(j, 0);
	//	}
	//	b.setValue(s, i, 0);
	//	s = 0;
	//}
	//return b;
//}

#endif
