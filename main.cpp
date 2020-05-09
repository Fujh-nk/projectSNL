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
    // cout << wFlag;
    return 0;
}
