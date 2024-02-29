#include <iostream>
using namespace std;

int main(void) {
	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]);
	int *ptr = vector;
	int res_max = *ptr;
	for (int i = 0; i < n; i++) {
		if (*(ptr + i) > res_max) {
			res_max = *(ptr + i);
		}
	}
	cout << "Min element in array - " << res_max;
	return 0;
}