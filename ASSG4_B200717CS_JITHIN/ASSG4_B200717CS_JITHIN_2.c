#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{
    int id;
    char nam[20];
    int ran;
};
void heapinckey(struct s chathr[],int m,struct s yy){
    chathr[m-1].ran=yy.ran;
    strcpy(chathr[m-1].nam,yy.nam);
    chathr[m-1].id=yy.id;
    while(m-1>0 && chathr[(m-1)/2].ran>chathr[m-1].ran){
        int c=chathr[m-1].id;
        chathr[m-1].id=chathr[(m-1)/2].id;
        chathr[(m-1)/2].id=c;
        int cc=chathr[m-1].ran;
        chathr[m-1].ran=chathr[(m-1)/2].ran;
        chathr[(m-1)/2].ran=cc;
        char ccc[20];
        strcpy(ccc,chathr[m-1].nam);
        strcpy(chathr[m-1].nam,chathr[(m-1)/2].nam);
        strcpy(chathr[(m-1)/2].nam,ccc);
        m= (m-1)/2;

    }
}
void enter(struct s chathr[],int n[0],struct s yy){   
        chathr=(struct s*)realloc(chathr,n[0]*sizeof(struct s));
        chathr[n[0]-1].ran=0;
        int m=n[0];
        heapinckey(chathr,m,yy);
       /* for(int i=0;i<n[0];i++){
            printf("%d %s %d\n",chathr[i].ran,chathr[i].nam,chathr[i].id);
        }*/
}
void maxheapify(struct s a[],int ontario,int i){
    int l=(2*i)+1;
    int r=(2*i)+2,largest;
    if(l<ontario && a[l].ran<a[i].ran){
    largest=l;
    
    }
    else
    largest=i;
    if(r<ontario && a[r].ran<a[largest].ran){
    largest=r;
    
    }
    if(largest!=i){
        
        int c=a[i].ran;
        a[i].ran=a[largest].ran;
        a[largest].ran=c;
        char q[20];
        strcpy(q,a[i].nam);
        strcpy(a[i].nam,a[largest].nam);
        strcpy(a[largest].nam,q);
        int w=a[i].id;
        a[i].id=a[largest].id;
        a[largest].id=w; 
        maxheapify(a,ontario,largest);
    }
}
void interview(struct s chathr[],int n[]){
    int max;
    if(n[0]<1){
    printf("%d\n",-1);
    return;
    }
    if(n[0]==1){
        printf("%d %s\n",chathr[0].id,chathr[0].nam);
        n[0]--;
        return;
    }
    else{
        max=chathr[0].ran;
        printf("%d %s\n",chathr[0].id,chathr[0].nam);
        chathr[0].ran=chathr[n[0]-1].ran;
        chathr[0].id=chathr[n[0]-1].id;
        strcpy(chathr[0].nam,chathr[n[0]-1].nam);
        n[0]--;
        int otawa=n[0];
        maxheapify(chathr,otawa,0);
    }    
}
void list(struct s chathr[],int n[]){
    struct s sec[n[0]];
    for(int i=0;i<n[0];i++){
        sec[i].id=chathr[i].id;
        strcpy(sec[i].nam,chathr[i].nam);
        sec[i].ran=chathr[i].ran;
    }
    int max,m[1];
    m[0]=n[0];
    while(1){
    if(m[0]<1){
    printf("%d\n",-1);
    break;
    }
    if(m[0]==1){
        printf("%d \n",sec[0].id);
        m[0]--;
        break;
    }
    else{
        max=sec[0].ran;
        printf("%d ",sec[0].id);
        sec[0].ran=sec[m[0]-1].ran;
        sec[0].id=sec[m[0]-1].id;
        strcpy(sec[0].nam,sec[m[0]-1].nam);
        m[0]--;
        int c=m[0];
        maxheapify(sec,c,0);
    }  
    }
}
int main(){
    char ch;
    int n[1];
    n[0]=0;
    struct s *chathr,yy;
    chathr=(struct s*)malloc(sizeof(struct s));
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'e':
            n[0]++;
            scanf("%d%s%d",&yy.id,&yy.nam,&yy.ran);
            enter(chathr,n,yy);
            break;
            case 'i':
            interview(chathr,n);
            break;
            case 'l':
            list(chathr,n);
            break;

        }
    }while(ch!='t');
    return 0;
}