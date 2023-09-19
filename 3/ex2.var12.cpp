#include <iostream>

int main() {
    int phoneCode;
    std::cout << "Enter the area code: ";
    std::cin >> phoneCode;
    std::string operatorName;
    switch (phoneCode) {
        case 98:
        case 68:
            operatorName = "Kyivstar";
            break;
        case 50:
        case 66:
        case 99:
            operatorName = "Vodafone";
            break;
        case 63:
        case 67:
        case 93:
            operatorName = "Lifecell";
            break;
        case 11:
            operatorName = "Oppo";
            break;
        case 22:
            operatorName = "Loop";
            break;
        case 33:
            operatorName = "Hofer";
            break;
	case 44:
            operatorName = "Lidl";
            break;
        default:
            operatorName = "Unknown operator";
            break;
    }
    std::cout << "Operator: " << operatorName << std::endl;
    
    return 0;
}