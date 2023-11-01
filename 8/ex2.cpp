#include <iostream>
#include <climits>

int main() {
    const int size = 7; 
    int array[size] = {-2, 3, -4, 5, -6, -7, 8}; 
    
    int maxIndex = -1;
    int maxValue = INT_MIN;
    
   
    for (int i = 0; i < size; ++i) {
        if (array[i] > maxValue) {
            maxValue = array[i];
            maxIndex = i;
        }
    }
    
  
    for (int i = 0; i < maxIndex; ++i) {
        if (array[i] < 0) {
            array[i] = 0;
        }
    }
    
   
    std::cout << "Result: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
