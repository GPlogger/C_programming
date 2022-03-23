#include <stdio.h>
int main()
{
	int n = 10;
	double d = 5.5;
	
	printf("%d %g\n", n, d);
	printf("%p %p\n", &n, &d);
}

//#include <stdio.h>
//int main()
//{
//	int n = 10;
//	int r = 0;
//
//	printf("%d %d\n", n, r);
//
//	r = n++;
//	printf("%d %d\n", n, r);
//
//	r = ++n;
//	printf("%d %d\n", n, r);
//}

//#include <stdio.h>
//int main()
//{
//	int n = 10;
//
//	printf("%d\n", n);
//
//	++n;
//	printf("%d\n", n);
//
//	n++;
//	printf("%d\n", n);
//}

//#include <stdio.h>
//int main()
//{
//	int n = 15;
//	if (10 < n && n < 20)
//		printf("10 < n && n < 20\n");
//}


//#include <stdio.h>
//int main()
//{
//	//논리 연산자
//	printf("%d\n", !0);
//	printf("%d\n", !1);
//}

//#include <stdio.h>
//int main()
//{
//	//논리 연산자
//	printf("%d\n", 0 || 0);
//	printf("%d\n", 0 || 1);
//	printf("%d\n", 1 || 0);
//	printf("%d\n", 1 || 1);
//}

//#include <stdio.h>
//int main()
//{
//	//논리 연산자
//	printf("%d\n", 0 && 0);
//	printf("%d\n", 0 && 1);
//	printf("%d\n", 1 && 0);
//	printf("%d\n", 1 && 1);
//}

//#include <stdio.h>
//int main()
//{
//	//비교연산자
//	printf("%d\n", 3 < 5);
//	printf("%d\n", 3 > 5);
//	printf("%d\n", 3 <= 5);
//	printf("%d\n", 3 >= 5);
//	printf("%d\n", 3 == 5);
//	printf("%d\n", 3 != 5);
//
//	//단항연산 or 이항연산
//	int k = 20;
//	printf("%d\n", k);
//	k += 20;
//	printf("%d\n", k);
//	k -= 20;
//	printf("%d\n", k);
//	k *= 20;
//	printf("%d\n", k);
//	k /= 20;
//	printf("%d\n", k);
//}

//#include <stdio.h>
//int main()
//{
//	//산술연산자
//	printf("%d\n", 3 + 5);
//	printf("%d\n", 3 - 5);
//	printf("%d\n", 3 * 5);
//	printf("%d\n", 3 / 5);
//	printf("%d\n", 3 % 5);
//
//}

//#include <stdio.h>
//int main()
//{
//	int n = 10;
//	printf("int : %d\n", n);
//	
//	n = 20;
//	printf("int : %d\n", n);
//
//	n = n + 20;
//	printf("int : %d\n", n);
//
//}

//#include <stdio.h>
//int main()
//{
//	int n = 100;
//	double d = 5.5;
//
//	n = 200;
//	d = 4.567;
//
//	printf("%d\n", n);
//	printf("%g\n", d);
//
//	int k = 300;
//	n = k;
//	printf("%d\n", n);
//}


//#include <stdio.h>
//int main()
//{
//	char c = 10;
//	short s = 20;
//	int n = 10;
//	long l = 40;
//	float f = 5.5;
//	double d = 6.6;
//
//	printf("%d\n", c);
//	printf("%d\n", s);
//	printf("%d\n", n);
//	printf("%d\n", l);
//	printf("%g\n", f);
//	printf("%g\n", d);
//
//	printf("%d\n", sizeof(c));
//	printf("%d\n", sizeof(s));
//	printf("%d\n", sizeof(n));
//	printf("%d\n", sizeof(l));
//	printf("%d\n", sizeof(f));
//	printf("%d\n", sizeof(d));
//
//}

//#include <stdio.h>
//int main()
//{
//	int n = 10;
//	double d = 5.5;
//
//	printf("Hello!\n");
//	printf("%d %g\n", n, d);
//}