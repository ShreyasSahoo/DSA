#include<iostream>
#include<queue>
using namespace std;
class Node{
public:
int data;
Node * left;
Node * right;
Node(int data){
    this->data= data;
}
};
Node* BSTfromInorder(int inorder[],int start,int end){
    if(start>end) return NULL;
    int mid = start + (end-start)/2;
    int middleElement = inorder[mid];
    Node * root = new Node(middleElement);
    root->left = BSTfromInorder(inorder,start,mid-1);
    root->right = BSTfromInorder(inorder,mid+1,end);
    return root;
}
void levelOrderTraversal(Node * root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * front = q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
        cout<<" "<<front->data;
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
}
int main(){
int inorder[] = {10,20,30,40,50,60,70,80};
Node * root = BSTfromInorder(inorder,0,7);
levelOrderTraversal(root);
return 0;
}