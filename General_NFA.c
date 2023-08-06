#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool result = false;
void stateUpgrade(int num_states,int num_symbol,char *setofstate,char *alphabet,char initialstate,char finalstate,char *inputstring,char transition[num_states][num_symbol][10],int num_transition[num_states][num_symbol],int index){
    printf("%c\n",initialstate);
    if(inputstring[index]!='\0' && initialstate==finalstate)return;
    if(inputstring[index]=='\0'){
        if(initialstate==finalstate){
            result = true;
            return;
        }
        else{
            result = false;
            return;
        }
    }
    int k=0;
    char res;
    while(k<num_transition[initialstate-'a'][inputstring[index]-'0']){
        if(transition[initialstate-'a'][inputstring[index]-'0'][k]!='*'){
            stateUpgrade(num_states,num_symbol,setofstate,alphabet,transition[initialstate-'a'][inputstring[index]-'0'][k],finalstate,inputstring,transition,num_transition,index+1);
        }
        k++;
    }
    if(initialstate == finalstate)result = true;
    else result = false;
    return;
}
int main(){
    int num_states,num_symbol,num_final;
    printf("Enter the number of states: ");
    scanf("%d",&num_states);
    printf("Enter the number of symbol in alphabet: ");
    scanf("%d",&num_symbol);
    printf("Enter the number of final state: ");
    scanf("%d",&num_final);
    getchar();
    char set_of_state[num_states],alphabet[num_symbol],initial_state,final_states[num_final],transition_table[num_states][num_symbol][10],input_string[100],steps[100];
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
        for(int j=0; j<num_symbol; j++){
            for(int k=0; k<10; k++){
                transition_table[i][j][k] = '*';
            }
        }
    }
    int num_transition[num_states][num_symbol];
    for(int i=0; i<num_states; i++){
        printf("For %c: \n",set_of_state[i]);
        for(int j=0; j<num_symbol; j++){
            printf("If the input is %c : \n",alphabet[j]);
            printf("How many transition? : ");
            scanf("%d",&num_transition[i][j]);
            getchar();
            for(int k=0; k<num_transition[i][j]; k++){
                scanf("%c",&transition_table[i][j][k]);
                getchar();
            }
        }
    }
    printf("Enter the string: ");
    scanf("%s",input_string);
    stateUpgrade(num_states,num_symbol,set_of_state,alphabet,initial_state,final_states[0],input_string,transition_table,num_transition,0);
    if(!result)printf("Not\n");
    else printf("Yes\n");
    return 0;
}