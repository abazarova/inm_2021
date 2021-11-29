#include <iostream>

template <typename T, int SIZE>
class Vector {
private:
	T arr[SIZE];
	int size;
public:
	Vector();
	explicit Vector(T init);

	T getValue(int n) const;
	int getSize() const;
	void setValue(T val, int n);

	Vector operator+(const Vector &B) const;
	Vector operator-(const Vector &B) const;
	T operator*(const Vector &B) const;
	Vector operator*(const T n) const;
	Vector<T, 3> operator^(const Vector &B) const;
};

template<typename T, int SIZE>
Vector<T, SIZE>::Vector() {
//	for(auto &number : arr) {
//		number = 0;
//	}
	size = SIZE;
}

template<typename T, int SIZE>
Vector<T, SIZE>::Vector(T init) {
	for(auto &number : arr) {
		number = init;
	}
	size = SIZE;
}

template<typename T, int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator+(const Vector &B) const {
	if (size != B.getSize()) {
		std::cout << "Vectors have different size" << '\n';
		return nullptr;
	} else {
		Vector<T, SIZE> ret;
		for (int i = 0; i < SIZE; i++) {
			ret.setValue(arr[i] + B.getValue(i), i);
		}
		return ret;
	}
}

template<typename T, int SIZE>
T Vector<T, SIZE>::getValue(int n) const {
	if (n < SIZE && n >= 0) {
		return arr[n];
	} else {
		std::cout << "Out of bound" << '\n';
		return 0;
	}
}

template<typename T, int SIZE>
int Vector<T, SIZE>::getSize() const {
	return size;
}

template<typename T, int SIZE>
void Vector<T, SIZE>::setValue(T val, int n) {
	if (n < size && n >= 0) {
		arr[n] = val;
	} else {
		std::cout << "Out of bound" << '\n';
	}
}

template<typename T, int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator-(const Vector &B) const {
	if (size != B.getSize()) {
		std::cout << "Vectors have different size" << '\n';
		return nullptr;
	} else {
		Vector<T, SIZE> ret;
		for (int i = 0; i < SIZE; i++) {
			ret.setValue(arr[i] - B.getValue(i), i);
		}
		return ret;
	}
}

template<typename T, int SIZE>
T Vector<T, SIZE>::operator*(const Vector &B) const {
	if (size != B.getSize()) {
		std::cout << "Vectors have different size" << '\n';
		return 0;
	} else {
		T ret = 0;
		for (int i = 0; i < SIZE; i++) {
			ret += arr[i]*B.getValue(i);
		}
		return ret;
	}
}

template<typename T, int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator*(const T n) const {
	Vector<T, SIZE> ret;
	for (int i = 0; i < SIZE; i++) {
		ret.setValue(arr[i]*n, i);
	}
	return ret;
}

template<typename T, int SIZE>
Vector<T, 3> Vector<T, SIZE>::operator^(const Vector &B) const {
	if (B.getSize() == 3) {
		Vector<T, 3> ret;
		ret.setValue(arr[1]*B.getValue(2) - arr[2]*B.getValue(1), 0);
		ret.setValue(arr[2]*B.getValue(0) - arr[0]*B.getValue(2), 1);
		ret.setValue(arr[0]*B.getValue(1) - arr[1]*B.getValue(0), 2);
		return ret;
	} else {
		std::cout << "Vector product is defined only in three-dimensional space\n";
		return Vector<T, 3>();
	}
}

