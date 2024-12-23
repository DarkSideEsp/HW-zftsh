#include <iostream>

using namespace std;

int lengthOfLastWord(string line){
    int pos = line.length() - 1;
    while(isblank(line[pos])){
        pos--;
        if(pos < 0) break;
    }

    int i = pos;
    while(!isblank(line[i])){
        i--;
        if(i < 0) break;
    }

    return pos - i;
}

int main(){
    cout << lengthOfLastWord("I love learning programming ") << "\n";
}