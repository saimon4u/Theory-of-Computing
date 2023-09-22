#include<bits/stdc++.h>
using namespace std;
char sub[100]; // to store a created string
vector <string> vec; // to store every created string for an iteration
set <int> dont; // to store the index of removed states

// this funcion generate all the input string for an iteration
void generate(int k,int index){
    if(index==k){
        sub[index] = '\0';
        vec.push_back(sub);
        return;
    }
    sub[index] = '0';
    generate(k,index+1);
    sub[index] = '1';
    generate(k,index+1);
    return;
}

//this function read all the input from the file and create the transition function of DFA
void createDfa(vector<char> &states,vector<vector<char>> &Dfa,char &initialState,set<char> &finalStates){
    int numState;
    cin >> numState;
    for(int i=0; i<numState; i++){
        getchar();
        char state;
        cin >> state;
        states.push_back(state);
        getchar();
        char zeroTransition,oneTransition;
        cin >> zeroTransition;
        getchar();
        cin >> oneTransition;
        Dfa.push_back({zeroTransition,oneTransition});
    }
    getchar();
    cin >> initialState;
    int numFinalState;
    cin >> numFinalState;
    for(int i=0; i<numFinalState; i++){
        getchar();
        char state;
        cin >> state;
        finalStates.insert(state);
    }
}

// this function checks if a given state final or not
bool isFinal(set<char> &finalStates,char state){
    return finalStates.find(state) != finalStates.end();
}

// this function returns the state that is reachable for a given state using the given input string
char transfer(vector<vector<char>> &dfa,char state,string str){
    for(auto s: str){
        if(s=='0') state = dfa[state-'a'][0];
        else state = dfa[state-'a'][1];
    }
    return state;
}


int main(){
    freopen("in.txt","r",stdin);
    vector <char> states;
    vector <vector <char>> dfa;
    char initialState;
    set <char> finalStates;

    // creating the input DFA
    createDfa(states,dfa,initialState,finalStates);
    cout << "Your main dfa look like: " << endl << endl;
    printf("%4s%4d%4d\n","from",0,1);
    for(int i=0; i<dfa.size(); i++){
        printf("%2c%6c%4c\n",i+'a',dfa[i][0],dfa[i][1]);
    }
    cout << endl << endl;

    // initialing the cross-equal table
    int numState = dfa.size();
    char table[numState][numState];
    for(int i=0; i<numState; i++){
        for(int j=0; j<numState; j++){
            table[i][j] = '*';
        }
    }

    // initializing cross for all the final state with non-final state
    for(int i=0; i<numState; i++){
        table[i][i] = '=';
        for(int j=i+1; j<numState; j++){
            if(isFinal(finalStates,states[i]) != isFinal(finalStates,states[j])){
                table[i][j] = 'X';
                table[j][i] = 'X';
            }
        }
    }

    // iterating through each state and checking their equivalency for 3 time 
    for(int i=0; i<numState; i++){
        for(int j=i+1; j<numState; j++){
            for(int l=1; l<=3; l++){
                if(table[i][j]=='X')continue;
                vec.clear();
                generate(l,0);
                int k;
                for(k=0; k<vec.size(); k++){
                    char tran_i = transfer(dfa,states[i],vec[k]);
                    char tran_j = transfer(dfa,states[j],vec[k]);
                    if(isFinal(finalStates,tran_i) != isFinal(finalStates,tran_j)){
                        table[i][j] = 'X';
                        table[j][i] = 'X';
                        break;
                    }
                    else{
                        table[i][j] = '=';
                        table[j][i] = '=';
                    }
                }
            }
        }
    }

    // printing the equivalent table
    cout << "After minimization the table look like: " << endl;
    for(int i=0; i<numState; i++){
        for(int j=0; j<i; j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    // creating the equivalent vector
    vector<vector<char>> rem(numState);
    for(int i=0; i<numState; i++){
        for(int j=0; j<i; j++){
            if(i==j)continue;
            else if(table[i][j]=='='){
                rem[i].push_back(j+'a');
                rem[j].push_back(i+'a');
            }
        }
    }

    // iterating through all the non-removable state and removing their equivalent state
    for(int i=0; i<rem.size(); i++){
        if(dont.find(i) != dont.end())continue;
        for(int j=0; j<rem[i].size(); j++){
            char now = rem[i][j];
            for(int k=0; k<dfa.size(); k++){
                for(int l=0; l<2; l++){
                    if(dfa[k][l] == now){
                        dfa[k][l] = 'a' + i;
                    }
                }
            }
            dont.insert(now-'a');
        }
    }
    
    // printing the final minimized DFA
    cout << "Your minimized dfa look like: " << endl << endl;
    printf("%4s%4d%4d\n","from",0,1);
    for(int i=0; i<dfa.size(); i++){
        if(dont.find(i) != dont.end())continue;
        printf("%2c%6c%4c\n",i+'a',dfa[i][0],dfa[i][1]);
    }
}