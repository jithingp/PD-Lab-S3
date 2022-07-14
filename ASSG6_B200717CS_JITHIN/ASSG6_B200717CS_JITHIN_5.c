#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct s{
    int data;
    struct s* nxt;
};
struct ll{
    struct s* top;
}; 
void push(struct ll *a,int ch){
    struct s *sel=NULL;
    sel=(struct s*)malloc(sizeof(struct s));
    sel->nxt=NULL;
    sel->data=ch;
    if(a->top==NULL){
        a->top=sel;
    }
    else{
        sel->nxt=a->top;
        a->top=sel;
    }
    
}
int evaluate(char ar[100000],int n){
    struct s *stack1=NULL,*zz=NULL;
    struct ll *a=NULL;
    int flag=0,tot=0;
    a=(struct ll*)malloc(sizeof(struct ll));
    a->top=NULL;
    for(int i=0;i<n;i++){
        if(isdigit(ar[i])){
            int m=ar[i]-'0';
            tot=(tot*10)+m;
            flag=0;
        }
        else if(ar[i]==' '&&flag==0){
            push(a,tot);
            tot=0;
        }
        else{
            int vv;
            flag=1;
            switch(ar[i]){
                case '+':
                vv=a->top->data+a->top->nxt->data;
                a->top=a->top->nxt->nxt;
                push(a,vv);
                break;
                case '-':
                vv=a->top->nxt->data-a->top->data;
                a->top=a->top->nxt->nxt;
                push(a,vv);
                break;
                case '*':
                vv=(a->top->data)*(a->top->nxt->data);
                a->top=a->top->nxt->nxt;
                push(a,vv);
                break;
                case '/':
                vv=a->top->nxt->data/a->top->data;
                a->top=a->top->nxt->nxt;
                push(a,vv);
                break;
            }
        }
    }
    return a->top->data;

}
int main(){

    char ar[100000];
    fgets(ar,100000,stdin);
    int n=strlen(ar);
    int m=evaluate(ar,n);    
    printf("%d",m);

    return 0;
}