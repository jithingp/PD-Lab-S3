#include<stdio.h>
void merge(int arrr[],int a,int b,int c,int cp[]){
   int y=b-a+1,z=c-b;
   int l[y+1],r[z+1];
   for(int i=0;i<y;i++){
       l[i]=arrr[a+i];
   }
   for(int i=0;i<z;i++){
       r[i]=arrr[b+i+1];
   }
   int i=0,j=0,k=a;
   l[y]=1000001,r[z]=1000001;
   for(;k<=c;k++){
       if(l[i]<=r[j]){
           arrr[k]=l[i];
           i++;
           cp[1]++;
       }
       else {
           arrr[k]=r[j];
           j++;
           cp[1]++;
           cp[0]=cp[0]+y-i;
       }
   }
  
}
void mergesort(int arrr[],int l,int r,int cp[]){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(arrr,l,mid,cp);
        mergesort(arrr,mid+1,r,cp);
        merge(arrr,l,mid,r,cp);
    }

}
int main(){
    int sizz,cp[2];
    cp[0]=0,cp[1]=0;
    scanf("%d",&sizz);
    int arrr[sizz];
    for(int i=0;i<sizz;i++){
        scanf("%d",&arrr[i]);
    }
    mergesort(arrr,0,sizz-1,cp);
    printf("%d\n%d",cp[0],cp[1]);
    return 0;

}