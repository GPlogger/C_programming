#include <stdio.h>
int main()
{
 
    char c = 10;
    int n = 100;
    double d = 5.5;


    printf("%d %d %g\n", c, n, d);
    printf("%p %p %p\n", &c, &n, &d);

    char* pc = &c;
    int* pn = &n;
    double* pd = &d;

    printf("%d %d %g\n", *pc, *pn, *pd);
    printf("%p %p %p\n", pc, pn, pd);

}

//#include <stdio.h>
//int main()
//{
//    int n = 100;
//    int* p = &n;
//
//    printf("%d %d\n",n, *p);
//    printf("%p :%p\n", &n, &*p);
//
//}

//#include <stdio.h>
//int main()
//{
//    int n = 100;
//    int* p = &n;
//
//    printf("n : %d\n", n);
//    printf("p : %p\n", p);
//    printf("*p : %d\n", *p);
//}

//#include <stdio.h>
//int main()
//{
//    int n = 100;
//    int* p = &n;
//
//    printf("n : %d\n", n);
//    printf("p : %p\n", p);
//}

//#include <stdio.h>
//int main()
//{
//    int sum = 0;
//    for (int i = 1; i <= 10; ++i)
//    {
//        sum += i;
//        printf("%d : %d\n", i, sum);
//    }
//    printf("sum : %d\n", sum)
//}

//#include <stdio.h>
//int main()
//{
//    for (int i = 1; i <= 10; ++i)
//        if (i % 5 == 0)
//            printf("%d\n", i);
//}

//#include <stdio.h>
//int main()
//{
//	printf("start main()\n");
//	for (int i = 1; i <= 5; ++i)
//	{
//		if (i % 2 == 1)
//			continue;
//		printf("i : %d\n", i);
//	}
//	printf("end main()\n");
//}

//#include <stdio.h>
//int main()
//{
//	printf("start main()\n");
//	for (int i = 1; i <= 5; ++i)
//	{
//		if (i % 2 == 0)
//			printf("i : %d\n", i);
//	}
//	printf("end main()\n");
//}

//#include <stdio.h>
//int main()
//{
//	printf("start main()\n");
//	for (int i = 1; i <= 5; ++i)
//	{
//		printf("i : %d\n", i);
//	}
//	printf("end main()\n");
//}

//#include <stdio.h>
//int main()
//{
//	printf("start main()\n");
//	while ( 1)
//	{
//		printf("정수 입력 : ");
//		int data = 0;
//		scanf_s("%d", &data);
//		if (data < 0)
//			break;
//
//		printf("int : %d\n", data--);
//	}
//	printf("end main()\n");
//}

//#include <stdio.h>
//int main()
//{
//	printf("start main()\n");
//	int i = 0;
//	while(i < 5)
//	{
//		printf("%d. hello\n", i);
//		i++;
//	}
//	printf("end main()\n");
//}

//#include <stdio.h>
//int main()
//{
//	printf("start main()\n");
//
//	for (int i = 1; i <= 5; i++)
//	{
//		printf("%d. hello\n",i);
//	}
//	printf("end main()\n");
//}

//#include <stdio.h>
//int main()
//{
//	printf("start main()\n");
//
//	for (int i = 1; i <= 5; i++)
//	{
//		printf("1. hello\n");
//		printf("2. hello\n");
//		printf("3. hello\n");
//	}
//	printf("end main()\n");
//
//}

//#include <stdio.h>
//int main()
//{
//	printf("start main()\n");
//
//	for (int i = 0; i < 5; i++)
//	{
//		printf("1. hello\n");
//		printf("2. hello\n");
//		printf("3. hello\n");
//	}
//	printf("end main()\n");
//
//}

//#include <stdio.h>
//int main()
//{
//	int n = 1;
//
//	switch (n)
//	{
//	case 1:
//		printf("1. hello!\n");
//		//break;
//	case 2:
//		printf("2. hello!\n");
//		//break;
//	case 3:
//		printf("3. hello!\n");
//		//break;
//
//	default:
//		printf("default\n");
//		//break;
//	}
//}

//#include <stdio.h>
//int main()
//{
//	int n = 1;
//	
//	switch (n)
//	{
//	case 1:
//		printf("1. hello!\n");
//		break;
//	case 2:
//		printf("2. hello!\n");
//		break;
//	case 3:
//		printf("3. hello!\n");
//		break;
//
//	default:
//		printf("default\n");
//		break;
//	}
//}

//#include <stdio.h>
//int main()
//{
//	int n = 10;
//	printf("정수 입력: ");
//	scanf_s("%d", &n);
//
//	printf("1. hello\n");
//	if (n > 10)
//		printf("2. hello!\n");
//	else
//		printf("3. hello!\n");
//}

//#include <stdio.h>
//int main()
//{
//	int n = 10;
//	printf("1. hello\n");
//	if (n > 10)
//	{
//		printf("2. hello!\n");
//		printf("3. hello!\n");
//	}
//}

//#include <stdio.h>
//int main()
//{
//	int n = 10;
//	double d = 5.5;
//	// 값 출력
//	printf("%d %g\n", n, d);
//
//	// 주소 출력
//	printf("%p %p\n", &n, &d);
//}

//#include <stdio.h>
//int main()
//{
//	printf("1. Hello\n");
//	printf("2. Hello\n");
//	printf("3. Hello\n");
//	printf("4. Hello\n");
//	printf("5. Hello\n");
//}