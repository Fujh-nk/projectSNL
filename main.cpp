#include<iostream>

#include"header.h"

using namespace std;

vector<token> tokens;  // token ����
vector<string> intConst;  // Interger ����
vector<char> charConst;  // Char ����
vector<string> var;  // ��ʶ��

int main()
{
    bool wFlag = wordAnalyse();
    // cout << wFlag;
    return 0;
}
