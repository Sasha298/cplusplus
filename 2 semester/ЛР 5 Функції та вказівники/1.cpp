#include <iostream>
#include <ctime>
using namespace std;
struct Date {
    int year;
    int month;
    int day;
};

bool isLeap(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}


int monthLength(int year, int month) {
    switch (month) {
    case 1:
        return 31;
    case 2:
        if (isLeap(year)) {
            return 29;
        }
        else { return 28; }
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    }
}

Date today() {
    time_t t = time(NULL);
    tm* tl = localtime(&t);

    Date currentDate;
    currentDate.year = tl->tm_year + 1900;
    currentDate.month = tl->tm_mon + 1;
    currentDate.day = tl->tm_mday;

    return currentDate;
}


int main() {
    Date currentDate = today();

    Date birthDate;
    birthDate.year = 2024;
    birthDate.month = 2;
    birthDate.day = 27;

    int daysPassed = 0;
    for (int year = birthDate.year; year < currentDate.year; ++year) {
        if (isLeap(year)) {
            daysPassed += 366;
        }
        else {
            daysPassed += 365;
        }
    }

    for (int month = 1; month < birthDate.month; ++month) {
        daysPassed -= monthLength(birthDate.year, month);
    }
    daysPassed -= birthDate.day;

    for (int month = 1; month < currentDate.month; ++month) {
        daysPassed += monthLength(currentDate.year, month);
    }

    daysPassed += currentDate.day;

    cout << "I am: " << daysPassed << " days old" << endl;

    return 0;
}