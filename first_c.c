#include<stdio.h>
int main(){
    char str[100];
    printf("Enter your string: ");
    scanf("%s",str);
    int flag = 1;
    for(int i=0; str[i]; i++){
        if(str[i]!='0' && str[i]!='1'){
            flag = 0;
            break;
        }
    }
    if(flag){
        printf("This string is from the alphabet\n");
    }
    else{
        printf("This string is not from alphabet\n");
    }
    return 0;
}