#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct goods {
	char num[10];
	char name[20];
	int count;
	struct goods *next;
}*head;

void creat();
void show();
void Pfree(struct goods *head);
int updateCount(char num[]);

int main() {
	char num[10];
	creat();
	show();
	printf("��������Ҫ�޸ĵ���Ʒ��ţ�\n");
	scanf("%s", num);
	if(updateCount(num) == 1)
		show();
	Pfree (head);

	return 0;
}
void  creat()   {
	int s = 1;
	head = (struct goods*)malloc(sizeof(struct goods));
	head->next = NULL;
	struct goods *q, *tail;
	tail = head;
	printf("����������ÿ����Ʒ��š����ơ�����\n");
	while (s == 1) {
		q = (struct goods*)malloc(sizeof(struct goods));
		q->next = NULL;
		scanf("%s", q->num);
		getchar();
		scanf("%s", q->name);
		scanf("%d", &q->count);
		tail->next = q;
		tail = q;
		printf("����1�������룬�����������ֽ������룺 ");
		scanf("%d", &s);
	}

}

void show()   {

	printf("������Ʒ����ϢΪ��\n");

	struct goods *out;
	out = head->next;

	while (out) {

		printf("%s %s %d\n", out->num, out->name, out->count);
		out = out->next;
	}
}

int  updateCount(char num[]) {

	struct goods *p;
	int flag = 0;

	p = head->next;

	while (p != NULL) {

		if (strcmp(p->num, num) == 0) {

			printf("�������������Ʒ������ ��\n");
			scanf("%d", &p->count);
			flag = 1;
			break;
		} else
			p = p->next;
	}

	if (flag == 0) {

		printf("�޸�ʧ��.\n");
		printf("����в����ڸ���Ʒ.\n");
	}

	return flag;
}

void Pfree(struct goods *head) {

	struct goods *p, *q = NULL;
	p = head;

	while (p != NULL) {

		q = p;
		p = p->next;
		free(q);
	}
}
