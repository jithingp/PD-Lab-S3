#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
    int zz=1;
    char vin;
    char *vari=(char*)malloc(sizeof(char));
    do{
        scanf("%c",&vin);
        zz++;
        vari=(char*)realloc(vari,sizeof(char)*zz);
        vari[zz-2]=vin;
    }while(vin!='\n');
    
    for(int i=0;i<strlen(vari)-1;i++){
       if(isupper(vari[i])){
           vari[i]=tolower(vari[i]);
           printf("%c",vari[i]);

       }
       else if(islower(vari[i])){
           vari[i]=toupper(vari[i]);
           printf("%c",vari[i]);
       }
       else{
           printf("%c",vari[i]);
       }
    }
   return 0;
}