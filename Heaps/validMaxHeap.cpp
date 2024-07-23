#include<iostream>
using namespace std;
class Node{
public:
int data;
Node * left, * right;
Node(int data){
    this->data = data;
    left = right = NULL;
}
};
pair<int,bool> validHeap(Node * root){
//null 
if(root == NULL){
    pair<int,bool> res = make_pair(INT_MIN,true);
    return res;
}
//leaf node
else if(root->left == NULL && root->right == NULL){
     pair<int,bool> res = make_pair(root->data,true);
     return res;
}
pair<int,bool> rightResult,leftResult;
//root should be greater than left and right child
if(root->left){
    if(root->data < root->left->data){
        pair<int,bool> res = make_pair(root->data,false);
        return res;
    }
     leftResult = validHeap(root->left);
}
if(root->right){
    if(root->data < root->right->data){
        pair<int,bool> res = make_pair(root->data,false);
        return res;
    }
    rightResult = validHeap(root->right);
    
}
    bool valid = (leftResult.second && rightResult.second);
    pair<int,bool> answer = make_pair(root->data,valid);
}
Node* createTree(){
    cout<<"Enter the data for the root : ";
    int data;
    cin>>data;
    if(data == - 1) return NULL;
    Node * root = new Node(data);
    cout<<"left Node of the Node "<<root->data<<endl;
    root->left = createTree();
    cout<<"Right Node of the Node "<<root->data<<endl;
    root->right = createTree();
    return root;
}
int main(){
Node * root = createTree();
pair<int,bool> answer = validHeap(root);
cout<<answer.first<<" "<<answer.second;
return 0;
}