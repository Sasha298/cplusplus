#include <iostream>
#include <string>
#include <regex>

using namespace std;

// Базовий клас IPAddress
class IPAddress {
protected:
    string address;
public:
    IPAddress(const string& addr) : address(addr) {}
    
    // Копіювальний конструктор
    IPAddress(const IPAddress& other) : address(other.address) {}
    
    // Метод для виводу адреси
    virtual void print() const {
        cout << address;
    }
};

// Похідний клас IPAddressChecked
class IPAddressChecked : public IPAddress {
private:
    bool isCorrect;
    
    // Метод для перевірки коректності IP-адреси
    bool checkIPAddress() {
        regex ipPattern(R"((\d{1,3}\.){3}\d{1,3})");
        if (!regex_match(address, ipPattern)) {
            return false;
        }
        
        size_t pos = 0;
        string token;
        string addrCopy = address;  // створюємо копію адреси для роботи з нею
        while ((pos = addrCopy.find('.')) != string::npos) {
            token = addrCopy.substr(0, pos);
            int num = stoi(token);
            if (num < 0 || num > 255) {
                return false;
            }
            addrCopy.erase(0, pos + 1);
        }
        int num = stoi(addrCopy);
        if (num < 0 || num > 255) {
            return false;
        }
        return true;
    }

public:
    IPAddressChecked(const string& addr) : IPAddress(addr), isCorrect(checkIPAddress()) {}
    
    // Копіювальний конструктор
    IPAddressChecked(const IPAddressChecked& other) 
        : IPAddress(other), isCorrect(other.isCorrect) {}
    
    // Метод для виводу адреси та її коректності
    void print() const override {
        IPAddress::print();
        if (isCorrect) {
            cout << " - Correct" << endl;
        } else {
            cout << " - Not Correct" << endl;
        }
    }
};

int main() {
    string ip1, ip2, ip3;
    cout << "Enter three IP addresses:" << endl;
    cin >> ip1 >> ip2 >> ip3;

    IPAddress ipAddress(ip1);
    IPAddressChecked ipAddressChecked1(ip2);
    IPAddressChecked ipAddressChecked2(ip3);

    ipAddress.print();
    cout << endl;
    ipAddressChecked1.print();
    ipAddressChecked2.print();

    return 0;
}

