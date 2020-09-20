#include <iostream>
#include <list>

namespace Prog1 {

	template <class T>
	int getNum(T& a, std::istream& stream)
	{
		stream >> a;
		if (!stream.good())	// обнаружена ошибка ввода или конец файла
			return -1;
		return 1;
	}

	struct MatItem {
		int x, y;
		double val;
	};

	struct Matrix {
		int n, m;
		std::list<MatItem> elems;

		Matrix(int const& _m, int const& _n) : n(_n), m(_m) {}
		void output();
	};

	Matrix input(std::istream& stream = std::cin);
	Matrix swapij(Matrix const& mat);
}