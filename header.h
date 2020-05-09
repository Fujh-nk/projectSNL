#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<vector>
#include<string>
#include<array>

#define NUM 1  // 0-9的标识
#define LETTER 2  // a-z, A-Z的标识
#define SPECCHAR 3  // 特殊字符标识
#define UNKNOW 0  // 不可识别标识

#define KIND 4  // 字符类别数(包括不可识别标识)
#define STATE 3  // 状态机状态数
#define ST_ERROR -1  // 错误状态码
#define ST_TOKEN 0  // 生成TOKEN状态码
#define ST_NUM 1  // 数字常量状态码
#define ST_VAR 2  // 标识符状态码

#define NUM_OF_REWORD 21  // 保留字数目
#define NUM_OF_SPECCHAR 15  // 特殊符号数目

using namespace std;

typedef pair<int, int> token;  // token 格式：<类型码，表内序号>

extern vector<token> tokens;  // token 序列
extern vector<string> intConst;  // Interger 常量, 字符串表示, 防止整数过大
extern vector<char> charConst;  // Char 常量
extern vector<string> var;  // 标识符

const array<string, NUM_OF_REWORD> reWord  // 保留字数组
{"array", "begin", "char", "do", "end", "else", "endwh",
"fi", "if", "integer", "of", "program", "procedure", "read",
"record", "return", "then", "type", "var", "while", "write"
};

const array<string, NUM_OF_SPECCHAR> specChar  // 特殊符号数组
{"+", "-", "*", "/",
"(", ")", "[", "]",
";", "=", "<", " ",
":=", ".", ".."};

const string specChar_str = "+-*/()[];<:=. \t\n'{}";  // 特殊字符组成的字符串

const int transMatrix[STATE][KIND]  // 状态转移矩阵
{ST_ERROR, ST_NUM, ST_VAR, ST_TOKEN,
ST_ERROR, ST_NUM, ST_ERROR, ST_TOKEN,
ST_ERROR, ST_VAR, ST_VAR, ST_TOKEN};

bool wordAnalyse();  // 词法分析
bool grammerAnalyse();  // 语法分析

#endif // HEADER_H_INCLUDED
