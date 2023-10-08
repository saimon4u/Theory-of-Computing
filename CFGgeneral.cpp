#include<bits/stdc++.h>
using namespace std;
vector<string> leftD;
vector <string> rightD;
unordered_map<char,vector<string>> mp;
string str;
int part;
string searchProd(char index,char forWhich){
    int i = 0;
    for(; i<mp[index].size(); i++){
        if((mp[index])[i][0] == forWhich) break;
    }
    if(i==mp[index].size()) return mp[index][0];
    return mp[index][i];
}
int indexof(char x,string s){
    for(int i=0; i<s.size(); i++){
        if(s[i]==x) return i;
    }
    return -1;
}
void generateLeftDerivation(int present,string current){
    leftD.push_back(current);
    if(present==current.size()) return;
    char start = str[present];
    string rep = searchProd(current[present],start);
    current = current.substr(0,present) + rep + current.substr(present+1,current.size());
    int i = 0;
    for(i=0; i<current.size(); i++){
        if(current[i] == 'A' || current[i] == 'B' || current[i] == 'S') break;
    }
    generateLeftDerivation(i,current);
}
// a1b = a11b = a110b = a1101b = a1101 = 1101
void generateRR(string &current){
    rightD.push_back(current);
    int i = 0;
    for(i=current.size()-1; i>=0; i--){
        if(current[i] == 'A' || current[i] == 'B' || current[i] == 'S') break;
    }
    if(i < part && current[i] != 'S')return;
    char start = str[i+1];
    string rep = searchProd(current[i],start);
    current = current.substr(0,i) + rep + current.substr(i+1,current.size());
    generateRR(current);
}
void generateRL(string &current,bool push){
    if(!push) rightD.push_back(current);
    int i = 0;
    for(i=0; i<current.size(); i++){
        if(current[i] == 'A' || current[i] == 'B' || current[i] == 'S') break;
    }
    if(i > part)return;
    char start = str[i];
    string rep = searchProd(current[i],start);
    current = current.substr(0,i) + rep + current.substr(i+1,current.size());
    generateRL(current,false);
}
void generateRightDerivation(string current){
    generateRR(current);
    generateRL(current,true);
}
int main(){
    mp['S'] = {"A1B"};
    mp['A'] = {"","0A"};
    mp['B'] = {"","0B","1B"};
    cout << "Enter a string: ";
    cin >> str;
    for(auto s: str){
        if(s != '0' && s!= '1'){
            cout << "Your input is invalid !" << endl;
            return 0;
        }
    }
    for(int i=0; i<str.size(); i++){
        if(str[i] == '1'){
            part = i;
            break;
        }
    }
    string present = "S";
    generateLeftDerivation(0,present);
    generateRightDerivation(present);
    if(leftD[leftD.size()-1] != str){
        cout << "Not in the grammer !" << endl;
        return 0;
    }
    cout << endl;
    cout << "Left Derivation : ";
    cout << leftD[0];
    for(int i=1; i<leftD.size(); i++){
        cout << " => " << leftD[i];
    }
    cout << endl << endl;
    cout << "Right Derivation : ";
    cout << rightD[0];
    for(int i=1; i<rightD.size(); i++){
        cout << " => " << rightD[i];
    }
    cout << endl << endl;
    return 0;
}