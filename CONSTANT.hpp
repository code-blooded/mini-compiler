#include <bits/stdc++.h>
using namespace std;

void print(int state){
    switch (state) {
        case 0:
            std::cout << "start";
            break;
        case 1:
            std::cout << "int_i";
            break;
        case 2:
            std::cout << "int_in";
            break;
        case 3:
            std::cout << "int_int";
            break;
        case 4:
            std::cout << "space";
            break;
        case 5:
            std::cout << "id";
            break;
        case 6:
            std::cout << "equals";
            break;
        case 7:
            std::cout << "constant_int";
            break;
        case 8:
            std::cout << "comma";
            break;
        default:
            std::cout << "Error!!";
    }
}

string STATE[] =
{
    "start",
    "int_i",
    "int_in",
    "int_int",
    "space",
    "id",
    "equals",
    "constant_int",
    "comma"
};
