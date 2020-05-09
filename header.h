#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<vector>
#include<string>
#include<array>

// �ַ�����ʶ
#define C_NUM 1  // 0-9�ı�ʶ
#define C_LETTER 2  // a-z, A-Z�ı�ʶ
#define C_SPECCHAR 3  // �����ַ���ʶ
#define C_UNKNOW 0  // ����ʶ���ʶ

#define KIND 4  // �ַ������(��������ʶ���ʶ)
#define STATE 3  // ״̬��״̬��
#define ST_ERROR -1  // ����״̬��
#define ST_TOKEN 0  // ����TOKEN״̬��
#define ST_NUM 1  // ���ֳ���״̬��
#define ST_VAR 2  // ��ʶ��״̬��

#define NUM_OF_REWORD 21  // ��������Ŀ
#define NUM_OF_SPECCHAR 15  // ���������Ŀ

// token ���
#define TK_UINT 1  // ���γ���
#define TK_SPECCHAR 2  // �����ַ�
#define TK_REWORD 3  // ������
#define TK_ID 4  // ��ʶ��
#define TK_CHAR 5  // �ַ�����

using namespace std;

typedef pair<int, int> token;  // token ��ʽ��<�����룬�������>

extern vector<token> tokens;  // token ����
extern vector<string> intConst;  // Interger ����, �ַ�����ʾ, ��ֹ��������
extern vector<char> charConst;  // Char ����
extern vector<string> var;  // ��ʶ��

const array<string, NUM_OF_REWORD> reWord  // ����������
{"array", "begin", "char", "do", "end", "else", "endwh",
"fi", "if", "integer", "of", "program", "procedure", "read",
"record", "return", "then", "type", "var", "while", "write"
};

const array<string, NUM_OF_SPECCHAR> specChar  // �����������
{"+", "-", "*", "/",
"(", ")", "[", "]",
";", "=", "<", " ",
":=", ".", ".."};

const string specChar_str = "+-*/()[];<:=. \t\n'{}";  // �����ַ���ɵ��ַ���
const unsigned int spacePos = specChar_str.find(' ');  // �ո��λ��

const int transMatrix[STATE][KIND]  // ״̬ת�ƾ���
{ST_ERROR, ST_NUM, ST_VAR, ST_TOKEN,
ST_ERROR, ST_NUM, ST_ERROR, ST_TOKEN,
ST_ERROR, ST_VAR, ST_VAR, ST_TOKEN};

bool wordAnalyse();  // �ʷ�����
bool grammerAnalyse();  // �﷨����

#endif // HEADER_H_INCLUDED