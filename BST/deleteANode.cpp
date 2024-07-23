#include<iostream>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* maxVal(TreeNode*root){
        TreeNode * temp = root;
        while(temp->right){
            temp = temp->right;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key){
            //leaf node 
            if(root->left == NULL && root->right == NULL){
                
                return NULL;
            }
            //only left child
            else if(root->left != NULL && root->right == NULL){
                TreeNode * leftChildSubtree = root->left;
                delete root;
                return leftChildSubtree;//return leftchildSubtree
            }
            //only right child
            else if(root->right != NULL && root->left == NULL){
                TreeNode * rightChildSubtree = root->right;
                delete root;
                return rightChildSubtree;//return leftchildSubtree
            }
            //two children
            else {
                TreeNode * maxi =maxVal(root->left);
                root->val = maxi->val;
               root->left =  deleteNode(root->left,maxi->val);//yaha pe galti karoge , root->left pass karna hai so that wahi node na delete ho jayes
            }
        }
        else if(root->val > key){
           root->left =  deleteNode(root->left,key);
        }
        else if(root->val < key){
           root->right = deleteNode(root->right,key);
        }
        return root;
    }
};
int main(){

return 0;
}