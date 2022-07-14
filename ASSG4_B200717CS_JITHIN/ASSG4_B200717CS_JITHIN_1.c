#include<stdio.h>
void maxheapify(int a[],int n,int i,int zz[]){
    int l=(2*i)+1;
    int r=(2*i)+2,largest;
    if(l<n)
    zz[0]++;
    if(l<n && a[l]>a[i]){
    largest=l;
    
    }
    else
    largest=i;
    if(r<n)
    zz[0]++;
    if(r<n && a[r]>a[largest]){
    largest=r;
    
    }
    if(largest!=i){
        int c=a[i];
        a[i]=a[largest];
        a[largest]=c;
        maxheapify(a,n,largest,zz);
    }
}
void buildmaxheap(int a[],int n,int zz[]){
    int m=n;
    for(int i=(n/2)-1;i>=0;i--){
        maxheapify(a,n,i,zz);
    }
}
void heapsort(int a[],int n,int zz[]){
    buildmaxheap(a,n,zz);
    for(int i=n-1;i>0;i--){
        
        int c=a[i];
        a[i]=a[0];
        a[0]=c;
        n--;
        maxheapify(a,n,0,zz);
    }
}
int main(){
    
    int n,zz[1];
    zz[0]=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    heapsort(a,n,zz);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n%d",zz[0]);
    return 0;

}