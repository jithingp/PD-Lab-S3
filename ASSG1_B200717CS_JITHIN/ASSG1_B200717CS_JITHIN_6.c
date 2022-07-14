#include<stdio.h>
#include<stdlib.h>

void camara(int c,int a,int b){
    if(a%c==0 && b%c==0)
    printf("%d",c);
    else{
        camara(c-1,a,b);
    }
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    a=abs(a);
    b=abs(b);
    if(a%b==0){
        printf("%d",b);
    }
    else if(b%a==0){
        printf("%d",a);
    }
    else{
        if(a>b)
        camara(b/2,a,b);
        else
        camara(a/2,a,b);
    }

    return 0;
}