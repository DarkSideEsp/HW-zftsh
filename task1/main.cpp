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
    cout << mySqrt(4) << "\n";
    cout << mySqrt(5) << "\n";
    cout << mySqrt(6) << "\n";
    cout << mySqrt(7) << "\n";
    cout << mySqrt(8) << "\n";
    cout << mySqrt(9) << "\n";
    cout << mySqrt(10) << "\n";
}