
#ifndef __DEALER_H__
#define __DEALER_H__

#include <iostream>
#include <vector>
#include <random>
#include "Share.h"
#include "LinearPolynomial.h"
#include "KeyGenerator.h"

using namespace std;
/**
 * @brief Represents the dealer who generates and distributes shares.
 * 
 */
class Dealer : public KeyGenerator{

    const int threshold,
              totShares;

    LinearPolynomial poly;
    vector<Share> shares;
    vector<int> commitments;

    public:

    /**
     * @brief initalizes commitments respective to each coefficient.
     * 
     * @return true 
     * @return false 
     */
    bool initalizeCommitments();
    
    Dealer(int seceret);

    /**
     * @brief Generates 4.
     * 
     * @return vector<Share> 
     */
    vector<Share> generateShares();

    int reconstructMessage(const vector<Share> &shares);
    
    friend class Share; 
};

#endif