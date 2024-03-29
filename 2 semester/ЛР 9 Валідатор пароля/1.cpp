#include <string>
#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	string password;
	getline(cin, password);
	bool has8char = false;
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;
    bool hasSpecialCharacter = false;
	if (password.length() < 8) 
        has8char = true;
    for (char ch : password) {
        if (isupper(ch))
            hasUpperCase = true;
        else if (islower(ch))
            hasLowerCase = true;
        else if (isdigit(ch))
            hasDigit = true;
        else if (!isalnum(ch))
            hasSpecialCharacter = true;
    }
    if (has8char)
        cout << "The password must be 8 characters long" << endl;
    if (!hasUpperCase)
        std::cout << "The password must have at least one upper case letter" << std::endl;
    if (!hasLowerCase)
        std::cout << "The password must have at least one lower case letter" << std::endl;
    if (!hasDigit)
        std::cout << "The password must have at least one digit" << std::endl;
    if (!hasSpecialCharacter)
        std::cout << "The password must have at least one special character" << std::endl;
    else 
        cout << "The password is valid" << endl;
	return 0;
}