#include "Prog1.hpp"
#include <algorithm>

namespace Prog1 {
	double** input(int& rm, int& rn, std::istream &stream = std::cin)
	{
		const char* pr = ""; // ������� ��������� �� ������
		double** lines = nullptr;  // ������������ ������ ����� �������
		int m;	// ���������� ����� �������
		int n;
		// ������� ������ ���������� �����
		do {
			std::cout << pr << std::endl;
			std::cout << "Enter number of lines: --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(m, stream) < 0) // ���������� ������ ����� ��� ����� �����
				return nullptr;
		} while (m < 1);

		// �������� ������ ��� ������ �������� - ����� �������
		try {
			lines = new double*[m];
		}
		catch (std::bad_alloc & ba)
		{
			std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
			return nullptr;
		}
		pr = "";
		do {
			std::cout << pr << std::endl;
			std::cout << "Enter number of items in any line --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(n, stream) < 0) { // ���������� ������ ����� ��� ����� �����
				return nullptr;
			}
		} while (n < 1);
		for (int i = 0; i < m; i++) {
			// ������ ��� ������ ������ ������� ������ ���������� �������� 
			
			// � �������� ����������� ������ ��� �������� ������
			try {
				lines[i] = new double[n];
			}
			catch (std::bad_alloc & ba)
			{
				std::cout << "------ too many items in matrix: " << ba.what() << std::endl;
				erase(lines, i);
				return nullptr;
			}

			// ������ ����� ������� ���� �������� ������ ������ �������
			std::cout << "Enter items for matrix line #" << (i + 1) << ":" << std::endl;
			for (int j = 0; j < n; j++) {
				if (getNum(lines[i][j], stream) < 0) { // ���������� ������ ����� ��� ����� �����
					erase(lines, i + 1); // ������������ ������, ������� ����� ���������� ��������
					return nullptr;
				}
			}
		}
		// ��������� ��������� - ���������� ����� � �������
		rm = m;
		rn = n;
		return lines;
	}

	void output(const char* msg, double** a, int const& m, int const& n)
	{
		int i, j;
		std::cout << msg << ":" << std::endl;
		for (i = 0; i < m; ++i) {
			for (j = 0; j < n; ++j)
				std::cout << a[i][j] << "  ";
			std::cout << std::endl;
		}
	}

	// ������� ������������ ������� ������
	void erase(double**& lines, int const& m)
	{
		int i;
		for (i = 0; i < m; i++)
			delete[] lines[i];
		delete[] lines;
	}

	double** swapij(double**& lines, int const& m, int const& n) {
		double** newmatrix = new double* [m];
		for (int i = 0; i < m; i++) {
			newmatrix[i] = new double[n];
			int a = -1, b = -1;
			for (int j = 0; j < (n-1); j++) {
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
}