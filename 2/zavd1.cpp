#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a;
    int b;
    int c;
    int x;
    double w;
    
    cout << "x value";
    cin >> x;
    cout << "a value";
    cin >> a;
    cout << "b value";
    cin >> b;
    cout << "c value";
    cin >> c;
    
    if (b<5) {
        w = pow(4-x, a*b);
    }
    else if (b>=c) {
        w = (0,25)+(b*c);
        }
    cout <<"Result" << w;
}