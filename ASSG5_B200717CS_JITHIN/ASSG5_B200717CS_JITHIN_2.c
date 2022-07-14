#include<stdio.h>
#include<stdlib.h>
struct s{
    int key;
    struct s *prev;
    struct s *next;
};
struct ll{
    struct s* head;
};
struct s* createnode(int k){
    struct s* b=NULL;
    b=(struct s*)malloc(sizeof(struct s));
    b->key=k;
    b->next=NULL;
    b->prev=NULL;
    return b;
}
void listinsertfront(struct ll *a,struct s *x){
    x->next=a->head;
    if(a->head!=NULL){
        a->head->prev=x;
    }
    a->head=x;
    x->prev=NULL;
}
struct s* listsearch(struct ll *a,int k){
    struct s *b=a->head;
    if(a->head==NULL){
        return b;
    }
    else{
        while(b!=NULL){
            if(b->key==k){
                return b;
            }
            b=b->next;
        }
    }
    return b;
}
void printreverse(struct ll *a,int k){
    struct s *b=a->head;
    int f=0;
    if(a->head==NULL){
        printf("%s","Not Found\n");
    }
    else{
        while(b!=NULL){
            if(b->key==k){
                f=1;
                break;
            }
            b=b->next;
        }
        while(b!=NULL){
            printf("%d ",b->key);
            b=b->prev;
        }
        
        if(f==0){
           printf("%s","Not Found\n");
           return;  
        }
        printf("\n");
    }
}
void listinserttail(struct ll *a,struct s* c){
    struct s *b=a->head;
    if(a->head==NULL){
        a->head=c;
    }
    else{
        while(b->next!=NULL){
            b=b->next;
        }
        b->next=c;
        c->prev=b;
    }
}
void listinsertafter(struct ll *a,struct s *c,int y){
    struct s *b=listsearch(a,y);
    if(b->next==NULL){
        c->next=b->next;
        c->prev=b;
        b->next=c;
    }
    else{
    c->next=b->next;
    c->prev=b;
    b->next->prev=c;
    b->next=c;
    }
}
void listinsertbefore(struct ll *a,struct s *c,int y){
    struct s *b=listsearch(a,y);
    if(b->prev==NULL){
        c->next=b;
        c->prev=b->prev;
        b->prev=c;
    }
    else{
    c->next=b;
    c->prev=b->prev;
    b->prev->next=c;
    b->prev=c;
    }
}
void listdelete(struct ll *a,int x){
    struct s *b=listsearch(a,x);
    if(b==NULL){
        printf("%s","Not Found\n");
    }
    else{
        if(b->next==NULL&&b->prev==NULL){
            a->head=NULL;
            printf("%s","NULL\n");
        }
        else if(b->prev==NULL){
            a->head=b->next;
            b->next->prev=NULL;
            printf("%d\n",b->next->key);
        }
        else if(b->next==NULL){
         b->prev->next=NULL;
         printf("%s\n","NULL");
        }
        else{
            struct s *z=b->prev;
            struct s *zz=b->next;
            zz->prev=z;
            z->next=zz;
            printf("%d\n",b->next->key);

        }
    }
}
void listdeleteinitial(struct ll *a){
    if(a->head==NULL){
        printf("%s\n","Not Found");
    }
    else if(a->head->next==NULL){
        printf("%d\n",a->head->key);
        a->head=NULL;
        
    }
    else{
        printf("%d\n",a->head->key);
        struct s *b=a->head->next;
        b->prev=NULL;
        a->head=b;
    }
}
void listdeletelast(struct ll *a){
    struct s *b=a->head;
    if(a->head==NULL){
        printf("%s\n","Not Found");
    }
    else if( a->head->next==NULL){
        printf("%d\n",a->head->key);
        a->head=NULL;
    }
    else{
        while(b->next!=NULL){
            b=b->next;
        }
        printf("%d\n",b->key);
        b->prev->next=NULL;
    }
}
int main(){
    struct s *c=NULL,*b=NULL;
    struct ll *a=NULL;
    a=(struct ll*)malloc(sizeof(struct ll));
    a->head=NULL;
    int k,x,y;
    char ch;
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'f':
            scanf(" %d",&k);
            c=createnode(k);
            listinsertfront(a,c);
            break; 
            case 'r':
            scanf(" %d",&k);
            printreverse(a,k);
            break;
            case 't':
            scanf("%d",&k);
            c=createnode(k);
            listinserttail(a,c);
            break;
            case 'a':
            scanf("%d%d",&x,&y);
            c=createnode(x);
            listinsertafter(a,c,y);
            break;
            case 'b':
            scanf("%d%d",&x,&y);
            c=createnode(x);
            listinsertbefore(a,c,y);
            break;
            case 'd':
            scanf("%d",&x);
            listdelete(a,x);
            break;
            case 'i':
            listdeleteinitial(a);
            break;
            case 'l':
            listdeletelast(a);
            break;

        }
    }while(ch!='e');
    

    return 0;
}