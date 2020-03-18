

#include"wc.h"

void func_list() {                               // ���������б�
	printf("  ============================================================\n");
	printf("||              ���������֧�����¼�������                  ||\n");
	printf("--------------------------------------------------------------\n");
	printf("||   wc.exe - c file.c    ||   �����ļ� file.c ���ַ���       ||\n");
	printf("||   wc.exe - w file.c    ||   �����ļ� file.c �Ĵʵ���       ||\n");
	printf("||   wc.exe - l file.c    ||   �����ļ� file.c ������         ||\n");
	printf("  ============================================================\n\n");
}

int IsLetter(char ch) {     // �ж��ַ��Ƿ�Ϊ��ĸ
	return(((ch < 91 && ch>64) || (ch < 123 && ch>96)) ? 1 : 0);
}

int char_count(FILE *fp)
{
	int count = 0;        // ��ʼ���ַ���Ϊ0
	while (!feof(fp))
	{
		if (fgetc(fp) == '\n')   // ���ƻ��з�
			continue;
		count++;           // �ۼ��ַ�
	}
	printf("�ַ�������%d\t", --count);
	return count;
}

int word_count(FILE *fp)
{

	int count;   // �ļ���������
	count = 0;
	char ch;
	char a_ch = '#';  // �ļ�ָ��ǰһ���ַ�
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (IsLetter(ch) && !IsLetter(a_ch) && a_ch != '.' && a_ch != '_')   // ǰһ���ַ�������ĸҲ����'.'�͡�_��
			count++;         // ���ַ�Ϊ�µ�Ԫ���ַ�  
		a_ch = ch;         // ���Ƽ��
	}
	printf("����������%d\t", count);
	return count;
}

int line_count(FILE *fp)
{
	int count = 0;  // ��ʼ������Ϊ0
	while (!feof(fp))
	{
		if (fgetc(fp) == '\n')  // �������з���Ϊһ�н���
			count++;
	}
	printf("��������%d\t", count);
	return count;
}