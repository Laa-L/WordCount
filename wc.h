#pragma once
#ifndef _WC_H_
#define _WC_H_

#include<stdio.h>


void func_list();             // 输入形式

int IsLetter(char ch);        // 判断字符是否为字母

int char_count(FILE *fp);     // 统计字符数（包括缩进字符）

int word_count(FILE *fp);     // 统计单词数

int line_count(FILE *fp);     // 统计行数


#endif 