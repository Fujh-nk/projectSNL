#include<iostream>
#include<string>

#include"header.h"

using namespace std;

int getType(const char);  // 获取字符类型
void addTokenList(const string);  // 将字符串加入 token
bool parseSpec(const char);  // 分析特殊字符

bool wordAnalyse()  // 词法分析
{
    char ch;
    int state = 0;  // 状态码
    string word = "";
    bool flag = true;  // 正常标志(未出错)

    tokens.clear();  // 清空 token 数组

    while (flag && ((ch = getchar()) != '#'))
    {
        int type = getType(ch);  // 获取字符类型
        state = transMatrix[state][type];  // 更新状态码
        switch (state)
        {
            case ST_ERROR: flag = false; break;
            case ST_NUM: word.append(string {ch}); break;
            case ST_VAR: word.append(string {ch}); break;
            case ST_TOKEN:
                addTokenList(word);
                flag = parseSpec(ch);
                break;
            default: break;
        }
    }
    return flag;
}


int getType(const char ch)  // 获取字符类型
{
    int type = 0;

    if (ch >= '0' && ch <= '9')
        type = NUM;
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'z'))
        type = LETTER;
    else if (specChar_str.find(ch) != string::npos)
        type = SPECCHAR;

    return type;
}


void addTokenList(const string word)  // 将字符串加入 token
{

}

bool parseSpec(const char ch)  // 分析特殊字符
{
    bool flag = true;  // 正常标准

    return flag;
}
/*
{
    if (ch != '\n' && ch != '{')  // 处理其他类型
        {
            int ch_type = getType(ch);
        }
        else if (ch == '\'')  // 分析字符常量
        {
            char temp = getchar();
            if (getchar() == '\'')
            {
                // 存入字符常量数组，并生成 token
            }
            else
                flag = false;  // 词法分析出错
        }
        else if (ch == '{')  // 分析注释
        {
            while (ch != '}' && ch != '#')  // 过滤注释
                ch = getchar();
            if (ch == '#')
                flag = false;  // 词法分析出错
        }
}*/
