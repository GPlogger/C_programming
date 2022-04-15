#include <stdio.h>
int main()
{
	char* s = "ABC";

	printf("%s %p \n", s, s);
	printf("%s %p \n", s+1, s+1);
}

//#include <stdio.h>
//int main()
//{
//	char* s = "ABC";
//
//	printf("%s %p \n", s, s);
//}

//#include <stdio.h>
//int main()
//{
//	char* s;
//	s = (char*)"ABC";
//
//	printf("%p\n", "ABC");
//	printf("%p\n", s);
//
//	printf("%d\n", s[0]);
//	printf("%d\n", s[1]);
//	printf("%d\n", s[2]);
//	printf("%d\n", s[3]);
//}

//#include <stdio.h>
//int main()
//{
//	int arr[4] = { 10,20,30,40 };
//	int* p = arr;
//
//	printf("%p %p %p\n", arr, p, &arr[0]);
//	printf("%d %d %d\n", *arr, *p, *&arr[0]);
//
//	printf("%d %d\n", p[0], arr[0]);
//	printf("%d %d\n", p[1], arr[1]);
//	printf("%d %d\n", p[2], arr[2]);
//	printf("%d %d\n", p[3], arr[3]);
//
//	printf("\n");
//	p = &arr[2];
//	printf("%d %d\n", arr[0], p[-2]);
//	printf("%d %d\n", arr[1], p[-1]);
//	printf("%d %d\n", arr[2], p[0]);
//	printf("%d %d\n", arr[3], p[1]);
//}

//#include <stdio.h>
//int main()
//{
//	int arr[4] = { 10,20,30,40 };
//
//	int* p = arr;
//
//	printf("%p %p %p\n", arr, p, &arr[0]);
//	printf("%d %d %d\n", *arr, *p, *&arr[0]);
//}

//#include <stdio.h>
//int main()
//{
//	int arr[4] = { 10,20,30,40 };
//
//	int* p = &arr[0];
//	printf("%p %p\n", p, &arr[0]);
//	printf("%p %p\n", p + 1, &arr[1]);
//	printf("%p %p\n", p + 2, &arr[2]);
//	printf("%p %p\n", p + 3, &arr[3]);
//
//	printf("\n");
//	printf("%d %d\n", *p, *&arr[0]);
//	printf("%d %d\n", *(p + 1), *&arr[1]);
//	printf("%d %d\n", *(p + 2), *&arr[2]);
//	printf("%d %d\n", *(p + 3), *&arr[3]);
//}

//#include <stdio.h>
//int main()
//{
//	int n = 10;
//
//	printf("%p %d\n", &n, n);
//	printf("%p %d\n", &n + 1, n + 1);
//	printf("%p %d\n", &n + 2, n + 2);
//	printf("%p %d\n", &n + 3, n + 3);
//	printf("%p %d\n", &n - 1, n - 1);
//}

//#include <stdio.h>
//
//int main()
//{
//    int arr[4] = { 10, 20, 30, 40 };
//    for (int i = 0; i < 4; i++)
//        printf("%p : %d\n", &arr[i], arr[i]);
//    printf("\n");
//
//    int* p = &arr[0];
//    printf("%p : %d\n", p, *p);
//    p = &arr[1];
//    printf("%p : %d\n", p, *p);
//    p = &arr[2];
//
//    printf("%p : %d\n", p, *p);
//    p = &arr[3];
//
//    printf("%p : %d\n", p, *p);
//
//}   

//#include <stdio.h>
//
//int main()
//{
//    int arr[5] = { 1,2,3 };
//    double da[5] = { 1.1, 2.2, 3.3 };
//
//    for (int i = 0; i < 5; ++i)
//        printf("%d %g\n", arr[i], da[i]);
//}

//#include <stdio.h>
//
//int main()
//{
//    int arr[5] = { 1,2,3 };
//    double da[5] = { 1.1, 2.2, 3.3 };
//
//    //배열 : 같은 자료형식의 연속한 메모리 집합
//    printf("%d %d %d %d %d\n",
//        arr[0], arr[1], arr[2], arr[3], arr[4]);
//
//    printf("%g %g %g %g %g\n",
//        da[0], da[1], da[2], da[3], da[4]);
//
//    printf("size: %d\n", sizeof(arr));
//    printf("size: %d\n", sizeof(da));
//}