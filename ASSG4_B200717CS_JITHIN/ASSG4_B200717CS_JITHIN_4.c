#include<stdio.h>
#include<stdlib.h>
void insert(int a[],int num,int n[]){
    n[0]++;
    a=(int*)realloc(a,n[0]*sizeof(int));
    a[n[0]-1]=10000001;
    a[n[0]-1]=num;
    int i=n[0]-1;
    while(i>0 && a[(i-1)/2] > a[i]){
        int c=a[i];
        a[i]=a[(i-1)/2];
        a[(i-1)/2]=c;
        i=(i-1)/2;
    }
}
void minheapify(int a[],int m,int i){
    int l=(2*i)+1;
    int r=(2*i)+2,smallest;
    if(l<m && a[l]<a[i])
    smallest=l;
    else
    smallest=i;
    if(r<m && a[r]<a[smallest])
    smallest=r;
    if(smallest!=i){
        int c=a[i];
        a[i]=a[smallest];
        a[smallest]=c;
        minheapify(a,m,smallest);
    }
}
void extract(int a[],int n[]){
    if(n[0]<1){
        printf("%d\n",-1);
        return;
    }
    if(n[0]==1){
        printf("%d\n",a[0]);
        n[0]--;
    }
    else{
       int max=a[0];
       printf("%d\n",a[0]);
        a[0]=a[n[0]-1];
        n[0]--;
        int m=n[0];
        minheapify(a,m,0);
    }
}
void getnext(int a[],int n[]){
    if(n[0]==0){
        printf("%d\n",-1);
        return;
    }
    printf("%d\n",a[0]);
}
void change(int a[],int i,int newnum){
    a[i]=newnum;
    while(i>0 && a[(i-1)/2] > a[i]){
        int c=a[i];
        a[i]=a[(i-1)/2];
        a[(i-1)/2]=c;
        i=(i-1)/2;
    }
}
void display(int a[],int zz){
    int b[zz];
    for(int i=0;i<zz;i++){
        b[i]=a[i];
    }
    while(1){
        if(zz==1){
            printf("%d\n",b[0]);
            break;
        }
        else{
            printf("%d ",b[0]);
            b[0]=b[zz-1];
            zz--;
            minheapify(b,zz,0);
        }
    }
}
int main(){
    char ch;
    int *a,num,n[1],zz;
    n[0]=0;
    a=(int*)malloc(sizeof(int));
    int fnum,newnum,i;
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            scanf("%d",&num);
            insert(a,num,n);
            break;
            case 'e':
            extract(a,n);
            break;
            case 'm':
            getnext(a,n);
            break;
            case 'c': 
            scanf("%d%d",&fnum,&newnum);
            for(int j=0;j<n[0];j++){
                if(a[j]==fnum)
                i=j;
            }
            change(a,i,newnum);
            break;
            case 'd':
            zz=n[0];
            display(a,zz);
            break;
        }
    }while(ch!='s');
    return 0;
}