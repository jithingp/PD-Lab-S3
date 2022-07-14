#include<stdio.h>
#include<stdlib.h>

void insertionsortds(int *omar,int osiz){
    
    
    for(int i=1;i < osiz;i++)
    {
        int temp=omar[i];
        int j =i-1;
 
        while(j >= 0&&omar[j]<temp)
        {
            omar[j+1]=omar[j];
            j--;
        }
        omar[j+1]=temp;
    }
}
void insertionsortas(int *emar,int esiz){
   
    
    
    for(int i = 1;i<esiz;i++)
    {
        int temp=emar[i];
        int j=i-1;
 
        while(j >= 0 && emar[j]>temp)
        {
            emar[j+1]=emar[j];
            j--;
        }
        emar[j+1]=temp;
    }

}
void print(int *x,int n){
    
    for(int i=0;i<n;i++){
        printf("%d ",x[i]);
    }
    printf("\n");

}

int main(){
    int siz,esiz,osiz;
    
    scanf("%d",&siz);
    if(siz%2==0){
        esiz=siz/2;
        osiz=siz/2;
    }
    else{
        esiz=(siz/2)+1;
        osiz=siz/2;
    }
    
    int vumar[siz],emar[esiz],omar[osiz],j=0,k=0;
    for(int i=0;i<siz;i++){
        scanf("%d",&vumar[i]);
        if(i%2==0){
            emar[j]=vumar[i];
            j++;
        }
        else{
            omar[k]=vumar[i];
            k++;
        }
    }
    
    insertionsortas(emar,esiz);
    insertionsortds(omar,osiz);
    print(emar,esiz);
    print(omar,osiz);

    return 0;
}