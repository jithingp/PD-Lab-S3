#include<stdio.h>
#include<string.h>
void gta(char *z,char *s,char *ch){
    z=ch;
    z++;
    
    
        ch=strstr(z,s);
        if(ch!=NULL){
            if(ch-z>=strlen(s)){
                z=z+strlen(s)-1;
            for(;z!=ch;z++){
                printf("%c",*z);
                
            }
            gta(z,s,ch);
            }
            else{
                z=ch+strlen(s);
                gta(z,s,ch);
            }
            
        }
        else{
            z--;
            z+=strlen(s);
            printf("%s",z);
            return;
        }

 
}
int main(){
    char c[1000],s[1000];
    scanf("%s",&c);
    scanf("%s",&s);
    char *z=c;
    
    
    char *ch=strstr(z,s);
    if(ch!=NULL){ 
         for(;z!=ch;z++){
                printf("%c",*z);
               
            }
         
     gta(z,s,ch);
    }
    else{
     printf("%s",c);
    }
    return 0;
}

