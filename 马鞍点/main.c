#include<stdio.h>

#define N 3

int main() {

	int a[100][100];
	int i, j, x, y, sign;

	printf("�������ά����:\n");

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			scanf("%d", &a[i][j]);

	for(i = 0; i < N; i++) {

		x = i;
		y = 0;
		sign = 1;

		for(j = 0; j < N; j++) {
			if(a[i][j] > a[x][y]) {
				y = j;
			}
		}

		for(j = 0; j < N; j++) {

			if(a[x][y] > a[j][y])
				sign = 0;
		}

		if(sign == 1) {

			printf("�ö�ά����İ���Ϊ%d:�±�Ϊ��%d,%d).\n", a[x][y], x, y);
			break;
		}
	}

	if(sign == 0)
		printf("�ö�ά������û�а���.\n");

    return 0;
}
