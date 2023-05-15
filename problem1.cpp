//Name: MuhammadOqil
//ID:221044

#include <iostream>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    
    TreeNode():val(0), left(nullptr), right(nullptr){};
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(nullptr), right(nullptr){};
};

class BinarySearchTree{
public:
    TreeNode *root;
    BinarySearchTree(){
        root = nullptr;
    }
    
    void insert(int num){
        
        TreeNode *newTreeNode = new TreeNode(num);
        if(root == nullptr){
            root=newTreeNode;
            return;
        }
        TreeNode *current_node = root;
        
        while(true){
            if(num<current_node->val){
                if(current_node->left==nullptr){
                    current_node->left = newTreeNode;
                    return;
                }
                current_node=current_node->left;
            }else{
                if(current_node->right==nullptr){
                    current_node->right = newTreeNode;
                    return;
                }
                current_node=current_node->right;
            }
        }
    }
    
    TreeNode* BST(int key){
        TreeNode *t = root;
        TreeNode *searchNode = new TreeNode(key);
        if(root==nullptr){
            return NULL;
        }
        while (t != NULL && t != searchNode){
            if (searchNode < t)
              t = t->left;
            else
              t = t->right;
          }
        if(t==root){
                    return t;
                }else{
                    return NULL;
                }
    }
//    TreeNode* getroot(){
//        TreeNode* roo1;
//        return roo1=root;
//    } //FIRST WAY
    
    void gettraversal(){
        inorder(root);
        cout<<endl;
        preorder(root);
        cout<<endl;
        postorder(root);
        cout<<endl;
//        BST(6);
//        cout<<endl;
        deletion(root);
    }
    

    void deletion(TreeNode *root){
        if(root == nullptr){
            return;
        }
        deletion(root->left);
        delete root;
        deletion(root->right);
          }
    void inorder(TreeNode *root){
        if(root == nullptr){
            return;
        }
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
            
    void preorder(TreeNode *root){
            if(root == nullptr){
                return;
            }
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(TreeNode *root){
        if(root == nullptr){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
};

int main(int argc, const char * argv[]) {
    BinarySearchTree bst;
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(13);
    bst.insert(4);
    bst.insert(7);
    bst.BST(6);
    
    bst.gettraversal();
    
    
    return 0;
}
