#include<stdio.h>
#include<stdbool.h>
int main(){
    char str[100],state='A',steps[100],condition[100];
    printf("Enter string to check: ");
    scanf("%s",str);
    printf("Enter condition: ");
    scanf("%s",condition);
    int i;
    bool flag = false;
    for(i=0; str[i]; i++){
        steps[i] = state;
        switch(state){
            case 'A':
                if(str[i]==condition[0])state = 'B';
                break;
            case 'B':
                if(str[i]==condition[1])state = state = 'C';
                else if(condition[1]==condition[0])state = 'A';
                break;
            case 'C':
                flag = true;
                break;
        }
    }
    steps[i++] = state;
    steps[i] = '\0';
    if(flag)printf("String accepted\n");
    else printf("String not accepted\n");
    printf("Steps are: ");
    for(i=0; steps[i]; i++)printf("%c ",steps[i]);
    printf("\n");
    return 0;
};