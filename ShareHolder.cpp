#include "ShareHolder.h"
#include <iostream>

using namespace std;

ShareHolder :: ShareHolder(Share share, int p, int g) : share(share), p(p), g(g) {}

bool ShareHolder :: verify() {

    return share.verifyShare(p, g);
}

