#include "Prog1.hpp"
#include <fstream>

using namespace Prog1;

int main() {
	double** arr = nullptr,**newmatrix=nullptr; // исходный массив
	int m;
	int n;	
	std::ifstream stream("../../../data.txt");
	//std::ofstream st("data");
	
	//stream.open()
	arr = input(m,n, stream); // ввод матрицы
	if (!arr) {
		std::cout << "incorrect data" << std::endl;
		return 1;
	}
	output("Sourced matrix", arr, m,n);
	newmatrix = swapij(arr,m,n);
	output("Resolved matrix", newmatrix, m, n);
	erase(arr, m); // освобождение памяти
	erase(newmatrix, m);
	return 0;
}