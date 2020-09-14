#include "Prog1.hpp"
#include <fstream>

using namespace Prog1;

int main() {
	double** arr = nullptr,**newmatrix=nullptr; // �������� ������
	int m;
	int n;	
	std::ifstream stream("../../../data.txt");
	//std::ofstream st("data");
	
	//stream.open()
	arr = input(m,n, stream); // ���� �������
	if (!arr) {
		std::cout << "incorrect data" << std::endl;
		return 1;
	}
	output("Sourced matrix", arr, m,n);
	newmatrix = swapij(arr,m,n);
	output("Resolved matrix", newmatrix, m, n);
	erase(arr, m); // ������������ ������
	erase(newmatrix, m);
	return 0;
}