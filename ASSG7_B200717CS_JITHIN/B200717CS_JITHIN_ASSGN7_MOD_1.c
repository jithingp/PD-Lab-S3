#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
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
void combine1(struct s* troot1,int k,struct s* troot2){
    struct s *s=NULL;
    s=createnode(k);
    s->left=troot1;
    s->right=troot2;
    if(troot1!=NULL){
    troot1->parent=s;}
    if(troot2!=NULL){
    troot2->parent=s;}
    inorder(s);
    troot1=NULL;
    troot2=NULL;
}
int main(){
    struct s* troot1=NULL,*troot2=NULL,*z=NULL,*s=NULL;
    char ch,ar[100000],ar2[100000];
    int k,tot=0;
    fgets(ar,100000,stdin);
    int n=strlen(ar);
    int flag=0,flag1=0;
    for(int i=0;i<n;i++){
        if(isdigit(ar[i])){
            k=ar[i]-'0';
            tot=(tot*10)+k;
            flag=1;
        }
        else if(flag==1){
            z=createnode(tot);
            troot1=insert(troot1,z);
            tot=0;
        }
    }
   
    tot=0;
    fgets(ar2,100000,stdin);
    int m=strlen(ar2);
    
    for(int i=0;i<m;i++){
        if(isdigit(ar2[i])){
            k=ar2[i]-'0';
            tot=(tot*10)+k;
            flag1=1;
        }
        else if(flag1==1){
            z=createnode(tot);
            troot2=insert(troot2,z);
            tot=0;
        }
    }
   //printf("\n%c",ar[0]);
    scanf("%d",&k);
    combine1(troot1,k,troot2);

     
   return 0;
}