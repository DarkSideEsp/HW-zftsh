#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class bigInteger{
private:
    int block_size;
    bool sign;
    vector<int>* num_ptr;

public:
    bigInteger(): block_size(2), sign(false), num_ptr(new vector<int> (1, 0)){}

    bigInteger(int num): block_size(2), sign(false), num_ptr(new vector<int>){
        if(num < 0) sign = true;

        while(num != 0){
            for(int i = 0; i < block_size; i++){
                num_ptr->push_back(num % 10);
                num /= 10;
            }
        }
        reverse(num_ptr->begin(), num_ptr->end());
    }

    ~bigInteger(){
        delete num_ptr;
        num_ptr = nullptr;
    }
};

int main(){
    bigInteger a = bigInteger();
    bigInteger b = bigInteger(134);
    bigInteger c = bigInteger(-1278);
}