#include <iostream>
#include <fstream>
#include <vector>

#include <Windows.h>



void coreTopologicSortOrgraph(std::vector <std::vector<int>>& matrix, int peak, std::vector<bool>& visited, std::vector <int>& peaksStorage) {
	visited[peak] = true;
	
	int peaks = matrix.size() - 1;
	for (int j = 1; j <= peaks; ++j) {
		if (matrix[peak][j] == 1 && !visited[j]) {
			coreTopologicSortOrgraph(matrix, j, visited, peaksStorage);
		}
	}
	peaksStorage.push_back(peak);
}



int main() {
	SetConsoleOutputCP(1251);
	int lines{}, columns{};
	std::vector <std::vector<int>> matrix{};
	std::vector <int> peaksStorage{};
	
	std::ifstream file("input.txt");
	if (file.is_open()) {
		file >> columns;
		lines = columns;
		matrix.resize(lines+1, std::vector<int>(columns+1));
		for (int i = 1; i <= lines; ++i) {
			for (int j = 1; j <= columns; ++j) {
				file >> matrix[i][j];
			}
		}
	}
	file.close();

	//основное выполнение
	std::vector <bool> visited(lines + 1, false);
	for (int i = 1; i <= lines; ++i) {
		if (!visited[i]) {
			coreTopologicSortOrgraph(matrix, i, visited, peaksStorage);
		}
	}
	std::cout << "Топологический порядок вершин: ";
	for (int i = peaksStorage.size() - 1; i >= 0; --i) {
		std::cout << peaksStorage[i] << " ";
	}
	std::cout << "\n";

	return 0;
}
