#include "Prog1.hpp"
#include <algorithm>

namespace Prog1 {

	Matrix input(std::istream& stream = std::cin) {
		const char* pr = ""; // будущее сообщение об ошибке
		int m;	// количество строк матрицы
		int n;
		// сначала вводим количество строк
		do {
			std::cout << pr << std::endl;
			std::cout << "Enter number of lines: --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(m, stream) < 0) // обнаружена ошибка ввода или конец файла
				return Matrix(0, 0);
		} while (m < 1);
		do {
			std::cout << pr << std::endl;
			std::cout << "Enter number of columns: --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(n, stream) < 0) // обнаружена ошибка ввода или конец файла
				return Matrix(0, 0);
		} while (n < 1);
		Matrix mat(m, n);

		for (int i = 0; i < m; i++) {
			// теперь можно вводить сами элементы данной строки матрицы
			std::cout << "Enter items for matrix line #" << (i + 1) << ":" << std::endl;
			for (int j = 0; j < n; j++) {
				double elem;
				if (getNum(elem, stream) < 0) { // обнаружена ошибка ввода или конец файла
					return Matrix(0, 0);
				}
				if (elem != 0)
					mat.elems.push_back({i, j, elem});
			}
		}
		return mat;
	}

	void Matrix::output() {
		auto elem = elems.begin();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (elem != elems.end() && elem->x == i && elem->y == j) {
					std::cout << elem->val << "  ";
					elem++;
				}
				else
					std::cout << "0  ";
			}
			std::cout << "\n";
		}
		std::cout.flush();// сброс буфера
	}

	Matrix swapij(Matrix const& mat) {
		auto prev = mat.elems.begin(), next = mat.elems.end();

	}
	
	double** swapij(double**& lines, int const& m, int const& n) {
		double** newmatrix = new double* [m];
		for (int i = 0; i < m; i++) {
			newmatrix[i] = new double[n];
			int a = -1, b = -1;
			for (int j = 0; j < (n - 1); j++) {
				if (a < 0 && lines[i][j] < lines[i][j + 1])
					a = j + 1;
				if (lines[i][j] > lines[i][j + 1])
					b = j + 1;
			}
			for (int j = 0; j < n; j++)
				newmatrix[i][j] = lines[i][j];
			if (a < 0 || b < 0)
				continue;
			std::swap(newmatrix[i][b], newmatrix[i][a]);
		}
		return newmatrix;
	}

	// double** input(int& rm, int& rn, std::istream &stream = std::cin)
	// {
	// 	const char* pr = ""; // будущее сообщение об ошибке
	// 	double** lines = nullptr;  // динамический массив строк матрицы
	// 	int m;	// количество строк матрицы
	// 	int n;
	// 	// сначала вводим количество строк
	// 	do {
	// 		std::cout << pr << std::endl;
	// 		std::cout << "Enter number of lines: --> ";
	// 		pr = "You are wrong; repeat please!";
	// 		if (getNum(m, stream) < 0) // обнаружена ошибка ввода или конец файла
	// 			return nullptr;
	// 	} while (m < 1);

	// 	// выделяем память под массив структур - строк матрицы
	// 	try {
	// 		lines = new double*[m];
	// 	}
	// 	catch (std::bad_alloc & ba)
	// 	{
	// 		std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
	// 		return nullptr;
	// 	}
	// 	pr = "";
	// 	do {
	// 		std::cout << pr << std::endl;
	// 		std::cout << "Enter number of items in any line --> ";
	// 		pr = "You are wrong; repeat please!";
	// 		if (getNum(n, stream) < 0) { // обнаружена ошибка ввода или конец файла
	// 			return nullptr;
	// 		}
	// 	} while (n < 1);
	// 	for (int i = 0; i < m; i++) {
	// 		// теперь для каждой строки матрицы вводим количество столбцов 

	// 		// и выделяем необходимую память под элементы строки
	// 		try {
	// 			lines[i] = new double[n];
	// 		}
	// 		catch (std::bad_alloc & ba)
	// 		{
	// 			std::cout << "------ too many items in matrix: " << ba.what() << std::endl;
	// 			erase(lines, i);
	// 			return nullptr;
	// 		}

	// 		// теперь можно вводить сами элементы данной строки матрицы
	// 		std::cout << "Enter items for matrix line #" << (i + 1) << ":" << std::endl;
	// 		for (int j = 0; j < n; j++) {
	// 			if (getNum(lines[i][j], stream) < 0) { // обнаружена ошибка ввода или конец файла
	// 				erase(lines, i + 1); // освобождение памяти, занятой ранее введенными строками
	// 				return nullptr;
	// 			}
	// 		}
	// 	}
	// 	// формируем результат - количество строк в матрице
	// 	rm = m;
	// 	rn = n;
	// 	return lines;
	// }

	// void output(const char* msg, double** a, int const& m, int const& n)
	// {
	// 	int i, j;
	// 	std::cout << msg << ":" << std::endl;
	// 	for (i = 0; i < m; ++i) {
	// 		for (j = 0; j < n; ++j)
	// 			std::cout << a[i][j] << "  ";
	// 		std::cout << std::endl;
	// 	}
	// }

	// // функция освобождения занятой памяти
	// void erase(double**& lines, int const& m)
	// {
	// 	int i;
	// 	for (i = 0; i < m; i++)
	// 		delete[] lines[i];
	// 	delete[] lines;
	// }

}