#include<stdio.h>
void stateUpgrade(char *state,char check,char update[],char alphabet[],int num){
    for(int i=0; i<num; i++){
        if(check == alphabet[i]) *(state) = update[i];
    }
}
int main(){

//Input Section

    int num_states,num_symbol,num_final;
    printf("Enter the number of states: ");
    scanf("%d",&num_states);
    printf("Enter the number of symbol in alphabet: ");
    scanf("%d",&num_symbol);
    printf("Enter the number of final state: ");
    scanf("%d",&num_final);
    getchar();
    char set_of_state[num_states],alphabet[num_symbol],initial_state,final_states[num_final],transition_table[num_states][num_symbol],input_string[100],steps[100];
    for(int i=0; i<num_states; i++){
        printf("Enter %dth state: ",i+1);
        scanf("%c",&set_of_state[i]);
        getchar();
    }
    printf("\n\n");
    for(int i=0; i<num_symbol; i++){
        printf("Enter %dth symbol of alphabet: ",i+1);
        scanf("%c",&alphabet[i]);
        getchar();
    }
    printf("Enter the initial state: ");
    scanf("%c",&initial_state);
    getchar();
    for(int i=0; i<num_final; i++){
        printf("Enter %dth final state: ",i+1);
        scanf("%c",&final_states[i]);
        getchar();
    }
    for(int i=0; i<num_states; i++){
        printf("For %c:\n",set_of_state[i]);
        for(int j=0; j<num_symbol; j++){
            printf("If the input is %c: ",alphabet[j]);
            scanf("%c",&transition_table[i][j]);
            getchar();
        }
    }
    printf("Enter the string: ");
    scanf("%s",input_string);

// Calculation Section

    int i;
    for(i=0; input_string[i]; i++){
        steps[i] = initial_state;
        stateUpgrade(&initial_state,input_string[i],transition_table[initial_state-'a'],alphabet,num_symbol);
    }
    steps[i] = initial_state;
    if(initial_state == 'a'+ num_states-1)printf("Accepted\n");
    else printf("Not Accepted\n");
    printf("States: ");
    for(i=0; steps[i]; i++)printf("%c ",steps[i]);
    printf("\n");
    return 0;
};