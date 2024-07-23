#include<iostream>
#include<queue>
using namespace std;
class Node{
public:
int val;
Node * left, * right;
Node(int val){
    this->val = val;
    left = right = NULL;
}
};
 Node* createTree(){
    cout<<"Enter the data for the root : ";
    int data;
    cin>>data;
    if(data == - 1) return NULL;
    Node * root = new Node(data);
    cout<<"left Node of the Node "<<root->val<<endl;
    root->left = createTree();
    cout<<"Right Node of the Node "<<root->val<<endl;
    root->right = createTree();
    return root;
}

    void preorderCount(Node * root,int &count){
        if(root == NULL) return;
        preorderCount(root->left,count);
        count++;
        preorderCount(root->right,count);
    }
    int levelorderCounting(Node * root){
        queue<Node *> q;
        int count = 0;
        q.push(root);
        while(!q.empty()){
            Node * front = q.front();
            q.pop();
            count++;
            //dont push nodes if it is a leaf node
            if(front->left == NULL && front->right == NULL){
                continue;
            }
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        return count;
    }
    bool isCompleteTree(Node* root) {
        int numberOfNodes = 0;
        preorderCount(root,numberOfNodes);
        cout<<numberOfNodes<<endl;

        int levelOrderCount = levelorderCounting(root);
         cout<<levelOrderCount<<endl;
        return numberOfNodes==levelOrderCount;
    }

int main(){
Node * root = createTree();
cout<<isCompleteTree(root);
return 0;
}