#include<stdio.h>
int main(){
    int n,counter=0,c=0,fin=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(arr[i]>=0){
            counter++;
            c+=arr[i];
            fin=1;
        }
    }
    if(fin==0){
        int max=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>max)
            max=arr[i];
        }
        printf("%d %d",max,1);
    }
    else{
    printf("%d %d",c,counter);
     }   
    return 0;

}