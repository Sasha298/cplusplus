#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main() {
	int const m = 5;
	int const n = 5;
	int numbers[m][n];
	srand(time(0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			numbers[i][j] = rand() % 2;
			cout << setw(4) << numbers[i][j];
		}
		cout << endl;
	}
	int sumDiagonals = 0;
	for (int i = 0; i < m; i++) {
		sumDiagonals += numbers[i][i] + numbers[i][n - 1 - i];
	}
	cout << "Sum diagonals are: " << sumDiagonals << endl;
	return 0;
}