#include<stdio.h>
int main(){
    int ziz1,ziz2;
    scanf("%d %d",&ziz1,&ziz2);
    int marr1[ziz1+ziz2];
    for(int i=0;i<ziz1;i++){
        scanf("%d",&marr1[i]);

    }
    for(int i=ziz1;i<ziz1+ziz2;i++){
        scanf("%d",&marr1[i]);
    }
    int tempo,zumba=1001;
    for(int i=0;i<(ziz1+ziz2-1);i++){
        tempo=marr1[i];
        int z=0;
        for(int j=i+1;j<ziz1+ziz2;j++){
             if(tempo==marr1[j]&&tempo<=1000){
                 if(z==0){
                     printf("%d %d",tempo,tempo);
                     z=1;
                     marr1[i]=zumba;
                     
                     marr1[j]=zumba;
                     
                 }
                 else{
                     printf("%d",tempo);
                     marr1[j]=zumba;
                     
                 }
                 printf(" ");

             }
        }
    }
    for(int i=0;i<ziz1+ziz2;i++){
        if(marr1[i]<=1000){
            printf("%d ",marr1[i]);
        }
    }
    return 0;
}