#include<stdio.h>
int main(){
    char str[100];
    printf("Enter your string: ");
    scanf("%s",str);
    int count = 0;
    for(int i=0; str[i]; i++){
        count++;
    }
    int flag = 1;
    for(int i=0,j=count-1; i<count/2; i++,j--){
        if(str[i]!=str[j]){
            flag = 0; 
            break;
        }
    }
    if(flag){
        printf("String is palindrome\n");
    }
    else{
        printf("String is not palindrome\n");
    }
    return 0;
}