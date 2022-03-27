// 카드 뒤집기 게임 : 20장의 카드, 콘솔에 0~19까지 숫자를 띄우고 같은 동물을 맞출 경우 정답, 틀린 횟수 count, 출력
#include <stdio.h>
#include <time.h>

// 전역변수
int arrayAnimal[4][5];	// 카드 지도
char* animalName[10];	// 동물이름 10개
int checkarray[4][5];	// 카드가 뒤집혔는지(뒤집히면 1 아니면 0)


// 함수 호출 //
void initData();
void SetAnimal();
void suffle();
int getEmpty();
int conv_x();
int conv_y();
void printQusetion();
void printAnswer();
int FoundAllAnimals();



// 메인 함수 //
int main()
{
	srand(time(NULL));
	initData();		//카드 지도 초기화
	SetAnimal();	//동물 이름 설정
	suffle();		//지도에 동물 이름 넣기
	int failcount = 0;
	// 게임 시작
	while (1)
	{
		// 정답 출력(개발용)
		printAnswer();

		// 문제 출력
		printQusetion();

		// 입력 2개 받기
		int select1, select2 = 0;
		printf("\n카드 두 개를 입력하세요 : ");
		scanf_s("%d %d", &select1, &select2);

		// 입력한 값이 중복될 경우
		if (select1 == select2)
		{
			printf("\n고른 카드가 중복됩니다. 다시 뽑아주세요.\n");
			continue;
		}

		// 좌표에 해당하는 배열 선언
		int first_x = conv_x(select1);
		int first_y = conv_y(select1);

		int second_x = conv_x(select2);
		int second_y = conv_y(select2);



		// 카드가 뒤집히지 않았는지, 두 동물이 같은지 확인
		if (checkarray[first_x][first_y] == 0 && checkarray[second_x][second_y] == 0	// 첫번째, 두번재 카드가 뒤집혀있고
			&&
			arrayAnimal[first_x][first_y] == arrayAnimal[second_x][second_y])			// 고른 두 카드가 같으면
		{
			printf("\n 정답입니다. 해당 카드를 뒤집습니다.\n");
			checkarray[first_x][first_y] = 1;
			checkarray[second_x][second_y] = 1;
		}
		// 해당하지 않는 경우, 오답인 카드의 동물을 출력, 실패 횟수 +
		else
		{
			printf("\n오답입니다.\n");
			printf("%d번 카드는 %s입니다.\n", select1, animalName[arrayAnimal[first_x][first_y]]);
			printf("%d번 카드는 %s입니다.\n", select2, animalName[arrayAnimal[second_x][second_y]]);

			failcount++;
		}

		// 게임이 끝났는지 확인
		if (FoundAllAnimals() == 1)
		{
			printf("\n********************************************\n");
			printf("모든 정답을 맞추셨습니다. 실패 횟수는 총 %d번입니다.", failcount);
			break;
		}

	}

	return 0;
}

void initData()		//카드지도 -1 초기화
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
void SetAnimal()	//동물 이름 설정
{
	animalName[0] = "강아지";
	animalName[1] = "고양이";
	animalName[2] = "코끼리";
	animalName[3] = "낙타";
	animalName[4] = "하마";
	animalName[5] = "기린";
	animalName[6] = "얼룩말";
	animalName[7] = "호랑이";
	animalName[8] = "사자";
	animalName[9] = "돌고래";
}
void suffle()		//동물 이름 넣기
{
	// 배열에 10개의 동물 이름을 두번 넣기
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			// 빈 카드지도 확인
			int position = getEmpty();
			int x = conv_x(position);
			int y = conv_y(position);

			arrayAnimal[x][y] = i;

		}
	}
}
int getEmpty()		// 카드지도의 빈 공간 랜덤으로 2개 뽑기
{
	while (1)
	{
		int randomnum = rand() % 20; //0~20 랜덤 숫자 반환
		// 랜덤 수의 좌표 반환 함수
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
	// 14 반환 시 2
	return x / 5;
}
int conv_y(int y)
{
	return y % 5;
}

void printQusetion()	// 카드의 순서대로 번호 출력(정답일 경우 해당 동물 이름 출력)
{
	printf("\n\n");
	int seq = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// 카드를 뒤집어서 정답을 맟추면 "동물 이름"
			if (checkarray[i][j] != 0)
			{
				printf("%8s", animalName[arrayAnimal[i][j]]);
			}
			// 아직 뒤집지 못했거나 정답이 아니면 뒷면(숫자)
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
	printf("\n =====================정답=====================\n");
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
	// 전체 다 찾으면(카드가 다 뒤집어지면) 1을 반환
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
//	 ㅁㅁㅁㅁㅁ	 // 0  1  2  3  4		// 0 0 0 0 0
//	 ㅁㅁㅁㅁㅁ	 // 5  6  7  8  9		// 1 1 1 1 1
//	 ㅁㅁㅁㅁㅁ	 // 10 11 12 13 14		// 2 2 2 2 2
//	 ㅁㅁㅁㅁㅁ	 // 15 16 17 18 19		// 3 3 3 3 3


// 카드뒤집기 프로젝트
// 사용자로부터 2개의 입력값(좌표) > 같은 동물 찾으면 카드 뒤집기
// 모든 동물 쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기
//#include <stdio.h>
//#include <time.h>
//int arrayAnimal[4][5];	// 카드 지도 20장
//int checkAnimal[4][5];  // 뒤집혔는지 여부 확인
//char * strAnimal[10];	// 동물 이름 10개
//void initAnimalArray()	// 카드 지도 초기화
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 5; j++)
//			arrayAnimal[i][j] = -1;
//	}
//}
//void initAnimalName()
//{
//	strAnimal[0] = "원숭이";
//	strAnimal[1] = "하마";
//	strAnimal[2] = "강아지";
//	strAnimal[3] = "고양이";
//	strAnimal[4] = "돼지";
//	strAnimal[5] = "코끼리";
//	strAnimal[6] = "기린";
//	strAnimal[7] = "낙타";
//	strAnimal[8] = "타조";
//	strAnimal[9] = "호랑이";
//}
//void shuffleAnimal()	//지도에 동물 2마리씩 배치
//{
//	// ㅁㅁㅁㅁㅁ	빈공간을 찾은 후 해당 자리에 배치
//	// ㅁㅁㅁㅁㅁ
//	// ㅁㅁㅁㅁㅁ
//	// ㅁㅁㅁㅁㅁ
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
//int getEmptyPosition()	// 좌표에서 빈 공간 찾기
//{
//	while (1)
//	{
//		int randPos = rand() % 20; // 0 ~ 19 까지 숫자 반환
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
//void printAnimals()		// 동물 위치 출력
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
//	printf("\n\n <문제> \n");
//	int seq = 0;
//
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			// 카드 뒤집어서 정답을 맞추면 '동물 이름'
//			if (checkAnimal[i][j] != 0)				//checkAnimal은 이미 찾은 카드
//			{
//				printf("%8s", strAnimal[arrayAnimal[i][j]]);
//			}
//			// 아직 뒤집지 못했으면(정답x) 뒷면(위치를 나타내는 숫자)
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
//	return 1;	// 모두 다 찾음
//}
//int main()
//{
//	srand(time(NULL));
//	initAnimalArray();
//	initAnimalName();
//	shuffleAnimal();
//
//	int failCount = 0;	//실패 횟수
//
//	while (1)
//	{
//		int select1 = 0;		// 사용자 선택 1
//		int select2 = 0;		// 사용자 선택 2
//
//		printAnimals();
//		printQusetion();
//
//		printf("뒤집을 카드를 2개 고르세요 : ");
//		scanf_s("%d %d", &select1, &select2);
//
//		if (select1 == select2)	// 같은 카드 두개 고를 시 무효
//			continue;
//
//		// 좌표에 해당하는 카드를 뒤집어 보고 같은지 확인
//		// x, y좌표로 변환 필요
//		int firstSelect_x = conv_pos_x(select1);
//		int firstSelect_y = conv_pos_y(select1);
//
//		int secondSelect_x = conv_pos_x(select2);
//		int secondSelect_y = conv_pos_y(select2);
//
//		// 카드가 이미 뒤집혔는지, 두 동물이 같은지 확인
//		if (checkAnimal[firstSelect_x][firstSelect_y] == 0
//			&& checkAnimal[secondSelect_x][secondSelect_y] == 0		//카드가 뒤집히지 않았는지
//			&&
//			arrayAnimal[firstSelect_x][firstSelect_y]
//			== arrayAnimal[secondSelect_x][secondSelect_y])			//선택한 카드 두 동물이 같은지
//		{
//			printf("\n\n 빙고! :%s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
//			checkAnimal[firstSelect_x][firstSelect_y] = 1;
//			checkAnimal[secondSelect_x][secondSelect_y] = 1;
//		}
//
//
//		// 다른 동물인 경우
//		else
//		{
//			printf("\n\n 땡! (틀렸거나 이미 뒤집힌 카드입니다)\n");
//			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
//			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
//			printf("\n\n");
//
//			failCount++;
//		}
//
//		// 모든 동물을 찾았는지 여부 확인 
//		if (foundAllAnimals() == 1)
//		{
//			printf("\n\n 축하합니다! 모든 동물을 다 찾았습니다. \n");
//			printf("지금까지 총 %d번 실수하셨습니다.\n", failCount);
//		}
//	}
//
//	return 0;
//}

//// 다차원배열 접근2
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
//	//1차원배열
//	printf("1차원 배열\n");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n\n");
//
//	//2차원배열
//	printf("\n2차원 배열1\n");
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
//	//2차원배열 2
//	printf("\n2차원 배열2\n");
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			printf("%d ", arr3[i][j]);
//		}
//		printf("\n");
//	}
//
//	//3차원 배열
//	printf("\n3차원 배열\n");
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

// 다차원배열 선언
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

//// 다차원배열 접근
//#include <stdio.h>
//int main()
//{
//	int i; //ㅁ
//	int arr[5];
//	//ㅁㅁㅁㅁㅁ
//	//[0][1][2][3][4]
//
//	int arr2[2][5];
//	//ㅁㅁㅁㅁㅁ
//	//ㅁㅁㅁㅁㅁ
//	//[0,0][0,1][0,2][0,3][0,4]  실제로 쓸 때 arr2[0][0]
//	//[1,0][1,1][1,2][1,3][1,4]  >> arr2[1][4]
//
//
//	int arr3[4][2];
//	//ㅁㅁ	[0,0][0,1]
//	//ㅁㅁ	[1,0][1,1]
//	//ㅁㅁ	[2,0][2,1]
//	//ㅁㅁ	[3,0][3,1]
//
//	int arr4[3][3][3];
//	//ㅁㅁㅁ
//	//ㅁㅁㅁ
//	//ㅁㅁㅁ
//
//	//ㅁㅁㅁ
//	//ㅁㅁㅁ
//	//ㅁㅁㅁ
//
//	//ㅁㅁㅁ
//	//ㅁㅁㅁ
//	//ㅁㅁㅁ
//
//	return 0;
//}

//다차원 배월
//#include <stdio.h>
//
//int main()
//{
//	int i; //ㅁ
//	int arr[5]; 
//	//ㅁㅁㅁㅁㅁ
//
//	int arr2[2][5];
//	//ㅁㅁㅁㅁㅁ
//	//ㅁㅁㅁㅁㅁ
//
//	int arr3[4][2];
//	//ㅁㅁ
//	//ㅁㅁ
//	//ㅁㅁ
//	//ㅁㅁ
//
//	int arr4[3][3][3];
//	//ㅁㅁㅁ
//	//ㅁㅁㅁ
//	//ㅁㅁㅁ
//	 
//	//ㅁㅁㅁ
//	//ㅁㅁㅁ
//	//ㅁㅁㅁ
//	
//	//ㅁㅁㅁ
//	//ㅁㅁㅁ
//	//ㅁㅁㅁ
//
//	return 0;
//}