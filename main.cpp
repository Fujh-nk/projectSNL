#include<iostream>

#include"header.h"

using namespace std;

vector<token> tokens;  // token 序列
vector<string> intConst;  // Interger 常量
vector<char> charConst;  // Char 常量
vector<string> var;  // 标识符

int main()
{
    bool wFlag = wordAnalyse();
    if (wFlag)
        for (token t : tokens)
            cout << t.first << '\t' << t.second << endl;
    else
        cout << "false" << endl;
    return 0;
}
