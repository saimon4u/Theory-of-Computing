#include<bits/stdc++.h>
using namespace std;
int main(){
    vector <vector <char> > dfa;
    char c;
    freopen("re.txt","r",stdin);
    for(int i=0; i<3; i++){
        vector <char> vec;
        for(int j=0; j<2; j++){
            cin >> c;
            vec.push_back(c);
        }
        dfa.push_back(vec);
    }
    vector <vector <vector <string> > > r;
    vector <vector <string> > r0(dfa.size(),vector<string>(dfa.size()));
    for(int i=0; i<dfa.size(); i++){
        for(int j=0; j<dfa.size(); j++){
            char present = 'a' + i;
            char destination = 'a' + j;
            string val;
            val.push_back('(');
            for(int k=0; k<dfa[i].size(); k++){
                if(dfa[i][k]==destination){
                    val.push_back('0'+k);
                    val.push_back('+');
                }
            }
            if(i==j)val.push_back('e');
            if(val[1]=='+')val.erase(val.begin()+1);
            if(val[val.size()-1]=='+')val.pop_back();
            val.push_back(')');
            if(val.size()==2)r0[i][j] = "";
            else r0[i][j] = val;
        }
    }
    r.push_back(r0);
    for(int k=0; k<2;  k++){
        vector <vector <string> > rn(dfa.size(),vector<string>(dfa.size()));
        for(int i=0; i<dfa.size(); i++){
            for(int j=0; j<dfa.size(); j++){
                string val = "";
                val += r[k][i][j] + "+" + r[k][i][k] + "(" + r[k][k][k] + ")" + "*" + r[k][k][j];
                if(val[0]=='+')val.erase(val.begin());
                if(val[val.size()-1]=='+')val.pop_back();
                rn[i][j] = val;
            }
        }
        r.push_back(rn);
    }
    for(int k=0; k<3;  k++){
        for(int i=0; i<dfa.size(); i++){
            for(int j=0; j<dfa.size(); j++){
                cout << "R(" << k << ")" << i+1 << j+1 << "->" << r[k][i][j] << endl;
            }
        }
        cout << endl << endl;
    }
}