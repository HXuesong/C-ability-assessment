#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct member {
	char num[20];
	char name[20];
	int total;
	struct member *next;
}*head;

void creat();
void show();
void upd(char name[]);
void Free();

int main() {

	char num[20];
	creat();
	printf("������Ҫ�޸ĵĻ�Ա��ţ�\n");
	scanf("%s", num);
	upd(num);
	Free();
	return 0;
}

void  creat() {

	struct member *q, *tail;

	head = (struct member *)malloc(sizeof(struct member));

	head->next = NULL;
	tail = head;

	char flag = 'Y';

	while(flag == 'Y')      {

		printf("����������ÿ����Ա�ı�š����������֣� \n");

		q = (struct member *)malloc(sizeof(struct member));
		q->next = NULL;

		scanf("%s %s %d", q->num, q->name, &q->total);

		tail->next = q;
		tail = q;

		printf("�Ƿ��������,��Y���������룬�������ͽ���.\n");

		getchar();
		flag = getchar();
	}

	tail->next = NULL;
}
void show()  {

	struct member *out;
	out = head->next;

	printf("���������ÿ����Ա�ı�š����������֣� \n");

	while(out) {

		printf("%s %s %d\n", out->num, out->name, out->total);
		out = out->next;
	}
}
void upd(char num[])  {

	struct member *p;
	int  mark;
	mark = 0;
	p = head;

	if(head == NULL) {

		printf("�޸�ʧ��.\n�����ڴ���ϵ��.\n");
		return ;
	} else {
		while(p != NULL) {

			if(strcmp(p->num, num) == 0) {

				printf("������Ҫ�޸ĵı�ţ�");
				scanf("%s", p->num);
				printf("������Ҫ�޸ĵ�������");
				scanf("%s", p->name); //1
				printf("������Ҫ�޸ĵĻ��֣�");
				scanf("%d", &p->total);
				mark = 1;
				break;

			} else
				p = p -> next;
		}
	}
	if(!mark) {

		printf("�޸�ʧ��.\n�����ڴ���ϵ��.\n");
		return ;
	}
	show();
}

void Free() {

	struct member *p = head, *pr = NULL;

	while (p != NULL) {

		pr = p;
		p = p->next;
		free(pr);
	}
}
