#include<stdio.h>      // 预处理
#include<string.h>
#include<stdlib.h>
#include <iostream>
#include "wc.h"

#define NULL 0

using namespace std;

int main() {
	char command[100];     // 输入的命令
	char *sub_com[2];      // 字符指针数组存放分割的得到的命令参数和文件路径
	char* next_token = NULL;
	FILE *fp = NULL;
	func_list();           // 调用函数显示基本功能列表
	printf("请按以上格式输入命令(输入“end”退出)...\n");
	cin.get(command, 100);     // 接收命令gets(command);//
	while (strcmp(command, "end") != 0) {
		sub_com[0] = strtok_s(command + 8, " ", &next_token);   // 以空格字符分割命令，第一次得到命令参数
		sub_com[1] = strtok_s(NULL, " ", &next_token);          // 再次分割得到文件路径

		// 打开文件
		errno_t err;
		if ((err = fopen_s(&fp, sub_com[1], "r")))
		{
			printf("文件打开错误\n");
			exit(0);
		}

		// 按匹配命令参数调用不同的函数
		switch (*sub_com[0]) {
		case 'c':
			char_count(fp); // 调用字符统计函数
			break;
		case 'w':
			word_count(fp); // 调用单词统计函数
			break;
		case 'l':
			line_count(fp); // 调用行统计函数
			break;
		default:
			printf("命令参数错误！\n");
			break;
		}
		printf("\n");
		// 关闭文件 
		if (fclose(fp) == EOF)
		{
			printf("文件关闭错误\n");
			exit(0);
		}
		next_token = NULL;
		printf("请按enter键继续...\n");
		getchar();
		getchar();
		printf("请按以上格式输入命令(输入“end”退出)...\n");
		cin.get(command, 100);    
	}
	getchar();
	printf("按Enter键退出程序！\n");
	getchar();
	return 0;
}