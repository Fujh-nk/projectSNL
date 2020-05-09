#include<iostream>
#include<string>

#include"header.h"

using namespace std;

int getType(const char);  // ��ȡ�ַ�����
void addTokenList(const string);  // ���ַ������� token
bool parseSpec(const char);  // ���������ַ�

bool wordAnalyse()  // �ʷ�����
{
    char ch;
    int state = 0;  // ״̬��
    string word = "";
    bool flag = true;  // ������־(δ����)

    tokens.clear();  // ��� token ����

    while (flag && ((ch = getchar()) != '#'))
    {
        int type = getType(ch);  // ��ȡ�ַ�����
        state = transMatrix[state][type];  // ����״̬��
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


int getType(const char ch)  // ��ȡ�ַ�����
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


void addTokenList(const string word)  // ���ַ������� token
{
    if (word == "")
        return;

    unsigned int i;
    if (word[0] >= '0' && word[0] <= '9')  // ����ĸ������
    {
        // �������γ�������
        for (i = 0; i < intConst.size(); i++)
            if (intConst[i] == word)
                break;

        tokens.push_back(make_pair(TK_UINT, i));

        // �����ڣ��²������γ�������
        if (i == intConst.size())
            intConst.push_back(word);

        return;
    }

    // ����ĸ����ĸ

    // ���ұ���������
    for (i = 0; i < reWord.size(); i++)
        if (reWord[i] == word)
        {
            tokens.push_back(make_pair(TK_REWORD, i));
            return;
        }

    // ���ұ�ʶ������
    for (i = 0; i < var.size(); i++)
        if (var[i] == word)
            break;

    tokens.push_back(make_pair(TK_ID, i));

    // �����ڣ������ʶ������
    if (i == var.size())
        var.push_back(word);

    return;
}

bool parseSpec(const char ch)  // ���������ַ�
{
    bool flag = true;  // ������׼
    unsigned int i;
    char temp;
    switch (ch)
    {
    case '\'':  // ���� ��
        temp = getchar();  // ��ȡ�ַ�����
        if (getchar() == '\'')  // �ж� �� �պ�
        {
            // �����ַ��������飬������ token
            for (i = 0; i < charConst.size(); i++)
                if (charConst[i] == temp)
                    break;

            tokens.push_back(make_pair(TK_CHAR, i));  // ���� token

            if (i == charConst.size())  // û�ҵ����ò���
                charConst.push_back(temp);

        }
        else
            flag = false;
        break;

    case '{':  // ���� {
        temp = getchar();
        while (temp != '}' && temp != '#')  // ����ע��
            temp = getchar();
        if (temp == '#')
            flag = false;  // �ʷ���������
        break;

    case '}':  // ֱ�ӳ��� }, ����
        flag = false;
        break;

    default:  // ���������ַ�
        i = specChar_str.find(ch);
        if (i < spacePos)  // ������հ��ַ�(�ո�\t��\n)
            tokens.push_back(make_pair(TK_SPECCHAR, i));
        break;
    }
    return flag;
}
