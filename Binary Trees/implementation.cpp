#include<iostream>
#include<queue>
#include<stack>
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
//NLR
void preorderTraversal(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    //left
    preorderTraversal(root->left);
    //right
    preorderTraversal(root->right);
}
//LNR
void inorderTraversal(Node* root){
    if(root == NULL) return;
    //left
    inorderTraversal(root->left);
    //N
    cout<<root->data<<" ";
    //right
    inorderTraversal(root->right);
}
//LRN
void postorderTraversal(Node* root){
    if(root == NULL) return;
    //left
    postorderTraversal(root->left);
    //right
    postorderTraversal(root->right);
    //N
    cout<<root->data<<" ";
}
void levelOrderTraversal(Node*root){
    queue<Node*> q;
    if(root==NULL) return;
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
            Node* leftChild = front->left;
            Node* rightChild = front->right;
            if(leftChild!= NULL) q.push(leftChild);
            if(rightChild!= NULL) q.push(rightChild);
        }
    }
}
     vector<vector<int> > zigzagLevelOrder(Node* root) {
        queue<Node*> q;
        stack<Node*> st;
        bool nextRight = true;
        vector<vector<int> > ans;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node * front = q.front();
            cout<<" "<<front->data<<" ";
            q.pop();
            if(front == NULL){
                nextRight = !nextRight;
                vector<int> level;
                bool isNotEmpty = !st.empty();
                while(!st.empty()){
                    Node * top = st.top();
                    st.pop();
                    q.push(top);
                    cout<<endl;
                    level.push_back(top->data);
                }
                cout<<endl;
                if(isNotEmpty) ans.push_back(level);
                if(!q.empty()) q.push(NULL);
            }
            else{
                if(nextRight){
                    if(front->left != NULL) st.push(front->left); 
                    if(front->right != NULL) st.push(front->right); 
                    }
                    else{
                    if(front->right != NULL) st.push(front->right); 
                    if(front->left != NULL) st.push(front->left); 
                }
            }
            
        } 
        return ans;
    }
      void sumHelper(Node *root,int k , int &count){
      if(root==NULL) return;
      k = k - root->data;
      if(k==0){
          count++;
      }
      sumHelper(root->left,k,count);
      sumHelper(root->right,k,count);
      
          
  }
    int sumK(Node *root,int k)
    {
        int count = 0;
        sumHelper (root,k,count);
        return count;
        // code here 
    }
int main(){
Node * root = createTree();
// levelOrderTraversal(root);
// vector<vector<int> > ans = zigzagLevelOrder(root);
// for (auto i:ans)
// {
//     cout<<i<<" ";
// }
// cout<<"he";
cout<<sumK(root,5);
return 0;
}