#include<stdio.h>      // Ԥ����
#include<string.h>
#include<stdlib.h>
#include <iostream>
#include "wc.h"

#define NULL 0

using namespace std;

int main() {
	char command[100];     // ���������
	char *sub_com[2];      // �ַ�ָ�������ŷָ�ĵõ�������������ļ�·��
	char* next_token = NULL;
	FILE *fp = NULL;
	func_list();           // ���ú�����ʾ���������б�
	printf("�밴���ϸ�ʽ��������(���롰end���˳�)...\n");
	cin.get(command, 100);     // ��������gets(command);//
	while (strcmp(command, "end") != 0) {
		sub_com[0] = strtok_s(command + 8, " ", &next_token);   // �Կո��ַ��ָ������һ�εõ��������
		sub_com[1] = strtok_s(NULL, " ", &next_token);          // �ٴηָ�õ��ļ�·��

		// ���ļ�
		errno_t err;
		if ((err = fopen_s(&fp, sub_com[1], "r")))
		{
			printf("�ļ��򿪴���\n");
			exit(0);
		}

		// ��ƥ������������ò�ͬ�ĺ���
		switch (*sub_com[0]) {
		case 'c':
			char_count(fp); // �����ַ�ͳ�ƺ���
			break;
		case 'w':
			word_count(fp); // ���õ���ͳ�ƺ���
			break;
		case 'l':
			line_count(fp); // ������ͳ�ƺ���
			break;
		default:
			printf("�����������\n");
			break;
		}
		printf("\n");
		// �ر��ļ� 
		if (fclose(fp) == EOF)
		{
			printf("�ļ��رմ���\n");
			exit(0);
		}
		next_token = NULL;
		printf("�밴enter������...\n");
		getchar();
		getchar();
		printf("�밴���ϸ�ʽ��������(���롰end���˳�)...\n");
		cin.get(command, 100);    
	}
	getchar();
	printf("��Enter���˳�����\n");
	getchar();
	return 0;
}