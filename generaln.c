#include<stdio.h>
void stateUpgrade(int *state,char check,char condition){
    if(check == condition)state++;
}
int main(){
    char str[100],steps[100],condition[100];
    printf("Enter string to check: ");
    scanf("%s",str);
    printf("Enter condition: ");
    scanf("%s",condition);
    int i;
    int count = 0;
    for(i=0; condition[i]; i++)count++;
    int totalState = count + 1;
    int state = 1;
    int j = 0;
    for(i=0; str[i]; i++){
        stateUpgrade(&state,str[i],condition[j]);
    }



    if(state=='C')printf("String accepted\n");
    else printf("String not accepted\n");
    printf("Steps are: ");
    for(i=0; steps[i]; i++)printf("%c ",steps[i]);
    printf("\n");
    return 0;
};