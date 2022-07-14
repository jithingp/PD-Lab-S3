#include<stdio.h>

int main(){
    int y,z;
    scanf("%d%d",&y,&z);
    int x=y-z,yay[y];
    for(int i=0;i<y;i++){
        scanf("%d",&yay[i]);
    }

    int temp,j;

    for(int i=1;i<y;i++){
        j=i-1;
        temp=yay[i];
        while(j>=0 && temp<yay[j]){
            yay[j+1]=yay[j];
            j--;
        }
        yay[j+1]=temp;
    }
    int qmax=0,qmin=0;
    for(int a=0;a<x;a++){
        qmin+=yay[a];
        qmax+=yay[y-a-1];
    }
    int ans=qmax-qmin;
    printf("%d",ans);
    return 0;
}