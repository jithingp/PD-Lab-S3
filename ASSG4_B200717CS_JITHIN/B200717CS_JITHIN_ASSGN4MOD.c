#include<stdio.h>
#include<stdlib.h>

void maxheapinsert(int a[],int i,int n){
    a[i]=-1;
     a[i]=n;
    while(i>0 && a[(i-1)/2]<a[i]){
        int c=a[i];
        a[i]=a[(i-1)/2];
        a[(i-1)/2]=c;
        i=(i-1)/2;
    }

}
void heapify(int a[],int numbag,int i){
    int l=(2*i)+1,r=(2*i)+2,largest;
    if(l<numbag&&a[l]>a[i]){
        largest=l;
    }
    else
    largest=i;
    if(r<numbag&&a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        int c=a[i];
        a[i]=a[largest];
        a[largest]=c;
        heapify(a,numbag,largest);
    }
    }
void eat(int a[],int numbag){
    a[0]=a[0]/2;
    heapify(a,numbag,0);
}
int main(){
    int numbag,pick,n,choc=0;
    scanf("%d",&numbag);
    scanf("%d",&pick);
    int a[numbag];
    for(int i=0;i<numbag;i++){
        scanf("%d",&n);
        maxheapinsert(a,i,n);
    }
    for(int i=0;i<pick;i++){
        choc+=a[0];
        for(int j=0;j<numbag;j++){
            printf("%d ",a[j]);
        }
        printf("\n");
        eat(a,numbag);
    }
    printf("%d",choc);


    return 0;
}