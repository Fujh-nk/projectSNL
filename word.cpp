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
                word = "";
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
        type = C_NUM;
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'z'))
        type = C_LETTER;
    else if (specChar_str.find(ch) != string::npos)
        type = C_SPECCHAR;

    return type;
}


void addTokenList(const string word)  // 将字符串加入 token
{
    if (word == "")
        return;

    unsigned int i;
    if (word[0] >= '0' && word[0] <= '9')  // 首字母是数字
    {
        // 查找整形常量数组
        for (i = 0; i < intConst.size(); i++)
            if (intConst[i] == word)
                break;

        tokens.push_back(make_pair(TK_UINT, i));

        // 不存在，新插入整形常量数组
        if (i == intConst.size())
            intConst.push_back(word);

        return;
    }

    // 首字母是字母

    // 查找保留字数组
    for (i = 0; i < reWord.size(); i++)
        if (reWord[i] == word)
        {
            tokens.push_back(make_pair(TK_REWORD, i));
            return;
        }

    // 查找标识符数组
    for (i = 0; i < var.size(); i++)
        if (var[i] == word)
            break;

    tokens.push_back(make_pair(TK_ID, i));

    // 不存在，插入标识符数组
    if (i == var.size())
        var.push_back(word);

    return;
}

bool parseSpec(const char ch)  // 分析特殊字符
{
    bool flag = true;  // 正常标准
    unsigned int i;
    char temp;
    switch (ch)
    {
    case '\'':  // 处理 ‘
        temp = getchar();  // 获取字符常量
        if (getchar() == '\'')  // 判断 ’ 闭合
        {
            // 存入字符常量数组，并生成 token
            for (i = 0; i < charConst.size(); i++)
                if (charConst[i] == temp)
                    break;

            tokens.push_back(make_pair(TK_CHAR, i));  // 生成 token

            if (i == charConst.size())  // 没找到，得插入
                charConst.push_back(temp);

        }
        else
            flag = false;
        break;

    case '{':  // 处理 {
        temp = getchar();
        while (temp != '}' && temp != '#')  // 过滤注释
            temp = getchar();
        if (temp == '#')
            flag = false;  // 词法分析出错
        break;

    case '}':  // 直接出现 }, 错误
        flag = false;
        break;

    default:  // 处理特殊字符
        i = specChar_str.find(ch);
        if (i < spacePos)  // 不处理空白字符(空格、\t、\n)
            tokens.push_back(make_pair(TK_SPECCHAR, i));
        break;
    }
    return flag;
}
