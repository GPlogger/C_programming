// Up & Down ���Ӹ����
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand(time(NULL));
	int random = rand() % 100 + 1; //1~100 ���� ����
	printf("����� �ϴ� ���ڴ� %d �Դϴ�.\n", random);

	int answer = 0; //�Է��� ��
	int chance = 5;	//���� ��ȸ
	while (chance > 0)
	{
		printf("���� ��ȸ�� %d���Դϴ�.\n", chance--);
		printf("���ڸ� �Է��ϼ��� : ");
		scanf_s("%d", &answer);

		if (answer == random)
		{
			printf("�����Դϴ�!\n");
			break;
		}
		else if (answer > random)
			printf("Down\n");
		else
			printf("UP\n");

		printf("\n");
		if (chance == 0)
			printf("���� ��ȸ�� �����ϴ�!");
	}
}

// ����ī�� switch �������� �����
//#include <stdio.h>
//int main()
//{
//	int age = 0;
//	printf("���̸� �Է��ϼ��� : ");
//	scanf_s("%d", &age);
//
//	switch (age)
//	{
//	case 8:
//	case 9:
//	case 10:
//	case 11:
//	case 12:
//	case 13: printf("�ʵ��л��Դϴ�."); break;	// break�� ������� ���� �� �Ʒ��� ��� ������ ����ϴ� ���� �̿��� ��ó�� ��� ����
//	case 14:
//	case 15:
//	case 16: printf("���л��Դϴ�."); break;
//	case 17:
//	case 18:
//	case 19: printf("����л��Դϴ�."); break;
//	default: printf("�л��� �ƴմϴ�."); break;
//
//	}
//	return 0;
//}

// switch ����������
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//int main()
//{
//	srand(time(NULL));
//	int i = rand() % 3;	//0~2 ��ȯ
//	// ����0 ����1 ��2
//	switch (i)
//	{
//	case 0:
//		printf("����"); break;
//	case 1:
//		printf("����"); break;
//	case 2:
//		printf("��"); break;
//	default:
//		printf("Error"); break;
//	}					// switch���� ���� ����� break�� ������ �Ʒ� ��� ������ ���
//						// ���� switch ���̽� �ڿ��� �׻� berak�� ���� ��
//	return 0;
//}

// if ����������
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//int main()
//{
//	srand(time(NULL));
//	int i = rand() % 3;	//0~2 ��ȯ
//	// ����0 ����1 ��2
//	if (i == 0)
//		printf("����");
//	else if (i == 1)
//		printf("����");
//	else if (i == 2)
//		printf("��");
//	else
//		printf("Error");
//
//	return 0;
//}

// ���� time.h, stdlib.h ���̺귯���� �ʿ���
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//int main()
//{
//	// rand() % ����(0 ~ ����)
//	/*
//	srand(time(NULL));			//���� �ʱ�ȭ (���ϸ� ���� ������ ����)
//	int num = rand() % 3 + 1;	//1�� ���ϸ� 1���� 3�� ���ڸ�, ������ ������ 0~2 ����
//	printf("%d\n", num);
//	*/
//	printf("���� �ʱ�� ����\n");		// ������ ���� ������ ������ ����
//	for (int i = 0; i < 10; i++)
//		printf("%d ", rand() % 10);
//	
//	printf("\n���� �ʱ�ȭ ����\n");
//	srand(time(NULL));
//	for (int i = 0; i < 10; i++)
//		printf("%d ", rand() % 10);
//
//	return 0;
//}

//// 7���� ������ 6������ 10������ ���� ��ǥ
//#include <stdio.h>
//int main()
//{
//	for (int i = 1; i <= 30; i++)
//	{
//		if (6 <= i && i <= 10)
//		{
//			if (i == 7)
//			{
//				printf("%d�� �л��� �Ἦ�Դϴ�.\n", i);
//				continue;		//continue�� �ݺ��� �ǳʶٱ�
//			}
//			printf("%d�� �л��� ��ǥ�� �ϼ���.\n", i);
//		}
//	}
//}

// break, continue
// 1������ 30������ �ִ� �ݿ��� 1������ 5������ ���� ��ǥ
//#include <stdio.h>
//int main()
//{
//	for (int i = 1; i <= 30; i++)
//	{
//		if (i >= 6)
//		{
//			printf("������ �л��� ���� ������.");
//			break;		// �ݺ����� Ż��
//		}
//		printf("%d�� �л��� ���� ��ǥ �غ� �ϼ���.\n", i);
//	}
//	return 0;
//}

//// �ʵ��л�(8~13) ���л�(14~16) ����л�(17~19) ����(20~)  ���̱���
//#include <stdio.h>
//int main()
//{
//	int age = 0;
//	printf("���̸� �Է��ϼ��� : ");
//	scanf_s("%d", &age);
//
//	if (age < 8)
//		printf("Error");
//	else if (8 <= age && age <= 13)
//		printf("�ʵ��л��Դϴ�.");
//	else if (14 <= age && age <= 16)
//		printf("���л��Դϴ�.");
//	else if (17 <= age && age <= 19)
//		printf("����л��Դϴ�.");
//	else
//		printf("�����Դϴ�.");
//	return 0;
//}

////���ǹ� if else
//#include <stdio.h>
//int main()
//{
//	int age = 0;
//	printf("���̸� �Է��Ͻÿ� : ");
//	scanf_s("%d", &age);
//
//	if (age < 20)
//		printf("�л��Դϴ�.");
//	else
//		printf("�����Դϴ�.");
//
//	return 0;
//}

//// �Ƕ�̵� �ױ� ( ���� �Է� �޾Ƽ� �� ����ŭ �ױ�)
//#include <stdio.h>
//int main()
//{
//	int count = 0;
//	printf("���� : ");
//	scanf_s("%d", &count);
//	printf("%d�� ������ �Ƕ�̵带 �׽��ϴ�.\n", count);
//
//	// 4�� ����
//	for (int i = 0; i < count; i++)				//���� 0 1 2 3
//	{
//		for (int j = i; j < count - 1; j++)		//���� 3 2 1 0
//			printf(" ");
//		for (int k = 0; k < (1 + i * 2); k++)	//* 1 3 5 7 (1 + 1*2)
//			printf("*");
//		printf("\n");
//	}
//}

// �� ���
/*
        *
	   **
	  ***
	 ****
	*****
*/
//#include <stdio.h>
//int main()
//{
//	for (int i = 0; i < 5; i++)			//0 1 2 3 4
//	{
//		for (int j = i; j < 4; j++)		//4 3 2 1 0
//			printf(" ");
//		for (int k = 0; k <= i; k++)	//1 2 3 4 5
//			printf("*");
//		printf("\n");
//	}
//}

//// �� ��� 5��, 1 2 3 4 5
//#include <stdio.h>
//int main()
//{
//	for (int i = 1; i <= 5; i++)		//����
//	{
//		for (int j = 1; j <= i; j++)	//����
//			printf("*");
//		printf("\n");
//	}
//}

//// ������
//#include <stdio.h>
//int main()
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		for (int j = 1; j <= 9; j++)
//			printf("%d x %d = %d\n", i, j, i*j);
//		printf("======================\n");
//	}
//}

//// ���� �ݺ���
//#include <stdio.h>
//int main()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		printf("ù ��° �ݺ��� : %d\n", i);
//
//		for (int j = 0; j < 5; j++)
//			printf("  �� ��° �ݺ��� : %d\n", j);
//	}
//}

//// �ݺ��� ����3
//#include <stdio.h>
//int main()
//{
//	// do {} while (����);
//	int i = 0;
//	do { printf("i : %d\n", i++); } while (i <= 10);
//	return 0;
//}

//// �ݺ��� ����2
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	while (i <= 10)
//	{
//		printf("i : %d\n", i++);
//	}
//	return 0;
//}

//// �ݺ��� ����1
//#include <stdio.h>
//int main()
//{
//	for (int i = 0; i <= 10; ++i)
//	{
//		printf("i : %d\n", i);
//	}
//	return 0;
//}

//// i++�� ++i
//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	printf("%d\n", num);
//	printf("%d\n", num++);	// ������ ��� �� �� num�� +1
//	printf("%d\n", ++num);	// ������ ����ϱ� �� num�� +1
//	printf("%d\n", num);
//
//	return 0;
//}


// �Է°� ��� ����
//#include <stdio.h>
//int main()
//{
//	char name[256] = { 0 };
//	int age = 0;
//	float weight = 0;
//	double height = 0;
//	char what[256] = { 0 };
//
//	printf("�̸��� �����Դϱ�?");
//	scanf_s("%s", name, sizeof(name));
//
//	printf("���̰� ����Դϱ�?");
//	scanf_s("%d", &age);			// �迭�� �ƴ� ������ &�� �ʿ���
//
//	printf("�����Դ� ��kg �Դϱ�?");
//	scanf_s("%f", &weight);			// float �ڷ����� %f
//
//	printf("Ű�� ��cm �Դϱ�?");
//	scanf_s("%lf", &height);		// double �ڷ����� %lf
//
//	printf("�ϰ���� ������ �����ּ���.");
//	scanf_s("%s", what, sizeof(what));
//
//	printf("�̸��� %s, ���̴� %d��, �����Դ� %.1f�Դϴ�.\n", name, age, weight);
//	printf("%s ��� �����̽��ϴ�.", what);
//	getchar();
//
//	return 0;
//}