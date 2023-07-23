#include<stdio.h>
int main(){
    char str[100],state='A',steps[100];
    printf("Enter string to check: ");
    scanf("%s",str);
    int i;
    for(i=0; str[i]; i++){
        steps[i] = state;
        switch(state){
            case 'A':
                if(str[i]=='0')state = 'B';
                else state = 'A';
                break;
            case 'B':
                if(str[i]=='0')state = 'C';
                else state = 'A';
                break;
            case 'C':
                if(str[i]=='0')state = 'C';
                else state = 'A';
                break;
        }
    }
    steps[i++] = state;
    steps[i] = '\0';
    if(state=='C')printf("String accepted\n");
    else printf("String not accepted\n");
    printf("Steps are: ");
    for(i=0; steps[i]; i++)printf("%c ",steps[i]);
    printf("\n");
    return 0;
}