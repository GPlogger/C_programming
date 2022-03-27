// ī�� ������ ���� : 20���� ī��, �ֿܼ� 0~19���� ���ڸ� ���� ���� ������ ���� ��� ����, Ʋ�� Ƚ�� count, ���
#include <stdio.h>
#include <time.h>

// ��������
int arrayAnimal[4][5];	// ī�� ����
char* animalName[10];	// �����̸� 10��
int checkarray[4][5];	// ī�尡 ����������(�������� 1 �ƴϸ� 0)


// �Լ� ȣ�� //
void initData();
void SetAnimal();
void suffle();
int getEmpty();
int conv_x();
int conv_y();
void printQusetion();
void printAnswer();
int FoundAllAnimals();



// ���� �Լ� //
int main()
{
	srand(time(NULL));
	initData();		//ī�� ���� �ʱ�ȭ
	SetAnimal();	//���� �̸� ����
	suffle();		//������ ���� �̸� �ֱ�
	int failcount = 0;
	// ���� ����
	while (1)
	{
		// ���� ���(���߿�)
		printAnswer();

		// ���� ���
		printQusetion();

		// �Է� 2�� �ޱ�
		int select1, select2 = 0;
		printf("\nī�� �� ���� �Է��ϼ��� : ");
		scanf_s("%d %d", &select1, &select2);

		// �Է��� ���� �ߺ��� ���
		if (select1 == select2)
		{
			printf("\n�� ī�尡 �ߺ��˴ϴ�. �ٽ� �̾��ּ���.\n");
			continue;
		}

		// ��ǥ�� �ش��ϴ� �迭 ����
		int first_x = conv_x(select1);
		int first_y = conv_y(select1);

		int second_x = conv_x(select2);
		int second_y = conv_y(select2);



		// ī�尡 �������� �ʾҴ���, �� ������ ������ Ȯ��
		if (checkarray[first_x][first_y] == 0 && checkarray[second_x][second_y] == 0	// ù��°, �ι��� ī�尡 �������ְ�
			&&
			arrayAnimal[first_x][first_y] == arrayAnimal[second_x][second_y])			// �� �� ī�尡 ������
		{
			printf("\n �����Դϴ�. �ش� ī�带 �������ϴ�.\n");
			checkarray[first_x][first_y] = 1;
			checkarray[second_x][second_y] = 1;
		}
		// �ش����� �ʴ� ���, ������ ī���� ������ ���, ���� Ƚ�� +
		else
		{
			printf("\n�����Դϴ�.\n");
			printf("%d�� ī��� %s�Դϴ�.\n", select1, animalName[arrayAnimal[first_x][first_y]]);
			printf("%d�� ī��� %s�Դϴ�.\n", select2, animalName[arrayAnimal[second_x][second_y]]);

			failcount++;
		}

		// ������ �������� Ȯ��
		if (FoundAllAnimals() == 1)
		{
			printf("\n********************************************\n");
			printf("��� ������ ���߼̽��ϴ�. ���� Ƚ���� �� %d���Դϴ�.", failcount);
			break;
		}

	}

	return 0;
}

void initData()		//ī������ -1 �ʱ�ȭ
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
			checkarray[i][j] = 0;
		}
	}
}
void SetAnimal()	//���� �̸� ����
{
	animalName[0] = "������";
	animalName[1] = "�����";
	animalName[2] = "�ڳ���";
	animalName[3] = "��Ÿ";
	animalName[4] = "�ϸ�";
	animalName[5] = "�⸰";
	animalName[6] = "��踻";
	animalName[7] = "ȣ����";
	animalName[8] = "����";
	animalName[9] = "����";
}
void suffle()		//���� �̸� �ֱ�
{
	// �迭�� 10���� ���� �̸��� �ι� �ֱ�
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			// �� ī������ Ȯ��
			int position = getEmpty();
			int x = conv_x(position);
			int y = conv_y(position);

			arrayAnimal[x][y] = i;

		}
	}
}
int getEmpty()		// ī�������� �� ���� �������� 2�� �̱�
{
	while (1)
	{
		int randomnum = rand() % 20; //0~20 ���� ���� ��ȯ
		// ���� ���� ��ǥ ��ȯ �Լ�
		int x = conv_x(randomnum);
		int y = conv_y(randomnum);

		if (arrayAnimal[x][y] == -1)
		{
			return randomnum;
		}
	}
}
int conv_x(int x)
{
	// 14 ��ȯ �� 2
	return x / 5;
}
int conv_y(int y)
{
	return y % 5;
}

void printQusetion()	// ī���� ������� ��ȣ ���(������ ��� �ش� ���� �̸� ���)
{
	printf("\n\n");
	int seq = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// ī�带 ����� ������ ���߸� "���� �̸�"
			if (checkarray[i][j] != 0)
			{
				printf("%8s", animalName[arrayAnimal[i][j]]);
			}
			// ���� ������ ���߰ų� ������ �ƴϸ� �޸�(����)
			else
			{
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

void printAnswer()
{
	printf("\n =====================����=====================\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s  ", animalName[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n ==============================================\n\n");
}
int FoundAllAnimals()
{
	// ��ü �� ã����(ī�尡 �� ����������) 1�� ��ȯ
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkarray[i][j] == 0)
				return 0;
		}
	}
	return 1;
}
//	 ����������	 // 0  1  2  3  4		// 0 0 0 0 0
//	 ����������	 // 5  6  7  8  9		// 1 1 1 1 1
//	 ����������	 // 10 11 12 13 14		// 2 2 2 2 2
//	 ����������	 // 15 16 17 18 19		// 3 3 3 3 3


// ī������� ������Ʈ
// ����ڷκ��� 2���� �Է°�(��ǥ) > ���� ���� ã���� ī�� ������
// ��� ���� ���� ã���� ���� ����
// �� ���� Ƚ�� �˷��ֱ�
//#include <stdio.h>
//#include <time.h>
//int arrayAnimal[4][5];	// ī�� ���� 20��
//int checkAnimal[4][5];  // ���������� ���� Ȯ��
//char * strAnimal[10];	// ���� �̸� 10��
//void initAnimalArray()	// ī�� ���� �ʱ�ȭ
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 5; j++)
//			arrayAnimal[i][j] = -1;
//	}
//}
//void initAnimalName()
//{
//	strAnimal[0] = "������";
//	strAnimal[1] = "�ϸ�";
//	strAnimal[2] = "������";
//	strAnimal[3] = "�����";
//	strAnimal[4] = "����";
//	strAnimal[5] = "�ڳ���";
//	strAnimal[6] = "�⸰";
//	strAnimal[7] = "��Ÿ";
//	strAnimal[8] = "Ÿ��";
//	strAnimal[9] = "ȣ����";
//}
//void shuffleAnimal()	//������ ���� 2������ ��ġ
//{
//	// ����������	������� ã�� �� �ش� �ڸ��� ��ġ
//	// ����������
//	// ����������
//	// ����������
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			int pos = getEmptyPosition();
//			int x = conv_pos_x(pos);
//			int y = conv_pos_y(pos);
//
//			arrayAnimal[x][y] = i;
//		}
//	}
//}
//int getEmptyPosition()	// ��ǥ���� �� ���� ã��
//{
//	while (1)
//	{
//		int randPos = rand() % 20; // 0 ~ 19 ���� ���� ��ȯ
//		// 19 > (3,4)
//		int x = conv_pos_x(randPos);
//		int y = conv_pos_y(randPos);
//
//		if (arrayAnimal[x][y] == -1)
//		{
//			return randPos;
//		}
//	}
//}
//
//int conv_pos_x(int x)
//{
//	return x / 5;	// 19 > 3,4
//}
//int conv_pos_y(int y)
//{
//	return y % 5;
//}
//
//void printAnimals()		// ���� ��ġ ���
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%8s", strAnimal[arrayAnimal[i][j]]);
//		}
//		printf("\n");
//	}
//	printf("=====================================\n\n");
//}
//void printQusetion()	
//{
//	printf("\n\n <����> \n");
//	int seq = 0;
//
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			// ī�� ����� ������ ���߸� '���� �̸�'
//			if (checkAnimal[i][j] != 0)				//checkAnimal�� �̹� ã�� ī��
//			{
//				printf("%8s", strAnimal[arrayAnimal[i][j]]);
//			}
//			// ���� ������ ��������(����x) �޸�(��ġ�� ��Ÿ���� ����)
//			else
//			{
//				printf("%8d", seq);
//			}
//			seq++;
//		}
//		printf("\n");
//	}
//}
//int foundAllAnimals()
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			if (checkAnimal[i][j] == 0) { return 0; }
//
//		}
//	}
//	return 1;	// ��� �� ã��
//}
//int main()
//{
//	srand(time(NULL));
//	initAnimalArray();
//	initAnimalName();
//	shuffleAnimal();
//
//	int failCount = 0;	//���� Ƚ��
//
//	while (1)
//	{
//		int select1 = 0;		// ����� ���� 1
//		int select2 = 0;		// ����� ���� 2
//
//		printAnimals();
//		printQusetion();
//
//		printf("������ ī�带 2�� ������ : ");
//		scanf_s("%d %d", &select1, &select2);
//
//		if (select1 == select2)	// ���� ī�� �ΰ� �� �� ��ȿ
//			continue;
//
//		// ��ǥ�� �ش��ϴ� ī�带 ������ ���� ������ Ȯ��
//		// x, y��ǥ�� ��ȯ �ʿ�
//		int firstSelect_x = conv_pos_x(select1);
//		int firstSelect_y = conv_pos_y(select1);
//
//		int secondSelect_x = conv_pos_x(select2);
//		int secondSelect_y = conv_pos_y(select2);
//
//		// ī�尡 �̹� ����������, �� ������ ������ Ȯ��
//		if (checkAnimal[firstSelect_x][firstSelect_y] == 0
//			&& checkAnimal[secondSelect_x][secondSelect_y] == 0		//ī�尡 �������� �ʾҴ���
//			&&
//			arrayAnimal[firstSelect_x][firstSelect_y]
//			== arrayAnimal[secondSelect_x][secondSelect_y])			//������ ī�� �� ������ ������
//		{
//			printf("\n\n ����! :%s �߰�\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
//			checkAnimal[firstSelect_x][firstSelect_y] = 1;
//			checkAnimal[secondSelect_x][secondSelect_y] = 1;
//		}
//
//
//		// �ٸ� ������ ���
//		else
//		{
//			printf("\n\n ��! (Ʋ�Ȱų� �̹� ������ ī���Դϴ�)\n");
//			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
//			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
//			printf("\n\n");
//
//			failCount++;
//		}
//
//		// ��� ������ ã�Ҵ��� ���� Ȯ�� 
//		if (foundAllAnimals() == 1)
//		{
//			printf("\n\n �����մϴ�! ��� ������ �� ã�ҽ��ϴ�. \n");
//			printf("���ݱ��� �� %d�� �Ǽ��ϼ̽��ϴ�.\n", failCount);
//		}
//	}
//
//	return 0;
//}

//// �������迭 ����2
//#include <stdio.h>
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int arr2[2][5] = {
//		{1,2,3,4,5},
//		{1,2,3,4,5}
//	};
//	int arr3[4][2] = {
//		{1,2},
//		{1,2},
//		{1,2},
//		{1,2}
//	};
//	int arr4[3][3][3] = {
//		{
//			{1,2,3},
//			{1,2,3},
//			{1,2,3}
//		},
//		{
//			{1,2,3},
//			{1,2,3},
//			{1,2,3}
//		},
//		{
//			{1,2,3},
//			{1,2,3},
//			{1,2,3}
//		}
//	};
//	//1�����迭
//	printf("1���� �迭\n");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n\n");
//
//	//2�����迭
//	printf("\n2���� �迭1\n");
//
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", arr2[i][j]);
//		}
//		printf("\n");
//	}
//
//	//2�����迭 2
//	printf("\n2���� �迭2\n");
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			printf("%d ", arr3[i][j]);
//		}
//		printf("\n");
//	}
//
//	//3���� �迭
//	printf("\n3���� �迭\n");
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			for (int k = 0; k < 3; k++)
//			{
//				printf("%d ", arr4[i][j][k]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//	}
//}

// �������迭 ����
//#include <stdio.h>
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int arr2[2][5] = { 
//		{1,2,3,4,5},
//		{1,2,3,4,5} 
//	};
//	int arr3[4][2] = { 
//		{1,2},
//		{1,2},
//		{1,2},
//		{1,2} 
//	};
//	int arr4[3][3][3] = {
//		{
//			{1,2,3},
//			{1,2,3},
//			{1,2,3}
//		},
//		{
//			{1,2,3},
//			{1,2,3},
//			{1,2,3}
//		},
//		{
//			{1,2,3},
//			{1,2,3},
//			{1,2,3}
//		}
//	};
//}

//// �������迭 ����
//#include <stdio.h>
//int main()
//{
//	int i; //��
//	int arr[5];
//	//����������
//	//[0][1][2][3][4]
//
//	int arr2[2][5];
//	//����������
//	//����������
//	//[0,0][0,1][0,2][0,3][0,4]  ������ �� �� arr2[0][0]
//	//[1,0][1,1][1,2][1,3][1,4]  >> arr2[1][4]
//
//
//	int arr3[4][2];
//	//����	[0,0][0,1]
//	//����	[1,0][1,1]
//	//����	[2,0][2,1]
//	//����	[3,0][3,1]
//
//	int arr4[3][3][3];
//	//������
//	//������
//	//������
//
//	//������
//	//������
//	//������
//
//	//������
//	//������
//	//������
//
//	return 0;
//}

//������ ���
//#include <stdio.h>
//
//int main()
//{
//	int i; //��
//	int arr[5]; 
//	//����������
//
//	int arr2[2][5];
//	//����������
//	//����������
//
//	int arr3[4][2];
//	//����
//	//����
//	//����
//	//����
//
//	int arr4[3][3][3];
//	//������
//	//������
//	//������
//	 
//	//������
//	//������
//	//������
//	
//	//������
//	//������
//	//������
//
//	return 0;
//}