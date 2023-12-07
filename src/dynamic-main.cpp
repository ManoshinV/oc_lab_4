#include <dlfcn.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

void* libHandle = NULL;

float (*Derivative)(float, float) = NULL;
char* (*Transletion)(long) = NULL;

using ptr_derivative = float (*)(float, float);
using ptr_transletion = char *(*)(long);

bool mode = 1;

void messageToUser() {
    cout << "~ Hello, you in a dynamic-main.cpp ~" << endl;
    cout << "~ You can use 4 commands ~" << endl;
    cout << "~ Enter 0 to change contract ~" << endl;
    cout << "~ Enter 1 and two numbers - the point and the increment ~" << endl;
    cout << "~ Enter 2 and the numbers the number for transletion ~" << endl;
    cout << "~ Enter -1 to stop programm ~" << endl;
}

void loadContract() {
    if(mode) {
        libHandle = dlopen("../b/liblib1.so", RTLD_LAZY);
    } else {
        libHandle = dlopen("../b/liblib2.so", RTLD_LAZY);
    }
    Derivative = (ptr_derivative)dlsym(libHandle, "Derivative");
    Transletion = (ptr_transletion)dlsym(libHandle, "Transletion");
}

void changeContract(){
    mode ^= 1;
    dlclose(libHandle);
    loadContract();
}

int main() {
    loadContract();
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
        if(tp == 0) {
            changeContract();
            cout << "Contract changed" << endl;
            continue;
        }
        if(tp == -1) {
            break;
        }
        cout << "Unknown command" << endl;
    }
    dlclose(libHandle);
}
