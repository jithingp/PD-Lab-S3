#include<stdio.h>
#include<string.h>
void togglemove(char* a){
int i=0;
while(a[i]!= '\0'){
    if (a[i]>='A' && a[i]<='Z'){
        a[i]=a[i]+32;
    }
   else if (a[i]>='a' && a[i]<='z'){
        a[i]=a[i]-32;
    }
    ++i;
}
 }
void mergereversestring(char* str1,char* str2){
strcat(str1,str2);
strrev(str1);
printf("%s \n",str1);
return;
}
int main(){
char arr[100][100];
int n;
scanf("%d",&n);
int m=2*n;
int i=0,l=0,q=0;
for(;i<m;++i){
    scanf("%s",&arr[i]);
}
for(;l<m;++l){
togglemove(arr[l]);
}
while(q<(m)){
        int o=q+1;
    mergereversestring(arr[q],arr[o]);
q+=2;
}
}
