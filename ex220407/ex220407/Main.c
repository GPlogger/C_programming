 //���� �б� fscanf
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000	// ���
int main()
{
	// ���Ͽ� �����͸� ����, ���Ͽ� ����� �����͸� �ҷ�����

	// fgets, fgets�� ���ڿ��� �����ϰ� �� �� ���
	// fprintf, fscanf : ����ȭ�� ������ �ְ�, ���˿� ���� ������ �а� ��
	int num[6] = { 0, };	// �ζ� ��÷ ��ȣ
	int bonus = 0;

	char str1[MAX];
	char str2[MAX];

	FILE* file = fopen("C:\\Users\\kkjj4\\Desktop\\c_programming\\test2.txt", "rb");
	if (file == NULL)
	{
		printf("�ش� ������ �ҷ��� �� �����ϴ�.\n");
		return 0;
	}
	
	fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);
	fscanf(file, "%s %d", str2, &bonus);
	printf("%s %d", str2, bonus);

	fclose(file);
	return 0;
}

// ���� ���� fprintf
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MAX 10000	// ���
//int main()
//{
//	// ���Ͽ� �����͸� ����, ���Ͽ� ����� �����͸� �ҷ�����
//
//	// fgets, fgets�� ���ڿ��� �����ϰ� �� �� ���
//	// fprintf, fscanf : ����ȭ�� ������ �ְ�, ���˿� ���� ������ �а� ��
//	int num[6] = { 0, };	// �ζ� ��÷ ��ȣ
//	int bonus = 0;
//
//	char str1[MAX];
//	char str2[MAX];
//
//	FILE* file = fopen("C:\\Users\\kkjj4\\Desktop\\c_programming\\test2.txt", "wb");
//	if (file == NULL)
//	{
//		printf("�ش� ������ �ҷ��� �� �����ϴ�.\n");
//		return 0;
//	}
//	// �ζ� ��÷��ȣ ����
//	fprintf(file, "%s %d %d %d %d %d %d\n", "��÷��ȣ ", 1, 2, 3, 4, 5, 6);
//	fprintf(file, "%s %d \n", "���ʽ���ȣ ", 7);
//	
//	fclose(file);
//	return 0;
//}

// ���� �ҷ�����
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MAX 10000	// ���
//int main()
//{
//	// ���Ͽ� �����͸� ����, ���Ͽ� ����� �����͸� �ҷ�����
//
//	// fgets
//	char line[MAX];	//char line[10000]
//	FILE* file = fopen("C:\\Users\\kkjj4\\Desktop\\c_programming\\test1.txt", "rb");	// c:\\���� �������ø� �ΰ� ��� ����
//												// r : �б� |  w : ���� |  a : �̾�� | t : �ؽ�Ʈ | b : ���̳ʸ� ������
//	if (file == NULL)
//	{
//		printf("���� ���� ����\n");
//		return 0;
//	}
//
//	while (fgets(line, MAX, file) != NULL)		// fgets(���� ������ �ּ�, ũ��, ����������)
//	{
//		printf("%s", line);
//	}
//	fclose(file);	//������ ����
//	// fprintf, fscanf
//
//	return 0;
//}

// ���� ����(fputs)
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MAX 10000	// ���
//int main()
//{
//	// ���Ͽ� �����͸� ����, ���Ͽ� ����� �����͸� �ҷ�����
//
//	// fputs, fgets
//	char line[MAX];	//char line[10000]
//	FILE* file = fopen("C:\\Users\\kkjj4\\Desktop\\c_programming\\test1.txt", "wb");	// c:\\���� �������ø� �ΰ� ��� ����
//												// r : �б� |  w : ���� |  a : �̾�� | t : �ؽ�Ʈ | b : ���̳ʸ� ������
//	if (file == NULL)
//	{
//		printf("���� ���� ����\n");
//		return 0;
//	}
//
//	fputs("fputs�� �̿��� ���� �ۼ�\n", file);
//	fputs("�� �������� Ȯ�����ּ���.\n", file);
//
//	fclose(file);	//������ ����
//	// fprintf, fscanf
//
//
//	return 0;
//}