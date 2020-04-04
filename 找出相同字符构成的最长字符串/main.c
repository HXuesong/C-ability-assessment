#include<stdio.h>
#include<string.h>
#define N 30
char fun(char a[], int *c) {

	char *p = a;
	int t = 1;
	char ch;

	while(*p) {
		if(*p == *(p + 1)) {
			t++;
		}
		else {
			if(t >= *c ) {
				*c = t;
				ch = *p;
			}
			t = 1;
		}
		p++;
	}
	return ch;
}

int main() {
	char b[N];
	int count = 0;
	int i = 1;
	char ch1;

	printf("请输入一个字符串: \n");

	scanf("%s", b);

	ch1 = fun(b, &count);

	printf("最长字符串：\n");

	for(i = 0; i < count; i++) {
		printf("%c", ch1);
	}

	return 0;
}
