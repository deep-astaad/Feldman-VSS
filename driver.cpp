#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include "Share.h"
#include "ShareHolder.h"
#include "Dealer.h"

void printBlock(const string& text) {
    int width = text.length() + 4;
    string horizontalLine(width, '=');
    cout << "" << horizontalLine << "" << endl;
    cout << "" << "= " << "" << text << "" << " =" << "" << endl;
    cout << "" << horizontalLine << "" << endl;
}

int main() {

    #define SIZE 2

    vector<uint8_t> secret(32);

    printBlock("Enter the Secret");

    cout << "Enter the secret (32 space-separated uint8_ts): ";
    for (int i = 0; i < SIZE; ++i) {
        int uint8_tValue;
        cin >> hex >> uint8_tValue;
        secret[i] = static_cast<uint8_t>(uint8_tValue);
    }

    for (int i = 0; i < SIZE; ++i) {
        int curBlock = static_cast<int>(secret[i]);

        cout << endl;
        printBlock("Block " + to_string(i + 1));

        cout << "Initial value: " << hex << uppercase << curBlock << "" << endl;

        Dealer myDealer(curBlock);

        vector<Share> shares = myDealer.generateShares();

        int shareA, shareB;
        cout << "Enter the two shares (separated by a space): ";
        cin >> shareA >> shareB;

        if (shareA < 0 || shareB < 0 || shareA > 3 || shareB > 3 || shareA == shareB) {
            cout << "ERROR" << endl;
            continue;
        }

        vector<Share> avilShares = {shares[shareA], shares[shareB]};

        int reconstBlock = myDealer.reconstructMessage(avilShares);
        
        cout << "\n==================================" << endl;
        cout << "=        Share Details            =" << endl;
        cout << "==================================" << endl;

        cout << "Reconstructed value: " << hex << uppercase << reconstBlock << "" << endl;
        cout << "Y coordinate of share " << shareA << ": " << shares[shareA].y << "" << endl;
        cout << "X coordinate of share " << shareA << ": " << shares[shareA].x << "" << endl;
        cout << "Commitment of the coefficients: ";
        for(auto comm : shares[shareA].commitments)
            cout << comm << " ";
        cout << "" << endl;
        cout << "Y coordinate of share " << shareB << ": " << shares[shareB].y << "" << endl;
        cout << "X coordinate of share " << shareB << ": " << shares[shareB].x << "" << endl;
        cout << endl;

    }

    return 0;
}
