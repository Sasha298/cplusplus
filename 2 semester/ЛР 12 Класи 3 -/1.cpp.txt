#include <iostream>
#include <cmath> 
using namespace std;
class AdHocSquare
{
public:
    AdHocSquare(double side);
    void set_side(double side);
    double get_area();
private:
    double side;
};

AdHocSquare::AdHocSquare(double side) : side(side) {}

void AdHocSquare::set_side(double side)
{
    this->side = side;
}

double AdHocSquare::get_area()
{
    return side * side;
}

class LazySquare
{
public:
    LazySquare(double side);
    void set_side(double side);
    double get_area();
private:
    double side;
    double area;
    bool side_changed;
};

LazySquare::LazySquare(double side) : side(side), area(side* side), side_changed(false) {}

void LazySquare::set_side(double side)
{
    this->side = side;
    side_changed = true;
}

double LazySquare::get_area()
{
    if (side_changed) {
        area = side * side;
        side_changed = false;
    }
    return area;
}

int main()
{
    AdHocSquare aSquare(4);
    cout << "AdHocSquare area: " << aSquare.get_area() << endl;
    aSquare.set_side(2.0);
    cout << "AdHocSquare area after side change: " << aSquare.get_area() << endl;

    LazySquare lSquare(6);
    cout << "LazySquare area: " << lSquare.get_area() << endl;
    lSquare.set_side(1.0);
    cout << "LazySquare area after side change: " << lSquare.get_area() << endl;

    return 0;
}