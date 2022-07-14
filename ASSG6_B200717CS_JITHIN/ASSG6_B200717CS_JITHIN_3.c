#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct s{
    char c;
    int val;
    struct s *nxt;
};
struct ll{
    struct s *top; 
};
struct s* createnode(char chh){
    struct s* neww=NULL;
    neww=(struct s*)malloc(sizeof(struct s));
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
const char* infixtopostfix(char ar[100000],int n){
   
    char w[100000],z[100000]; 
    struct s *stack1=NULL,*zz=NULL;
    struct ll *a=NULL;
    a=(struct ll*)malloc(sizeof(struct ll));
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
int main(){
    char ar[100000],w[100000];
    scanf("%s",&ar);
    int n=strlen(ar);
    printf("%s",infixtopostfix(ar,n));
    
    return 0;
}