#include <iostream>
#include <vector>
using namespace std;

class Node{
public :
    char data;
    Node* left;
    Node* right;

    Node(char item){
        data = item;
        left = nullptr;
        right = nullptr;
    }
};


class BST{
public:
    Node *root = nullptr;

    void insert(char item){
        if(root == nullptr){
            root = new Node(item);
        }
        else{
            Node* p = root;
            while(true){
                if(item < p->data){ // go left
                    if(p->left == nullptr){ 
                        p->left = new Node(item);
                        break;
                    }
                    else p = p->left;
                }
                else{
                    if(p->right == nullptr){
                        p->right = new Node(item);
                        break;
                    }
                    else p = p->right;                   
                }
            }
        }
    }

    bool search(char item){
        Node *p = root;
        while(p != nullptr){
            if(item == p->data){
                return true;
            }
            else if(item < p->data){
                p=p->left;
            }
            else{
                p=p->right;
            }
        }
        return false;
    }

    void print_tree(){
        int depth = find_depth(0,root) + 1;
        int width = pow2(depth);
        vector<vector<char>> table;
        for(int i=0;i<depth*2;i++){
            table.push_back(vector<char>());
            for(int j=0;j<width + 1;j++){
                table[i].push_back(' ');
            }
        }

        print_vector(&table,0,width/2,width/4,root);

        for(int i=0;i<(depth - 1) * 2;i++){
            for(int j=0;j<width;j++){
                cout << table[i][j];
            }
            cout << endl;
        }
    }

    void print_preorder(){      preorder(root); }
    void print_inorder(){       inorder(root);  }
    void print_postorder(){     postorder(root); }

private:
    void preorder(Node* p){
        if(p == nullptr) return;

        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }

    void inorder(Node* p){
        if(p == nullptr) return;
        
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }

    void postorder(Node* p){
        if(p == nullptr) return;
    
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }

    int max(int a,int b){
        if(a > b) return a;
        return b;
    }

    int find_depth(int n,Node* p){
        if(p == nullptr) return n;
        return max(find_depth(n+1,p->left) , find_depth(n+1,p->right));
    }

    int pow2(int n){
        int result = 1;
        for(int i=0;i<n;i++){
            result *= 2;
        }
        return result;
    }

    void print_vector(vector<vector<char>> *v,int level,int loc,int space,Node* p){

        if( p == nullptr) return;
        (*v)[level][loc] = p->data;

        if(p->left != nullptr){
            for(int i=0;i<space - 2;i++){
                (*v)[level][loc - i - 1] = '_';
            }
            (*v)[level+1][loc - space + 1] = '/';
            print_vector(v,level+2,loc - space,space/2,p->left);
        }

        if(p->right != nullptr){
            for(int i=0;i<space - 2;i++){
                (*v)[level][loc + i + 1] = '_';
            }
            (*v)[level+1][loc + space - 1] = '\\';
            print_vector(v,level+2,loc + space,space/2,p->right);
        }
    }
};

void delete_node(Node** n){
    if((*n)->left == nullptr && (*n)->right == nullptr){ // leaf node (case 1)
        delete (*n);
        (*n) = nullptr;
    }
    else if((*n)->left == nullptr){ // replace with right node (case 2)
        (*n) = (*n)->right;
    }
    else if((*n)->right == nullptr){ // replace with left node (case 2)
        (*n) = (*n)->left;
    }
    else{ // replace with next inorder and process to next inorder node (case 3)
        Node** p = &((*n)->right);
        while((*p)->left != nullptr){
            p = &((*p)->left);
        }
        (*n)->data = (*p)->data;
        delete_node(p);
    }
}

int main(){

    BST tree;
    tree.insert('H');
    tree.insert('A');
    tree.insert('R');
    tree.insert('H');
    tree.insert('U');
    tree.insert('I');

    tree.print_preorder(); 
    cout << endl;
    tree.print_inorder();
    cout << endl;
    tree.print_postorder(); 

    cout << endl;
    tree.print_tree();

    delete_node(&(tree.root->left));// A
    delete_node(&(tree.root->right));
    delete_node(&(tree.root->right));
   

    tree.print_preorder(); 
    cout << endl;
    tree.print_inorder();
    cout << endl;
    tree.print_postorder(); 

    cout << endl;
    tree.print_tree();


/*
    BST tree2;
    tree2.insert('G');
    tree2.insert('O');
    tree2.insert('I');
    tree2.insert('N');
    tree2.insert('G');
    tree2.insert('M');
    tree2.insert('E');
    tree2.insert('R');
    tree2.insert('T');
    tree2.insert('Y');

    tree2.print_preorder(); 
    cout << endl;
    tree2.print_inorder();
    cout << endl;
    tree2.print_postorder(); 

    delete_node(&(tree2.root->right->left));
    delete_node(&((tree2.root->right->left)->right));
    delete_node(&((tree2.root->right->right)->right));
    delete_node(&((tree2.root->right->right)->right));

    cout << endl;
    tree2.print_tree();
*/
/*
    BST tree3;
    tree3.insert('A');
    tree3.insert('B');
    tree3.insert('C');
    tree3.insert('D');
    tree3.insert('E');
    tree3.insert('F');
    tree3.insert('G');
    tree3.insert('H');


    tree3.print_preorder(); 
    cout << endl;
    tree3.print_inorder();
    cout << endl;
    tree3.print_postorder(); 

    delete_node(&(tree3.root));
    delete_node(&(tree3.root));
    delete_node(&(tree3.root));
    delete_node(&(tree3.root));


    cout << endl;
    tree3.print_tree();
*/
    return 0;
}