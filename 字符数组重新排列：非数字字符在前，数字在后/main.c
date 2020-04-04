#include<stdio.h>
#include<string.h>

#define N 30

void fun(char *s, char C[]) {
	char D[N];
	int i, j, k;

	i = j = k = 0;

	for(i = 0; s[i] != '\0'; i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			D[k] = s[i];
			k++;
		} else {
			C[j] = s[i];
			j++;
		}
	}

	C[j] = '\0';
	D[k] = '\0';

	strcat(C, D);
}
int main() {

	char s[N], x[N];

	printf("请输入字符串(30字符以内):\n");

	gets(s);

	fun(s, x);

	printf("结果为：\n");

	puts(x);

	return 0;
}
