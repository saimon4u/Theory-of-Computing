#include<bits/stdc++.h>
#include<fstream>
using namespace std;
// vector <string> vec;
void printSingleLine(string line){
    int pos = line.find("//");
    for(int i=pos+2; i<line.size(); i++){
        cout << line[i];
    }
}
void printMultiLine(string line){
    int sPos = line.find("/*");
    int ePos = line.find("*/");
    for(int i=sPos+2; i<ePos; i++){
        cout << line[i];
    }
}
void getComment(string &filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error Opening file: " << filename << endl;
        return;
    }
    string line;
    bool insideMultiComment = false;
    int number = 1;
    while(getline(file,line)){
        if(line.empty()){
            number++;
            continue;
        }
        if(line.size() >= 2 && line.find("//") != string::npos){
            cout << number << "---";
            printSingleLine(line);
            cout << endl;
        }
        else if(line.size()>=2 && line.find("/*") != string::npos && line.find("*/") != string::npos){
            // vec.push_back(line);
            cout << number << "---";
            printMultiLine(line); 
            cout << endl;
        }
        else if(line.size() >= 2 && line.find("/*") != string::npos) {
            insideMultiComment = true;
            cout << number << "---";
            int sPos = line.find("/*");
            for(int i= sPos+2; i<line.size(); i++){
                cout << line[i];
            }
            cout << endl;
            // vec.push_back(line);
        }
        else if(insideMultiComment && line.find("*/") != string::npos) {
            insideMultiComment = false;
            cout << number << "---";
            int i=0;
            while(isspace(line[i]))i++;
            for(; line[i]!='*'; i++){
                cout << line[i];
            }
            cout << endl;
            // vec.push_back(line);
        }
        else if(insideMultiComment){
            cout << number << "---" << line << endl;
            // vec.push_back(line);
        }
        number++;
    }
    file.close();
    // if(insideMultiComment)cout << "There was an error you didn't put the ending comment" << endl;
    // else{
    //     for(auto v: vec){
    //         cout << v << endl;
    //     }
    // }
}
int main(){
    string fileName = "input.c";
    getComment(fileName);
    return 0;
}