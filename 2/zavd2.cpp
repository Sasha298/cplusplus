#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x;
    int y;
    double w;
    
    cout << "x value";
    cin >> x;
    cout << "y value";
    cin >> y;
    
    if (x>=0 && x <=3 && y >= 0 && y <=1) {
        cout <<"WIN";
    }
    else if (x>0) {
        cout <<"LOSE";
        }
  
}