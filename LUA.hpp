#include <bits/stdc++.h>
using namespace std;

#define INPUT  "input.txt"
#define OUTPUT "output.txt"

void print(vector<string> code){
    for (size_t i = 0; i < code.size(); i++) {
        cout<<i<<" --> ";
        cout<<code[i]<<endl;
    }
}

vector<string> input(){
	// reading input file using stringstream
    ifstream in(INPUT);
    string line;
    vector<string> code;
    while(getline(in,line)){
		// read line by line
        stringstream linestream(line);
        string value;
        while(getline(linestream,value)){
            code.push_back(line);
        }
    }
    return code;
}
