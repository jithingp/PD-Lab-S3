#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{
    int head;
    int tail;
    char e[1000000][30];
};
int queuefull(struct s *a,int n){
    if((a->head==0&&a->tail==n-1)||(a->tail+1==a->head)){
        return -1;
    }
    else{
        return 1;
    }
}
int queueempty(struct s *a){
    if(a->head==-1){
        return -1;
    }
    else{
        return 1;
    }
}
void enqueue(struct s *a,int n,char k[]){
    int b=queuefull(a,n);
    if(b==-1){
        printf("%d\n",-1);
    }
    else{
        if(a->tail==n-1){
            a->tail=0;
        }
        else{
            a->tail++;
        }
        strcpy(a->e[a->tail],k);
    }
    if(a->head==-1){
        a->head=0;
    }
 
}
void dequeue(struct s *a,int n){
    int b=queueempty(a);
    if(b==-1){
        printf("%d\n",-1);
    }
    else{
        if(a->head==a->tail){
            printf("%s\n",a->e[a->head]);
            a->head=-1;
            a->tail=-1;
        }
        else if(a->head==n-1){
            printf("%s\n",a->e[a->head]);
            a->head=0;
        }
        else{
            printf("%s\n",a->e[a->head]);
            a->head++;
        }
    }
}
int main(){

    int n,b;
    struct s *a=NULL;
    a=(struct s*)malloc(sizeof(struct s));
    a->head=-1;
    a->tail=-1;
    scanf("%d",&n);
    n--;
    char ch,k[20];
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            scanf(" %s",&k);
            enqueue(a,n,k);
            break;
            case 'f':
            b=queuefull(a,n);
            printf("%d\n",b);
            break;
            case 'e':
            b=queueempty(a);
            printf("%d\n",b);
            break;
            case 'd':
            dequeue(a,n);
            break;

        }
    }while(ch!='t');

    return 0;
}