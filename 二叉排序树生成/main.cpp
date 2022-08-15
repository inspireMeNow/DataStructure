#include <iostream>
# include <stack>
using namespace std;
typedef int ElemType;
typedef struct TreeNode{
    TreeNode *left;
    TreeNode *right;
    ElemType data;
    int height=1;
};
int max(int a,int b){
    return a>b?a:b;
}
int height(TreeNode *x){
    if(x==NULL){
        return 0;
    }
    return x->height;
}
TreeNode* InsertBST(TreeNode *t,ElemType e){
    if(!t){
        t=new TreeNode;
        if(t==NULL){
            return 0;
        }
        else{
            t->data=e;
            t->left=t->right=NULL;
        }
    }
    else if(e<t->data){
        t->left=InsertBST(t->left,e);
    }
    else if(e>t->data){
        t->right=InsertBST(t->right,e);
    }
    t->height=max(height(t->left), height(t->right))+1;
    return t;
}
void preOrder(TreeNode *node){
    if(node){
        cout<<node->data<<" ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
void inorder(TreeNode *node){
    if(node){
        preOrder(node->left);
        cout<<node->data<<" ";
        preOrder(node->right);
    }
}
void postorder(TreeNode *node){
    if(node){
        preOrder(node->left);
        preOrder(node->right);
        cout<<node->data<<" ";
    }
}
int getBalance(TreeNode *x){
    if(x==NULL){
        return 0;
    }
    return height(x->left)- height(x->right);
}
TreeNode *rotateLeft(TreeNode *x){ //左旋
    TreeNode *y=x->right;
    x->right=y->left;
    y->left=x;
    x->height=max(height(x->left), height(x->right))+1;
    y->height=max(height(y->left), height(y->right))+1;
    return y;
}
TreeNode *rotateRight(TreeNode *x){ //右旋
    TreeNode *y=x->left;
    x->left=y->right;
    y->right=x;
    x->height=max(height(x->left), height(x->right))+1;
    y->height=max(height(y->left), height(y->right))+1;
    return y;
}
TreeNode *reBalance(TreeNode *x){
    int balance= getBalance(x);
    if(balance>1&& getBalance(x->left)>0){ //LL型
        return rotateRight(x);
    }
    if(balance>1&& getBalance(x->left)<=0){ //LR型
        TreeNode *t= rotateLeft(x);
        return rotateRight(t);
    }
    if(balance<-1&& getBalance(x->right)<=0){ //RR型
        return rotateLeft(x);
    }
    if(balance<-1&& getBalance(x->right)>0){
        TreeNode *t= rotateRight(x);
        return rotateLeft(t);
    }
    return x;
}
void Order(TreeNode *t){
    cout<<"先序遍历系列为：";
    preOrder(t);
    cout<<endl;
    cout<<"中序遍历序列为：";
    inorder(t);
    cout<<endl;
    cout<<"后序遍历序列为：";
    postorder(t);
    cout<<endl;
}
/*class solution{
    int getDepth(TreeNode *cur){
        stack<TreeNode*> stack;
        if(cur!=NULL){
            stack.push(cur);
        }
        int depth=0;
        int result=0;
        while(!stack.empty()){
            TreeNode *node=stack.top();
            if(node!=NULL){
                stack.pop();
                stack.push(node);
                stack.push(NULL);
                depth++;
                if(node->left)stack.push(node->left);
                if(node->right)stack.push(node->right);
            }
            else{
                stack.pop();
                node=stack.top();
                stack.pop();
                depth--;
            }
            result=result>depth?result:depth;
        }
        return result;
    }
public:
    bool isBalanced(TreeNode *root){
        stack<TreeNode*> stack;
        if(root==NULL){
            return 1;
        }
        stack.push(root);
        while(!stack.empty()){
            TreeNode *node=stack.top();
            stack.pop();
            if(abs(getDepth(node->left)- getDepth(node->right))>1){
                return 0;
            }
            if(node->left){
                stack.push(node->left);
            }
            if(node->right){
                stack.push(node->right);
            }
        }
        return 1;
    }
};*/
int main() {
    TreeNode *t=NULL;
    int n;
    cout<<"请输入数字的个数：";
    cin>>n;
    ElemType e;
    for(int i=0;i<n;i++){
        cin>>e;
        t=InsertBST(t,e);
    }
    cout<<"平衡化前："<<endl;
    Order(t);
    t=reBalance(t);
    cout<<"平衡化后："<<endl;
    Order(t);
    return 0;
}
