/**
 * @file Polynomial.h
 * @author Aman Deep Singh
 * @brief 
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __LINEAR_POLYNOMIAL__
#define __LINEAR_POLYNOMIAL__

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Class to represent a linear polynomial in q field.
 * 
 */
class LinearPolynomial {
public:

    std::vector<int> coefficients; // Coefficients of the linear polynomial
    int q;

    LinearPolynomial();

     /**
      * @brief Construct a new Linear Polynomial object
      * 
      * @param a 
      * @param b 
      * @param q
      */
    LinearPolynomial(int a, int b, int q);

    /**
     * @brief Construct a new Linear Polynomial object
     * 
     * @param lp 
     */
    LinearPolynomial(LinearPolynomial &lp) {
        coefficients = lp.coefficients;
        q = lp.q;
    }

    /**
     * @brief Function to evaluate the polynomial at a given x value
     * 
     * @param x 
     * @return int 
     */
    int evaluate(int x);

    /**
     * @brief reinitialize the polynomial
     * 
     * @param a 
     * @param b 
     * @param q 
     */
    void init(int a, int b, int q);

};

#endif