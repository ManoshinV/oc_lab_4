extern "C" {
    #include "derivative-transletion.h"
}
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void messageToUser() {
    cout << "~ Hello, you in a dynamic-main.cpp ~" << endl;
    cout << "~ You can use 3 commands ~" << endl;
    cout << "~ Enter 1 and two numbers - the point and the increment ~" << endl;
    cout << "~ Enter 2 and the numbers the number for transletion ~" << endl;
    cout << "~ Enter -1 to stop programm ~" << endl;
}

int main() {
    messageToUser();
    while (1) {
        int tp;
        cin >> tp;
        if(tp == 1) {
            float A, deltaX;
            cin >> A >> deltaX;
            cout << "Derivative = " << Derivative(A, deltaX) << endl;
            continue;
        }
        if(tp == 2) {
            long x;
            cin >> x;
            cout << "Transletion = " << Transletion(x) << endl;
            continue;
        }
        if(tp == -1) {
            break;
        }
        cout << "Unknown command" << endl;
    }
}
