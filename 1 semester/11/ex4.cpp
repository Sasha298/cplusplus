#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int const m = 4;
	int const n = 6;
	int numbers[m][n];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			numbers[i][j] = rand() % 10;
			cout << numbers[i][j] << ' ';
		}
		cout << endl;
	}
	for (int j = 0; j < n; j++) {
		int sumColumn = 0;
		for (int i = 0; i < m; i++) {
				sumColumn+=numbers[i][j];
			
		}
		cout << "Sum in column " << j + 1 << " are: " << sumColumn << endl;
	}
	return 0;
}