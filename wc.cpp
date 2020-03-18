

#include"wc.h"

void func_list() {                               // 基本功能列表
	printf("  ============================================================\n");
	printf("||              请输入命令，支持以下几种命令                  ||\n");
	printf("--------------------------------------------------------------\n");
	printf("||   wc.exe - c file.c    ||   返回文件 file.c 的字符数       ||\n");
	printf("||   wc.exe - w file.c    ||   返回文件 file.c 的词的数       ||\n");
	printf("||   wc.exe - l file.c    ||   返回文件 file.c 的行数         ||\n");
	printf("  ============================================================\n\n");
}

int IsLetter(char ch) {     // 判断字符是否为字母
	return(((ch < 91 && ch>64) || (ch < 123 && ch>96)) ? 1 : 0);
}

int char_count(FILE *fp)
{
	int count = 0;        // 初始化字符数为0
	while (!feof(fp))
	{
		if (fgetc(fp) == '\n')   // 不计换行符
			continue;
		count++;           // 累计字符
	}
	printf("字符总数：%d\t", --count);
	return count;
}

int word_count(FILE *fp)
{

	int count;   // 文件单词总数
	count = 0;
	char ch;
	char a_ch = '#';  // 文件指针前一个字符
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (IsLetter(ch) && !IsLetter(a_ch) && a_ch != '.' && a_ch != '_')   // 前一个字符不是字母也不是'.'和‘_’
			count++;         // 该字符为新单元首字符  
		a_ch = ch;         // 下移检查
	}
	printf("单词总数：%d\t", count);
	return count;
}

int line_count(FILE *fp)
{
	int count = 0;  // 初始化行数为0
	while (!feof(fp))
	{
		if (fgetc(fp) == '\n')  // 遇到换行符即为一行结束
			count++;
	}
	printf("行总数：%d\t", count);
	return count;
}