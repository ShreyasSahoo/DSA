#include<iostream>
#include<queue>
using namespace std;
class Node{
public:
int data;
Node * left;
Node * right;
Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}
};
Node* insertBST(int data,Node * root) {
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data<root->data){
       root->left = insertBST(data,root->left);
    }
    else{
        root->right = insertBST(data,root->right);
    }
    return root;
}
void createBST(Node * &root){
    int data;
    cout<<"Enter Data"<<endl;
    cin>>data;
    
    while(data != -1){
    root = insertBST(data,root);
    cout<<"Enter Data"<<endl;
    cin>>data;
    }
}
void levelOrderTraversal(Node * root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * front = q.front();
        q.pop();
        if(front == NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<front->data<<" ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
}
void preOrderTraversal(Node * root){

    if(root==NULL) return ;

    cout<<" "<<root->data;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(Node * root){

    if(root==NULL) return ;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<" "<<root->data;
}
void inOrderTraversal(Node * root){

    if(root==NULL) return ;

    inOrderTraversal(root->left);
    cout<<" "<<root->data;
    inOrderTraversal(root->right);
}
int minValue(Node * root){
    if(root == NULL) return -1;
    Node * temp = root;
    while(temp){
       temp =  temp->left;
    }
    return temp->data;
}
int maxValue(Node * root){
    if(root == NULL) return -1;
    Node * temp = root;
    while(temp){
       temp =  temp->right;
    }
    return temp->data;
}
bool searchBST(Node * root,int target){
    if(root==NULL) return false;

    if(root->data = target) return true;

    else if(root->data>target)
    {
        return searchBST(root->left,target);
    }
    else if(root->data<target)
    {
        return searchBST(root->right,target);
    }
}
int main(){
Node * root = NULL;
createBST(root);
inOrderTraversal(root);
return 0;
}