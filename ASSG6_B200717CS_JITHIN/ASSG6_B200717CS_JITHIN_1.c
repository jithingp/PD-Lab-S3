#include<stdio.h>
#include<stdlib.h>
struct s{
    int data;
    struct s* nxt;
};
struct ll{
    struct s* top;
};
struct s* createnode(int num){
    struct s* neww=NULL;
    neww=(struct s*)malloc(sizeof(struct s));
    neww->data=num;
    neww->nxt=NULL;
    return neww;
}
void push(struct ll* a,struct s* zz){
    if(a->top==NULL){
        a->top=zz;
    }
    else{
        zz->nxt=a->top;
        a->top=zz;
    }
}
int stackempty(struct ll* a){
    if(a->top==NULL){
        return -1;
    }
    return 1;
}
void pop(struct ll *a){
    int q=stackempty(a);
    if(q==-1){
        printf("%d\n",q);
    }
    else{
        struct s *v=a->top;
        a->top=v->nxt;
        printf("%d\n",v->data);
    }
}
int main(){
    struct s *stack1=NULL,*zz=NULL;
    struct ll *a=NULL;
    a=(struct ll*)malloc(sizeof(struct ll));
    a->top=NULL;
    char ch;
    int num,ret;
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            scanf("%d",&num);
            zz=createnode(num);
            push(a,zz);
            break;
            case 'e':
            ret= stackempty(a);
            printf("%d\n",ret);
            break;
            case 'd':
            pop(a);
            break;


        }
    }while(ch!='t');

    return 0;
    
}