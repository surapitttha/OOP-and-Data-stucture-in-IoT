#include<iostream>
using namespace std;

int hash_function(int in){
    return (in%100);
}

int main(){

    int box[100] = {0};

    box[hash_function(00)]++; // insert 00
    box[hash_function(00)]++; // insert 00
    box[hash_function(01)]++; // insert 01
    box[hash_function(01)]++; // insert 01
    box[hash_function(01)]++; // insert 01
    box[hash_function(03)]++; // insert 03

    box[hash_function(89654)]++; // insert 03
    box[hash_function(89654)]++; // insert 03

    for(int i =0;i<5;i++){
        cout << "box[" << i << "] -> " << box[hash_function(i)] << endl; // access
    }
    cout << "box[89654] -> " << box[hash_function(89654)] << endl; // access

    return 0;
}