#include <iostream>
#include <vector>
using namespace std;

bool isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

int monthLength(int year, int month) {
    vector<int> daysInMonth = {31, 28 + isLeap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonth[month - 1];
}

int main(void) {
    for(int yr = 2000; yr < 2002; yr++) {
        for(int mo = 1; mo <= 12; mo++)
            cout << monthLength(yr,mo) << " ";
        cout << endl;
    }
    return 0;
}
