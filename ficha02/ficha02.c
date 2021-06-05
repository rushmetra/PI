#include <stdio.h>

float multInt1(int n, float m) {
    float r = 0;
    int i;
    for(int i = 1; i <= n; i++) {
        r  += m;
    }
    return r;
}

float multInt2(int n, float m) {
    float r = 0;
    while(n > 0) {
        if(n % 2) r += m;
        n /= 2;
        m *= 2;
    }
    return r;
}

int mdc1(int a, int b) {
    int temp, ans;
    if(a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    for(int i = 1; i <= b; i++) {
        if(a % i == 0 && b % i == 0) ans = i;
    }
    return ans;
}

int mdc2 (int a, int b){
    while(a != 0 && b != 0) {
        if(a>b) a -= b;
        else if(b > a) b -=a;
        else return a;
    }
    if(a == 0) return b;
    else return a;
}

int mdc4 (int a, int b){
    while(a != 0 && b != 0) {
        if(a>b) a %= b;
        else if(b > a) b %=a;
        else return a;
    }
    if(a == 0) return b;
    else return a;
}

int fib (int n) {
    if(n == 1 || n == 2) return 1;
    else return fib(n - 1) + fib(n - 2);
}

int fib2(int n) {
    int temp, aux1 = 1, aux2 = 1;
    for(i = 3; i <= n; i++) {
        temp = aux2;
        aux2 += aux1;
        aux1 = temp;
    }
    return aux2;
}

int main() {
    int n1 = 4, n2 = 81;
    float res, m1 = 3, m2 = 423;
    //res = multInt1(n1,m1);
    res = multInt2(n2, m2);
    printf("%f\n", res);
    return 0;
}