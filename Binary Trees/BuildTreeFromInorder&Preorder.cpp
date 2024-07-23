#include<iostream>
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
int searchElementIndex(int inorder[],int inorderStart,int inorderEnd,int key){
    for (int i = inorderStart; i <= inorderEnd; i++)
    {
        if(inorder[i]==key) return i;
    }
    
}
Node* buildTreeFromPreAndInorder(int preorder[],int inorder[],int preIndex, int size,int inorderStart,int inorderEnd){
    if(preIndex == size || inorderStart > inorderEnd){
        return NULL;
    }    
    int element = preorder[preIndex];
    preIndex++;
    int position = searchElementIndex(inorder,inorderStart,inorderEnd,element);
    Node * root = new Node(element);
    root->left = buildTreeFromPreAndInorder(preorder,inorder,preIndex,size,inorderStart,position-1);
    root->right = buildTreeFromPreAndInorder(preorder,inorder,preIndex,size,position+1,inorderEnd);
    return root;
}
Node* buildTreeFromPostAndInorder(int postorder[],int inorder[],int postIndex, int size,int inorderStart,int inorderEnd){
    if(postIndex < 0 || inorderStart > inorderEnd){
        return NULL;
    }    
    int element = postorder[postIndex];
    postIndex--;
    int position = searchElementIndex(inorder,inorderStart,inorderEnd,element);
    Node * root = new Node(element);
    root->right = buildTreeFromPreAndInorder(postIndex,inorder,postIndex,size,position+1,inorderEnd);
    root->left = buildTreeFromPreAndInorder(postIndex,inorder,postIndex,size,inorderStart,position-1);
    return root;
}
int main(){

return 0;
}