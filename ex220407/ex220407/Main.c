 //파일 읽기 fscanf
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000	// 상수
int main()
{
	// 파일에 데이터를 저장, 파일에 저장된 데이터를 불러오기

	// fgets, fgets는 문자열을 저장하고 쓸 때 사용
	// fprintf, fscanf : 정형화된 포맷이 있고, 포맷에 대해 파읽을 읽고 씀
	int num[6] = { 0, };	// 로또 추첨 번호
	int bonus = 0;

	char str1[MAX];
	char str2[MAX];

	FILE* file = fopen("C:\\Users\\kkjj4\\Desktop\\c_programming\\test2.txt", "rb");
	if (file == NULL)
	{
		printf("해당 파일을 불러올 수 없습니다.\n");
		return 0;
	}
	
	fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);
	fscanf(file, "%s %d", str2, &bonus);
	printf("%s %d", str2, bonus);

	fclose(file);
	return 0;
}

// 파일 쓰기 fprintf
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MAX 10000	// 상수
//int main()
//{
//	// 파일에 데이터를 저장, 파일에 저장된 데이터를 불러오기
//
//	// fgets, fgets는 문자열을 저장하고 쓸 때 사용
//	// fprintf, fscanf : 정형화된 포맷이 있고, 포맷에 대해 파읽을 읽고 씀
//	int num[6] = { 0, };	// 로또 추첨 번호
//	int bonus = 0;
//
//	char str1[MAX];
//	char str2[MAX];
//
//	FILE* file = fopen("C:\\Users\\kkjj4\\Desktop\\c_programming\\test2.txt", "wb");
//	if (file == NULL)
//	{
//		printf("해당 파일을 불러올 수 없습니다.\n");
//		return 0;
//	}
//	// 로또 추첨번호 저장
//	fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호 ", 1, 2, 3, 4, 5, 6);
//	fprintf(file, "%s %d \n", "보너스번호 ", 7);
//	
//	fclose(file);
//	return 0;
//}

// 파일 불러오기
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MAX 10000	// 상수
//int main()
//{
//	// 파일에 데이터를 저장, 파일에 저장된 데이터를 불러오기
//
//	// fgets
//	char line[MAX];	//char line[10000]
//	FILE* file = fopen("C:\\Users\\kkjj4\\Desktop\\c_programming\\test1.txt", "rb");	// c:\\에서 역슬래시를 두개 써야 인지
//												// r : 읽기 |  w : 쓰기 |  a : 이어쓰기 | t : 텍스트 | b : 바이너리 데이터
//	if (file == NULL)
//	{
//		printf("파일 열기 실패\n");
//		return 0;
//	}
//
//	while (fgets(line, MAX, file) != NULL)		// fgets(값을 저장할 주소, 크기, 파일포인터)
//	{
//		printf("%s", line);
//	}
//	fclose(file);	//파일을 닫음
//	// fprintf, fscanf
//
//	return 0;
//}

// 파일 쓰기(fputs)
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MAX 10000	// 상수
//int main()
//{
//	// 파일에 데이터를 저장, 파일에 저장된 데이터를 불러오기
//
//	// fputs, fgets
//	char line[MAX];	//char line[10000]
//	FILE* file = fopen("C:\\Users\\kkjj4\\Desktop\\c_programming\\test1.txt", "wb");	// c:\\에서 역슬래시를 두개 써야 인지
//												// r : 읽기 |  w : 쓰기 |  a : 이어쓰기 | t : 텍스트 | b : 바이너리 데이터
//	if (file == NULL)
//	{
//		printf("파일 열기 실패\n");
//		return 0;
//	}
//
//	fputs("fputs를 이용해 글을 작성\n", file);
//	fputs("잘 적히는지 확인해주세요.\n", file);
//
//	fclose(file);	//파일을 닫음
//	// fprintf, fscanf
//
//
//	return 0;
//}