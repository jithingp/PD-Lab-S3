#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{
    int key;
    struct s* left;
    struct s* right;
    struct s* parent;
};
struct s* createnode(int k){
    struct s *node=NULL;
    node=(struct s*)malloc(sizeof(struct s));
    node->key=k;
    node->left=NULL;
    node->parent=NULL;
    node->right=NULL;
    return node;
}
struct s* insert(struct s *t,struct s *z){
    struct s *y=NULL;
    struct s *x=t;
    while(x!=NULL){
        y=x;
        if(z->key<x->key){
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    z->parent=y;
    if(y==NULL)
    t=z;
    else if(z->key<y->key)
    y->left=z;
    else
    y->right=z;
    return t;
}
void inorder(struct s* node){
    if(node==NULL){
        return;
    }
    inorder(node->left);
    printf("%d ",node->key);
    inorder(node->right);
}
void preorder(struct s* node){
    if(node==NULL)
    return;
    printf("%d ",node->key);
    preorder(node->left);
    preorder(node->right);
}
void postorder(struct s* node){
    if(node==NULL)
    return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->key);
}
struct s* search(struct s* node,int k){
    if(node==NULL||k==node->key)
    return node;
    if(k<node->key)
    return search(node->left,k);
    else
    return search(node->right,k);
}
void successor(struct s* t,struct s* node){
    struct s* y=NULL;
    if(node->right!=NULL){
        node=node->right;
        while(node->left!=NULL){
            node=node->left;
        }
        printf("%d\n",node->key);
        return;
    }
    y=node->parent;
    while(y!=NULL && node==y->right){
        node=y;
        y=y->parent;
    }
    if(y==NULL)
    printf("%d\n",-1);
    else
    printf("%d\n",y->key);
}
void predecessor(struct s* t,struct s* node){
    struct s* y=NULL;
    if(node->left!=NULL){
        node=node->left;
        while(node->right!=NULL)
        node=node->right;
        printf("%d\n",node->key);
        return;
    }
    y=node->parent;
    while(y!=NULL && node==y->left){
        node=y;
        y=y->parent;
    }
    if(y==NULL)
    printf("%d\n",-1);
    else
    printf("%d\n",y->key);
}
void transplant(struct s** t,struct s* u,struct s* v){
    if(u->parent==NULL)
    *t=v;
    else if(u==u->parent->left)
    u->parent->left=v;
    else
    u->parent->right=v;
    if(v!=NULL)
    v->parent=u->parent;
}
struct s* delete(struct s* t,struct s* node){
    printf("%d\n",node->key);
    if(node->left==NULL){
        transplant(&t,node,node->right);
    }
    else if(node->right==NULL){
        transplant(&t,node,node->left);
    }
    else{
        struct s* y=node->right;
        while(y->left!=NULL){
            y=y->left;
        }
        if(y->parent!=node){
            transplant(&t,y,y->right);
            y->right=node->right;
            y->right->parent=y;
        }
        transplant(&t,node,y);
        y->left=node->left;
        y->left->parent=y;
        
    }
    return t;
}
int main(){
    struct s* troot=NULL,*z=NULL,*s=NULL;
    char ch;
    int k;
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'a':
            scanf("%d",&k);
            z=createnode(k);
            troot=insert(troot,z);
            break;
            case 'i':
            inorder(troot);
            printf("\n");
            break;
            case 'p':
            preorder(troot);
            printf("\n");
            break;
            case 't':
            postorder(troot);
            printf("\n");
            break;
            case 's':
            scanf("%d",&k);
            s=search(troot,k);
            if(s==NULL)
            printf("%d\n",-1);
            else
            printf("%d\n",1);
            break;
            case 'c':
            scanf("%d",&k);
            s=search(troot,k);
            successor(troot,s);
            break;
            case 'r':
            scanf("%d",&k);
            s=search(troot,k);
            predecessor(troot,s);
            break;
            case 'd':
            scanf("%d",&k);
            s=search(troot,k);
            if(s==NULL)
            printf("%d\n",-1);
            else
            troot=delete(troot,s);
            break;


        }

    }while(ch!='e');

 
 
return 0;
}