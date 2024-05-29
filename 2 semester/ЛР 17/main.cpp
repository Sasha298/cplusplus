#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Member {
public:
    int id;
    string name;
    int months;

    Member(int memberId, string memberName) : id(memberId), name(memberName), months(0) {}
};

class Gym {
private:
    vector<Member> members;

    Member* findMember(int id) {
        for (auto &member : members) {
            if (member.id == id) {
                return &member;
            }
        }
        return nullptr;
    }

public:
    Gym() {
        members.reserve(10); // Максимальна кількість членів - 10
    }

    void create(int id, string name) {
        if (members.size() >= 10) {
            cout << "Cannot perform this operation: Maximum number of members reached." << endl;
            return;
        }
        if (findMember(id) != nullptr) {
            cout << "Cannot perform this operation: Member with ID " << id << " already exists." << endl;
            return;
        }
        members.emplace_back(id, name);
        cout << "Member " << id << " : " << name << ", subscription valid for 0 months" << endl;
    }

    void deleteMember(int id) {
        for (auto it = members.begin(); it != members.end(); ++it) {
            if (it->id == id) {
                members.erase(it);
                cout << "Member with ID " << id << " deleted." << endl;
                return;
            }
        }
        cout << "Cannot perform this operation: Member with ID " << id << " does not exist." << endl;
    }

    void extend(int id, int n) {
        Member* member = findMember(id);
        if (member == nullptr) {
            cout << "Cannot perform this operation: Member with ID " << id << " does not exist." << endl;
            return;
        }
        member->months += n;
        cout << "Member " << id << " : " << member->name << ", subscription valid for " << member->months << " months" << endl;
    }

    void cancel(int id) {
        Member* member = findMember(id);
        if (member == nullptr) {
            cout << "Cannot perform this operation: Member with ID " << id << " does not exist." << endl;
            return;
        }
        member->months = 0;
        cout << "Member " << id << " : " << member->name << ", subscription valid for 0 months" << endl;
    }

    void printMembers() {
        if (members.empty()) {
            cout << "No members in the system" << endl;
            return;
        }
        for (const auto &member : members) {
            cout << "Member " << member.id << " : " << member.name << ", subscription valid for " << member.months << " months" << endl;
        }
    }
};

int main() {
    Gym gym;
    string command;

    while (true) {
        cin >> command;

        if (command == "create") {
            int id;
            string firstName, lastName;
            cin >> id >> firstName >> lastName;
            gym.create(id, firstName + " " + lastName);
        } else if (command == "delete") {
            int id;
            cin >> id;
            gym.deleteMember(id);
        } else if (command == "extend") {
            int id, months;
            cin >> id >> months;
            gym.extend(id, months);
        } else if (command == "cancel") {
            int id;
            cin >> id;
            gym.cancel(id);
        } else if (command == "quit") {
            break;
        }

        gym.printMembers();
    }

    return 0;
}


