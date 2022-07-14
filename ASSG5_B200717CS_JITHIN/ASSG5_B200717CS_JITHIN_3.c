#include<stdio.h>
#include<stdlib.h>
struct s{
    int top;
    char e[1000000];
};
int stackfull(struct s *a,int n){
    if(a->top+1<n){
        return 1;
    }
    return -1;
}
void push(struct s *a,int n,char k){
    int b=stackfull(a,n);
    if(b==-1){
        printf("%d\n",-1);
    }
    else{
        a->top++;
        a->e[a->top]=k;
    }
}
int stackempty(struct s *a){
    if(a->top==-1){
        return -1;
    }
    else{
        return 1;
    }
}
void peek(struct s *a,int n){
    int b=stackempty(a);
    if(b==-1){
        printf("%d\n",-1);
    }
    else{
        printf("%c\n",a->e[a->top]);
    }
}
void pop(struct s *a,int n){
    int b=stackempty(a);
    if(b==-1){
        printf("%d\n",-1);
    }
    else{
        printf("%c\n",a->e[a->top]);
        a->top--;
    }
}
int main(){
    int n;
    struct s *a=NULL;
    a=(struct s*)malloc(sizeof(struct s));
    a->top=-1;
    scanf("%d",&n);
    char ch,k;
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            scanf(" %c",&k);
            push(a,n,k);
            break;
            case 'p':
            peek(a,n);
            break;
            case 'd':
            pop(a,n);
            break;

        }
    }while(ch!='t');
    free(a);

    return 0;
}