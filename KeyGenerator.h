/**
 * @file KeyGenerator.h
 * @author Aman Deep Singh
 * @brief 
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __KEY_GENERATOR__
#define __KEY_GENERATOR__

#include <vector>
using namespace std;

class KeyGenerator {

    protected:

    int q;
    vector<bool> sieve;

    /**
     * @brief initializes a large prime to p greater than s.
     * 
     * @param s 
     */
    void initalizeP(int &s);

    /**
     * @brief initalizez the primitive root of p.
     * 
     */
    void initalizeG();

    /**
     * @brief initalizes seive of Erasthothenes.
     * 
     */
    void initalizeSeive();

    public : 

    int p, g;
    
    /**
     * @brief binary exponentiation function.
     * 
     * @param a 
     * @param b 
     * @param p 
     * @return int 
     */
    int power(int a, int b,int p);

    /**
     * @brief Construct a new Key Generator object
     * 
     * @param q 
     */
    KeyGenerator(int q);
};

#endif