#include <stdio.h>
int main()
{
	char buf[] = "ABC";
	char* s = "ABC";

	printf("%s %s\n", buf, s);

	buf[0] = 'Z';
	printf("%s %s\n", buf, s);
	s = "ZBC"; // 리터럴 상수는 못고침
	printf("%s %s\n", buf, s);
}

//#include <stdio.h>
//int main()
//{
// char buf[4] = "ABC"; // null문자 자리 넣어야함
// //char buf[] = "ABC" 와 동일
// printf("%d\n", buf[0]);
// printf("%d\n", buf[1]);
// printf("%d\n", buf[2]);
// printf("%s\n", buf);
//}

//#include <stdio.h>
//int main()
//{
//// char buf[5] = { 'A','B','C' }; // 문자열 포인터로 담는법, 배열로 담는법(기말)
// char buf[5] = "ABC"; 
//
// printf("%d\n", buf[0]);
// printf("%d\n", buf[1]);
// printf("%d\n", buf[2]);
// printf("%d\n", buf[3]);
// printf("%d\n", buf[4]);
// printf("%s\n", buf);
//}

//#include <stdio.h>
//int main()
//{
// char buf[5] = { 'A','B','C' }; // 뒤 안정하면 0
//
// printf("%d\n", buf[0]);
// printf("%d\n", buf[1]);
// printf("%d\n", buf[2]);
// printf("%d\n", buf[3]);
// printf("%d\n", buf[4]);
// printf("%s\n", buf);
//}

//#include <stdio.h>
//int main()
//{
// char buf[] = { 'A','B','C',0 ,5 }; // 원소가 정의되어 있으면 배열 크기 생략 가능
//
// printf("%d\n", buf[0]);
// printf("%d\n", buf[1]);
// printf("%d\n", buf[2]);
// printf("%d\n", buf[3]);
// printf("%d\n", buf[4]);
//
// printf("%s\n", buf);
//}

//#include <stdio.h>
//int main()
//{
// char buf[] = { 1,2,3,4,5 }; // 원소가 정의되어 있으면 배열 크기 생략 가능
//
// printf("%d\n", buf[0]);
// printf("%d\n", buf[1]);
// printf("%d\n", buf[2]);
// printf("%d\n", buf[3]);
// printf("%d\n", buf[4]);
//}

// 10. 문자열 함수 출력3
//#include <stdio.h>
//void PrintString(char* s)
//{
// printf("string : %s\n", s);
//}
//int main()
//{
// char* s = "hello!";
//
// PrintString(s);
// PrintString("ABC");
//}

// 9. 문자열 함수 출력2
//#include <stdio.h>
//void PrintString(char* s)
//{
// printf("%c : %d\n", s[0], s[0]);
// printf("%c : %d\n", s[1], s[1]);
// printf("%c : %d\n", s[2], s[2]);
// printf("%c : %d\n", s[3], s[3]);
// printf("%c : %d\n", s[4], s[4]);
// printf("%c : %d\n", s[5], s[5]);
//}
//int main()
//{
// char* s = "hello!";
//
// PrintString(s);
//}

// 8. 문자열 함수출력
//#include <stdio.h>
//void PrintString(char* s)
//{
// printf("%p : %s",s, s);
//}
//int main()
//{
// char* s = "hello!";
//
// PrintString(s);
//}

// 7. 문자열
//#include <stdio.h>
//int main()
//{
// char* s = "hello!";
//
// printf("%p : %s\n", s, s);
// printf("%p : %s\n", s+1, s+1);
//}

// 6. 배열 출력함수 2
//#include <stdio.h>
//void PrintArray(int* arr, int size)
//{
// for (int i = 0; i < size; i++)
//  printf("[%d] : %d\n", i, arr[i]);
//}
//int main()
//{
// int arr[6] = { 10, 20, 30, 40 , 4, 2};
// int size = sizeof(arr) / 4;
// int* pa = arr;
// PrintArray(arr, size);
// printf("\n");
// PrintArray(pa, size);
//}

// 5. 배열 출력 함수
//#include <stdio.h>
//void PrintArray(int* arr)
//{
// for (int i = 0; i < 4; i++)
//  printf("[%d] : %d\n", i, arr[i]);
//}
//int main()
//{
// int arr[4] = { 10, 20, 30, 40 };
// int* pa = arr;
// PrintArray(arr);
// printf("\n");
// PrintArray(pa);
//}

// 4. for문 배열 출력
//#include <stdio.h>
//int main()
//{
// int arr[4] = { 10, 20, 30, 40 };
//
//// for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
// for(int i = 0; i < 4; i++)
//  printf("[%d] : %d\n", i, arr[i]);
//}

// 3. 사용자함수 2
//#include <stdio.h>
//void PrintHello(int n)
//{
// for (int i = 0; i < n; i++)
//  printf("Hello : %d\n", n);
// printf("\n");
//}
//int main()
//{
// for (int i = 0; i < 5; i++)
//  PrintHello(i); //함수호출(인수);
//
// return 0;
//}

// 2. 사용자 함수
//#include <stdio.h>
//void PrintHello(int n)
//{
// printf("Hello! %d\n", n);
//}
//int main()
//{
// for (int i = 0; i < 5; i++)
//  PrintHello(i); //함수호출(인수);
//
// return 0;
//}

//#include <stdio.h>
//int main()
//{
// printf("Hello!\n");
// return 0;
//} 