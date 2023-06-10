#include "LinearPolynomial.h"
#include <vector>
using namespace std;

LinearPolynomial :: LinearPolynomial() {
        
}

LinearPolynomial :: LinearPolynomial(int a, int b, int q): q(q) {
        coefficients.push_back(a);
        coefficients.push_back(b);
}

int LinearPolynomial :: evaluate(int x)  {
        return (((coefficients[0]) * (x )) + (coefficients[1]) );
}
