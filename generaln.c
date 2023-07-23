#include<stdio.h>
void stateUpgrade(char *state,char check,char update_x,char update_y){
    if(check == '0')*(state) = update_x;
    else *(state) = update_y;
}
int main(){
    char str[100],condition[100],states[100][2];
    int c_size;
    printf("Enter the string: ");
    scanf("%s",str);
    printf("Enter the size of your condition: ");
    scanf("%d",&c_size);
    getchar();
    // printf("Enter the condition: ");
    // scanf("%s",condition);
    // getchar();
    printf("Enter the transition table: \n");
    for(int i=0; i<=c_size; i++){
        printf("For: %c\n",'A'+i);
        printf("If the input is 0: ");
        scanf("%c",&states[i][0]);
        getchar();
        printf("If the input is 1: ");
        scanf("%c",&states[i][1]);
        getchar();
    }
    char current_states = 'A';
    char list[100];
    int i;
    for(i=0; str[i]; i++){
        list[i] = current_states;
        stateUpgrade(&current_states,str[i],states[current_states-'A'][0],states[current_states-'A'][1]);
    }
    list[i] = current_states;
    if(current_states == 'A'+ c_size)printf("Accepted\n");
    else printf("Not Accepted\n");
    printf("States: ");
    for(i=0; list[i]; i++)printf("%c ",list[i]);
    printf("\n");
    return 0;
};