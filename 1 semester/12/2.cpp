#include <iostream>
using namespace std;

struct Date {
    int hours;
    int minutes;
};

int main() {
    Date startTime, endTime;

    cout << "Enter the start time of the event: ";
    cin >> startTime.hours;

    cout << "Enter the minutes of the event start: ";
    cin >> startTime.minutes;

    cout << "Enter the end time of the event:";
    cin >> endTime.hours;

    cout << "Enter the minutes of the event completion:";
    cin >> endTime.minutes;

    int startTotalMinutes = startTime.hours * 60 + startTime.minutes;
    int endTotalMinutes = endTime.hours * 60 + endTime.minutes;
    int durationTotalMinutes = endTotalMinutes - startTotalMinutes;

    int durationHours = durationTotalMinutes / 60;
    int durationMinutes = durationTotalMinutes % 60;

    cout << "Duration of the event: " << durationHours << "hours " << durationMinutes << "minutes" << endl;

    return 0;
}
