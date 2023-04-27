#include <iostream>
using namespace std;

class Node{
public :
    char data;
    Node* next;
};

void add_node(Node* p,char item){
    if(p == nullptr){ // for empty head list
        p = new Node();
        p->data = item;
        p->next = nullptr;
    }
    else{
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = new Node();
        (p->next)->data = item;
        (p->next)->next = nullptr; 
    }
}

int main(){

    Node* head = nullptr;
    
    head = new Node();
    head->data = 'A';
    head->next = nullptr;

    (head->next) = new Node();
    (head->next)->data = 'B';
    (head->next)->next = nullptr;

    (head->next)->next = new Node();
    ((head->next)->next)->data = 'C';
    ((head->next)->next)->next = nullptr;

    cout << head->data << endl;
    cout << (head->next)->data << endl;
    cout << ((head->next)->next)->data << endl;

    add_node(head,'D');

    cout << head->data << endl;
    cout << (head->next)->data << endl;
    cout << ((head->next)->next)->data << endl;
    cout << (((head->next)->next)->next)->data << endl;

    return 0;
}