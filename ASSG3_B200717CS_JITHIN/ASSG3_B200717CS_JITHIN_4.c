#include<stdio.h>
int merge(int arr[], int a, int b, int c,int inv) {
    int y=b-a+1,z=c-b;
    int l[y+1],r[z+1];
    for (int i = 0;i<y;i++){
        l[i]=arr[a+i];
    }
    for (int j=0;j<z;j++){
        r[j]=arr[b+1+j];
    }
    int i=0,j=0,k=a;
    l[y]=1001,r[z]=1001;
 
    for(;k<=c;k++){
        if (l[i]<=r[j]) {
            arr[k] = l[i];
            i++;
            inv++;
        } else {
            inv++;
            arr[k]=r[j];
            j++;
        }
    }

    return inv;
}
int mergesort(int arr[],int l,int r,int inv) {
  if (l<r) {
    int m=(l+r)/2;

    inv=mergesort(arr,l,m,inv);
    inv=mergesort(arr,m+1,r,inv);
    inv=merge(arr,l,m,r,inv);
  }
  return inv;
}
void print(int b[],int qq){
    for(int i=0;i<qq;i++){
         printf("%d ",b[i]);
     }
}
int main(){
     int qq,inv;
     scanf("%d",&qq);
     int list1[qq],b[qq];
     for(int i=0;i<qq;i++){
        scanf("%d",&list1[i]);
     }
     inv=mergesort(list1,0,qq-1,0);
     print(list1,qq);
     printf("\n%d",inv);
     return 0;

}