#include<stdio.h>
#include<stdlib.h>
int *CONVERT(int n){
    int i=15;
    int *bitar=(int*)malloc(16*sizeof(int));
    do{
        bitar[i]=n%2;
        n/=2;
        i--;
    }while(n>0);
    i++;
    while(i--){
        bitar[i]=0;
    }
    for(int j=0;j<16;j++){
        printf("%d",bitar[j]);
    }
    printf("\n");
    return bitar;
   
}
int main(){
    int n,*np,k;
    scanf("%d %d",&n,&k);

    np=CONVERT(n);
    for(int j=k;j<16;j++){
        printf("%d",np[j]);
    }
    for(int j=0;j<k;j++){
        printf("%d",np[j]);
    }
    printf("\n");
    for(int j=16-k;j<16;j++){
        printf("%d",np[j]);
    }
    for(int j=0;j<16-k;j++){
        printf("%d",np[j]);
    }
    return 0;

}