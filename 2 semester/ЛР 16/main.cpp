#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class FlightBooking {
public:
    FlightBooking();
    void createFlight(int id, int capacity);
    void deleteFlight(int id);
    void addReservations(int id, int numToAdd);
    void cancelReservations(int id, int numToCancel);
    void printFlightStatus(int id);
private:
    int id[10];
    int capacity[10];
    int reserved[10];
};

FlightBooking::FlightBooking() {
    for (int i = 0; i < 10; ++i) {
        id[i] = 0;
        capacity[i] = 0;
        reserved[i] = 0;
    }
}

void FlightBooking::createFlight(int id, int capacity) {
    if (id <= 0 || id > 10 || this->id[id - 1] != 0) {
        cout << "Cannot create flight: invalid ID or flight already exists." << endl;
        return;
    }
    this->id[id - 1] = id;
    this->capacity[id - 1] = capacity;
}

void FlightBooking::deleteFlight(int id) {
    if (id <= 0 || id > 10 || this->id[id - 1] == 0) {
        cout << "Cannot delete flight: flight not found." << endl;
        return;
    }
    this->id[id - 1] = 0;
    this->capacity[id - 1] = 0;
    this->reserved[id - 1] = 0;
}

void FlightBooking::addReservations(int id, int numToAdd) {
    if (id <= 0 || id > 10 || this->id[id - 1] == 0) {
        cout << "Cannot add reservations: flight not found." << endl;
        return;
    }
    int totalSeats = reserved[id - 1] + numToAdd;
    if (totalSeats <= capacity[id - 1] * 1.05) {
        reserved[id - 1] = totalSeats;
    }
    else {
        cout << "Cannot add reservations: capacity reached." << endl;
    }
}

void FlightBooking::cancelReservations(int id, int numToCancel) {
    if (id <= 0 || id > 10 || this->id[id - 1] == 0) {
        cout << "Cannot cancel reservations: flight not found." << endl;
        return;
    }
    int newReserved = reserved[id - 1] - numToCancel;
    if (newReserved >= 0) {
        reserved[id - 1] = newReserved;
    }
    else {
        cout << "Cannot cancel reservations: insufficient reserved seats." << endl;
    }
}

void FlightBooking::printFlightStatus(int id) {
    if (id <= 0 || id > 10 || this->id[id - 1] == 0) {
        cout << "Flight not found." << endl;
        return;
    }
    double percentage = (static_cast<double>(reserved[id - 1]) / capacity[id - 1]) * 100;
    cout << "Flight " << id << " : " << reserved[id - 1] << "/" << capacity[id - 1] << " (" << fixed << setprecision(0) << percentage << "%) seats reserved" << endl;
}

int main() {
    FlightBooking booking;
    string command = "";
    while (command != "quit") {
        cout << "Enter command (create, delete, add, cancel, print, quit): ";
        cin >> command;
        if (command == "create") {
            int id, capacity;
            cin >> id >> capacity;
            booking.createFlight(id, capacity);
        }
        else if (command == "delete") {
            int id;
            cin >> id;
            booking.deleteFlight(id);
        }
        else if (command == "add") {
            int id, numToAdd;
            cin >> id >> numToAdd;
            booking.addReservations(id, numToAdd);
        }
        else if (command == "cancel") {
            int id, numToCancel;
            cin >> id >> numToCancel;
            booking.cancelReservations(id, numToCancel);
        }
        else if (command == "print") {
            int id;
            cin >> id;
            booking.printFlightStatus(id);
        }
    }
    return 0;
}
