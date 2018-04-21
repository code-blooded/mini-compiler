#include <bits/stdc++.h>
#include "CONSTANT.hpp"
using namespace std;

#define INPUT  "input.txt"
#define OUTPUT "output.txt"

struct node{
    int type;
    string val;
    int line;
};

enum state {start, int_i, int_in, int_int, space, id, equals, constant_int, comma};

map <pair<state,char>,state> transition;

void insert_alpha(state curr, state next){
    for (size_t i = 0; i < 26; i++) {
        transition.insert(pair <pair<state,char>,state> ({curr,(char)('a'+i)}, next));
    }
    for (size_t i = 0; i < 26; i++) {
        transition.insert(pair <pair<state,char>,state> ({curr,(char)('A'+i)}, next));
    }
    transition.insert(pair <pair<state,char>,state> ({curr,'_'},next));
}

void insert_star(state curr, state next){
    for (size_t i = 0; i < 26; i++) {
        transition.insert(pair <pair<state,char>,state> ({curr,(char)('a'+i)}, next));
    }
    for (size_t i = 0; i < 26; i++) {
        transition.insert(pair <pair<state,char>,state> ({curr,(char)('A'+i)}, next));
    }
    for (size_t i = 0; i < 10; i++) {
        transition.insert(pair <pair<state,char>,state> ({curr,(char)('0'+i)}, next));
    }
    transition.insert(pair <pair<state,char>,state> ({curr,'_'},next));
}

void insert_no(state curr, state next){
    for (size_t i = 0; i < 10; i++) {
        transition.insert(pair <pair<state,char>,state> ({curr,(char)('0'+i)}, next));
    }
}

void init(){
    // start
    transition.insert(pair <pair<state,char>,state> ({start,' '}, start));
    transition.insert(pair <pair<state,char>,state> ({start,'i'}, int_i));
    // int_i
    transition.insert(pair <pair<state,char>,state> ({int_i,'n'}, int_in));
    // int_in
    transition.insert(pair <pair<state,char>,state> ({int_in,'t'}, int_int));
    // int_int
    transition.insert(pair <pair<state,char>,state> ({int_int,' '}, space));
    // space
    transition.insert(pair <pair<state,char>,state> ({space,' '}, space));
    transition.insert(pair <pair<state,char>,state> ({space,','}, comma));
    transition.insert(pair <pair<state,char>,state> ({space,'='}, equals));
    insert_alpha(space,id);
    insert_no(space,constant_int);
    // id
    insert_star(id,id);
    transition.insert(pair <pair<state,char>,state> ({id,';'}, start));
    transition.insert(pair <pair<state,char>,state> ({id,'='}, equals));
    transition.insert(pair <pair<state,char>,state> ({id,','}, comma));
    transition.insert(pair <pair<state,char>,state> ({id,' '}, space));
    // equals
    insert_no(equals,constant_int);
    transition.insert(pair <pair<state,char>,state> ({equals,' '}, space));
    // constant_int
    insert_no(constant_int,constant_int);
    transition.insert(pair <pair<state,char>,state> ({constant_int,','}, comma));
    transition.insert(pair <pair<state,char>,state> ({constant_int,';'}, start));
    transition.insert(pair <pair<state,char>,state> ({constant_int,' '}, space));
    // comma
    insert_star(comma,id);
    transition.insert(pair <pair<state,char>,state> ({comma,' '}, space));
}

void print(vector<string> code){
    for (size_t i = 0; i < code.size(); i++) {
        cout<<i<<" --> ";
        cout<<code[i]<<endl;
    }
}

void print(vector<struct node> parsed){
    for (size_t i = 0; i < parsed.size(); i++) {
        cout << "----------------------------------" << '\n';
        cout << "Type: " << parsed[i].type << '\n';
        cout << "Val: " << parsed[i].val << '\n';
        cout << "Line: " << parsed[i].line << '\n';
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

void dfa(string statement, int line, vector<struct node> parsed){
    state current = start;
    int curr = 0;
    while(statement[curr]!='\0'){
        std::cout << STATE[current] << " --> ";
        current = transition[{current,statement[curr]}];
        curr++;
        std::cout << STATE[current] << '\n';
    }
}

vector<struct node> parser(vector<string> code){
    vector<struct node> parsed;
    for (size_t i = 0; i < code.size(); i++) {
        dfa(code[i],i,parsed);
    }
    return parsed;
}
