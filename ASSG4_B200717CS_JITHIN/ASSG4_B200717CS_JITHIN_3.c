#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct s{
    char aname[20];
    int asiz;
};
void insert(struct s ara[],int i,struct s yy){
    ara[i].asiz=0;
    ara[i].asiz=yy.asiz;
    int xx=i;
    strcpy(ara[i].aname,yy.aname);
    while((i>0 && ara[(i-1)/2].asiz>ara[i].asiz)||(i>0&&ara[(i-1)/2].asiz==ara[i].asiz&&strcmp(ara[(i-1)/2].aname,ara[i].aname)>0) ){
        int c=ara[i].asiz;
        ara[i].asiz=ara[(i-1)/2].asiz;
        ara[(i-1)/2].asiz=c;
        char cc[20];
        strcpy(cc,ara[i].aname);
        strcpy(ara[i].aname,ara[(i-1)/2].aname);
        strcpy(ara[(i-1)/2].aname,cc);
        i=(i-1)/2;
    }

}
void read(struct s ara[],int n){
    struct s yy;
   
    for(int i=0;i<n;i++){
    scanf("%s%d",&yy.aname,&yy.asiz);
    insert(ara,i,yy);
    }
}
void minheapify(struct s ara[],int n,int i){
    int l=(2*i)+1,r=(2*i)+2,smallest;
    if(l<n && ara[l].asiz<ara[i].asiz)
    smallest=l;
    else if(l<n && ara[l].asiz==ara[i].asiz){
        if(strcmp(ara[l].aname,ara[i].aname)<0){
            smallest=l;
        }
        else
        smallest=i;
    }
    else
    smallest=i;
    if(r<n && ara[r].asiz<ara[smallest].asiz)
    smallest=r;
    else if(r<n && ara[r].asiz==ara[smallest].asiz){
        if(strcmp(ara[r].aname,ara[smallest].aname)<0)
            smallest=r;
        else
        smallest=i;    
    }
    if(smallest!=i){
        int c=ara[i].asiz;
        ara[i].asiz=ara[smallest].asiz;
        ara[smallest].asiz=c;
        char cc[20];
        strcpy(cc,ara[i].aname);
        strcpy(ara[i].aname,ara[smallest].aname);
        strcpy(ara[smallest].aname,cc);
        minheapify(ara,n,smallest);
    }
}
void combine(struct s ara[],int n[]){
    struct s a[2],b;
    for(int j=0;j<2;j++){
        a[j].asiz=ara[0].asiz;
        strcpy(a[j].aname,ara[0].aname);
        ara[0].asiz=ara[n[0]-1].asiz;
        strcpy(ara[0].aname,ara[n[0]-1].aname);
        n[0]--;
        minheapify(ara,n[0],0);
    }
    strcpy(b.aname,a[0].aname);
    b.asiz=a[0].asiz+a[1].asiz;
    printf("%s %s %d\n",a[0].aname,a[1].aname,b.asiz);
    int k=n[0];
    n[0]++;
    insert(ara,k,b);
    
}
int main(){
    int n[1];
    scanf("%d",&n[0]);
    struct s ara[n[0]];
    read(ara,n[0]);
    while(n[0]>1)
    combine(ara,n);
    printf("%s %d",ara[0].aname,ara[0].asiz);

    return 0;
}