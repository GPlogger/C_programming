// Up & Down 게임만들기
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand(time(NULL));
	int random = rand() % 100 + 1; //1~100 랜덤 정수
	printf("맞춰야 하는 숫자는 %d 입니다.\n", random);

	int answer = 0; //입력한 답
	int chance = 5;	//남은 기회
	while (chance > 0)
	{
		printf("남은 기회는 %d번입니다.\n", chance--);
		printf("숫자를 입력하세요 : ");
		scanf_s("%d", &answer);

		if (answer == random)
		{
			printf("정답입니다!\n");
			break;
		}
		else if (answer > random)
			printf("Down\n");
		else
			printf("UP\n");

		printf("\n");
		if (chance == 0)
			printf("남은 기회가 없습니다!");
	}
}

// 교통카드 switch 문법으로 만들기
//#include <stdio.h>
//int main()
//{
//	int age = 0;
//	printf("나이를 입력하세요 : ");
//	scanf_s("%d", &age);
//
//	switch (age)
//	{
//	case 8:
//	case 9:
//	case 10:
//	case 11:
//	case 12:
//	case 13: printf("초등학생입니다."); break;	// break를 사용하지 않을 시 아래의 모든 내용을 출력하는 것을 이용해 이처럼 사용 가능
//	case 14:
//	case 15:
//	case 16: printf("중학생입니다."); break;
//	case 17:
//	case 18:
//	case 19: printf("고등학생입니다."); break;
//	default: printf("학생이 아닙니다."); break;
//
//	}
//	return 0;
//}

// switch 가위바위보
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//int main()
//{
//	srand(time(NULL));
//	int i = rand() % 3;	//0~2 반환
//	// 가위0 바위1 보2
//	switch (i)
//	{
//	case 0:
//		printf("가위"); break;
//	case 1:
//		printf("바위"); break;
//	case 2:
//		printf("보"); break;
//	default:
//		printf("Error"); break;
//	}					// switch에서 조건 실행시 break가 없으면 아래 모든 구문을 출력
//						// 따라서 switch 케이스 뒤에는 항상 berak가 들어가야 함
//	return 0;
//}

// if 가위바위보
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//int main()
//{
//	srand(time(NULL));
//	int i = rand() % 3;	//0~2 반환
//	// 가위0 바위1 보2
//	if (i == 0)
//		printf("가위");
//	else if (i == 1)
//		printf("바위");
//	else if (i == 2)
//		printf("보");
//	else
//		printf("Error");
//
//	return 0;
//}

// 랜덤 time.h, stdlib.h 라이브러리가 필요함
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//int main()
//{
//	// rand() % 범위(0 ~ 범위)
//	/*
//	srand(time(NULL));			//난수 초기화 (안하면 같은 랜덤이 나옴)
//	int num = rand() % 3 + 1;	//1을 더하면 1부터 3의 숫자를, 더하지 않으면 0~2 뽑음
//	printf("%d\n", num);
//	*/
//	printf("난수 초기와 이전\n");		// 재실행시 같은 범위의 난수가 나옴
//	for (int i = 0; i < 10; i++)
//		printf("%d ", rand() % 10);
//	
//	printf("\n난수 초기화 이후\n");
//	srand(time(NULL));
//	for (int i = 0; i < 10; i++)
//		printf("%d ", rand() % 10);
//
//	return 0;
//}

//// 7번을 제외한 6번부터 10번까지 조별 발표
//#include <stdio.h>
//int main()
//{
//	for (int i = 1; i <= 30; i++)
//	{
//		if (6 <= i && i <= 10)
//		{
//			if (i == 7)
//			{
//				printf("%d번 학생은 결석입니다.\n", i);
//				continue;		//continue는 반복문 건너뛰기
//			}
//			printf("%d번 학생은 발표를 하세요.\n", i);
//		}
//	}
//}

// break, continue
// 1번부터 30번까지 있는 반에서 1번부터 5번까지 조별 발표
//#include <stdio.h>
//int main()
//{
//	for (int i = 1; i <= 30; i++)
//	{
//		if (i >= 6)
//		{
//			printf("나머지 학생은 집에 가세요.");
//			break;		// 반복문을 탈출
//		}
//		printf("%d번 학생은 조별 발표 준비를 하세요.\n", i);
//	}
//	return 0;
//}

//// 초등학생(8~13) 중학생(14~16) 고등학생(17~19) 성인(20~)  나이구분
//#include <stdio.h>
//int main()
//{
//	int age = 0;
//	printf("나이를 입력하세요 : ");
//	scanf_s("%d", &age);
//
//	if (age < 8)
//		printf("Error");
//	else if (8 <= age && age <= 13)
//		printf("초등학생입니다.");
//	else if (14 <= age && age <= 16)
//		printf("중학생입니다.");
//	else if (17 <= age && age <= 19)
//		printf("고등학생입니다.");
//	else
//		printf("성인입니다.");
//	return 0;
//}

////조건문 if else
//#include <stdio.h>
//int main()
//{
//	int age = 0;
//	printf("나이를 입력하시오 : ");
//	scanf_s("%d", &age);
//
//	if (age < 20)
//		printf("학생입니다.");
//	else
//		printf("성인입니다.");
//
//	return 0;
//}

//// 피라미드 쌓기 ( 숫자 입력 받아서 그 층만큼 쌓기)
//#include <stdio.h>
//int main()
//{
//	int count = 0;
//	printf("높이 : ");
//	scanf_s("%d", &count);
//	printf("%d층 높이의 피라미드를 쌓습니다.\n", count);
//
//	// 4층 기준
//	for (int i = 0; i < count; i++)				//세로 0 1 2 3
//	{
//		for (int j = i; j < count - 1; j++)		//공백 3 2 1 0
//			printf(" ");
//		for (int k = 0; k < (1 + i * 2); k++)	//* 1 3 5 7 (1 + 1*2)
//			printf("*");
//		printf("\n");
//	}
//}

// 별 찍기
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

//// 별 찍기 5줄, 1 2 3 4 5
//#include <stdio.h>
//int main()
//{
//	for (int i = 1; i <= 5; i++)		//세로
//	{
//		for (int j = 1; j <= i; j++)	//가로
//			printf("*");
//		printf("\n");
//	}
//}

//// 구구단
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

//// 이중 반복문
//#include <stdio.h>
//int main()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		printf("첫 번째 반복문 : %d\n", i);
//
//		for (int j = 0; j < 5; j++)
//			printf("  두 번째 반복문 : %d\n", j);
//	}
//}

//// 반복문 연습3
//#include <stdio.h>
//int main()
//{
//	// do {} while (조건);
//	int i = 0;
//	do { printf("i : %d\n", i++); } while (i <= 10);
//	return 0;
//}

//// 반복문 연습2
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

//// 반복문 연습1
//#include <stdio.h>
//int main()
//{
//	for (int i = 0; i <= 10; ++i)
//	{
//		printf("i : %d\n", i);
//	}
//	return 0;
//}

//// i++과 ++i
//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	printf("%d\n", num);
//	printf("%d\n", num++);	// 문장을 출력 한 뒤 num에 +1
//	printf("%d\n", ++num);	// 문장을 출력하기 전 num에 +1
//	printf("%d\n", num);
//
//	return 0;
//}


// 입력과 출력 연습
//#include <stdio.h>
//int main()
//{
//	char name[256] = { 0 };
//	int age = 0;
//	float weight = 0;
//	double height = 0;
//	char what[256] = { 0 };
//
//	printf("이름이 무엇입니까?");
//	scanf_s("%s", name, sizeof(name));
//
//	printf("나이가 몇살입니까?");
//	scanf_s("%d", &age);			// 배열이 아닌 변수는 &가 필요함
//
//	printf("몸무게는 몇kg 입니까?");
//	scanf_s("%f", &weight);			// float 자료형은 %f
//
//	printf("키는 몇cm 입니까?");
//	scanf_s("%lf", &height);		// double 자료형은 %lf
//
//	printf("하고싶은 말씀을 적어주세요.");
//	scanf_s("%s", what, sizeof(what));
//
//	printf("이름은 %s, 나이는 %d세, 몸무게는 %.1f입니다.\n", name, age, weight);
//	printf("%s 라고 적으셨습니다.", what);
//	getchar();
//
//	return 0;
//}