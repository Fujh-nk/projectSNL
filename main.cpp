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
    if (wFlag)
        for (token t : tokens)
            cout << t.first << '\t' << t.second << endl;
    else
        cout << "false" << endl;
    return 0;
}
