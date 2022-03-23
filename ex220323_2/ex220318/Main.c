#include <stdio.h>
#include <time.h>

int level = 1;
int arrayFish[6];
int* cursor;

void initData()		//초기 데이터 초기화
{
	level = 1;
	for (int i = 0; i < 6; i++)
		arrayFish[i] = 100;
}
void printFish()	//어항 상태 출력
{
	printf("1번\t2번\t3번\t4번\t5번\t6번\t\n");
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
		arrayFish[i] -= level * 2 * (int)prev;		// 어항에 레벨*2 *지난 시간
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

	int num = 0; // 몇번 어항에 물을 줄건지
	cursor = arrayFish;

	startTime = clock();		//현재 시간을 밀리세컨드 단위로 저장

	while (1)
	{
		printFish();
		printf("몇 번째 어항에 물을 주시겠습니까? : ");
		scanf_s("%d", &num);

		if (num < 1 || num > 6)
		{
			printf("\n******무효. 잘못된 값을 입력했습니다.******\n");
			continue;
		}

		// 총 경과 시간
		totalTime = (clock() - startTime) / CLOCKS_PER_SEC;	// 현재시간 - 시작시간을 초로 나눠 지난 초를 계산
		printf("총 경과 시간 : %ld\n", totalTime);

		// 직전에 물을 준 시간 이후 흐른 시간
		prevTime = totalTime - prevTime;		// 물 준 시간 = 총 경과시간 - 전 물 준시간
		printf("물을 준 지 %ld초가 지났습니다.\n", prevTime);

		// 어항의 물 감소
		decreaseWater(prevTime);

		// 사용자가 물을 주면 2++
		// 1. 물의 양이 0이면 값은 0
		if (cursor[num - 1] <= 0)
		{
			printf("\n !!! %d번째 어항의 물고기는 이미 죽었습니다.\n", num);
		}

		else if (cursor[num - 1] + 1 <= 100)
		{
			printf("%d번째 어항에 물을 줍니다.\n\n", num);
			cursor[num - 1] += 1;
		}

		// 레벨업 부분(20초마다 레벨업)
		if (totalTime / 20 > level - 1)
		{
			level++;
			printf("===== Level Up! 현재 레벨은 %d입니다. =====\n", level);
			//레벨 5 게임 종료
			if (level == 5)
			{
				printf("===== 축하합니다. 게임을 클리어하셨습니다. =====");
				exit(0);
			}

		}

		// 모든 물고기가 죽었을 때
		if (checkFish() == 0)
		{
			printf("===== Game Over. =====\n");
			exit(0);
		}


		prevTime = totalTime;					// 후에 총 경과시간으로 바꿔야 계속 최신화 가능

	}
	return 0;
}

// //프로젝트
// //물고기 6마리, 어항에 살고 있음
// //사막이 너무 건조해 물이 빠르게 증가. 물이 증발하기 전에 부지런히 어항에 물을 줘야 함
// //시간이 지날수록 점점 커져 나중에는 먹음
//#include <stdio.h>
//#include <time.h>
//int level;
//int arrayFish[6];
//int * cursor;
//
//void initData()
//{
//	level = 1;	// 레벨은 1~5;
//	for (int i = 0; i < 6; i++)
//	{
//		arrayFish[i] = 100;
//	}
//}
//void printFishes()
//{
//	printf("%3d번  %3d번  %3d번  %3d번  %3d번  %3d번\n", 1, 2, 3, 4, 5, 6);
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
//	int num;		//몇 번 어항에 물을 줄건지
//	initData();
//
//	cursor = arrayFish;
//
//	startTime = clock();	//현재의 시간을 밀리세컨드 단위 반환
//
//	while (1)
//	{
//		printFishes();
//		printf("몇 번 어항에 물을 주시겠어요?");
//		scanf_s("%d", &num);
//
//		if (num < 1 || num > 6)
//		{
//			printf("입력값이 잘못되었습니다.\n");
//			continue;
//		}
//
//		// 총 경과 시간
//		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
//		printf("총 경과 시간 : %ld 초\n", totalElapsedTime);
//
//		// 직전 물 준 시간(마지막으로 물 준 시간) 이후로 흐른 시간
//		prevElapseddTime = totalElapsedTime - prevElapseddTime;
//		printf("최근 경과 시간 : %ld 초 \n", prevElapseddTime);
//
//		// 어항의 물 감소
//		decreaseWater(prevElapseddTime);
//
//		//사용자가 입력한 어항에 물을 줌
//		//1. 어항의 물이 0이면 물 주기 x
//		if (cursor[num - 1] <= 0)
//		{
//			printf("%d번 물고기는 이미 죽었습니다.\n", num);
//		}
//		//2. 어항의 물이 0이 아닌 경우 물을 줌, 100을 넘지 않는지 체크
//		else if (cursor[num - 1] + 1 <= 100)
//		{
//			printf("%d번 어항에 물을 줍니다\n\n", num);
//			cursor[num - 1] += 1;
//		}
//
//		//레벨업 할 건지 확인(레벨업은 20초마다 한번씩 수정
//		if (totalElapsedTime / 20 > level - 1)
//		{
//			level++;
//			printf("===level up! 기존 %d 레벨에서 %d 레벨로 업그레이드===\n", level - 1, level);
//
//			// 최종레벨 5 게임종료
//			if (level == 5)
//			{
//				printf("===축하합니다. 최고레벨을 달성했습니다. 게임을 종료합니다.\n");
//				exit(0);
//			}
//		}
//
//		// 모든 물고기가 죽었으면 게임 종료
//		if (checkFishAlive() == 0)
//		{
//			printf("Game Over. 모든 물고기가 죽었습니다.\n");
//			exit(0);
//			// 물고기 모두 죽음
//		}
//		else
//		{
//			printf("물고기가 아직 살아있습니다.\n");
//		}
//		prevElapseddTime = totalElapsedTime; // 
//	}
//	return 0;
//}
//

//// 프로젝트
//// 물고기 6마리, 어항에 살고 있음
//// 사막이 너무 건조해 물이 빠르게 증가. 물이 증발하기 전에 부지런히 어항에 물을 줘야 함
//// 시간이 지날수록 점점 커져 나중에는 먹음
//#include <stdio.h>
//#include <time.h>
//int level;
//int arrayFish[6];
//int * cursor;
//
//void initData()
//{
//	level = 1;	// 레벨은 1~5;
//	for (int i = 0; i < 6; i++)
//	{
//		arrayFish[i] = 100;
//	}
//}
//void printFishes()
//{
//	printf("%3d번  %3d번  %3d번  %3d번  %3d번  %3d번\n", 1, 2, 3, 4, 5, 6);
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
//	int num;		//몇 번 어항에 물을 줄건지
//	initData();
//
//	cursor = arrayFish;
//
//	startTime = clock();	//현재의 시간을 밀리세컨드 단위 반환
//
//	while (1)
//	{
//		printFishes();
//		printf("몇 번 어항에 물을 주시겠어요?");
//		scanf_s("%d", &num);
//
//		if (num < 1 || num > 6)
//		{
//			printf("입력값이 잘못되었습니다.\n");
//			continue;
//		}
//
//		// 총 경과 시간
//		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
//		printf("총 경과 시간 : %ld 초\n", totalElapsedTime);
//
//		// 직전 물 준 시간(마지막으로 물 준 시간) 이후로 흐른 시간
//		prevElapseddTime = totalElapsedTime - prevElapseddTime;
//		printf("최근 경과 시간 : %ld 초 \n", prevElapseddTime);
//
//		// 어항의 물 감소
//		decreaseWater(prevElapseddTime);
//
//		//사용자가 입력한 어항에 물을 줌
//		//1. 어항의 물이 0이면 물 주기 x
//		if (cursor[num - 1] <= 0)
//		{
//			printf("%d번 물고기는 이미 죽었습니다.\n", num);
//		}
//		//2. 어항의 물이 0이 아닌 경우 물을 줌, 100을 넘지 않는지 체크
//		else if (cursor[num - 1] + 1 <= 100)
//		{
//			printf("%d번 어항에 물을 줍니다\n\n", num);
//			cursor[num - 1] += 1;
//		}
//
//		//레벨업 할 건지 확인(레벨업은 20초마다 한번씩 수정
//		if (totalElapsedTime / 20 > level - 1)
//		{
//			level++;
//			printf("===level up! 기존 %d 레벨에서 %d 레벨로 업그레이드===\n", level - 1, level);
//			
//			// 최종레벨 5 게임종료
//			if (level == 5)
//			{
//				printf("===축하합니다. 최고레벨을 달성했습니다. 게임을 종료합니다.\n");
//				exit(0);
//			}
//		}
//
//		// 모든 물고기가 죽었으면 게임 종료
//		if (checkFishAlive() == 0)
//		{
//			printf("Game Over. 모든 물고기가 죽었습니다.\n");
//			exit(0);
//			// 물고기 모두 죽음
//		}
//		else
//		{
//			printf("물고기가 아직 살아있습니다.\n");
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
//	changeArray(arr2);			// 배열은 주소를 가리키므로 &를 붙이지 않음
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d\n", arr2[i]);
//	}
//}

////Swap
//#include <stdio.h>
//void Swap(int a, int b)	//함수 내부에서 외부 값의 스왑 어려움
//{
//	int tmp = a;
//	a = b;
//	b = a;
//	printf("Swap 함수 내부 a : %d\tb = %d\n", a, b);
//
//}
//void Swap_addr(int *a, int *b)	// 포인터를 사용해 스왑
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
//	printf("Swap 함수 후 a : %d\tb = %d\n", a, b);
//
//	Swap_addr(&a, &b);
//	printf("주소 스왑 후 a : %d\tb = %d\n", a, b);
//
//}

// 배열과 포인터
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
//	// arr, ptr은 둘 다 주소를 가리킴, 따라서 똑같은 표현
//	printf("%d\n", *(arr + 1));
//	printf("%d\n", *(ptr + 1));
//}

// 포인터
//#include <stdio.h>
//int main()
//{
//	int num = 1;
//
//	printf("num의 메모리 주소는 %d, 값은 %d 입니다.\n", &num, num);
//	int * ptr = &num;
//
//	printf("포인터의 메모리 주소는 %d, 값은 %d 입니다.\n", &ptr, ptr);
//	printf("포인터가 가리키는 메모리 주소는 %d, 값은 %d 입니다.\n", ptr, *ptr);
//
//	*ptr = 20;	// 값 변경 가능
//	printf("num의 값은 %d 입니다.", num);
//
//	return 0;
//}

// 아스키코드
//#include <stdio.h>
//int main()
//{
//	for (int i = 0; i < 128; i++)
//		printf("%d : %c\n", i, i);
//}

// 문자열 5
//#include <stdio.h>
//int main()
//{
//	char name[256];
//	printf("이름을 입력하세요 : ");
//	scanf_s("%s", name, sizeof(name));		//scanf_s를 사용해 값을 받을 때, 배열의 크기도 파라미터로 들어감
//	printf("%s", name);
//}

// 문자열 4
//#include <stdio.h>
//int main()
//{
//	char arr[10] = { 'c', 'o', 'd' ,'e'};
//	printf("%s\n", arr);
//
//	for (int i = 0; i < sizeof(arr); i++)	//code 뒤 남는 자리는 빈 칸으로 들어감(NULL)
//		printf("%c\n", arr[i]);
//}

//문자열 3
//#include <stdio.h>
//int main()
//{
//	char kor[] = "한국어";		// 영어는 한 글자당 1byte, 한글은 2byte
//	printf("%s\n", kor);
//	printf("%d\n", sizeof(kor));
//	return 0;
//}

//문자열 2
//#include <stdio.h>
//int main()
//{
//	char str[] = "coding";		//배열을 [] 비워서 넣으면 자동으로 크기만큼 입력됨
//	printf("%s\n", str);
//	printf("%d\n", sizeof(str));
//
//	for (int i = 0; i < sizeof(str); ++i)		//sizeof 함수를 이용해 문자열 출력 예시
//	{
//		printf("%c", str[i]);
//	}
//	return 0;
//}


// 문자와 문자열
//#include <stdio.h>
//int main()
//{
//	char c = 'A';
//	printf("%c\n", c);
//
//	char str[7] = "coding";  //문자열 끝에는 끝을 의미하는 NULL문자가 항상 포함되어야 한다.
//	printf("%s", str);		// [c], [o], [d], [i], [n], [g], [\0]
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr[3];		//배열 선언
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
//	printf("정답을 입력하세요 : ");
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
//			printf("프로그램을 종료합니다.\n");
//			break;
//		}
//		else if (answer == num1 * num2)
//		{
//			printf("정답입니다.\n");
//			if (i == 5)
//				printf("축하합니다. 모든 답을 맞추셨습니다.");
//		}
//		else
//		{
//			printf("오답입니다.\n");
//			break;
//		}
//	}
//
//
//
//	return 0;
//}