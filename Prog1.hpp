#include <iostream>

namespace Prog1 {

	template <class T>
	int getNum(T& a, std::istream &stream)
	{
		stream >> a;
		if (!stream.good())	// обнаружена ошибка ввода или конец файла
			return -1;
		return 1;
	}
	double** input(int& rm, int& rn, std::istream &stream = std::cin);
	void output(const char* msg, double** a, int const& m, int const& n);
	void erase(double**& lines, int const& m);
	double** swapij(double**& lines, int const& m, int const& n);
}