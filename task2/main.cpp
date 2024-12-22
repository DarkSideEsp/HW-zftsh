#include <iostream>

using namespace std;

bool isPalindrome(string line){
    string newline = "";
    for(auto i : line) if(isalnum(i)) newline += i; // :)

    bool ans = true;
    for(int i = 0; i < newline.size() / 2; i++){
        if(newline[i] != newline[newline.size() - i - 1]){
            ans = false;
            break;
        }
    }

    return ans;
}

int main(){
    cout << isPalindrome("some838///emos") << "\n";
}