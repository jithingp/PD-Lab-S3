#include<stdio.h>
#include<stdlib.h>
struct s{
    int data;
    struct s* nxt;
};
struct q{
    struct s* head;
    struct s* tail;
};
struct s* createnode(int num){
    struct s *neww=NULL;
    neww=(struct s*)malloc(sizeof(struct s));
    neww->data=num;
    neww->nxt=NULL;
    return neww;
}
void insertt(struct q *a,struct s *nod){
    if(a->head==NULL){
        a->head=nod;
        a->tail=nod;
    }
    else{
        a->head->nxt=nod;
        a->head=nod;
    }
}
int queueempty(struct q *a){
    if(a->head==NULL){
        return -1;
    }
    return 1;
}
void dequeue(struct q *a){
    int z=queueempty(a);
    if(z==-1){
        printf("%d\n",z);
    }
    else if(a->tail==a->head){
        printf("%d\n",a->tail->data);
        a->tail=NULL;
        a->head=NULL;
    }
    else{
        printf("%d\n",a->tail->data);
        a->tail=a->tail->nxt;
    }
}
int main(){
    struct s *qq=NULL,*nod=NULL;
    struct q *a=NULL;
    a=(struct q*)malloc(sizeof(struct q));
    a->head=NULL;
    a->tail=NULL;
    char ch;
    int num,c;
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            scanf("%d",&num);
            nod=createnode(num);
            insertt(a,nod);
            break;
            case 'e':
            c=queueempty(a);
            printf("%d\n",c);
            break;
            case 'd':
            dequeue(a);
            break;

        }
    }while(ch!='t');

}