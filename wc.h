#pragma once
#ifndef _WC_H_
#define _WC_H_

#include<stdio.h>


void func_list();             // ������ʽ

int IsLetter(char ch);        // �ж��ַ��Ƿ�Ϊ��ĸ

int char_count(FILE *fp);     // ͳ���ַ��������������ַ���

int word_count(FILE *fp);     // ͳ�Ƶ�����

int line_count(FILE *fp);     // ͳ������


#endif 