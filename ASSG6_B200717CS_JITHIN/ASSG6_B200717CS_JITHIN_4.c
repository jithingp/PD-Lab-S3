#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct s{
    char key;
    struct s* lchild;
    struct s* rchild;
    struct s* nxt;
};
struct ll{
    struct s *top;
};
struct s* createnode1(char ch,struct s* a,struct s* b){
    struct s *sel=NULL;
    sel=(struct s*)malloc(sizeof(struct s));
    sel->key=ch;
    sel->lchild=a;
    sel->rchild=b;
    sel->nxt=NULL;
    return sel;
}
void push(struct ll *a,struct s *node){
    
        node->nxt=a->top;
        a->top=node;
    
}
struct s* maketree(char ar[],int n){
    struct ll *a=NULL;
    struct s *node=NULL;
    node=(struct s*)malloc(sizeof(struct s));
    a=(struct ll*)malloc(sizeof(struct ll));
    a->top=NULL;
    for(int i=0;i<n;i++){
        if(isalpha(ar[i])){
             node=createnode1(ar[i],NULL,NULL);
             push(a,node);
        }
        else{
            struct s* sele=NULL;
            sele=(struct s*)malloc(sizeof(struct s));
            sele->rchild=a->top;
            a->top=a->top->nxt;
            sele->lchild=a->top;
            a->top=a->top->nxt;
            node=createnode1(ar[i],sele->lchild,sele->rchild);
            push(a,node);
        }

    }
    return a->top;
}
void preorder(struct s* node){
     if(node==NULL){
         return;
     }
     printf("%c",node->key);
     preorder(node->lchild);
     preorder(node->rchild);
}
void postorder(struct s* node){
    if(node==NULL){
        return;
    }
    postorder(node->lchild);
    postorder(node->rchild);
    printf("%c",node->key);
}
void inorder(struct s* node){
    if(node==NULL){
        return;
    }
    inorder(node->lchild);
    printf("%c",node->key);
    inorder(node->rchild);
}
int main(){
     struct s *troot=NULL;
    char ar[100000];
    char ch;
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'e':
            scanf(" %s ",&ar);
            int n=strlen(ar);
            troot=maketree(ar,n);
            break;
            case 'p':
            preorder(troot);
            printf("\n");
            break;
            case 's':
            postorder(troot);
            printf("\n");
            break;
            case 'i':
            inorder(troot);
            printf("\n");
            break;


        }
    }while(ch!='t');


    return 0;
}