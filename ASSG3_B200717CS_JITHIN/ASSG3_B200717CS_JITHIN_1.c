#include<stdio.h>
int nakal=0;
int binar(int sarr[],int l,int r,int ntw){
     nakal++;
    if(l>r){
        return -1;
    }
   
    int mid=(r+l)/2;
    if(sarr[mid]==ntw){
       
       return mid;
    }
    else if(ntw>sarr[mid]){

        binar(sarr,mid+1,r,ntw);
    }
    else if(ntw<sarr[mid]){
       binar(sarr,l,mid-1,ntw);
    }
}
int main(){
    int ws,ntw;
    scanf("%d",&ws);
    int sarr[ws];
    for(int i=0;i<ws;i++){
        scanf("%d",&sarr[i]);
    }
    scanf("%d",&ntw);
    int posicion=binar(sarr,0,ws-1,ntw);
    printf("%d\n",posicion);
    printf("%d",nakal);
    return 0;
}