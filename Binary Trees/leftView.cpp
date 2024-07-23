#include<iostream>
#include<queue>
#include<map>
using namespace std;
class Node {
public:
    int data;
    Node * left, * right;
    Node(int data){
    this->data = data;
    }
};
void leftView(Node * root,int level,vector<int> & ans){
    if(root == NULL) return;

    //N
    if(ans.size()==level) ans.push_back(root->data);
    //left
    leftView(root->left,level+1,ans);
    //right
    leftView(root->right,level+1,ans);
}
void rightView(Node * root,int level,vector<int> & ans){
    if(root == NULL) return;

    //N
    if(ans.size()==level) ans.push_back(root->data);
    //right
    rightView(root->right,level+1,ans);
    //left
    rightView(root->left,level+1,ans);
}
void topView(Node * root){
    if(root == NULL) return ;
    queue< pair <Node*,int> > q;
    q.push(make_pair(root,0));
    map <int,int> hdToNodeMap;
   
    while(!q.empty()){
        pair<Node *,int> front = q.front();
        q.pop();
       Node* frontNode = front.first;
       int hd = front.second;
       //hd not found
        if(hdToNodeMap.find(hd) == hdToNodeMap.end()){
            hdToNodeMap[hd] = frontNode->data;
        }
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
        
    }
    for (auto i:hdToNodeMap)
        {
            cout<<" "<<i.second;
        }
}
void bottomView(Node * root){
    if(root == NULL) return ;
    queue< pair <Node*,int> > q;
    q.push(make_pair(root,0));
    map <int,int> hdToNodeMap;
   
    while(!q.empty()){
        pair<Node *,int> front = q.front();
        q.pop();
       Node* frontNode = front.first;
       int hd = front.second;
            hdToNodeMap[hd] = frontNode->data;
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
        
    }
    for (auto i:hdToNodeMap)
        {
            cout<<" "<<i.second;
        }
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
 vector<int> ans ;
//  rightView(root,0,ans);
//  for (int i = 0; i < ans.size(); i++)
//  {
//     cout<<" "<<ans[i];
//  }
 bottomView(root);
return 0;
}