#include <stdio.h>
#include <time.h>

int level = 1;
int arrayFish[6];
int* cursor;

void initData()		//�ʱ� ������ �ʱ�ȭ
{
	level = 1;
	for (int i = 0; i < 6; i++)
		arrayFish[i] = 100;
}
void printFish()	//���� ���� ���
{
	printf("1��\t2��\t3��\t4��\t5��\t6��\t\n");
	for (int i = 0; i < sizeof(arrayFish) / sizeof(int); i++)
	{
		printf("%d\t", arrayFish[i]);
	}
	printf("\n");
}
void decreaseWater(long prev)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= level * 2 * (int)prev;		// ���׿� ����*2 *���� �ð�
		if (arrayFish[i] < 0)
			arrayFish[i] = 0;
	}
}
int checkFish()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
			return 1;
	}
	return 0;
}
int main()
{
	initData();

	long startTime = 0;
	long totalTime = 0;
	long prevTime = 0;

	int num = 0; // ��� ���׿� ���� �ٰ���
	cursor = arrayFish;

	startTime = clock();		//���� �ð��� �и������� ������ ����

	while (1)
	{
		printFish();
		printf("�� ��° ���׿� ���� �ֽðڽ��ϱ�? : ");
		scanf_s("%d", &num);

		if (num < 1 || num > 6)
		{
			printf("\n******��ȿ. �߸��� ���� �Է��߽��ϴ�.******\n");
			continue;
		}

		// �� ��� �ð�
		totalTime = (clock() - startTime) / CLOCKS_PER_SEC;	// ����ð� - ���۽ð��� �ʷ� ���� ���� �ʸ� ���
		printf("�� ��� �ð� : %ld\n", totalTime);

		// ������ ���� �� �ð� ���� �帥 �ð�
		prevTime = totalTime - prevTime;		// �� �� �ð� = �� ����ð� - �� �� �ؽð�
		printf("���� �� �� %ld�ʰ� �������ϴ�.\n", prevTime);

		// ������ �� ����
		decreaseWater(prevTime);

		// ����ڰ� ���� �ָ� 2++
		// 1. ���� ���� 0�̸� ���� 0
		if (cursor[num - 1] <= 0)
		{
			printf("\n !!! %d��° ������ ������ �̹� �׾����ϴ�.\n", num);
		}

		else if (cursor[num - 1] + 1 <= 100)
		{
			printf("%d��° ���׿� ���� �ݴϴ�.\n\n", num);
			cursor[num - 1] += 1;
		}

		// ������ �κ�(20�ʸ��� ������)
		if (totalTime / 20 > level - 1)
		{
			level++;
			printf("===== Level Up! ���� ������ %d�Դϴ�. =====\n", level);
			//���� 5 ���� ����
			if (level == 5)
			{
				printf("===== �����մϴ�. ������ Ŭ�����ϼ̽��ϴ�. =====");
				exit(0);
			}

		}

		// ��� ����Ⱑ �׾��� ��
		if (checkFish() == 0)
		{
			printf("===== Game Over. =====\n");
			exit(0);
		}


		prevTime = totalTime;					// �Ŀ� �� ����ð����� �ٲ�� ��� �ֽ�ȭ ����

	}
	return 0;
}

// //������Ʈ
// //����� 6����, ���׿� ��� ����
// //�縷�� �ʹ� ������ ���� ������ ����. ���� �����ϱ� ���� �������� ���׿� ���� ��� ��
// //�ð��� �������� ���� Ŀ�� ���߿��� ����
//#include <stdio.h>
//#include <time.h>
//int level;
//int arrayFish[6];
//int * cursor;
//
//void initData()
//{
//	level = 1;	// ������ 1~5;
//	for (int i = 0; i < 6; i++)
//	{
//		arrayFish[i] = 100;
//	}
//}
//void printFishes()
//{
//	printf("%3d��  %3d��  %3d��  %3d��  %3d��  %3d��\n", 1, 2, 3, 4, 5, 6);
//	for (int i = 0; i < 6; i++)
//	{
//		printf("  %3d  ", arrayFish[i]);
//	}
//	printf("\n\n");
//}
//void decreaseWater(long elapsedTime)
//{
//	for (int i = 0; i < 6; i++)
//	{
//		arrayFish[i] -= (level) * 2 * (int)elapsedTime;
//		if (arrayFish[i] < 0)
//		{
//			arrayFish[i] = 0;
//		}
//	}
//}
//int checkFishAlive()
//{
//	for (int i = 0; i < 6; i++)
//	{
//		if (arrayFish[i] > 0)
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	long startTime = 0;
//	long totalElapsedTime = 0;
//	long prevElapseddTime = 0;
//
//	int num;		//�� �� ���׿� ���� �ٰ���
//	initData();
//
//	cursor = arrayFish;
//
//	startTime = clock();	//������ �ð��� �и������� ���� ��ȯ
//
//	while (1)
//	{
//		printFishes();
//		printf("�� �� ���׿� ���� �ֽðھ��?");
//		scanf_s("%d", &num);
//
//		if (num < 1 || num > 6)
//		{
//			printf("�Է°��� �߸��Ǿ����ϴ�.\n");
//			continue;
//		}
//
//		// �� ��� �ð�
//		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
//		printf("�� ��� �ð� : %ld ��\n", totalElapsedTime);
//
//		// ���� �� �� �ð�(���������� �� �� �ð�) ���ķ� �帥 �ð�
//		prevElapseddTime = totalElapsedTime - prevElapseddTime;
//		printf("�ֱ� ��� �ð� : %ld �� \n", prevElapseddTime);
//
//		// ������ �� ����
//		decreaseWater(prevElapseddTime);
//
//		//����ڰ� �Է��� ���׿� ���� ��
//		//1. ������ ���� 0�̸� �� �ֱ� x
//		if (cursor[num - 1] <= 0)
//		{
//			printf("%d�� ������ �̹� �׾����ϴ�.\n", num);
//		}
//		//2. ������ ���� 0�� �ƴ� ��� ���� ��, 100�� ���� �ʴ��� üũ
//		else if (cursor[num - 1] + 1 <= 100)
//		{
//			printf("%d�� ���׿� ���� �ݴϴ�\n\n", num);
//			cursor[num - 1] += 1;
//		}
//
//		//������ �� ���� Ȯ��(�������� 20�ʸ��� �ѹ��� ����
//		if (totalElapsedTime / 20 > level - 1)
//		{
//			level++;
//			printf("===level up! ���� %d �������� %d ������ ���׷��̵�===\n", level - 1, level);
//
//			// �������� 5 ��������
//			if (level == 5)
//			{
//				printf("===�����մϴ�. �ְ����� �޼��߽��ϴ�. ������ �����մϴ�.\n");
//				exit(0);
//			}
//		}
//
//		// ��� ����Ⱑ �׾����� ���� ����
//		if (checkFishAlive() == 0)
//		{
//			printf("Game Over. ��� ����Ⱑ �׾����ϴ�.\n");
//			exit(0);
//			// ����� ��� ����
//		}
//		else
//		{
//			printf("����Ⱑ ���� ����ֽ��ϴ�.\n");
//		}
//		prevElapseddTime = totalElapsedTime; // 
//	}
//	return 0;
//}
//

//// ������Ʈ
//// ����� 6����, ���׿� ��� ����
//// �縷�� �ʹ� ������ ���� ������ ����. ���� �����ϱ� ���� �������� ���׿� ���� ��� ��
//// �ð��� �������� ���� Ŀ�� ���߿��� ����
//#include <stdio.h>
//#include <time.h>
//int level;
//int arrayFish[6];
//int * cursor;
//
//void initData()
//{
//	level = 1;	// ������ 1~5;
//	for (int i = 0; i < 6; i++)
//	{
//		arrayFish[i] = 100;
//	}
//}
//void printFishes()
//{
//	printf("%3d��  %3d��  %3d��  %3d��  %3d��  %3d��\n", 1, 2, 3, 4, 5, 6);
//	for (int i = 0; i < 6; i++)
//	{
//		printf("  %3d  ", arrayFish[i]);
//	}
//	printf("\n\n");
//}
//void decreaseWater(long elapsedTime)
//{
//	for (int i = 0; i < 6; i++)
//	{
//		arrayFish[i] -= (level) * 2 * (int)elapsedTime;
//		if (arrayFish[i] < 0)
//		{
//			arrayFish[i] = 0;
//		}
//	}
//}
//int checkFishAlive()
//{
//	for (int i = 0; i < 6; i++)
//	{
//		if (arrayFish[i] > 0)
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	long startTime = 0;
//	long totalElapsedTime = 0;
//	long prevElapseddTime = 0;
//
//	int num;		//�� �� ���׿� ���� �ٰ���
//	initData();
//
//	cursor = arrayFish;
//
//	startTime = clock();	//������ �ð��� �и������� ���� ��ȯ
//
//	while (1)
//	{
//		printFishes();
//		printf("�� �� ���׿� ���� �ֽðھ��?");
//		scanf_s("%d", &num);
//
//		if (num < 1 || num > 6)
//		{
//			printf("�Է°��� �߸��Ǿ����ϴ�.\n");
//			continue;
//		}
//
//		// �� ��� �ð�
//		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
//		printf("�� ��� �ð� : %ld ��\n", totalElapsedTime);
//
//		// ���� �� �� �ð�(���������� �� �� �ð�) ���ķ� �帥 �ð�
//		prevElapseddTime = totalElapsedTime - prevElapseddTime;
//		printf("�ֱ� ��� �ð� : %ld �� \n", prevElapseddTime);
//
//		// ������ �� ����
//		decreaseWater(prevElapseddTime);
//
//		//����ڰ� �Է��� ���׿� ���� ��
//		//1. ������ ���� 0�̸� �� �ֱ� x
//		if (cursor[num - 1] <= 0)
//		{
//			printf("%d�� ������ �̹� �׾����ϴ�.\n", num);
//		}
//		//2. ������ ���� 0�� �ƴ� ��� ���� ��, 100�� ���� �ʴ��� üũ
//		else if (cursor[num - 1] + 1 <= 100)
//		{
//			printf("%d�� ���׿� ���� �ݴϴ�\n\n", num);
//			cursor[num - 1] += 1;
//		}
//
//		//������ �� ���� Ȯ��(�������� 20�ʸ��� �ѹ��� ����
//		if (totalElapsedTime / 20 > level - 1)
//		{
//			level++;
//			printf("===level up! ���� %d �������� %d ������ ���׷��̵�===\n", level - 1, level);
//			
//			// �������� 5 ��������
//			if (level == 5)
//			{
//				printf("===�����մϴ�. �ְ����� �޼��߽��ϴ�. ������ �����մϴ�.\n");
//				exit(0);
//			}
//		}
//
//		// ��� ����Ⱑ �׾����� ���� ����
//		if (checkFishAlive() == 0)
//		{
//			printf("Game Over. ��� ����Ⱑ �׾����ϴ�.\n");
//			exit(0);
//			// ����� ��� ����
//		}
//		else
//		{
//			printf("����Ⱑ ���� ����ֽ��ϴ�.\n");
//		}
//		prevElapseddTime = totalElapsedTime; // 
//	}
//	return 0;
//}

//change array
//#include <stdio.h>
//void changeArray(int * ptr)
//{
//	ptr[2] = 50;
//}
//int main()
//{
//	int arr2[3] = { 10, 20, 30 };
//	changeArray(arr2);			// �迭�� �ּҸ� ����Ű�Ƿ� &�� ������ ����
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d\n", arr2[i]);
//	}
//}

////Swap
//#include <stdio.h>
//void Swap(int a, int b)	//�Լ� ���ο��� �ܺ� ���� ���� �����
//{
//	int tmp = a;
//	a = b;
//	b = a;
//	printf("Swap �Լ� ���� a : %d\tb = %d\n", a, b);
//
//}
//void Swap_addr(int *a, int *b)	// �����͸� ����� ����
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	printf("a : %d\tb = %d\n", a, b);
//	Swap(a, b);
//	printf("Swap �Լ� �� a : %d\tb = %d\n", a, b);
//
//	Swap_addr(&a, &b);
//	printf("�ּ� ���� �� a : %d\tb = %d\n", a, b);
//
//}

// �迭�� ������
//#include <stdio.h>
//int main()
//{
//	int arr[3] = { 5, 10, 15 };
//	int* ptr = arr;
//
//	for (int i = 0; i < 3; i++)
//	{
//		printf("arr[%d] : %d\n", i, arr[i]);
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		printf("ptr[%d] : %d\n", i, ptr[i]);
//	}
//	// arr, ptr�� �� �� �ּҸ� ����Ŵ, ���� �Ȱ��� ǥ��
//	printf("%d\n", *(arr + 1));
//	printf("%d\n", *(ptr + 1));
//}

// ������
//#include <stdio.h>
//int main()
//{
//	int num = 1;
//
//	printf("num�� �޸� �ּҴ� %d, ���� %d �Դϴ�.\n", &num, num);
//	int * ptr = &num;
//
//	printf("�������� �޸� �ּҴ� %d, ���� %d �Դϴ�.\n", &ptr, ptr);
//	printf("�����Ͱ� ����Ű�� �޸� �ּҴ� %d, ���� %d �Դϴ�.\n", ptr, *ptr);
//
//	*ptr = 20;	// �� ���� ����
//	printf("num�� ���� %d �Դϴ�.", num);
//
//	return 0;
//}

// �ƽ�Ű�ڵ�
//#include <stdio.h>
//int main()
//{
//	for (int i = 0; i < 128; i++)
//		printf("%d : %c\n", i, i);
//}

// ���ڿ� 5
//#include <stdio.h>
//int main()
//{
//	char name[256];
//	printf("�̸��� �Է��ϼ��� : ");
//	scanf_s("%s", name, sizeof(name));		//scanf_s�� ����� ���� ���� ��, �迭�� ũ�⵵ �Ķ���ͷ� ��
//	printf("%s", name);
//}

// ���ڿ� 4
//#include <stdio.h>
//int main()
//{
//	char arr[10] = { 'c', 'o', 'd' ,'e'};
//	printf("%s\n", arr);
//
//	for (int i = 0; i < sizeof(arr); i++)	//code �� ���� �ڸ��� �� ĭ���� ��(NULL)
//		printf("%c\n", arr[i]);
//}

//���ڿ� 3
//#include <stdio.h>
//int main()
//{
//	char kor[] = "�ѱ���";		// ����� �� ���ڴ� 1byte, �ѱ��� 2byte
//	printf("%s\n", kor);
//	printf("%d\n", sizeof(kor));
//	return 0;
//}

//���ڿ� 2
//#include <stdio.h>
//int main()
//{
//	char str[] = "coding";		//�迭�� [] ����� ������ �ڵ����� ũ�⸸ŭ �Էµ�
//	printf("%s\n", str);
//	printf("%d\n", sizeof(str));
//
//	for (int i = 0; i < sizeof(str); ++i)		//sizeof �Լ��� �̿��� ���ڿ� ��� ����
//	{
//		printf("%c", str[i]);
//	}
//	return 0;
//}


// ���ڿ� ���ڿ�
//#include <stdio.h>
//int main()
//{
//	char c = 'A';
//	printf("%c\n", c);
//
//	char str[7] = "coding";  //���ڿ� ������ ���� �ǹ��ϴ� NULL���ڰ� �׻� ���ԵǾ�� �Ѵ�.
//	printf("%s", str);		// [c], [o], [d], [i], [n], [g], [\0]
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr[3];		//�迭 ����
//	arr[0] = 30;
//	arr[1] = 40;
//	arr[2] = 50;
//
//	for (int i = 0; i < 3; i++)
//	{
//		printf("[%d] = %d\n", i, arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//int getRandomNum(int i)
//{
//	int num = rand() % (i*7)+ 1;
//	return num;
//}
//void ShowQuestion(int i, int x, int y)
//{
//	printf("[%d] %d x %d = ?\n", i, x, y);
//	printf("������ �Է��ϼ��� : ");
//}
//int main()
//{
//	srand(time(NULL));
//	int answer = 0;
//	for (int i = 1; i <= 5; i++)
//	{
//		int num1 = getRandomNum(i);
//		int num2 = getRandomNum(i);
//		ShowQuestion(i, num1, num2);
//		scanf_s("%d", &answer);
//		if (answer == -1)
//		{
//			printf("���α׷��� �����մϴ�.\n");
//			break;
//		}
//		else if (answer == num1 * num2)
//		{
//			printf("�����Դϴ�.\n");
//			if (i == 5)
//				printf("�����մϴ�. ��� ���� ���߼̽��ϴ�.");
//		}
//		else
//		{
//			printf("�����Դϴ�.\n");
//			break;
//		}
//	}
//
//
//
//	return 0;
//}