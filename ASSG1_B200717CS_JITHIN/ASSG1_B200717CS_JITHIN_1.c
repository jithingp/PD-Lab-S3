#include<stdio.h>
int main(){
    int octnum,decinum=0;
    scanf("%d",&octnum);
    int c=1,d;
    do{
       d=octnum%10;
       decinum=decinum+(d*c);
       c*=8;
       octnum/=10;
    }while(octnum>0);
    printf("%d",decinum);
    return 0;
}