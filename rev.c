#include<stdio.h>
#include<string.h>

void reverse(char* str){
    int len=strlen(str);
    int i;
    int j=len-1;
    while(i<j){
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j++;
    }
}

int main(){
    char str[]="parthu";
    reverse(str);
    printf("reveresed character : %c",str);
    return 0;
}
