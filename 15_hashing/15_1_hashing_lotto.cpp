#include<iostream>
using namespace std;

int main(){

    int box[100000] = {0};

    box[00]++; // insert 00
    box[00]++; // insert 00
    box[01]++; // insert 01
    box[01]++; // insert 01
    box[01]++; // insert 01
    box[03]++; // insert 03

    box[89654]++; // insert 0089654
    box[89654]++; // insert 0089654

    for(int i =0;i<5;i++){
        cout << "box[" << i << "] -> " << box[i] << endl; // access
    }
    cout << "box[89654] -> " << box[89654] << endl; // access

    return 0;
}