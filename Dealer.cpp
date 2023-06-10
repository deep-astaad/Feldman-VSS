#include <iostream>
#include <vector>
#include <random>
#include "Dealer.h"
#include <time.h>
#include "Share.h"
#include "LinearPolynomial.h"

using namespace std;

/**
 * @brief Constructs the object for dealer.
 * 
 * @param seceret 
 * @param th 
 * @param q 
 * @param totS 
 * @return Dealer 
 */
Dealer :: Dealer(int seceret) :
    KeyGenerator(127), threshold(2), totShares(4) {
        

        initalizeSeive();

        int p_seed = max(2 * q, seceret);
        do{
            p_seed += 1;
            initalizeP(p_seed);
            initalizeG();
            poly = LinearPolynomial(rand() % (p - 1) + 1, seceret, q);
        } while(initalizeCommitments());
}


bool Dealer :: initalizeCommitments() {

    for(int i = 0; i < 2; i++) {
        commitments.push_back(power(g, poly.coefficients[i], p));

        if(commitments.back() == 1) {
            commitments.clear();
            return true;
        }
    }
    
    return false;
}

vector<Share> Dealer :: generateShares() {

    for(int i = 1; i <= totShares; i++) {
        int x = i,
            y = poly.evaluate(x);
            
            shares.push_back(Share(x, y, commitments));
    } 


    return shares;
}


int Dealer :: reconstructMessage(const vector<Share> &newShares) {

    if(newShares.size() < threshold)
        throw std::underflow_error("Not enough newShares.");
    
    int x1 = newShares[0].x,
        x2 = newShares[1].x,
        y1 = newShares[0].y,
        y2 = newShares[1].y;
    
    if(x1 < x2)
        swap(x1, x2),
        swap(y1, y2);
    
    int a1 = (y1 - y2) / (x1 - x2),
        a0 = y1 - a1* x1;
    return a0 % p;
}

// int main() {

//     Dealer myD(50);
//     cout << myD.reconstructMessage(myD.generateShares());

    
// }