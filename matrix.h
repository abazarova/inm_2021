#include<iostream>

#include <iostream>

//class Vector;

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
	T getByIndex(int n) const;

	Matrix operator+(const Matrix &B) const;
	Matrix operator-(const Matrix &B) const;
	Matrix operator*(const T n) const;
	Matrix operator*(const Matrix &B) const;
};

