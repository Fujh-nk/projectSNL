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
        type = NUM;
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'z'))
        type = LETTER;
    else if (specChar_str.find(ch) != string::npos)
        type = SPECCHAR;

    return type;
}


void addTokenList(const string word)  // ���ַ������� token
{

}

bool parseSpec(const char ch)  // ���������ַ�
{
    bool flag = true;  // ������׼

    return flag;
}
/*
{
    if (ch != '\n' && ch != '{')  // ������������
        {
            int ch_type = getType(ch);
        }
        else if (ch == '\'')  // �����ַ�����
        {
            char temp = getchar();
            if (getchar() == '\'')
            {
                // �����ַ��������飬������ token
            }
            else
                flag = false;  // �ʷ���������
        }
        else if (ch == '{')  // ����ע��
        {
            while (ch != '}' && ch != '#')  // ����ע��
                ch = getchar();
            if (ch == '#')
                flag = false;  // �ʷ���������
        }
}*/
