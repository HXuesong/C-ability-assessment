#include<stdio.h>
#include<string.h>

#define M 30

void fun(char c[]);

int main() {

	char ch[M];

	printf("�������ַ�����\n");

	gets(ch);

	fun(ch);

	return 0;
}
void fun(char c[]) {

	char str1[M];
	char s;
	int i = 0, j = 0, count = 1, k = 0;

	for(i = 0; i < strlen(c); i++) {
		if(c[i] != ' ') {

			s = c[i];
			for(j = 0; j < strlen(c); j++) {

				if(s == c[j]) {

					str1[k] = c[j];
					k++;
					c[j] = ' ';
				}
			}
		}
	}

    str1[k] = '\0';

	printf("�����������ַ���Ϊ:\n");

	puts(str1);
}
