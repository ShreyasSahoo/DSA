#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node * left, * right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
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
void leftEdge(Node * root,vector<int> &ans){
        //leaf node
        if(root == NULL) {
		return;
	}
        if(root->left == NULL && root->right == NULL) return;
        ans.push_back(root->data);
        if(root->left != NULL) leftEdge(root->left,ans);
        else leftEdge(root->right,ans);
    }
    void leafNodes(Node * root,vector<int> & ans){
        if(root == NULL) return;
        if(root->left == NULL & root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
    }
    void rightEdge(Node * root,vector<int> &ans){
        if(root == NULL) {
		return;
	}
        if(root->left == NULL && root->right == NULL) return;
        if(root->right != NULL) rightEdge(root->right,ans);
        else rightEdge(root->left,ans);
        ans.push_back(root->data);
    }
int main(){
    Node* root = createTree();
    vector<int> ans;
    cout<<endl<<root->data<<endl;
    leftEdge(root,ans);
    cout<<endl<<root->data<<endl;
    leafNodes(root,ans);
    for (auto i : ans)
    {
        /* code */cout<<" "<<i;
    }
   // 1 2 -1 -1 3 4 -1 5 7 -1 -1 -1 6 -1 -1
return 0;
}