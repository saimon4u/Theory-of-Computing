#include<bits/stdc++.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
using namespace std;
void printTable(vector <vector <vector <int> > > &transition){
    cout << "s  | 1| 0   " << endl;
    int c = 1;
    for(auto t: transition){
        cout << c++ << "-> ";
        for(auto d: t){
            for(auto o: d){
                cout << o;
            }
            cout << "  ";
        }
        cout << endl;
    }
}
void printNewTable(vector <vector <vector <int> > > &transition,vector <vector <int> > &newstate){
    int c = 0;
    for(auto t: transition){
        cout << "{";
        for(int i=0; i<newstate[c].size(); i++){
            cout << newstate[c][i];
            if(i!=newstate[c].size()-1)cout << ",";
        }
        cout << "}->";
        for(auto d: t){
            if(d.size()==0){
                cout << "$   ";
                continue;
            }
            for(auto o: d){
                cout << o;
            }
            cout << "  ";
        }
        cout << endl;
        c++;
    }
}
void subsets(vector<int>& A, vector<vector<int> >& res,vector<int>& subset, int index){
	res.push_back(subset);
	for (int i = index; i < A.size(); i++) {
		subset.push_back(A[i]);
		subsets(A, res, subset, i + 1);
		subset.pop_back();
	}
	return;
}
bool compare(vector<int> &a,vector<int> &b){
    return a.size() < b.size();
}
int main(){

// this freopen reads input from a file called nfa.txt

    freopen("new.txt","r",stdin);
    int num_states,num_symbol,num_final,temp;
    // printf("Enter the number of states: ");
    cin >> num_states;
    // printf("Enter the number of symbol in alphabet: ");
    cin >> num_symbol;
    // printf("Enter the number of final state: ");
    cin >> num_final;
    vector <int> set_of_state;
    int alphabet[num_symbol],initial_state,final_states[num_final];



    // I store the whole Transition function of this NFA in a 3D vector


    vector <vector <vector <int> > > transition;
    for(int i=0; i<num_states; i++){
        // printf("Enter %dth state: ",i+1);
        cin >> temp;
        set_of_state.push_back(temp);
    }
    // printf("\n\n");
    for(int i=0; i<num_symbol; i++){
        // printf("Enter %dth symbol of alphabet: ",i+1);
        cin >> alphabet[i];
    }
    // printf("Enter the initial state: ");
    cin >> initial_state;
    for(int i=0; i<num_final; i++){
        // printf("Enter %dth final state: ",i+1);
        cin >> final_states[i];
    }
    int num_transition[num_states][num_symbol];
    for(int i=0; i<num_states; i++){
        // printf("For %d: \n",set_of_state[i]);
        vector <vector <int> > d;
        for(int j=0; j<num_symbol; j++){
            // printf("If the input is %d : \n",alphabet[j]);
            // printf("How many transition? : ");
            cin >> num_transition[i][j];
            vector <int> t;
            for(int k=0; k<num_transition[i][j]; k++){
                cin >> temp;
                t.push_back(temp);
            }
            d.push_back(t);
        }
        transition.push_back(d);
    }


    cout << "This the transition table of the given NFA: " << endl;
    printTable(transition);


// This section generates all the subsets of our given states and map them with a integer value so that we can refer them easily


    vector <vector <int> > newstate;
    vector <int> subset;
    int index = 0;
    subsets(set_of_state,newstate,subset,index);
    sort(newstate.begin(),newstate.end(),compare);

    cout << endl << "This is the list of all subset of our given states: " << endl;
    for(auto n: newstate){
        for(auto s: n){
            cout << s << " ";
        }
        cout << endl;
    }
    cout << endl;
    index = 1;
    map <vector<int>,int> mp;
    for(auto v: newstate){
        if(v.empty())continue;
        mp[v] = index++;
    }


//This section creates a new table for all the subset ... i create this table using union of set


    vector <vector <vector <int> > > newTable;
    for(auto state: newstate){
        vector< vector <int> > newIndiState;
        vector<int> zero;
        vector<int> one;
        for(auto indistate: state){
            for(auto t: transition[indistate-1][0]){
                zero.push_back(t);
            }
            for(auto t: transition[indistate-1][1]){
                one.push_back(t);
            }
        }
        newIndiState.push_back(zero);
        newIndiState.push_back(one);
        newTable.push_back(newIndiState);
        zero.clear();
        one.clear();
        newIndiState.clear();
    }
    cout <<"This is the new subset transition table: " << endl << endl;;
    printNewTable(newTable,newstate);
    cout << endl;


/*This section create the original DFA table from the subset transition table using subset generation method and store them in a 2D vector
but i also use a vector of pair so that i can print the ingoing and transition states in a understable way.... but if i print the 2D vector 
then the result will be the same but this will be hard to understand */


    vector < vector <int> > dfaTable;
    vector<pair < int ,vector<int> > > table;
    queue <int> track;
    track.push(1);
    int b = 0;
    while(!track.empty() && b<newTable.size()){
        b = track.front();
        vector<int> res;
        for(int j=0; j<newTable[b].size(); j++){
            if(newTable[b][j].empty())continue;
            for(int k=0; k<newstate.size(); k++){
                if(newTable[b][j]==newstate[k]){
                    res.push_back(mp[newTable[b][j]]);
                    if(k!=b && k>b)track.push(mp[newTable[b][j]]);
                    break;
                }
            }
        }
        if(!res.empty())dfaTable.push_back(res);
        table.push_back({b,res});
        res.clear();
        track.pop();
    }
    cout << "This is our desired DFA table: " << endl << endl;
    for(auto it: table){
        cout << it.first << "  -> ";
        for(auto v: it.second){
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}