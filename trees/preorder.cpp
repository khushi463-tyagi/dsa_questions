#include<bits/stdc++.h>

using namespace std;

class Tree{
    public:
    int val;
    Tree* left;
    Tree* right;
    Tree(){
        val=0;
        left=right=NULL;
    }

    Tree(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }

    Tree* createTree(){
        int x;
        cout<<" value for graph (-1 for null)";
        cin>>x;
        if(x==-1)return NULL;
        Tree* node =new Tree(x);
        cout<<"enter left child for :"<<x;
        node->left=createTree();
        cout<<"enter right child for"<<x;
        node->right=createTree();
        return node;
    }

    void preorder(vector<int>& ans,Tree* root){
        if(root==NULL)return;
        ans.push_back(root->val);
        if (root->left)preorder(ans,root->left);
        if(root->right)preorder(ans,root->right);
        return;
    }


};

int main(){
    Tree t;
    Tree* node=t.createTree();
    cout<<"preorder traversal :";
    vector<int>ans;
    t.preorder(ans,node);
    for(int x:ans)cout<<x<<" ";
    return 0;


}


