#include<stdio.h>
int main(){
    int tot;
    scanf("%d",&tot);
    int numarr[tot];
    for(int i=0;i<tot;i++){
        scanf("%d",&numarr[i]);

    }
    int tempo,zumba=1001;
    int y=0;
    for(int i=0;i<tot-1;i++){
        int ennaam=0;
        int z=0;
        tempo=numarr[i];
        for(int j=i+1;j<tot;j++){
          
           if(tempo==numarr[j]&&tempo<=1000){
               if(z==0){
                   printf("%d %d %d",tempo,i,j);
                   z=1;
                   y=1;
                   numarr[i]=zumba;
                   numarr[j]=zumba;
                   ennaam=2;
               }
               else{
                   printf(" %d",j);
                   numarr[j]=zumba;
                   ennaam++;
               }
           }
        }
        if(ennaam!=0)
        printf(" %d\n",ennaam);
    }
    if(y==0)
    printf("%d",-1);
    return 0;
}