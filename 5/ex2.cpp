#include <iostream>

int main() {
    int sum = 0;

    for (int number = 1; number <= 100; number += 2) {
        sum += number;
    }

    std::cout << "The sum of odd numbers from 1 to 100 is equal: " << sum << std::endl;

    return 0;
}