
#include <iostream>
#include <vector>
#include <algorithm>
#include "Share.h"

using namespace std;

Share :: Share(int x, int y, const vector<int> &commitments) :
x(x), y(y), commitments(commitments) {}

Share :: Share() :
x(0), y(0) {}

int power(int a, int b, int p){
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

bool Share :: verifyShare(int p, int g) {

  // i is share of ith party
  int gsi = power(g, y, p);
    vector<int> temp = commitments;
    reverse(commitments.begin(), commitments.end());
    
  int v = 1;
  for (int idx = 0; idx < commitments.size(); ++idx)
  {
    int temp = power(x, idx, p-1);
    v *= power(commitments[idx], temp, p);
    v%=p;
  }
  // cout<<gsi<<' '<<v<<endl;
  if (gsi == v){
    // cout<<"Verified\n";
    return true;
  }
  else{
    // cout<<"Verification Failed\n";
    return false;
  }
  commitments = temp;


}
