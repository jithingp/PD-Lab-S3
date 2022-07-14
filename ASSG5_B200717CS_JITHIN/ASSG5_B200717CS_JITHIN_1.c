#include<stdio.h>
#include<stdlib.h>
struct s{
    char key;
    struct s* next;
};
struct ll{
    struct s *head;
};
struct s* createnode(char temp){
    struct s *b;
    b=(struct s*)malloc(sizeof(struct s));
    b->key=temp;
    b->next=NULL;
    //printf("%c %c ",b->key,temp);
    return b; 
}
void listinsertfront(struct ll *a,struct s *c){
    c->next=a->head;
    a->head=c;
    //printf("%c ",(c->key));
}
void printlist(struct ll *a){
    struct s *selected;
    selected=(struct s*)malloc(sizeof(struct s));
    selected=a->head;
    if(selected==NULL){
        printf("%s","NULL");
    }
    else{
        while(selected!=NULL){
            printf("%c ",selected->key);
            selected=selected->next;
        }
    }
    printf("\n");
}
void listinserttail(struct ll *a,struct s *c){
    struct s *selected=a->head;
    if(selected!=NULL){
        while(selected->next!=NULL){
            selected=selected->next;
        }
        selected->next=c;
    }
    else{
        a->head=c;
    }
}
void listinsertafter(struct ll *a,struct s *c,char y){
    int f=0;
    struct s *selected=a->head;
    if(selected!=NULL)
    while(selected!=NULL){

        if(selected->key==y){
            c->next=selected->next;
            selected->next=c;
            f=1;
            break;
        }
        selected=selected->next;
    } 
    if(f==0)
    printf("%d ",0);
}
void listinsertbefore(struct ll *a,struct s *c,char y){
    struct s *selected=a->head;
    if(selected->key==y){
        a->head=c;
        c->next=selected;
    }
    else{
    while(selected->next!=NULL){
        if(selected->next->key==y){
            c->next=selected->next;
            selected->next=c;
            break;
        }
        selected=selected->next;
    }
    }
}
void listdeletefirst(struct ll *a){
    struct s *selected=a->head;
    if(selected==NULL){
        printf("%d\n",-1);
    }
    else{
    a->head=selected->next;
    printf("%c\n",selected->key);
    }
}
void listdeletelast(struct ll *a){
    struct s *selected=a->head;
    if(selected!=NULL){
        if(selected->next==NULL){
            a->head=NULL;
            printf("%c\n",selected->key);
        }
        else
        {
            while(selected->next->next!=NULL){
            selected=selected->next;
        }
        printf("%c\n",selected->next->key);
        selected->next=NULL;
        
        }
    }
    else{
        printf("%d\n",-1);
    }
}
void listdelete(struct ll *a,char x){
    struct s *selected=a->head;
    int f=0;
    if(selected==NULL){
        printf("%d\n",-1);
    }
    else{
        if(selected->key==x){
            f=1;
            a->head=selected->next;
            if(a->head!=NULL){
                printf("%c\n",a->head->key);
            }
            else{
                printf("%d\n",-2);
            }
        }
        else{
        while(selected->next!=NULL){
            if(selected->next->key==x){
                f=1;
                struct s *z=selected->next->next;
                selected->next=z;
                if(z==NULL){
                    printf("%d\n",-2);
                }
                else{
                    printf("%c\n",z->key);
                }
            }
            selected=selected->next;
        }
        }
        if(f==0)
        printf("%d\n",-1);
    }

}
int main(){
    struct s *c=NULL;
    struct ll *a;
    a=(struct ll*)malloc(sizeof(struct ll));
    a->head=NULL;
    char ch,temp,x,y;
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'f':
            scanf(" %c",&temp);
            c=createnode(temp);
            listinsertfront(a,c);
            break;
            case 't':
            scanf(" %c",&temp);
            c=createnode(temp);
            listinserttail(a,c);
            break;
            case 'p':
            printlist(a);
            break;
            case 'a':
            scanf(" %c %c",&x,&y);
            c=createnode(x);
            listinsertafter(a,c,y);
            break;
            case 'b':
            scanf(" %c %c",&x,&y);
            c=createnode(x);
            listinsertbefore(a,c,y);
            break;
            case 'i':
            listdeletefirst(a);
            break;
            case 'l':
            listdeletelast(a);
            break;
            case 'd':
            scanf(" %c",&x);
            listdelete(a,x);
            break;

        }
    }while(ch!='e');


    return 0;
}