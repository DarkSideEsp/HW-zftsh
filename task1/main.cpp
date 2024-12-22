#include <iostream>

using namespace std;

int mySqrt(int x){
    int l = 1;
    int r = x;
    int mid = (l + r) / 2;
    while(r - l > 1){
        mid = (l + r) / 2;
        if(mid * mid <= x) l = mid;
        else r = mid;
    }

    return l;
}

int main(){
    cout << mySqrt(3) << "\n";
}