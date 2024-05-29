#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_ob_seats);
    bool cancelReservations(int number_ob_seats);
private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
    : id(id), capacity(capacity), reserved(reserved)
{
    // Limit reservations to 105% of capacity
    if (reserved > capacity * 1.05) {
        this->reserved = capacity * 1.05;
    }
    else if (reserved < 0) {
        this->reserved = 0;
    }
}

void FlightBooking::printStatus() {
    double occupancy = (static_cast<double>(reserved) / capacity) * 100;
    cout << "Flight " << id << " : " << reserved << "/" << capacity << " seats reserved (" << fixed << setprecision(0) << occupancy << "%)\n";
}

bool FlightBooking::reserveSeats(int number_ob_seats) {
    int totalSeats = reserved + number_ob_seats;
    if (totalSeats <= capacity * 1.05) {
        reserved = totalSeats;
        return true;
    }
    return false;
}

bool FlightBooking::cancelReservations(int number_ob_seats) {
    int totalSeats = reserved - number_ob_seats;
    if (totalSeats >= 0) {
        reserved = totalSeats;
        return true;
    }
    return false;
}

int main() {
    int reserved = 0, capacity = 0;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;

    FlightBooking booking(1, capacity, reserved);
    string command;
    int num;

    while (true) {
        booking.printStatus();
        cout << "What would you like to do? (add [n]/cancel [n]/quit): ";
        cin >> command;

        if (command == "add") {
            cin >> num;
            if (!booking.reserveSeats(num)) {
                cout << "Cannot perform this operation\n";
            }
        }
        else if (command == "cancel") {
            cin >> num;
            if (!booking.cancelReservations(num)) {
                cout << "Cannot perform this operation\n";
            }
        }
        else if (command == "quit") {
            break;
        }
        else {
            cout << "Invalid command\n";
        }
    }

    return 0;
}
