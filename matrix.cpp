#include<iostream>

#include "matrix.h"

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

template<typename T, int STR, int COL>
Matrix<T, STR, COL> Matrix<T, STR, COL>::operator*(const Matrix &B) const {
	return Matrix<T, STR, B.getCol()>();
}

