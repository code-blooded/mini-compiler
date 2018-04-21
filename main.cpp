#include <bits/stdc++.h>
#include "LUA.hpp"
using namespace std;

int main(){

    init();

    auto code = input();
    print(code);

    auto parsed = parser(code);
    print(parsed);

    return 0;
}
