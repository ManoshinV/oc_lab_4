#include "derivative-transletion.h"

float Derivative(float A, float deltaX){
    return (cos(A + deltaX) - cos(A)) / deltaX;
}
char* Transletion(long x){
    char *ans = (char*)malloc(sizeof(char) * 100);
    int n = 0;
    while(x > 0) {
        ans[n] = (x % 2) + '0';
        x /= 2;
        ++n;
    }
    for(int i = 0 ; i < n / 2; ++i){
        char a = ans[i];
        ans[i] = ans[n - i - 1];
        ans[n - i - 1] = a;
    }
    return ans;
}
