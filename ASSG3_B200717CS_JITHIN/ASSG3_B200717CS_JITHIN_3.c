#include<stdio.h>
int binar(int sarr[],int l,int r,int ntw){
    
    if(l>r){
        return 1001;
    }
    
    int mid=(r+l)/2;
    if(sarr[mid]==ntw){
       
       return ntw;
    }
    else if(ntw<sarr[mid]){

        binar(sarr,mid+1,r,ntw);
    }
    else if(ntw>sarr[mid]){
       binar(sarr,l,mid-1,ntw);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&arr2[i]);
    }
    int z;
    for(int i=0;i<n;i++){
       z= binar(arr2,0,m-1,arr1[i]);
       if(z!=1001){
           printf("%d ",z);
           
       }
    }
    
    return 0;
}