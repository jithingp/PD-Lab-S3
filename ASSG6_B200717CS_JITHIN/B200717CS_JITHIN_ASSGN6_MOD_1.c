#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct ss{
    char c;
    int val;
    struct ss *nxt;
};
struct lll{
    struct ss *top; 
};

struct ss* createnode(char chh){
    struct ss* neww=NULL;
    neww=(struct ss*)malloc(sizeof(struct ss));
    neww->c=chh;
    neww->nxt=NULL;
    if(chh=='*'||chh=='/'){
        neww->val=2;
    }
    else if(chh=='+'||chh=='-'){
        neww->val=1;
    }
    else if(chh=='('){
        neww->val=3;
        
    }
    else if(chh==')'){
        neww->val=0;
       
    }
    return neww;
}
char* topostfix(char ar[10000],int n){
   
    char w[10000],z[10000]; 
    struct ss *stack1=NULL,*zz=NULL;
    struct lll *a=NULL;
    a=(struct lll*)malloc(sizeof(struct lll));
    a->top=NULL;
    
    int j=0;
    for(int i=0;i<n;i++){
        if(isalpha(ar[i])){
            w[j]=ar[i];
            j++;
        }
        else {
            zz=createnode(ar[i]);
            while(1){
            if(a->top!=NULL){
                
                if(a->top->val<zz->val){
                    zz->nxt=a->top;
                    a->top=zz;
                    if(zz->c=='('){
                        zz->val=-1;
                        
                    }
                    break;
                }
                else{
                    w[j]=a->top->c;
                    a->top=a->top->nxt;
                    j++;
                }
                
            }
            else{
                a->top=zz;
                 if(zz->c=='('){
                        zz->val=-1;
                        
                    }
                break;
            }

            }
            if(a->top->c==')'){
                a->top=a->top->nxt->nxt;
            }

        }
    }
    while(a->top!=NULL){
        w[j]=a->top->c;
        j++;
        a->top=a->top->nxt;
    }
    
    char *re=w;
    return re;
    
    }

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
void postorder(struct s* node){
    if(node==NULL){
        return;
    }
    postorder(node->lchild);
    postorder(node->rchild);
    printf("%c",node->key);
}
int main(){
   char ar[10000],br[10000];
   scanf("%s",&ar);
   int n=strlen(ar);
    strncpy(br,ar+2,n-3);
    
    char *ar2=topostfix(br,n-3);
    int mm=strlen(ar2);
    
    struct s *troot=NULL,*kingroot=NULL,*left=NULL;
    troot=(struct s*)malloc(sizeof(struct s));
    kingroot=(struct s*)malloc(sizeof(struct s));
    left=(struct s*)malloc(sizeof(struct s));
    troot=maketree(ar2,mm);
    left=createnode1(ar[0],NULL,NULL);
    kingroot=createnode1(ar[1],left,troot);
    postorder(kingroot);


    return 0;
}