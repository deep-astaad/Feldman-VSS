/**
 * @file ShareHolder.h
 * @author Aman Deep Singh
 * @brief 
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __SHAREHOLDER_H__
#define __SHAREHOLDER_H__

#include <iostream>
#include <vector>
#include <random>
#include "Share.h"

/**
 * @brief Represents the dealer who generates and distributes shares.
 * 
 */
class ShareHolder {

    int p, g;

    public:
    
    Share share;
    ShareHolder(Share share, int p, int g);
    bool verify();

};

#endif