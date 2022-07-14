#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int zarr[n];
    int verdhe=0;
    for(int i=0;i<n;i++){
        scanf("%d",&zarr[i]);
        int c=abs(zarr[i]),templeft,fin=0;
        int tempright=c%10;
        c/=10;
        while(c>0){
            templeft=c%10;
            if(templeft>tempright){
                fin=1;
            }
            tempright=templeft;
            c/=10;
        }
        if(fin==0){
        printf("%d ",zarr[i]);
        verdhe=1;
        }

    }
    if(verdhe==0)
    printf("%d",-1);
    return 0;
}