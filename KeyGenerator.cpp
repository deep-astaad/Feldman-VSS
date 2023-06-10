#include "KeyGenerator.h"
#include <iostream>
#include <vector>

using namespace std;

KeyGenerator :: KeyGenerator(int q) : p(-1), g(-1), q(q) {
    
}

void KeyGenerator :: initalizeSeive()  {
    sieve = vector<bool> (1e6, true);
    int n = sieve.size();
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
}

int KeyGenerator :: power(int a, int b, int p){
    int ans = 1;
    a%=p;
    while(b){
        if(b&1) ans*=a;
        ans%=p;
        a*=a;
        a%=p;
        b>>=1;
    }
    return ans;
}


void KeyGenerator :: initalizeP(int &i) {

    for(; i < 1e6; i += 1) {
        if((i - 1) % q == 0 && sieve[i]) {
            p = i;
            break;
        }
    }

    if(p == -1)
        throw domain_error("No p value possible!");
}

void KeyGenerator :: initalizeG() {

    for(int i = p - 2; i >= 2; i--) {

        if(power(i, (p - 1) / q, p) == 1) {
            g = i;
            break;
        }
    }

    if(g == -1)
        throw domain_error("No possible g value possible!");

}
